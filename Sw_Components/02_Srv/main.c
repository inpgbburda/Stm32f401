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

#define RANDOM_PWM_VAL 10U

int main(void)
{
    ClockInit(&Clock_Config);
    PortInit(Port_Config);
    PwmInit(&Pwm2_Config);
    SpiInit(&Spi2_Config);
    SystickInit();
    
    PwmStart(&Pwm2_Config);
    PwmSetDuty(&Pwm2_Config, PWM_CHAN_1, RANDOM_PWM_VAL);

    while (1){
        static uint16_t spi_data = 0;
        spi_data = SpiReadBuffer(SPI2);
    }
}