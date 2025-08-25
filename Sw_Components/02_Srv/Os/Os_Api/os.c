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

#define MAX_QUEUE_LENGTH 10

/*
|===================================================================================================================================|
    Local types definitions 
|===================================================================================================================================|
*/
static void PwmTask(void* pvParameters);
static void SpiTask(void* pvParameters);

/*
|===================================================================================================================================|
Object allocations 
|===================================================================================================================================|
*/

static TaskHandle_t SpiTaskHandle;
static QueueHandle_t Spi_To_Pwm_Queue;

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
void OsInit(Os_Handle_T* os_handle)
{
    Spi_To_Pwm_Queue = xQueueCreate(MAX_QUEUE_LENGTH, sizeof(PowerRequestsPackage_T));
    MotorCtrlAsignInputQueue(Spi_To_Pwm_Queue);

    xTaskCreate(PwmTask, "PwmTask", configMINIMAL_STACK_SIZE + 100, NULL, PWM_TASK_PRIORITY, NULL);
    xTaskCreate(SpiTask, "SpiTask", configMINIMAL_STACK_SIZE + 100, &(os_handle->rec_handle), SPI_TASK_PRIORITY, &SpiTaskHandle);
}

/**
 * @brief This function is a task that updates the PWM output.
 * @param pvParameters A pointer to the task's parameters. This parameter is not used in this function.
 *
 * @return This function does not return. It runs in an infinite loop.
 */
static void PwmTask(void* pvParameters)
{
    for (;;)
    {
        /* Task updating the PWM output */
        MotorCtrlExecutePeriodic();
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
    Receiver_Handle_T* rec_handle = (Receiver_Handle_T*)pvParameters;
    /* Task reading data from an SPI peripheral */
    for (;;)
    {
        ReceiverExecute(rec_handle);
    }
}

void Spi2_RxCompleteCbk(void)
{
    ReceiverCallRxCompleted(SpiTaskHandle);
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