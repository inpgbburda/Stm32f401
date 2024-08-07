#include "port_cfg.h"
#include "port_types.h"

const uint32_t portA_mode = 
(
    GPIO_0_ALT_FUN_MODE|
    GPIO_1_INPUT_MODE  |
    GPIO_2_INPUT_MODE  |
    GPIO_3_INPUT_MODE  |
    GPIO_4_INPUT_MODE  |
    GPIO_5_INPUT_MODE  |
    GPIO_6_INPUT_MODE  |
    GPIO_7_INPUT_MODE  |
    GPIO_8_INPUT_MODE  |
    GPIO_9_INPUT_MODE  |
    GPIO_10_INPUT_MODE |
    GPIO_11_INPUT_MODE |
    GPIO_12_INPUT_MODE |
    GPIO_13_INPUT_MODE |
    GPIO_14_INPUT_MODE |
    GPIO_15_INPUT_MODE
);
const uint32_t portB_mode =
(
    GPIO_1_INPUT_MODE   |
    GPIO_2_INPUT_MODE   |
    GPIO_3_INPUT_MODE   |
    GPIO_4_INPUT_MODE   |
    GPIO_5_INPUT_MODE   |
    GPIO_6_INPUT_MODE   |
    GPIO_7_INPUT_MODE   |
    GPIO_8_INPUT_MODE   |
    GPIO_9_INPUT_MODE   |
    GPIO_10_INPUT_MODE  |
    GPIO_11_INPUT_MODE  |
    GPIO_12_ALT_FUN_MODE|
    GPIO_13_ALT_FUN_MODE|
    GPIO_14_ALT_FUN_MODE|
    GPIO_15_ALT_FUN_MODE 
);

const uint32_t portA_afrl = 
(
    GPIO_0_ALT_FUN_1| /* TIM2 pin */
    GPIO_1_ALT_FUN_0|
    GPIO_2_ALT_FUN_0|
    GPIO_3_ALT_FUN_0|
    GPIO_4_ALT_FUN_0|
    GPIO_5_ALT_FUN_0|
    GPIO_6_ALT_FUN_0|
    GPIO_7_ALT_FUN_0
);
const uint32_t portA_afrh = 
(
    GPIO_8_ALT_FUN_0 |
    GPIO_9_ALT_FUN_0 |
    GPIO_10_ALT_FUN_0|
    GPIO_11_ALT_FUN_0|
    GPIO_12_ALT_FUN_0|
    GPIO_13_ALT_FUN_0|
    GPIO_14_ALT_FUN_0|
    GPIO_15_ALT_FUN_0
);

const uint32_t portB_afrl = 
(
    GPIO_0_ALT_FUN_0|
    GPIO_1_ALT_FUN_0|
    GPIO_2_ALT_FUN_0|
    GPIO_3_ALT_FUN_0|
    GPIO_4_ALT_FUN_0|
    GPIO_5_ALT_FUN_0|
    GPIO_6_ALT_FUN_0|
    GPIO_7_ALT_FUN_0
);
const uint32_t portB_afrh = 
(
    GPIO_8_ALT_FUN_0 |
    GPIO_9_ALT_FUN_0 |
    GPIO_10_ALT_FUN_0|
    GPIO_11_ALT_FUN_0|
    GPIO_12_ALT_FUN_5|  /* Spi pins */
    GPIO_13_ALT_FUN_5|  /* Spi pins */
    GPIO_14_ALT_FUN_5|  /* Spi pins */
    GPIO_15_ALT_FUN_5   /* Spi pins */
); 

const Port_Cfg_T Port_Config[PORT_MAX_NUMBER] = 
{
    {GPIOA,  portA_mode, portA_afrl, portA_afrh},    
    {GPIOB,  portB_mode, portB_afrl, portB_afrh}                                                                                       
};