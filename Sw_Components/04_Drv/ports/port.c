/**
 * @file port.c
 * @brief Port Driver.
 * @date day/month/year
 * 
 * Files provides hw abstraction for MCU Ports
 */

#include "port.h"
#include "stm32f401xc.h"

#define GPIO_AFRL 0x00U
#define GPIO_AFRH 0x01U

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
void PortInit(const Port_Cfg_T config[])
{
    GPIO_TypeDef* port;

    /* iterate through all ports in config */
    for (int i = 0; i < PORT_MAX_NUMBER; i++)
    {
        port = config[i].port;

        port->MODER = config[i].moder;
        /* GPIOx_AFRL (for pin 0 to 7)  */
        port->AFR[GPIO_AFRL] = config[i].alt_fun_pin_0_7;
        /* GPIOx_AFRH (for pin 8 to 15) */
        port->AFR[GPIO_AFRH] = config[i].alt_fun_pin_8_15;
    }
}

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
void PortSetGpioState(GPIO_TypeDef *port, uint8_t pin, bool state)
{
    if (state)
    {
        port->ODR |= (1 << pin);
    }
    else
    {
        port->ODR &= ~(1 << pin);
    }
}
