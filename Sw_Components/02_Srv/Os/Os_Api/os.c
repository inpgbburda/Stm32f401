/**
 * @file os.c
 * @brief This file contains the implementation of the operating system (OS) functions for a microcontroller using FreeRTOS.
 *
 */

/*
|===================================================================================================================================|
    File includes 
|===================================================================================================================================|
*/
#include "os.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

#include "spi.h"
#include "spi_cfg.h"

#include "pwm.h"
#include "pwm_cfg.h"

#include "motor_ctrl.h"

/*
|===================================================================================================================================|
    Macro definitions
|===================================================================================================================================|
*/
#define SPI_TASK_PERIOD_MS 10
#define PWM_TASK_PERIOD_MS 20

#define PWM_TASK_PRIORITY 1
#define SPI_TASK_PRIORITY 2

#define DEBUG_BUFFER_SIZE 100

#define TICKS_TO_WAIT 10
#define MAX_QUEUE_LENGTH 10

#define LUT_SIZE 255

/*
|===================================================================================================================================|
    Local types definitions 
|===================================================================================================================================|
*/

static QueueHandle_t          Spi_To_Pwm_Queue;
static PowerRequestsPackage_T Debug_Buffer[DEBUG_BUFFER_SIZE] = {0};
static int                    Debug_Samples_Cnt = 0;

static void PwmTask(void* pvParameters);
static void SpiTask(void* pvParameters);

/*
|===================================================================================================================================|
    Object allocations 
|===================================================================================================================================|
*/
uint16_t Motor_Req_To_Pwm_Lut[LUT_SIZE] = {
    0, 78, 157, 235, 313, 392, 470, 549, 627, 705, 784, 862, 941, 1019, 1097, 1176, 1254, 1333, 1411, 1489,
    1568, 1646, 1725, 1803, 1881, 1960, 2038, 2117, 2195, 2273, 2352, 2430, 2509, 2587, 2665, 2744, 2822, 2901,
    2979, 3057, 3136, 3214, 3293, 3371, 3449, 3528, 3606, 3685, 3763, 3841, 3920, 3998, 4077, 4155, 4233, 4312,
    4390, 4469, 4547, 4625, 4704, 4782, 4861, 4939, 5017, 5096, 5174, 5253, 5331, 5409, 5488, 5566, 5645, 5723,
    5801, 5880, 5958, 6037, 6115, 6193, 6272, 6350, 6429, 6507, 6585, 6664, 6742, 6821, 6899, 6977, 7056, 7134,
    7213, 7291, 7369, 7448, 7526, 7605, 7683, 7761, 7840, 7918, 7997, 8075, 8153, 8232, 8310, 8389, 8467, 8545,
    8624, 8702, 8781, 8859, 8937, 9016, 9094, 9173, 9251, 9329, 9408, 9486, 9565, 9643, 9721, 9800, 9878, 9957,
    10035, 10113, 10192, 10270, 10349, 10427, 10505, 10584, 10662, 10741, 10819, 10897, 10976, 11054, 11133, 11211,
    11289, 11368, 11446, 11525, 11603, 11681, 11760, 11838, 11917, 11995, 12073, 12152, 12230, 12309, 12387, 12465,
    12544, 12622, 12701, 12779, 12857, 12936, 13014, 13093, 13171, 13249, 13328, 13406, 13485, 13563, 13641, 13720,
    13798, 13877, 13955, 14033, 14112, 14190, 14269, 14347, 14425, 14504, 14582, 14661, 14739, 14817, 14896, 14974,
    15053, 15131, 15209, 15288, 15366, 15445, 15523, 15601, 15680, 15758, 15837, 15915, 15993, 16072, 16150, 16229,
    16307, 16385, 16464, 16542, 16621, 16699, 16777, 16856, 16934, 17013, 17091, 17169, 17248, 17326, 17405, 17483,
    17561, 17640, 17718, 17797, 17875, 17953, 18032, 18110, 18189, 18267, 18345, 18424, 18502, 18581, 18659, 18737,
    18816, 18894, 18973, 19051, 19129, 19208, 19286, 19365, 19443, 19521, 19600, 19678, 19757, 19835, 19913, 19992};

uint8_t buffer[4] = {0};

TaskHandle_t SpiTaskHandle;

/*
|===================================================================================================================================|
    Local function declarations
|===================================================================================================================================|
*/

/*
|===================================================================================================================================|
    Function definitions
|===================================================================================================================================|
*/

