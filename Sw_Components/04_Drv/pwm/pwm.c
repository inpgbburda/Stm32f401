/**
* File contains 
*
*/

/*
|===================================================================================================================================|
    File includes 
|===================================================================================================================================|
*/

#include "pwm.h"
#include "pwm_cfg.h"
#include "stm32f401xc.h"

/*
|===================================================================================================================================|
    Macro definitions
|===================================================================================================================================|
*/
#define GPIO_AFRL 0x00U
#define MODER0_ALT_FUN_MODE      GPIO_MODER_MODER0_1
#define AFRL_TIM1TIM2_SEL        GPIO_AFRL_AFSEL0_0
#define FIRST_PERIOD 0xFFU

/*
|===================================================================================================================================|
    Local types definitions 
|===================================================================================================================================|
*/


/*
|===================================================================================================================================|
    Object allocations 
|===================================================================================================================================|
*/


/*
|===================================================================================================================================|
    Local function declarations
|===================================================================================================================================|
*/

/*
|===================================================================================================================================|
    Function definitions
|===================================================================================================================================|
*/

void PwmInit(void)
{
    RCC->AHB1ENR = RCC_AHB1LPENR_GPIOALPEN;     /*Enable clock for GPIO*/
    GPIOA->MODER |= MODER0_ALT_FUN_MODE;        /*Configure the desired I/O as an alternate function*/
    GPIOA->AFR[GPIO_AFRL] |= AFRL_TIM1TIM2_SEL; /*Root desired TIMer as pin source*/

    RCC->APB1ENR = RCC_APB1ENR_TIM2EN;  /*Enable clock for Timer*/
    TIM2->ARR = FIRST_PERIOD;           /* Must be set before enabling automatic preload to avoid waiting for first overflow*/
    TIM2->CCMR1 |= (TIM_CCMR1_OC1M_1|TIM_CCMR1_OC1M_2);     /*Pwm mode 1*/
    TIM2->CCMR1 |=  TIM_CCMR1_OC1PE;                        /*Enable the Preload register*/
    TIM2->CR1 |= TIM_CR1_ARPE;                              /*Enable the auto-reload Preload register */
    TIM2->CCER |= TIM_CCER_CC1E;  /*Set OC1 signal is output on the corresponding output pin*/

    TIM2->ARR = PERIOD_VAL;
    TIM2->CCR1 = DUTY_VAL; 
}

void PwmStart()
{
    TIM2->CR1 |= TIM_CR1_CEN;  /*Set Counter Enable Bit*/
}