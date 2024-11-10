#include <unity.h>
#include "spi.h"
#include "spi_helper_UT.h"

#define REG_FIELD_NOT_UT_RELEVANT 0U

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

const uint32_t timeout = 20U;
const uint32_t exp_len = 4U;
const uint32_t spi1_int_prio = 1U;
const uint32_t spi2_int_prio = 2U;

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

const int Irq_Too_Few_Calls = 2U;

void spi_It_ReceivesChunkOfBytes(void)
{
    uint8_t Expected_Message[] = {0xDE, 0xAD, 0xBE, 0xEF};

    uint8_t Injected_Message[] = {0xDE, 0xAD, 0xBE, 0xEF};
    bool InjectedFlags[] =       {true, true, true, true};

    SpiHelper_SetupTest(Injected_Message, InjectedFlags, sizeof(Injected_Message));

    SpiReadIt(SPI2, Destination_Buffer, exp_len);
    for(int i=0; i<sizeof(Injected_Message); i++){
        SPI2_IRQHandler();
    }

    TEST_ASSERT_EQUAL(true, SpiHelper_CheckIf_RxCompleteCbkCalled(SPI_HELPER_DRV_2));
    TEST_ASSERT_EQUAL_HEX8_ARRAY(Expected_Message, Destination_Buffer, exp_len);

    SpiHelper_Clear_RxCompleteCbkStatuses();
}

void spi_It_ReceivesMoreBytesThanRequested(void)
{
    uint8_t Expected_Message[] = {0xDE, 0xAD, 0xBE, 0xEF};

    uint8_t Injected_Message[] = {0xDE, 0xAD, 0xBE, 0xEF, 0x11, 0x22, 0x33, 0x44};
    bool InjectedFlags[] =       {true, true, true, true, true, true, true, true};

    SpiHelper_SetupTest(Injected_Message, InjectedFlags, sizeof(Injected_Message));
    
    SpiReadIt(SPI2, Destination_Buffer, exp_len);
    for(int i=0; i<sizeof(Injected_Message); i++){
        SPI2_IRQHandler();
    }
    
    TEST_ASSERT_EQUAL(true, SpiHelper_CheckIf_RxCompleteCbkCalled(SPI_HELPER_DRV_2));
    TEST_ASSERT_EQUAL_HEX8_ARRAY(Expected_Message, Destination_Buffer, exp_len);
    
    SpiHelper_Clear_RxCompleteCbkStatuses();
}

void spi_It_FailsToReceiveWholeMessage(void)
{
    uint8_t Expected_Message[] = {0xDE, 0xAD, 0xBE, 0xEF};

    uint8_t Injected_Message[] = {0xDE, 0xAD, 0xBE, 0xEF};
    bool InjectedFlags[] =       {true, true, true, true};

    SpiHelper_SetupTest(Injected_Message, InjectedFlags, sizeof(Injected_Message));

    SpiReadIt(SPI2, Destination_Buffer, exp_len);
    for(int i=0; i<Irq_Too_Few_Calls; i++){
        SPI2_IRQHandler();
    }

    TEST_ASSERT_EQUAL(false, SpiHelper_CheckIf_RxCompleteCbkCalled(SPI_HELPER_DRV_2));

    SpiHelper_Clear_RxCompleteCbkStatuses();
}

const Spi_Cfg_T Spi1_Config =
{
    SPI1,
    SPI_MODE_INTERRUPT,
    spi1_int_prio,
    REG_FIELD_NOT_UT_RELEVANT,
    REG_FIELD_NOT_UT_RELEVANT,
    REG_FIELD_NOT_UT_RELEVANT,
    REG_FIELD_NOT_UT_RELEVANT,
    REG_FIELD_NOT_UT_RELEVANT,
    REG_FIELD_NOT_UT_RELEVANT,
    REG_FIELD_NOT_UT_RELEVANT,
    REG_FIELD_NOT_UT_RELEVANT,
    REG_FIELD_NOT_UT_RELEVANT
};

const Spi_Cfg_T Spi2_Config =
{
    SPI2,
    SPI_MODE_INTERRUPT,
    spi2_int_prio,
    REG_FIELD_NOT_UT_RELEVANT,
    REG_FIELD_NOT_UT_RELEVANT,
    REG_FIELD_NOT_UT_RELEVANT,
    REG_FIELD_NOT_UT_RELEVANT,
    REG_FIELD_NOT_UT_RELEVANT,
    REG_FIELD_NOT_UT_RELEVANT,
    REG_FIELD_NOT_UT_RELEVANT,
    REG_FIELD_NOT_UT_RELEVANT,
    REG_FIELD_NOT_UT_RELEVANT
};

void spi_It_IsProperlyInitialised(void)
{
    /*Check if given interrupt is really using assigned hw and calls the expected callback in the end*/
    SpiInit(&Spi1_Config);
    SpiInit(&Spi2_Config);

    SpiReadIt(SPI1, Destination_Buffer, exp_len);
    for(int i=0; i<exp_len; i++){
        SPI1_IRQHandler();
    }
    TEST_ASSERT_EQUAL(true, SpiHelper_CheckIf_RxCompleteCbkCalled(SPI_HELPER_DRV_1));
    TEST_ASSERT_EQUAL(false, SpiHelper_CheckIf_RxCompleteCbkCalled(SPI_HELPER_DRV_2));
    
    SpiHelper_Clear_RxCompleteCbkStatuses();

    SpiReadIt(SPI2, Destination_Buffer, exp_len);
    for(int i=0; i<exp_len; i++){
        SPI2_IRQHandler();
    }
    TEST_ASSERT_EQUAL(false, SpiHelper_CheckIf_RxCompleteCbkCalled(SPI_HELPER_DRV_1));
    TEST_ASSERT_EQUAL(true, SpiHelper_CheckIf_RxCompleteCbkCalled(SPI_HELPER_DRV_2));
    
    SpiHelper_Clear_RxCompleteCbkStatuses();
}

/* Create test which reads two spi drivers, each for interchangeably message pieces*/

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
    RUN_TEST(spi_It_IsProperlyInitialised);

    return UNITY_END();
}