#include "spi_helper_UT.h"
#include <stdint.h>
#include <stddef.h>
#include "spi.h"

static uint8_t Fake_Message[100];
static bool Fake_Flags[100];
static int sample_cnt = 0;
static bool Spi2RxComplete = false;

bool SpiHelper_ReadRxNeFlagMock(void)
{
    bool result;
    result = Fake_Flags[sample_cnt];
    return result;
}

uint8_t SpiHelper_ReadDrMock(void)
{
    uint8_t result;
    result = Fake_Message[sample_cnt];
    return result;
}

void SpiHelper_GoToNextSample(void)
{
    sample_cnt++;
}

void SpiHelper_SetTestPreCondMess(uint8_t mess[], int len)
{
    for (size_t i = 0; i < len; i++)
    {
        Fake_Message[i] = mess[i];
    }
}
void SpiHelper_SetTestPreCondFlags(bool flags[], int len)
{
    for (size_t i = 0; i < len; i++)
    {
        Fake_Flags[i] = flags[i];
    }
}

void SpiHelper_ResetReadIdx(void)
{
    sample_cnt = 0;
}

void SpiHelper_ResetBuffer(uint8_t buffer[], int len)
{
    for(int i=0; i<len; i++){
        buffer[i] = 0;
    }
}

void Spi2_RxCompleteCbk(void)
{
    Spi2RxComplete = true;
}

bool SpiHelper_CheckIf_Spi2_RxCompleteCbkCalled(void)
{
    return Spi2RxComplete;
}

void SpiHelper_Clear_Spi2_RxCompleteCbkStatus(void)
{
    Spi2RxComplete = false;
}

void SpiHelper_SetupTest(uint8_t* injected_message, bool* injected_flags, int len)
{
    SpiHelper_SetTestPreCondMess(injected_message, len);
    SpiHelper_SetTestPreCondFlags(injected_flags, len);
}