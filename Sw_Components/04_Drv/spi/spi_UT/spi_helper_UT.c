#include "spi_helper_UT.h"
#include <stdint.h>
#include <stddef.h>
#include "spi.h"

#define FAKE_MESSAGE_MAX_SIZE 100U
#define MAX_DRIVER_NUMBER 3U

static uint8_t Fake_Message[FAKE_MESSAGE_MAX_SIZE];
static bool Fake_Flags[FAKE_MESSAGE_MAX_SIZE];
static int sample_cnt = 0;
static bool SpiRxCompleteStatuses[SPI_HELPER_DRV_MAX] = {false};

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

void Spi1_RxCompleteCbk(void)
{
    SpiRxCompleteStatuses[SPI_HELPER_DRV_1] = true;
}

void Spi2_RxCompleteCbk(void)
{
    SpiRxCompleteStatuses[SPI_HELPER_DRV_2] = true;
}

bool SpiHelper_CheckIf_RxCompleteCbkCalled(SpiHelper_Driver_T driver)
{
    return SpiRxCompleteStatuses[driver];
}

void SpiHelper_Clear_RxCompleteCbkStatuses(void)
{
    SpiRxCompleteStatuses[SPI_HELPER_DRV_1] = false;
    SpiRxCompleteStatuses[SPI_HELPER_DRV_2] = false;
}

void SpiHelper_SetupTest(uint8_t* injected_message, bool* injected_flags, int len)
{
    SpiHelper_SetTestPreCondMess(injected_message, len);
    SpiHelper_SetTestPreCondFlags(injected_flags, len);
}