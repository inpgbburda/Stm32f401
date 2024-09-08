#include "os.h"
#include "FreeRTOS.h"
#include "task.h"
#include "spi.h"

void vApplicationStackOverflowHook(TaskHandle_t xTask, char *pcTaskName) {
    while(1){

    };
}

void vTask1(void *pvParameters) {
    for (;;) {
        // Task 1 code
        vTaskDelay(pdMS_TO_TICKS(1000));  // 1-second delay
    }
}

void vTask2(void *pvParameters) {
    for (;;) {
        static uint16_t spi_data = 0;
        spi_data = SpiReadBuffer(SPI2);
        vTaskDelay(pdMS_TO_TICKS(10));
    }
}

void OsInit(void)
{
    xTaskCreate(vTask1, "Task 1", configMINIMAL_STACK_SIZE + 100, NULL, 1, NULL);
    xTaskCreate(vTask2, "Task 2", configMINIMAL_STACK_SIZE + 100, NULL, 2, NULL);
}

void OsStart(void)
{
    vTaskStartScheduler();
}