#include "motor_ctrl.h"

#include "pwm.h"
#include "pwm_cfg.h"

void CalculateMotorsSets(void)
{
    PwmSetDuty(&Pwm2_Config, 1, 1);
}