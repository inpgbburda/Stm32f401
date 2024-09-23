#include "spi_helper_UT.h"
#include <stdint.h>
#include <stddef.h>

static uint8_t Fake_Message[100];
static bool Fake_Flags[100];
static int cnt = 0;

void ResetMocks(void);

void SetTestPreConditionsMessage(uint8_t mess[], int len)
{
    for (size_t i = 0; i < len; i++)
    {
        /* code */
        Fake_Message[i] = mess[i];
    }
}
void SetTestConditionsFlags(bool flags[], int len)
{
    for (size_t i = 0; i < len; i++)
    {
        /* code */
        Fake_Flags[i] = flags[i];
    }
}

bool ReadRxNeFlagMock(void)
{
    cnt++;
    bool result;
    result = Fake_Flags[cnt-1];
    return result;
}

uint8_t ReadDrMock(void)
{
    uint8_t result;
    result = Fake_Message[cnt-1];
    return result;
}

void ResetMocks(void)
{
    cnt = 0;
}