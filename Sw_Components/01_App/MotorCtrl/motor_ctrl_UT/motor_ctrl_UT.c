#include <unity.h>
#include "motor_ctrl.h"
#include "pwm_types.h"
#include "pwm.h"


void setUp(void)
{
    pwm_Init();
}

void tearDown(void)
{
    pwm_Verify();
}

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
