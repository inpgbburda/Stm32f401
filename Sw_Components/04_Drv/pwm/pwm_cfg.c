#include "pwm_cfg.h"

const Pwm_Cfg_T Pwm2_Config = 
{
    TIM2,      /* instance */
    15U,       /* prescaler value*/
    19999U,    /* reload_val: 16Mhz/16/20000= 50hz;  counter tic = 1us*/
    TIM_CCER_CC4E | TIM_CCER_CC3E | TIM_CCER_CC2E | TIM_CCER_CC1E /* Selected channels */
};