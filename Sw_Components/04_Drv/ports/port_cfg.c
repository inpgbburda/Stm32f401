#include "port_cfg.h"

const Port_Cfg_T Port_Config[PORT_MAX_NUMBER] = {

    {GPIOA,  GPIO_MODER_MODER0_1,       GPIO_AFRL_AFSEL0_0, 0U                                                      },    /* Alternate function mode for TIM2 pins */
    {GPIOB, (GPIO_MODER_MODER15_1 |                                                                         /* Alternate function mode for SPI2 pins */
             GPIO_MODER_MODER14_1 | 
             GPIO_MODER_MODER13_1 | 
            GPIO_MODER_MODER12_1),      0U,                 (GPIO_AFRH_AFSEL15_2 | GPIO_AFRH_AFSEL15_0 | /* AF5 for Pin15 */
                                                             GPIO_AFRH_AFSEL14_2 | GPIO_AFRH_AFSEL14_0 | /* AF5 for Pin14 */
                                                             GPIO_AFRH_AFSEL13_2 | GPIO_AFRH_AFSEL13_0 | /* AF5 for Pin13 */
                                                             GPIO_AFRH_AFSEL12_2 | GPIO_AFRH_AFSEL12_0)              }
};