/**
* @file clock.h
* @brief Functions for initializing and handling the clocks of microcontroller.
*
* Detailed description of the module
*
* @author -
* @date 28/07/2024
*/
/*
|===================================================================================================================================|
    File includes 
|===================================================================================================================================|
*/
#include "clock.h"

/*
|===================================================================================================================================|
    Function definitions
|===================================================================================================================================|
*/

/**
 * @brief Initializes the clocks of the microcontroller based on the provided configuration.
 *
 * This function enables the clocks for the AHB1 and APB1 peripherals based on the given configuration.
 *
 * @param config A pointer to a Clock_Cfg_T structure containing the clock configuration settings.
 *
 * @return void
 */
void ClockInit(const Clock_Cfg_T* config)
{
    RCC->AHB1ENR |= config->rcc_ahb1;
    RCC->APB1ENR |= config->rcc_apb1;
    RCC->APB2ENR |= config->rcc_apb2;
}