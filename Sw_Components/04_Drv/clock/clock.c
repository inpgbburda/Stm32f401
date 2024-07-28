#include "clock.h"
#include "stm32f401xc.h"

void ClockInit(void)
{
    RCC->AHB1ENR |= RCC_AHB1LPENR_GPIOALPEN;     /* Enable clock for GPIO PORT A */
    RCC->AHB1ENR |= RCC_AHB1LPENR_GPIOBLPEN;    /* Enable clock for GPIO PORT B */
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;          /* Enable clock for Timer 2 */
    RCC->APB1ENR |= RCC_APB1ENR_SPI2EN;         /* Enable clock for SPI2 */
}