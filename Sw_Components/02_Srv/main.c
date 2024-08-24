#include "pwm.h"
#include "pwm_cfg.h"
#include "spi.h"
#include "spi_cfg.h"
#include "cmsis_gcc.h"
#include "systick.h"
#include "port.h"
#include "port_cfg.h"
#include "clock.h"
#include "clock_cfg.h"
#include "FreeRTOS.h"
#include "task.h"

#define RANDOM_PWM_VAL 10U

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
        // Task 2 code
        vTaskDelay(pdMS_TO_TICKS(500));  // 500ms delay
    }
}

int main(void)
{
    ClockInit(&Clock_Config);
    PortInit(Port_Config);
    PwmInit(&Pwm2_Config);
    SpiInit(&Spi2_Config);
    SystickInit();
    
    PwmStart(&Pwm2_Config);
    PwmSetDuty(&Pwm2_Config, PWM_CHAN_1, RANDOM_PWM_VAL);

    xTaskCreate(vTask1, "Task 1", configMINIMAL_STACK_SIZE + 100, NULL, 1, NULL);
    xTaskCreate(vTask2, "Task 2", configMINIMAL_STACK_SIZE + 100, NULL, 2, NULL);

    vTaskStartScheduler();

    while (1){
        static uint16_t spi_data = 0;
        spi_data = SpiReadBuffer(SPI2);
    }
}