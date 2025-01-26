/**
 * @file port.h
 * @brief Functions for initializing and handling the Ports of the microcontroller.
 * @date day/month/year
 */

#ifndef PORT_H
#define PORT_H

#include "stm32f401xc.h"
#include "stdbool.h"

#define PORT_MAX_NUMBER 2 /* For stm32f401 exist only ports A and B */

/*
|===================================================================================================================================|
    File includes 
|===================================================================================================================================|
*/

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

typedef struct
{
    GPIO_TypeDef* port;
    uint32_t moder;            /* mode: input, output, alt.functions, analog */
    uint32_t alt_fun_pin_0_7;  /* alternate functions 0-7 */
    uint32_t alt_fun_pin_8_15; /* alternate functions 8-15 */
}
Port_Cfg_T;

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
 * @brief Initializes the GPIO ports based on the provided configuration.
 *
 * @param config An array of Port_Cfg_T structures, where each structure contains
 * the configuration for a single GPIO port.
 *
 * This function iterates through the provided configuration array and sets the
 * mode and alternate function
 * 
 * @return void
 *
 * @note The PORT_MAX_NUMBER macro should be defined to indicate the maximum number
 * of ports in the configuration array.
 */
void PortInit(const Port_Cfg_T config[]);

/**
 * @brief Sets the state of a specific GPIO pin.
 *
 * @param port A pointer to the GPIO_TypeDef structure representing the GPIO port.
 * @param pin The pin number within the specified GPIO port.
 * @param state The desired state of the pin. true for high, false for low.
 * 
 * This function allows the user to set the state of a specified GPIO pin to either
 * high (true) or low (false). The function uses the GPIO Data Output Register (ODR)
 * to achieve this.
 *
 * @return void
 *
 * @note This function assumes that the GPIO port and selected pin have been properly
 * initialized and configured.
 */
void PortSetGpioState(GPIO_TypeDef* port, uint8_t pin, bool state);

#endif /* PORT_H */