#include "spi_helper_UT.h"
#include <stdint.h>
#include <stddef.h>

static uint8_t Fake_Message[100];
static bool Fake_Flags[100];
static int cnt = 0;

void ResetReadIdx(void);

void GoToNextSample(void)
{
    cnt++;
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
    result = Fake_Flags[cnt];
    return result;
}

uint8_t ReadDrMock(void)
{
    uint8_t result;
    result = Fake_Message[cnt];
    return result;
}

void ResetReadIdx(void)
{
    cnt = 0;
}

void ResetBuffer(uint8_t buffer[], int len)
{
    for(int i=0; i<len; i++){
        buffer[i] = 0;
    }
}
