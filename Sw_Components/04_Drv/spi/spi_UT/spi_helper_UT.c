#include "spi_helper_UT.h"
#include <stdint.h>
#include <stddef.h>
#include "spi.h"

#define FAKE_MESSAGE_MAX_SIZE 100U

static uint8_t Fake_Message[SPI_HELPER_DRV_MAX][FAKE_MESSAGE_MAX_SIZE];
static bool Fake_Flags[SPI_HELPER_DRV_MAX][FAKE_MESSAGE_MAX_SIZE];
static int sample_cnt[SPI_HELPER_DRV_MAX] = {0};
static bool SpiRxCompleteStatuses[SPI_HELPER_DRV_MAX] = {false};

bool SpiHelper_ReadRxNeFlagMock(const SPI_TypeDef* driver)
{
    bool result;
    int cnt;

    if(SPI1 == driver){
        cnt = sample_cnt[SPI_HELPER_DRV_1];
        result = Fake_Flags[SPI_HELPER_DRV_1][cnt];
    }
    else if(SPI2 == driver){
        cnt = sample_cnt[SPI_HELPER_DRV_2];
        result = Fake_Flags[SPI_HELPER_DRV_2][cnt];
    }
    else if(SPI3 == driver){
        cnt = sample_cnt[SPI_HELPER_DRV_3];
        result = Fake_Flags[SPI_HELPER_DRV_3][cnt];
    }
    else{

    }
    return result;
}

uint8_t SpiHelper_ReadDrMock(const SPI_TypeDef* driver)
{
    uint8_t result;
    int cnt;

    if(SPI1 == driver){
        cnt = sample_cnt[SPI_HELPER_DRV_1];
        result = Fake_Message[SPI_HELPER_DRV_1][cnt];
    }
    else if(SPI2 == driver){
        cnt = sample_cnt[SPI_HELPER_DRV_2];
        result = Fake_Message[SPI_HELPER_DRV_2][cnt];
    }
    else if(SPI3 == driver){
        cnt = sample_cnt[SPI_HELPER_DRV_3];
        result = Fake_Message[SPI_HELPER_DRV_3][cnt];
    }
    else{

    }
    return result;
}

void SpiHelper_GoToNextSample(const SPI_TypeDef* driver)
{
    if(SPI1 == driver){
        (sample_cnt[SPI_HELPER_DRV_1]) ++;
    }
    else if(SPI2 == driver){
        (sample_cnt[SPI_HELPER_DRV_2]) ++;
    }
    else if(SPI3 == driver){
        (sample_cnt[SPI_HELPER_DRV_3]) ++;
    }
    else{

    }
}

void SpiHelper_SetTestPreCondMess(const SpiHelper_Driver_T driver, uint8_t mess[], int len)
{
    for (size_t i = 0; i < len; i++)
    {
        Fake_Message[driver][i] = mess[i];
    }
}
void SpiHelper_SetTestPreCondFlags(const SpiHelper_Driver_T driver, bool flags[], int len)
{
    for (size_t i = 0; i < len; i++)
    {
        Fake_Flags[driver][i] = flags[i];
    }
}

void SpiHelper_ResetReadIdx(void)
{
    for(int i=0; i<SPI_HELPER_DRV_MAX; i++){
        sample_cnt[i] = 0;
    }
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

void Spi3_RxCompleteCbk(void)
{
    SpiRxCompleteStatuses[SPI_HELPER_DRV_3] = true;
}

bool SpiHelper_CheckIf_RxCompleteCbkCalled(SpiHelper_Driver_T driver)
{
    return SpiRxCompleteStatuses[driver];
}

void SpiHelper_Clear_RxCompleteCbkStatuses(void)
{
    SpiRxCompleteStatuses[SPI_HELPER_DRV_1] = false;
    SpiRxCompleteStatuses[SPI_HELPER_DRV_2] = false;
    SpiRxCompleteStatuses[SPI_HELPER_DRV_3] = false;
}

void SpiHelper_SetupTest(SpiHelper_Driver_T driver, uint8_t* injected_message, bool* injected_flags, int len)
{
    SpiHelper_SetTestPreCondMess(driver, injected_message, len);
    SpiHelper_SetTestPreCondFlags(driver, injected_flags, len);
}

void SpiHelper_CallHandlerNumberOfTimes(void (*handler)(void), uint32_t number)
{
    for(uint32_t cnt=0; cnt<number; cnt++){
        handler();
    }

}