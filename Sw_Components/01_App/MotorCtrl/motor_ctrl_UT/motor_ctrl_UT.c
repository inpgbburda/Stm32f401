#include <unity.h>
#include "motor_ctrl.h"
#include "pwm_types.h"
#include "pwm.h"
#include "queue.h"
#include "rtos_types_UT.h"

const int Max_Queue_Length = 10;
const int Max_Queue_Item_Size = 4;
const QueueHandle_t Arbitrary_Queue_Handle = (void*)0x1234; /*Variable used only to store non NULL pointer */

static void ExpectPwmSetDutyCallWithConfigIgnore(uint16_t channel_values[] )
{
    for(int i = 0; (Pwm_Timer_Chan_T)i < PWM_CHAN_MAX; i++)
    {
        PwmSetDuty_Expect(NULL, i, channel_values[i]);
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

void motor_ctrl_CalculatesMotorsSets(void)
{
    PwmSetDuty_ExpectAnyArgs();

    CalculateMotorsSets();
}

void motor_ctrl_Initialises(void)
{
    MotorCtrlInit(Arbitrary_Queue_Handle);

    TEST_ASSERT_EQUAL(Arbitrary_Queue_Handle, MotorCtrlGetInboxQueueHandle());
}

void motor_ctrl_ExecutesPeriodically(void)
{
    uint16_t channel_values[] = {0, 0, 0, 0};

    xQueueReceive_ExpectAnyArgsAndReturn(pdPASS);
    ExpectPwmSetDutyCallWithConfigIgnore(channel_values);

    MotorCtrlExecutePeriodic();
}

void motor_ctrl_ExecutesPeriodicallyWithCorrectValues(void)
{
    uint16_t channel_values[] = {1490, 1235, 1999, 1003};
    const uint8_t received_values[] = {100, 50, 255, 1};
    PowerRequestsPackage_T received_message = {{100, 50, 255, 1}};

    xQueueReceive_ExpectAnyArgsAndReturn(pdPASS);
    xQueueReceive_ReturnThruPtr_pvBuffer(&received_message);
    ExpectPwmSetDutyCallWithConfigIgnore(channel_values);

    MotorCtrlExecutePeriodic();
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(motor_ctrl_Initialises);
    RUN_TEST(motor_ctrl_CalculatesMotorsSets);
    // RUN_TEST(motor_ctrl_ExecutesPeriodically);
    RUN_TEST(motor_ctrl_ExecutesPeriodicallyWithCorrectValues);
    return UNITY_END();
}
