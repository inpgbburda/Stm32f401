/**
 * @file port.h
 * @brief Functions for initializing and handling the Ports of the microcontroller.
 * 
 */

#ifndef PORT_H
#define PORT_H

#include "stm32f401xc.h"
#include "stdbool.h"

#define PORT_MAX_NUMBER 2 /* For stm32f401 exist ports A and B */

typedef struct
{
    GPIO_TypeDef* port;
    uint32_t moder;            /* mode: input, output, alt.functions, analog */
    uint32_t alt_fun_pin_0_7;  /* alternate functions 0-7 */
    uint32_t alt_fun_pin_8_15; /* alternate functions 8-15 */
}
Port_Cfg_T;


void PortInit(const Port_Cfg_T config[]);
void PortSetGpioState(GPIO_TypeDef* port, uint8_t pin, bool state);

#endif /* PORT_H */