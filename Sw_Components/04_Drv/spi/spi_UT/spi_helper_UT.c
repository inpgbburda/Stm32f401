#include "spi_helper_UT.h"
#include <stdint.h>
#include <stddef.h>
#include "spi.h"

static uint8_t Fake_Message[100];
static bool Fake_Flags[100];
static int sample_cnt = 0;
static bool Spi2RxComplete = false;

void ResetReadIdx(void);

void GoToNextSample(void)
{
    sample_cnt++;
}

void SetTestPreConditionsMessage(uint8_t mess[], int len)
{
    for (size_t i = 0; i < len; i++)
    {
        Fake_Message[i] = mess[i];
    }
}
void SetTestConditionsFlags(bool flags[], int len)
{
    for (size_t i = 0; i < len; i++)
    {
        Fake_Flags[i] = flags[i];
    }
}

bool ReadRxNeFlagMock(void)
{
    bool result;
    result = Fake_Flags[sample_cnt];
    return result;
}

uint8_t ReadDrMock(void)
{
    uint8_t result;
    result = Fake_Message[sample_cnt];
    return result;
}

void ResetReadIdx(void)
{
    sample_cnt = 0;
}

void ResetBuffer(uint8_t buffer[], int len)
{
    for(int i=0; i<len; i++){
        buffer[i] = 0;
    }
}

void SetupSpiTest(uint8_t* injected_message, bool* injected_flags, int len)
{
    SetTestPreConditionsMessage(injected_message, len);
    SetTestConditionsFlags(injected_flags, len);
}

void Spi2_RxCompleteCbk(void)
{
    Spi2RxComplete = true;
}

bool Was_Spi2_RxCompleteCbkCalled(void)
{
    return Spi2RxComplete;
}

void Clear_Spi2_RxCompleteCbkStatus(void)
{
    Spi2RxComplete = false;
}
