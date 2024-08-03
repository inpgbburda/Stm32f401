#include "port_cfg.h"

const uint32_t portA_mode = 
    GPIO_MODER_MODER0_1;

const uint32_t portB_mode =
   (GPIO_MODER_MODER15_1 |
    GPIO_MODER_MODER14_1 |
    GPIO_MODER_MODER13_1 |
    GPIO_MODER_MODER12_1);

const uint32_t portA_afrl = 
    GPIO_AFRL_AFSEL0_0; /* Alternate function mode for TIM2 pins */
const uint32_t portA_afrh = 
    0U;

const uint32_t portB_afrl = 
    0U;
const uint32_t portB_afrh = 
    (GPIO_AFRH_AFSEL15_2 | GPIO_AFRH_AFSEL15_0 | /* AF5 for Pin15 */
     GPIO_AFRH_AFSEL14_2 | GPIO_AFRH_AFSEL14_0 | /* AF5 for Pin14 */
     GPIO_AFRH_AFSEL13_2 | GPIO_AFRH_AFSEL13_0 | /* AF5 for Pin13 */
     GPIO_AFRH_AFSEL12_2 | GPIO_AFRH_AFSEL12_0);

const Port_Cfg_T Port_Config[PORT_MAX_NUMBER] = {

    {GPIOA,  portA_mode, portA_afrl, portA_afrh},    
    {GPIOB,  portB_mode, portB_afrl, portB_afrh}                                                                                       
};