/**
 * @brief This function is called if a task overflows its stack.
 *
 * This function is a FreeRTOS hook function that is called if a task's stack overflows.
 * It is intended to provide debugging information about the task that caused the overflow.
 *
 * @param xTask The handle of the task that overflowed its stack.
 * @param pcTaskName The name of the task that overflowed its stack.
 *
 * @return This function does not return. It enters an infinite loop to prevent the program from continuing.
 */
void vApplicationStackOverflowHook(TaskHandle_t xTask, char* pcTaskName)
{
    while (1)
    {
    };
}

/**
 * @brief This function initializes the operating system (OS) by creating tasks.
 *
 * @return This function does not return.
 */
void OsInit(void)
{
    Spi_To_Pwm_Queue = xQueueCreate(MAX_QUEUE_LENGTH, sizeof(PowerRequestsPackage_T));
    xTaskCreate(PwmTask, "PwmTask", configMINIMAL_STACK_SIZE + 100, NULL, PWM_TASK_PRIORITY, NULL);
    xTaskCreate(SpiTask, "SpiTask", configMINIMAL_STACK_SIZE + 100, NULL, SPI_TASK_PRIORITY, &SpiTaskHandle);
}

/**
 * @brief This function is a task that updates the PWM output.
 * @param pvParameters A pointer to the task's parameters. This parameter is not used in this function.
 *
 * @return This function does not return. It runs in an infinite loop.
 */
static void PwmTask(void* pvParameters)
{

    static PowerRequestsPackage_T receivedMessage;
    BaseType_t                    queue_rx_status;
    uint32_t                      pwm_val;

    for (;;)
    {
        /* Task updating the PWM output */
        if (NULL != Spi_To_Pwm_Queue)
        {
            queue_rx_status = xQueueReceive(Spi_To_Pwm_Queue, &receivedMessage, (TickType_t)TICKS_TO_WAIT);
            if (pdPASS == queue_rx_status)
            {
                /* xRxedStructure now contains a copy of xMessage. */
            }
            if (Debug_Samples_Cnt < DEBUG_BUFFER_SIZE)
            {
                Debug_Buffer[Debug_Samples_Cnt] = receivedMessage;
                Debug_Samples_Cnt++;
            }
        }
        for (int i = 0; i < MOTORS_NUMBER; i++)
        {
            pwm_val = Motor_Req_To_Pwm_Lut[receivedMessage.req_vals[i]];
            /* Update PWM output */
            switch (i)
            {
            case (0):
                PwmSetDuty(&Pwm2_Config, PWM_CHAN_1, pwm_val);
                break;
            case (1):
                PwmSetDuty(&Pwm2_Config, PWM_CHAN_2, pwm_val);
                break;
            case (2):
                PwmSetDuty(&Pwm2_Config, PWM_CHAN_3, pwm_val);
                break;
            case (3):
                PwmSetDuty(&Pwm2_Config, PWM_CHAN_4, pwm_val);
                break;
            default:
                break;
            }
        }
        vTaskDelay(pdMS_TO_TICKS(PWM_TASK_PERIOD_MS));
    }
}

/**
 * @brief This function is a task that reads data from an SPI peripheral and updates a variable.
 *
 * This function is a FreeRTOS task that continuously reads data from an SPI peripheral (SPI2 in this case)
 * and updates a static variable 'spi_data'. It then delays for 10 milliseconds before repeating the process.
 *
 * @param pvParameters A pointer to the task's parameters. This parameter is not used in this function.
 *
 * @return This function runs in an infinite loop and does not return.
 */
static void SpiTask(void* pvParameters)
{
    /* Task reading data from an SPI peripheral */
    PowerRequestsPackage_T dataToPass;
    BaseType_t             queue_tx_status;

    for (;;)
    {
        SpiReadIt(&Spi_Storage, dataToPass.req_vals, MOTORS_NUMBER);
        /*Block the task untill the SPI callback comes*/
        ulTaskNotifyTake(pdTRUE, portMAX_DELAY);

        if (Spi_To_Pwm_Queue != 0)
        {
            queue_tx_status = xQueueSendToFront(Spi_To_Pwm_Queue, (void*)&dataToPass, (TickType_t)TICKS_TO_WAIT);
            if (pdPASS != queue_tx_status)
            {
                /* Failed to post the message on queue in given timeout */
            }
        }
    }
}

void Spi2_RxCompleteCbk(void)
{
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;
    /* Notify the SPI task */
    vTaskNotifyGiveFromISR(SpiTaskHandle, &xHigherPriorityTaskWoken);
    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}

/**
 * @brief This function starts the operating system scheduler.
 *
 * Starts the FreeRTOS scheduler, allowing the created tasks to run.
 *
 * @return This function does not return. It enters an infinite loop once the scheduler has started.
 */
void OsStart(void)
{
    vTaskStartScheduler();
}