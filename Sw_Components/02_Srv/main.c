#include "pwm.h"
#include "stm32f401xc.h"

#define PERIOD_VAL 100U
#define DUTY_VAL 50U

int main(void)
{
    TIM2-> CR1 |= TIM_CR1_CEN;                  /*Set Counter Enable Bit*/
    RCC->APB1ENR = RCC_APB1ENR_TIM2EN;          /*Enable clock for Timer*/

    TIM2->CCMR1 = (TIM_CCMR1_OC1M & 0x4);       /*Pwm mode 1*/
    TIM2->CCMR1 |=  TIM_CCMR1_OC1PE;            /*Enable the Preload register*/
    TIM2->CCMR1 |= TIM_CR1_ARPE;                /*Enable the auto-reload preload register */
    
    TIM2->ARR = PERIOD_VAL;
    TIM2->CCR1 = DUTY_VAL;

    while (1){
    }
}