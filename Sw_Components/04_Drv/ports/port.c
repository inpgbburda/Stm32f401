#include "port.h"
#include "stm32f401xc.h"

#define GPIO_AFRL 0x00U
#define GPIO_AFRH 0x01U

void PortInit(const Port_Cfg_T config[])
{
    GPIO_TypeDef* port;

    /* iterate through all ports in config */
    for(int i=0; i<PORT_MAX_NUMBER; i++)
    {
        port = config[i].port;

        port->MODER = config[i].moder;
        /* GPIOx_AFRL (for pin 0 to 7)  */
        port->AFR[GPIO_AFRL] = config[i].alt_fun_pin_0_7;
 	    /* GPIOx_AFRH (for pin 8 to 15) */
        port->AFR[GPIO_AFRH] = config[i].alt_fun_pin_8_15;
    }
}

void PortSetGpioState(GPIO_TypeDef *port, uint8_t pin, bool state)
{
}
