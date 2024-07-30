#include "port.h"
#include "stm32f401xc.h"

#define GPIO_AFRL 0x00U
#define GPIO_AFRH 0x01U
#define AFRL_TIM1TIM2_SEL     GPIO_AFRL_AFSEL0_0

#define PORT_MAX_NUMBER 2

typedef struct
{
    GPIO_TypeDef* port;
    uint32_t moder;
}
Port_Cfg_T;

const Port_Cfg_T Config[PORT_MAX_NUMBER] = {
    {GPIOA,  GPIO_MODER_MODER0_1   },    /* Alternate function mode for TIM2 pins */
    {GPIOB, (GPIO_MODER_MODER15_1 |      /* Alternate function mode for SPI2 pins */
             GPIO_MODER_MODER14_1 | 
             GPIO_MODER_MODER13_1 | 
             GPIO_MODER_MODER12_1) }
};

void PortInit(void)
{
    GPIO_TypeDef* port;

    //iterate through all ports in config:
    for(int i=0; i<PORT_MAX_NUMBER; i++)
    {
        port = Config[i].port;
        port->MODER = Config[i].moder;
    }
    /* Set up multiplexers for connecting PORTS with desired hw */
    GPIOA->AFR[GPIO_AFRL] |= AFRL_TIM1TIM2_SEL;     /* Root desired TIMer as pin source*/
    GPIOB->AFR[GPIO_AFRH] |=                        
        GPIO_AFRH_AFSEL15_2 | GPIO_AFRH_AFSEL15_0 | /* AF5 for Pin15 */
        GPIO_AFRH_AFSEL14_2 | GPIO_AFRH_AFSEL14_0 | /* AF5 for Pin14 */
        GPIO_AFRH_AFSEL13_2 | GPIO_AFRH_AFSEL13_0 | /* AF5 for Pin13 */
        GPIO_AFRH_AFSEL12_2 | GPIO_AFRH_AFSEL12_0;  /* AF5 for Pin12 */
}