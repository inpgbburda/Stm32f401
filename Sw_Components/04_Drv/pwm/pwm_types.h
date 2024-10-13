#ifndef PWM_TYPES_H
#define PWM_TYPES_H

#include "stm32f401xc.h"

typedef struct
{
    TIM_TypeDef* instance;
    uint16_t prescaler_val;
    uint32_t reload_val;
    uint16_t chan_sel;
}
Pwm_Cfg_T;

typedef enum
{
    PWM_CHAN_1,
    PWM_CHAN_2,
    PWM_CHAN_3,
    PWM_CHAN_4
}
Pwm_Timer_Chan_T;

#endif /* PWM_TYPES_H */