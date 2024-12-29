/**
 * @file os.c
 * @brief This file contains the implementation of the operating system (OS) functions for a microcontroller using FreeRTOS.
 *
 */

#include "os.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

#include "spi.h"
#include "spi_cfg.h"

#define SPI_TASK_PERIOD_MS 10
#define PWM_TASK_PERIOD_MS 20

#define PWM_TASK_PRIORITY 2
#define SPI_TASK_PRIORITY 1

#define ARRAY_SIZE 4
#define DEBUG_BUFFER_SIZE 100

#define TICKS_TO_WAIT 10
#define MAX_QUEUE_LENGTH 10

typedef struct {
    uint8_t data[ARRAY_SIZE]; 
} PowerRequestsPackage_T;

static QueueHandle_t  SpiToPWmQueue;
static bool MessageReceived = true; 
static PowerRequestsPackage_T Debug_Buffer[DEBUG_BUFFER_SIZE] = {0};
static int cnt = 0;

static void PwmTask(void *pvParameters);
static void SpiTask(void *pvParameters);


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
void vApplicationStackOverflowHook(TaskHandle_t xTask, char *pcTaskName) {
    while(1){

    };
}


/**
 * @brief This function initializes the operating system (OS) by creating tasks.
 *
 * @return This function does not return.
 */
void OsInit(void)
{
    SpiToPWmQueue = xQueueCreate(MAX_QUEUE_LENGTH, sizeof(PowerRequestsPackage_T));
    xTaskCreate(PwmTask, "PwmTask", configMINIMAL_STACK_SIZE + 100, NULL, PWM_TASK_PRIORITY, NULL);
    xTaskCreate(SpiTask, "SpiTask", configMINIMAL_STACK_SIZE + 100, NULL, SPI_TASK_PRIORITY, NULL);
}


/**
 * @brief This function is a task that updates the PWM output.
 * @param pvParameters A pointer to the task's parameters. This parameter is not used in this function.
 *
 * @return This function does not return. It runs in an infinite loop.
 */
static void PwmTask(void *pvParameters) {

    PowerRequestsPackage_T receivedMessage;

    for (;;) {
        /* Task updating the PWM output */
        if( SpiToPWmQueue != NULL ){
            if( xQueueReceive(SpiToPWmQueue, &receivedMessage, (TickType_t)TICKS_TO_WAIT) == pdPASS ){
                /* xRxedStructure now contains a copy of xMessage. */
            }
            if( cnt < DEBUG_BUFFER_SIZE ){
                Debug_Buffer[cnt] = receivedMessage;
                cnt++;
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
static void SpiTask(void *pvParameters) {
    /* Task reading data from an SPI peripheral */
    PowerRequestsPackage_T dataToPass;

    for (;;) {
        if( MessageReceived){
            if( SpiToPWmQueue != 0 ){
                if( xQueueSendToFront(SpiToPWmQueue,( void * ) &dataToPass,( TickType_t ) TICKS_TO_WAIT) != pdPASS ){
                    /* Failed to post the message, even after 10 ticks. */
                }
            }
            MessageReceived = false;
            SpiReadIt(&Spi_Storage, dataToPass.data, ARRAY_SIZE);
        }
        else{
            /*Do nothing*/
        }
        vTaskDelay(pdMS_TO_TICKS(SPI_TASK_PERIOD_MS));
    }
}

void Spi2_RxCompleteCbk(void)
{
    MessageReceived = true;
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