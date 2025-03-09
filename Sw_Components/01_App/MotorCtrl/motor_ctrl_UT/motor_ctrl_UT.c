#include <unity.h>
#include "motor_ctrl.h"
#include "pwm_types.h"
#include "pwm.h"
#include "queue.h"
#include "task.h"
#include "rtos_types_UT.h"
#include "spi.h"

Spi_Storage_T Spi_Storage;

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
    spi_Init();
    queue_Init();
    task_Init();
}

void tearDown(void)
{
    pwm_Verify();
    spi_Verify();
    queue_Verify();
    task_Verify();

    pwm_Destroy();
    spi_Destroy();
    queue_Destroy();
    task_Destroy();
}

void motor_ctrl_AssignsQueue(void)
{
    MotorCtrlAsignInputQueue(Arbitrary_Queue_Handle);

    TEST_ASSERT_EQUAL(Arbitrary_Queue_Handle, MotorCtrlGetInboxQueueHandle());
}

void motor_ctrl_ExecutesPeriodicallyWithCorrectValues(void)
{
    PowerRequestsPackage_T received_message = {{100, 50, 255, 1}};
    uint16_t expected_pwm_values[] = {1392, 1196, 2000, 1004};

    xQueueReceive_ExpectAnyArgsAndReturn(pdPASS);
    xQueueReceive_ReturnThruPtr_pvBuffer(&received_message);
    ExpectPwmSetDutyCallWithConfigIgnore(expected_pwm_values);

    MotorCtrlExecutePeriodic();
}

void receiver_Executes(void)
{
    const TickType_t undefined_wait_period = portMAX_DELAY;
    const BaseType_t expected_single_event = pdTRUE;
    const PowerRequestsPackage_T read_data = {{1, 100, 2, 3}};
    const TickType_t max_puting_time = 100;

    SpiReadIt_ExpectAnyArgs();
    SpiReadIt_ReturnThruPtr_dest_ptr((void*)&read_data);

    ulTaskGenericNotifyTake_ExpectAndReturn(tskDEFAULT_INDEX_TO_NOTIFY, expected_single_event, undefined_wait_period, pdTRUE);

    xQueueGenericSend_ExpectAndReturn(Arbitrary_Queue_Handle, (void*)&read_data, (TickType_t)max_puting_time, queueSEND_TO_FRONT, pdPASS);

    ReceiverExecute();
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(motor_ctrl_AssignsQueue);
    RUN_TEST(motor_ctrl_ExecutesPeriodicallyWithCorrectValues);
    RUN_TEST(receiver_Executes);
    return UNITY_END();
}
