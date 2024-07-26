#include "pwm_cfg.h"

const Pwm_Cfg_T Pwm2_Config = 
{
    TIM2,        /* instance */
    1000U,       /* prescaler value*/
    100U,        /* reload_val */
    TIM_CCER_CC4E | TIM_CCER_CC3E | TIM_CCER_CC2E | TIM_CCER_CC1E /* Selected channels */
};