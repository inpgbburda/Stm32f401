#include "pwm.h"
#include "pwm_cfg.h"
#include "spi.h"
#include "spi_cfg.h"
#include "cmsis_gcc.h"
#include "systick.h"

int main(void)
{
    PwmInit(&Pwm2_Config);
    SpiInit(&Spi2_Config);
    SystickInit();
    
    PwmStart();
    
    while (1){
        static uint16_t spi_data = 0;
        spi_data = SpiReadBuffer(SPI2);
    }
}