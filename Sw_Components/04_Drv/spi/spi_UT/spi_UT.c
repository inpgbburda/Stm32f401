#include <unity.h>
#include "spi.h"
#include "spi_helper_UT.h"

#define EXPECTED_MESS_LEN 4U

static uint8_t Destination_Buffer[] = {0,0,0,0};

void setUp(void)
{
    /* Initialize variables or objects before each test */
}

void tearDown(void)
{
    SpiHelper_ResetBuffer(Destination_Buffer, EXPECTED_MESS_LEN);
    SpiHelper_ResetReadIdx();
}

const uint32_t timeout = 20;
const uint32_t exp_len = 4;

void spi_ReceivesChunkOfBytes(void)
{
    uint8_t Expected_Message[] = {0x11, 0x22, 0x33, 0x44};

    uint8_t Injected_Message[] = { 0x11, 0x22, 0x33, 0x44};
    bool InjectedFlags[] =       {true, true, true, true};

    SpiHelper_SetupTest(Injected_Message, InjectedFlags, sizeof(Injected_Message));

    TEST_ASSERT_EQUAL(E_OK, SpiReadSynch(SPI2, Destination_Buffer, exp_len, timeout));
    TEST_ASSERT_EQUAL_HEX8_ARRAY(Expected_Message, Destination_Buffer, exp_len);
}

void spi_ReceivesChunkOfBytesWithFewSpaces(void)
{
    uint8_t Expected_Message[] = {0x11, 0x22, 0x33, 0x44};

    uint8_t Injected_Message[] = {0x11, 0x22, 0x00,  0x00,  0x33, 0x00,  0x44, 0x00 };
    bool InjectedFlags[] =       {true, true, false, false, true, false, true, false};

    SpiHelper_SetupTest(Injected_Message, InjectedFlags, sizeof(Injected_Message));

    TEST_ASSERT_EQUAL(E_OK, SpiReadSynch(SPI2, Destination_Buffer, exp_len, timeout));
    TEST_ASSERT_EQUAL_HEX8_ARRAY(Expected_Message, Destination_Buffer, exp_len);
}

void spi_ReceivesTwoChunksOfBytesWhenOnlyFirstOneIsExpected(void)
{
    uint8_t Expected_Message[] = {0x11, 0x22, 0x33, 0x44};

    uint8_t Injected_Message[] = {0x11, 0x22, 0x33, 0x44, 0x00,  0x55, 0x66, 0x77, 0x88};
    bool InjectedFlags[] =       {true, true, true, true, false, true, true, true, true};

    SpiHelper_SetupTest(Injected_Message, InjectedFlags, sizeof(Injected_Message));

    TEST_ASSERT_EQUAL(E_OK, SpiReadSynch(SPI2, Destination_Buffer, exp_len, timeout));
    TEST_ASSERT_EQUAL_HEX8_ARRAY(Expected_Message, Destination_Buffer, exp_len);
}

void spi_ReceivesChunkOfBytesWithOneByteMore(void)
{
    uint8_t Expected_Message[] = {0x11, 0x22, 0x33, 0x44};

    uint8_t Injected_Message[] = {0x11, 0x22, 0x33, 0x44, 0x55, 0x00,  0x66, 0x77, 0x88};
    bool InjectedFlags[] =       {true, true, true, true, true, false, true, true, true};

    SpiHelper_SetupTest(Injected_Message, InjectedFlags, sizeof(Injected_Message));

    TEST_ASSERT_EQUAL(E_OK, SpiReadSynch(SPI2, Destination_Buffer, exp_len, timeout));
    TEST_ASSERT_EQUAL_HEX8_ARRAY(Expected_Message, Destination_Buffer, exp_len);
}

void spi_DoesntReceiveInTimeout(void)
{
    uint32_t too_short_timeout = 2U;

    uint8_t Injected_Message[] = { 0x11, 0x22, 0x33, 0x44};
    bool InjectedFlags[] =       {true, true, true, true};

    SpiHelper_SetupTest(Injected_Message, InjectedFlags, sizeof(Injected_Message));

    TEST_ASSERT_EQUAL(E_NOT_OK, SpiReadSynch(SPI2, Destination_Buffer, exp_len, too_short_timeout));
}

void spi_ReturnsFailureBeingCalledWithInvalidBuffer(void)
{
    uint8_t* Inv_Dest_Buff = NULL;

    uint8_t Injected_Message[] = { 0x11, 0x22, 0x33, 0x44};
    bool InjectedFlags[] =       {true, true, true, true};

    SpiHelper_SetupTest(Injected_Message, InjectedFlags, sizeof(Injected_Message));

    TEST_ASSERT_EQUAL(E_NOT_OK, SpiReadSynch(SPI2, Inv_Dest_Buff, exp_len, timeout));
}

