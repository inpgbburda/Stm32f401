#include "port.h"
#include "stm32f401xc.h"

#define GPIO_AFRL 0x00U
#define GPIO_AFRH 0x01U

#define PORT_MAX_NUMBER 2

typedef struct
{
    GPIO_TypeDef* port;
    uint32_t moder;
    uint32_t alt_fun_pin_0_7;
    uint32_t alt_fun_pin_8_15;
}
Port_Cfg_T;

const Port_Cfg_T Config[PORT_MAX_NUMBER] = {

    {GPIOA,  GPIO_MODER_MODER0_1,       GPIO_AFRL_AFSEL0_0, 0U                                                      },    /* Alternate function mode for TIM2 pins */
    {GPIOB, (GPIO_MODER_MODER15_1 |                                                                         /* Alternate function mode for SPI2 pins */
             GPIO_MODER_MODER14_1 | 
             GPIO_MODER_MODER13_1 | 
            GPIO_MODER_MODER12_1),      0U,                 (GPIO_AFRH_AFSEL15_2 | GPIO_AFRH_AFSEL15_0 | /* AF5 for Pin15 */
                                                             GPIO_AFRH_AFSEL14_2 | GPIO_AFRH_AFSEL14_0 | /* AF5 for Pin14 */
                                                             GPIO_AFRH_AFSEL13_2 | GPIO_AFRH_AFSEL13_0 | /* AF5 for Pin13 */
                                                             GPIO_AFRH_AFSEL12_2 | GPIO_AFRH_AFSEL12_0)              }
};

void PortInit(void)
{
    GPIO_TypeDef* port;

    //iterate through all ports in config:
    for(int i=0; i<PORT_MAX_NUMBER; i++)
    {
        port = Config[i].port;
        port->MODER = Config[i].moder;
    //- GPIOx_AFRL (for pin 0 to 7) 
 	//- GPIOx_AFRH (for pin 8 to 15)
        port->AFR[GPIO_AFRL] = Config[i].alt_fun_pin_0_7;
        port->AFR[GPIO_AFRH] = Config[i].alt_fun_pin_8_15;
    }
}