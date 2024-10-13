#include <unity.h>
#include "motor_ctrl.h"
#include "pwm_types.h"
#include "pwm.h"

void motor_ctrl_CalculatesMotorsSets(void)
{
    PwmSetDuty_ExpectAnyArgs();

    CalculateMotorsSets();
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(motor_ctrl_CalculatesMotorsSets);

    return UNITY_END();
}
