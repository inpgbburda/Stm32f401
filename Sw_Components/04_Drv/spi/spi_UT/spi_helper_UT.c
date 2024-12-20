#include "spi_helper_UT.h"
#include <stdint.h>
#include <stddef.h>
#include "spi.h"

/* Maximum size that fake sequences can be simulated */
#define FAKE_MESSAGE_MAX_SIZE 100U

static uint8_t Fake_Message[SPI_INSTANCE_COUNT_MAX][FAKE_MESSAGE_MAX_SIZE];
static bool Fake_Flags[SPI_INSTANCE_COUNT_MAX][FAKE_MESSAGE_MAX_SIZE];
static int Sample_Cnts[SPI_INSTANCE_COUNT_MAX] = {0};
static bool SpiRxCompleteStatuses[SPI_INSTANCE_COUNT_MAX] = {false};

bool SpiHelper_ReadRxNeFlagMock(const SPI_TypeDef* driver)
{
    bool result;
    int cnt;

    if(SPI1 == driver){
        cnt = Sample_Cnts[SPI_INSTANCE_1];
        result = Fake_Flags[SPI_INSTANCE_1][cnt];
    }
    else if(SPI2 == driver){
        cnt = Sample_Cnts[SPI_INSTANCE_2];
        result = Fake_Flags[SPI_INSTANCE_2][cnt];
    }
    else if(SPI3 == driver){
        cnt = Sample_Cnts[SPI_INSTANCE_3];
        result = Fake_Flags[SPI_INSTANCE_3][cnt];
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
        cnt = Sample_Cnts[SPI_INSTANCE_1];
        result = Fake_Message[SPI_INSTANCE_1][cnt];
    }
    else if(SPI2 == driver){
        cnt = Sample_Cnts[SPI_INSTANCE_2];
        result = Fake_Message[SPI_INSTANCE_2][cnt];
    }
    else if(SPI3 == driver){
        cnt = Sample_Cnts[SPI_INSTANCE_3];
        result = Fake_Message[SPI_INSTANCE_3][cnt];
    }
    else{

    }
    return result;
}

void SpiHelper_GoToNextSample(const SPI_TypeDef* driver)
{
    if(SPI1 == driver){
        (Sample_Cnts[SPI_INSTANCE_1]) ++;
    }
    else if(SPI2 == driver){
        (Sample_Cnts[SPI_INSTANCE_2]) ++;
    }
    else if(SPI3 == driver){
        (Sample_Cnts[SPI_INSTANCE_3]) ++;
    }
    else{

    }
}

void SpiHelper_SetTestPreCondMess(const Spi_Instance_Id_T driver, uint8_t mess[], int len)
{
    for (size_t i = 0; i < len; i++)
    {
        Fake_Message[driver][i] = mess[i];
    }
}
void SpiHelper_SetTestPreCondFlags(const Spi_Instance_Id_T driver, bool flags[], int len)
{
    for (size_t i = 0; i < len; i++)
    {
        Fake_Flags[driver][i] = flags[i];
    }
}

void SpiHelper_ResetReadIdx(void)
{
    for(int i=0; i<SPI_INSTANCE_COUNT_MAX; i++){
        Sample_Cnts[i] = 0;
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
    SpiRxCompleteStatuses[SPI_INSTANCE_1] = true;
}

void Spi2_RxCompleteCbk(void)
{
    SpiRxCompleteStatuses[SPI_INSTANCE_2] = true;
}

void Spi3_RxCompleteCbk(void)
{
    SpiRxCompleteStatuses[SPI_INSTANCE_3] = true;
}

bool SpiHelper_CheckIf_RxCompleteCbkCalled(Spi_Instance_Id_T driver)
{
    return SpiRxCompleteStatuses[driver];
}

void SpiHelper_Clear_RxCompleteCbkStatuses(void)
{
    for(int i=0; i<SPI_INSTANCE_COUNT_MAX; i++){
        SpiRxCompleteStatuses[i] = false;
    }
}

void SpiHelper_SetupTest(Spi_Instance_Id_T driver, uint8_t* injected_message, bool* injected_flags, int len)
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