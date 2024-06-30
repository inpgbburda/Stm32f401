#include "pwm.h"
#include "spi.h"
#include "spi_cfg.h"
#include "cmsis_gcc.h"
#include "systick.h"

int systic_status = 0;

int main(void)
{
    PwmInit();
    SpiInit(&Spi2_Config);
    systic_status = SystickInit();
    
    PwmStart();
    
    while (1){
        uint16_t spi_data = 0;
        spi_data = SpiReadBuffer(SPI2);
    }
}