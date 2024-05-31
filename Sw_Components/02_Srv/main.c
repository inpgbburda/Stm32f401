#include "pwm.h"
#include "spi.h"
#include "spi_cfg.h"

int main(void)
{
    PwmInit();
    SpiInit(&Spi2_Config);

    PwmStart();
    
    while (1){
        uint16_t spi_data = 0;
        spi_data = SpiReadBuffer(SPI2);
    }
}