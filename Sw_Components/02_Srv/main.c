#include "pwm.h"
#include "spi.h"
#include "spi_cfg.h"

int main(void)
{
    PwmInit();
    SpiInit(&Spi_Config);

    PwmStart();
    
    while (1){
    }
}