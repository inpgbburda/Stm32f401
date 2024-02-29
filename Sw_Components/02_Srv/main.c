#include "pwm.h"
#include "spi.h"

int main(void)
{
    PwmInit();
    SpiInit();

    PwmStart();
    
    while (1){
    }
}