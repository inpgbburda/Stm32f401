/**
* @file clock.h
* @brief Functions for initializing and handling the clocks of microcontroller.
*
* Detailed description of the module
*
* @author -
* @date 28/07/2024
*/


#ifndef CLOCK_H
#define CLOCK_H

/*
|===================================================================================================================================|
    File includes 
|===================================================================================================================================|
*/
#include "stdint.h"
#include "stm32f401xc.h"

/*
|===================================================================================================================================|
    Exported types declarations
|===================================================================================================================================|
*/
typedef struct
{
    uint32_t rcc_ahb1;
    uint32_t rcc_apb1;
    uint32_t rcc_apb2;
} Clock_Cfg_T;

/*
|===================================================================================================================================|
    Exported functions declarations
|===================================================================================================================================|
*/

/**
 * @brief Initializes the clock with the specified configuration.
 * @param config Pointer to a Clock_Cfg_T structure that contains the configuration information for the clock.
 * 
 * This function sets up the clock according to the provided configuration.
 * 
 * @return None
 * 
 * @note Ensure that the config parameter is not NULL and points to a valid Clock_Cfg_T structure.
 */
void ClockInit(const Clock_Cfg_T* config);

#endif /* CLOCK_H */