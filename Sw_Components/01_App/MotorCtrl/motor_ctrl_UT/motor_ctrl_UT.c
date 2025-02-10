#include <unity.h>
#include "motor_ctrl.h"
#include "pwm_types.h"
#include "pwm.h"
#include "queue.h"
#include "rtos_types_UT.h"

const int Max_Queue_Length = 10;
const int Max_Queue_Item_Size = 4;
const QueueHandle_t Arbitrary_Queue_Handle = (void*)0x1234; /*Variable used only to store non NULL pointer */

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
    void *Queue_Handler;

    xQueueGenericCreate_ExpectAndReturn(Max_Queue_Length, Max_Queue_Item_Size, queueQUEUE_TYPE_BASE, Arbitrary_Queue_Handle);
    Queue_Handler = MotorCtrlInit();

    TEST_ASSERT_NOT_NULL(Queue_Handler);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(motor_ctrl_Initialise);
    RUN_TEST(motor_ctrl_CalculatesMotorsSets);

    return UNITY_END();
}
