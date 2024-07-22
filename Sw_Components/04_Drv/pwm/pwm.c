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
#define PERIOD_VAL 100U

void PwmInit(const Pwm_Cfg_T* config)
{
    TIM_TypeDef* timer_instance;

    timer_instance = config->instance;
    RCC->AHB1ENR = RCC_AHB1LPENR_GPIOALPEN;     /*Enable clock for GPIO*/
    GPIOA->MODER |= MODER0_ALT_FUN_MODE;        /*Configure the desired I/O as an alternate function*/
    GPIOA->AFR[GPIO_AFRL] |= AFRL_TIM1TIM2_SEL; /*Root desired TIMer as pin source*/

    RCC->APB1ENR = RCC_APB1ENR_TIM2EN;          /*Enable clock for Timer*/
    timer_instance->ARR = FIRST_PERIOD;         /* Must be set before enabling automatic preload to avoid waiting for first overflow*/
    timer_instance->CCMR1 |= (TIM_CCMR1_OC1M_1|TIM_CCMR1_OC1M_2);     /*Pwm mode 1*/
    timer_instance->CCMR1 |=  TIM_CCMR1_OC1PE;                        /*Enable the Preload register*/
    timer_instance->CR1 |= TIM_CR1_ARPE;                              /*Enable the auto-reload Preload register */
    timer_instance->CCER |= TIM_CCER_CC1E;      /*Set OC1 signal is output on the corresponding output pin*/
    timer_instance->DIER |= TIM_DIER_CC1IE;

    timer_instance->ARR = config->reload_val;
    timer_instance->CCR1 = 0U;
}

void PwmStart(const Pwm_Cfg_T* config)
{
    TIM_TypeDef* timer_instance = config->instance;
    timer_instance->CR1 |= TIM_CR1_CEN;  /*Set Counter Enable Bit*/
}

void PwmSetDuty(const Pwm_Cfg_T* config, uint32_t cc_reg_val)
{
    TIM_TypeDef* timer_instance = config->instance;
    timer_instance->CCR1 = cc_reg_val;
}