/**
* @file pwm.c
* @brief PWM driver source file
*
* This file contains the implementation of the PWM driver functions.
*
* @note This driver is designed for the STM32F401 microcontroller.
* @attention Ensure that the timer and GPIO configurations are properly set before using the PWM functions.
* @see pwm.h for the function declarations and types.
* @date 26/07/2024
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

/**
 * @brief Initializes the PWM signal using the provided configuration.
 *
 * @param config Pointer to the PWM configuration structure.
 *
 * The function configures the GPIO pin, timer instance, and sets the initial parameters for the PWM signal.
 * It also enables the necessary clocks and alternate functions for the GPIO pin.
 */
void PwmInit(const Pwm_Cfg_T* config)
{
    TIM_TypeDef* timer_instance;
    timer_instance = config->instance;

    timer_instance->PSC = config->prescaler_val;    /* Set prescaler value */
    timer_instance->ARR = FIRST_PERIOD;         /* Must be set before enabling automatic preload to avoid waiting for first overflow*/
    timer_instance->CCMR1 |= (TIM_CCMR1_OC1M_1|TIM_CCMR1_OC1M_2);     /*Pwm mode 1*/
    timer_instance->CCMR1 |=  TIM_CCMR1_OC1PE;                        /*Enable the Preload register*/
    timer_instance->CR1 |= TIM_CR1_ARPE;                              /*Enable the auto-reload Preload register */
    timer_instance->CCER |= config->chan_sel;      /* Set channels as output */

    timer_instance->ARR = config->reload_val;
    timer_instance->CCR1 = 0U;
    timer_instance->CCR2 = 0U;
    timer_instance->CCR3 = 0U;
    timer_instance->CCR4 = 0U;
}

/**
 * @brief Starts the PWM signal using the provided configuration.
 *
 * @param config Pointer to the PWM configuration structure.
 */
void PwmStart(const Pwm_Cfg_T* config)
{
    TIM_TypeDef* timer_instance = config->instance;
    timer_instance->CR1 |= TIM_CR1_CEN;  /*Set Counter Enable Bit*/
}

/**
 * @brief Sets the duty cycle of the PWM signal for the specified channel.
 *
 * @param config Pointer to the PWM configuration structure.
 * @param channel The PWM channel to set the duty cycle for.
 * @param cc_reg_val The value to set in the corresponding capture/compare register.
 */
void PwmSetDuty(const Pwm_Cfg_T* config, Pwm_Timer_Chan_T channel, uint32_t cc_reg_val)
{
    TIM_TypeDef* timer_instance = config->instance;
    switch(channel)
    {
    case PWM_CHAN_1:
        timer_instance->CCR1 = cc_reg_val;
        break;
    case PWM_CHAN_2:
        timer_instance->CCR2 = cc_reg_val;
        break;
    case PWM_CHAN_3:
        timer_instance->CCR3 = cc_reg_val;
        break;
    case PWM_CHAN_4:
        timer_instance->CCR4 = cc_reg_val;
        break;
    default:
        /* Handle invalid channel - don't set anything */
        break;
    }
}