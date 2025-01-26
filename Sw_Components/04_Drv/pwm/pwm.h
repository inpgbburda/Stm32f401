/**
* @file pwm.h
* @brief PWM driver header file
*
* This file contains the declarations for the PWM driver functions and types.
*
*/

#ifndef PWM_H
#define PWM_H

/*
|===================================================================================================================================|
    File includes 
|===================================================================================================================================|
*/
#include <stdbool.h>
#include "stm32f401xc.h"
#include "pwm_types.h"

/*
|===================================================================================================================================|
    Macro definitions
|===================================================================================================================================|
*/

/*
|===================================================================================================================================|
    Exported types declarations
|===================================================================================================================================|
*/

/*
|===================================================================================================================================|
    Exported objects declarations
|===================================================================================================================================|
*/

/*
|===================================================================================================================================|
    Exported functions declarations
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
void PwmInit(const Pwm_Cfg_T* config);

/**
 * @brief Starts the PWM signal using the provided configuration.
 *
 * @param config Pointer to the PWM configuration structure.
 */
void PwmStart(const Pwm_Cfg_T *config);

/**
 * @brief Sets the duty cycle of the PWM signal for the specified channel.
 *
 * @param config Pointer to the PWM configuration structure.
 * @param channel The PWM channel to set the duty cycle for.
 * @param cc_reg_val The value to set in the corresponding capture/compare register.
 */
void PwmSetDuty(const Pwm_Cfg_T* config, Pwm_Timer_Chan_T channel, uint32_t cc_reg_val);

#endif /* PWM_H */