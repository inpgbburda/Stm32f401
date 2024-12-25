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

QueueHandle_t  qeue1;


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
 * @brief This function is a task that updates the PWM output.
 * @param pvParameters A pointer to the task's parameters. This parameter is not used in this function.
 *
 * @return This function does not return. It runs in an infinite loop.
 */
void PwmTask(void *pvParameters) {

    uint8_t receivedValue[20];

    for (;;) {
        /* Task updating the PWM output */
        /* TODO */
    
        if( qeue1 != NULL )
        {
            if( xQueueReceive( qeue1, &receivedValue, (TickType_t)10 ) == pdPASS )
            {
                /* xRxedStructure now contains a copy of xMessage. */
            }
        }
        vTaskDelay(pdMS_TO_TICKS(PWM_TASK_PERIOD_MS));
    }
}

uint8_t buffer[4] = {0};

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

bool MessageReceived = true; 

void SpiTask(void *pvParameters) {
    /* Task reading data from an SPI peripheral */
    uint8_t ulVar = 0;

    for (;;) {
        if( MessageReceived){
            if( qeue1 != 0 )
            {
                /* Send an unsigned long. Wait for 10 ticks for space to become
                available if necessary. */
                if( xQueueSendToBack( qeue1,
                                    ( void * ) &buffer[0],
                                    ( TickType_t ) 10 ) != pdPASS )
                {
                    /* Failed to post the message, even after 10 ticks. */
                }
            }
            for(int i =0; i<4; i++){
                buffer[i] = 0;
            }
            MessageReceived = false;
            SpiReadIt(&Spi_Storage, buffer, 4);
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
 * @brief This function initializes the operating system (OS) by creating tasks.
 *
 * @return This function does not return.
 */
void OsInit(void)
{
    qeue1 = xQueueCreate(10, 4);
    xTaskCreate(PwmTask, "PwmTask", configMINIMAL_STACK_SIZE + 100, NULL, 1, NULL);
    xTaskCreate(SpiTask, "SpiTask", configMINIMAL_STACK_SIZE + 100, NULL, 2, NULL);
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