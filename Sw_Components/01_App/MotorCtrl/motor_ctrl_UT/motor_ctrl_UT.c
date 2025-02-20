#include <unity.h>
#include "motor_ctrl.h"
#include "pwm_types.h"
#include "pwm.h"
#include "queue.h"
#include "rtos_types_UT.h"

const int Max_Queue_Length = 10;
const int Max_Queue_Item_Size = 4;
const QueueHandle_t Arbitrary_Queue_Handle = (void*)0x1234; /*Variable used only to store non NULL pointer */

static void ExpectPwmSetDutyCallWithConfigIgnore(uint16_t Expected_Pwm_Values[] )
{
    for(int i = 0; (Pwm_Timer_Chan_T)i < PWM_CHAN_MAX; i++)
    {
        PwmSetDuty_Expect(NULL, i, Expected_Pwm_Values[i]);
        PwmSetDuty_IgnoreArg_config();
    }
}

void setUp(void)
{
    pwm_Init();
}

void tearDown(void)
{
    pwm_Verify();
}

void motor_ctrl_Initialises(void)
{
    MotorCtrlInit(Arbitrary_Queue_Handle);

    TEST_ASSERT_EQUAL(Arbitrary_Queue_Handle, MotorCtrlGetInboxQueueHandle());
}

void motor_ctrl_ExecutesPeriodicallyWithCorrectValues(void)
{
    PowerRequestsPackage_T received_message = {{100, 50, 255, 1}};
    uint16_t Expected_Pwm_Values[] = {1392, 1196, 2000, 1004};

    xQueueReceive_ExpectAnyArgsAndReturn(pdPASS);
    xQueueReceive_ReturnThruPtr_pvBuffer(&received_message);
    ExpectPwmSetDutyCallWithConfigIgnore(Expected_Pwm_Values);

    MotorCtrlExecutePeriodic();
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(motor_ctrl_Initialises);
    RUN_TEST(motor_ctrl_ExecutesPeriodicallyWithCorrectValues);
    return UNITY_END();
}
