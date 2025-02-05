#include <unity.h>
#include "motor_ctrl.h"
#include "pwm_types.h"
#include "pwm.h"
// #include "FreeRTOS.h"
#include "queue.h"
#include "rtos_types.h"

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

void motor_ctrl_Initialise(void)
{
    void *Feed_Queue;
    xQueueGenericCreate_ExpectAndReturn(2, 3, queueQUEUE_TYPE_BASE, pdPASS);
    Feed_Queue = MotorCtrlInit();
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(motor_ctrl_Initialise);
    RUN_TEST(motor_ctrl_CalculatesMotorsSets);

    return UNITY_END();
}