void spi_ReturnsFailureBeingCalledWithInvalidPeripheral(void)
{
    const SPI_TypeDef* inv_spi_hdl = NULL;

    uint8_t Injected_Message[] = { 0x11, 0x22, 0x33, 0x44};
    bool InjectedFlags[] =       {true, true, true, true};

    SpiHelper_SetupTest(Injected_Message, InjectedFlags, sizeof(Injected_Message));

    TEST_ASSERT_EQUAL(E_NOT_OK, SpiReadSynch(inv_spi_hdl, Destination_Buffer, exp_len, timeout));
}


/* Interrupt-mode receiving tests */

void spi_It_ReceivesChunkOfBytes(void)
{
    uint8_t Expected_Message[] = {0xDE, 0xAD, 0xBE, 0xEF};

    uint8_t Injected_Message[] = {0xDE, 0xAD, 0xBE, 0xEF};
    bool InjectedFlags[] =       {true, true, true, true};

    SpiHelper_SetupTest(Injected_Message, InjectedFlags, sizeof(Injected_Message));

    SpiReadIt(SPI2, Destination_Buffer, exp_len);
    for(int i=0; i<4; i++){
        SPI2_IRQHandler();
    }

    TEST_ASSERT_EQUAL(true, SpiHelper_CheckIf_Spi2_RxCompleteCbkCalled());
    TEST_ASSERT_EQUAL_HEX8_ARRAY(Expected_Message, Destination_Buffer, exp_len);

    SpiHelper_Clear_Spi2_RxCompleteCbkStatus();
}

void spi_It_ReceivesMoreBytesThanRequested(void)
{
    uint8_t Expected_Message[] = {0xDE, 0xAD, 0xBE, 0xEF};

    uint8_t Injected_Message[] = {0xDE, 0xAD, 0xBE, 0xEF, 0x11, 0x22, 0x33, 0x44};
    bool InjectedFlags[] =       {true, true, true, true, true, true, true, true};

    SpiHelper_SetupTest(Injected_Message, InjectedFlags, sizeof(Injected_Message));
    
    SpiReadIt(SPI2, Destination_Buffer, exp_len);
    for(int i=0; i<8; i++){
        SPI2_IRQHandler();
    }
    
    TEST_ASSERT_EQUAL(true, SpiHelper_CheckIf_Spi2_RxCompleteCbkCalled());
    TEST_ASSERT_EQUAL_HEX8_ARRAY(Expected_Message, Destination_Buffer, exp_len);
    
    SpiHelper_Clear_Spi2_RxCompleteCbkStatus();
}

void spi_It_FailsToReceiveWholeMessage(void)
{
    uint8_t Expected_Message[] = {0xDE, 0xAD, 0xBE, 0xEF};

    uint8_t Injected_Message[] = {0xDE, 0xAD, 0xBE, 0xEF};
    bool InjectedFlags[] =       {true, true, true, true};

    SpiHelper_SetupTest(Injected_Message, InjectedFlags, sizeof(Injected_Message));

    SpiReadIt(SPI2, Destination_Buffer, exp_len);
    for(int i=0; i<2; i++){
        SPI2_IRQHandler();
    }

    TEST_ASSERT_EQUAL(false, SpiHelper_CheckIf_Spi2_RxCompleteCbkCalled());

    SpiHelper_Clear_Spi2_RxCompleteCbkStatus();
}
int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(spi_ReceivesChunkOfBytes);
    RUN_TEST(spi_ReceivesChunkOfBytesWithFewSpaces);
    RUN_TEST(spi_ReceivesTwoChunksOfBytesWhenOnlyFirstOneIsExpected);
    RUN_TEST(spi_ReceivesChunkOfBytesWithOneByteMore);
    RUN_TEST(spi_DoesntReceiveInTimeout);
    RUN_TEST(spi_ReturnsFailureBeingCalledWithInvalidBuffer);
    RUN_TEST(spi_ReturnsFailureBeingCalledWithInvalidPeripheral);
    
    RUN_TEST(spi_It_ReceivesChunkOfBytes);
    RUN_TEST(spi_It_ReceivesMoreBytesThanRequested);
    RUN_TEST(spi_It_FailsToReceiveWholeMessage);

    return UNITY_END();
}