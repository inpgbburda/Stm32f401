#include <unity.h>
#include "spi.h"
#include "spi_helper_UT.h"

#define REG_FIELD_NOT_UT_RELEVANT 0U

#define EXPECTED_MESS_LEN 4U
#define SPI1_INT_PRIO 1U
#define SPI2_INT_PRIO 2U
#define SPI3_INT_PRIO 3U

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

static Spi_Storage_T Spi_Storage_1;
static Spi_Storage_T Spi_Storage_2;
static Spi_Storage_T Spi_Storage_3;

const Spi_Cfg_T Spi1_Config =
{
    SPI1,
    SPI_MODE_SYNCHRONOUS,
    0U,
    NULL,

    REG_FIELD_NOT_UT_RELEVANT,
    REG_FIELD_NOT_UT_RELEVANT,
    REG_FIELD_NOT_UT_RELEVANT,
    REG_FIELD_NOT_UT_RELEVANT,
    REG_FIELD_NOT_UT_RELEVANT,
    REG_FIELD_NOT_UT_RELEVANT,
    REG_FIELD_NOT_UT_RELEVANT,
    REG_FIELD_NOT_UT_RELEVANT,
};

const Spi_Cfg_T Spi2_Config =
{
    SPI2,
    SPI_MODE_SYNCHRONOUS,
    0U,
    NULL,

    REG_FIELD_NOT_UT_RELEVANT,
    REG_FIELD_NOT_UT_RELEVANT,
    REG_FIELD_NOT_UT_RELEVANT,
    REG_FIELD_NOT_UT_RELEVANT,
    REG_FIELD_NOT_UT_RELEVANT,
    REG_FIELD_NOT_UT_RELEVANT,
    REG_FIELD_NOT_UT_RELEVANT,
    REG_FIELD_NOT_UT_RELEVANT,
};

const Spi_Cfg_T Spi3_Config =
{
    SPI3,
    SPI_MODE_SYNCHRONOUS,
    0U,
    NULL,

    REG_FIELD_NOT_UT_RELEVANT,
    REG_FIELD_NOT_UT_RELEVANT,
    REG_FIELD_NOT_UT_RELEVANT,
    REG_FIELD_NOT_UT_RELEVANT,
    REG_FIELD_NOT_UT_RELEVANT,
    REG_FIELD_NOT_UT_RELEVANT,
    REG_FIELD_NOT_UT_RELEVANT,
    REG_FIELD_NOT_UT_RELEVANT,
};

const Spi_Cfg_T Spi_With_Config_No_Instance =
{
    NULL,
    SPI_MODE_SYNCHRONOUS,
    0U,
    NULL,

    REG_FIELD_NOT_UT_RELEVANT,
    REG_FIELD_NOT_UT_RELEVANT,
    REG_FIELD_NOT_UT_RELEVANT,
    REG_FIELD_NOT_UT_RELEVANT,
    REG_FIELD_NOT_UT_RELEVANT,
    REG_FIELD_NOT_UT_RELEVANT,
    REG_FIELD_NOT_UT_RELEVANT,
    REG_FIELD_NOT_UT_RELEVANT,
};

void spi_ReceivesChunkOfBytes(void)
{
    uint8_t Expected_Message[] = {0x11, 0x22, 0x33, 0x44};

    uint8_t Injected_Message[] = { 0x11, 0x22, 0x33, 0x44};
    bool InjectedFlags[] =       {true, true, true, true};

    SpiHelper_SetupTest(SPI_INSTANCE_2, Injected_Message, InjectedFlags, sizeof(Injected_Message));
    SpiInit(&Spi_Storage_2, &Spi2_Config);

    TEST_ASSERT_EQUAL(E_OK, SpiReadSynch(&Spi_Storage_2, Destination_Buffer, exp_len, timeout));
    TEST_ASSERT_EQUAL_HEX8_ARRAY(Expected_Message, Destination_Buffer, exp_len);
}

void spi_ReceivesChunkOfBytesWithFewSpaces(void)
{
    uint8_t Expected_Message[] = {0x11, 0x22, 0x33, 0x44};

    uint8_t Injected_Message[] = {0x11, 0x22, 0x00,  0x00,  0x33, 0x00,  0x44, 0x00 };
    bool InjectedFlags[] =       {true, true, false, false, true, false, true, false};

    SpiHelper_SetupTest(SPI_INSTANCE_2, Injected_Message, InjectedFlags, sizeof(Injected_Message));
    SpiInit(&Spi_Storage_2, &Spi2_Config);

    TEST_ASSERT_EQUAL(E_OK, SpiReadSynch(&Spi_Storage_2, Destination_Buffer, exp_len, timeout));
    TEST_ASSERT_EQUAL_HEX8_ARRAY(Expected_Message, Destination_Buffer, exp_len);
}

void spi_ReceivesTwoChunksOfBytesWhenOnlyFirstOneIsExpected(void)
{
    uint8_t Expected_Message[] = {0x11, 0x22, 0x33, 0x44};

    uint8_t Injected_Message[] = {0x11, 0x22, 0x33, 0x44, 0x00,  0x55, 0x66, 0x77, 0x88};
    bool InjectedFlags[] =       {true, true, true, true, false, true, true, true, true};

    SpiHelper_SetupTest(SPI_INSTANCE_2, Injected_Message, InjectedFlags, sizeof(Injected_Message));
    SpiInit(&Spi_Storage_2, &Spi2_Config);

    TEST_ASSERT_EQUAL(E_OK, SpiReadSynch(&Spi_Storage_2, Destination_Buffer, exp_len, timeout));
    TEST_ASSERT_EQUAL_HEX8_ARRAY(Expected_Message, Destination_Buffer, exp_len);
}

void spi_ReceivesChunkOfBytesWithOneByteMore(void)
{
    uint8_t Expected_Message[] = {0x11, 0x22, 0x33, 0x44};

    uint8_t Injected_Message[] = {0x11, 0x22, 0x33, 0x44, 0x55, 0x00,  0x66, 0x77, 0x88};
    bool InjectedFlags[] =       {true, true, true, true, true, false, true, true, true};

    SpiHelper_SetupTest(SPI_INSTANCE_2, Injected_Message, InjectedFlags, sizeof(Injected_Message));
    SpiInit(&Spi_Storage_2, &Spi2_Config);

    TEST_ASSERT_EQUAL(E_OK, SpiReadSynch(&Spi_Storage_2, Destination_Buffer, exp_len, timeout));
    TEST_ASSERT_EQUAL_HEX8_ARRAY(Expected_Message, Destination_Buffer, exp_len);
}

void spi_DoesntReceiveInTimeout(void)
{
    uint32_t too_short_timeout = 2U;

    uint8_t Injected_Message[] = { 0x11, 0x22, 0x33, 0x44};
    bool InjectedFlags[] =       {true, true, true, true};

    SpiHelper_SetupTest(SPI_INSTANCE_2, Injected_Message, InjectedFlags, sizeof(Injected_Message));
    SpiInit(&Spi_Storage_2, &Spi2_Config);

    TEST_ASSERT_EQUAL(E_NOT_OK, SpiReadSynch(&Spi_Storage_2, Destination_Buffer, exp_len, too_short_timeout));
}

void spi_ReturnsFailureBeingCalledWithInvalidBuffer(void)
{
    uint8_t* Inv_Dest_Buff = NULL;

    uint8_t Injected_Message[] = { 0x11, 0x22, 0x33, 0x44};
    bool InjectedFlags[] =       {true, true, true, true};

    SpiHelper_SetupTest(SPI_INSTANCE_2, Injected_Message, InjectedFlags, sizeof(Injected_Message));
    SpiInit(&Spi_Storage_2, &Spi2_Config);

    TEST_ASSERT_EQUAL(E_NOT_OK, SpiReadSynch(&Spi_Storage_2, Inv_Dest_Buff, exp_len, timeout));
}

void spi_ReturnsFailureBeingCalledWithInvalidPeripheral(void)
{
    uint8_t Injected_Message[] = { 0x11, 0x22, 0x33, 0x44};
    bool InjectedFlags[] =       {true, true, true, true};

    SpiHelper_SetupTest(SPI_INSTANCE_2, Injected_Message, InjectedFlags, sizeof(Injected_Message));
    SpiInit(&Spi_Storage_2, &Spi_With_Config_No_Instance);

    TEST_ASSERT_EQUAL(E_NOT_OK, SpiReadSynch(&Spi_Storage_2, Destination_Buffer, exp_len, timeout));
}


/* Interrupt-mode receiving tests */
const int Irq_Too_Few_Calls = 2U;

static Spi_Storage_T Spi_It_Storage_1;
static Spi_Storage_T Spi_It_Storage_2;
static Spi_Storage_T Spi_It_Storage_3;

const Spi_Cfg_T Spi1_It_Config =
{
    SPI1,
    SPI_MODE_INTERRUPT,
    SPI1_INT_PRIO,
    Spi1_RxCompleteCbk,

    REG_FIELD_NOT_UT_RELEVANT,
    REG_FIELD_NOT_UT_RELEVANT,
    REG_FIELD_NOT_UT_RELEVANT,
    REG_FIELD_NOT_UT_RELEVANT,
    REG_FIELD_NOT_UT_RELEVANT,
    REG_FIELD_NOT_UT_RELEVANT,
    REG_FIELD_NOT_UT_RELEVANT,
    REG_FIELD_NOT_UT_RELEVANT,
};

const Spi_Cfg_T Spi2_It_Config =
{
    SPI2,
    SPI_MODE_INTERRUPT,
    SPI2_INT_PRIO,
    &Spi2_RxCompleteCbk,

    REG_FIELD_NOT_UT_RELEVANT,
    REG_FIELD_NOT_UT_RELEVANT,
    REG_FIELD_NOT_UT_RELEVANT,
    REG_FIELD_NOT_UT_RELEVANT,
    REG_FIELD_NOT_UT_RELEVANT,
    REG_FIELD_NOT_UT_RELEVANT,
    REG_FIELD_NOT_UT_RELEVANT,
    REG_FIELD_NOT_UT_RELEVANT,
};

const Spi_Cfg_T Spi3_It_Config =
{
    SPI3,
    SPI_MODE_INTERRUPT,
    SPI3_INT_PRIO,
    &Spi3_RxCompleteCbk,

    REG_FIELD_NOT_UT_RELEVANT,
    REG_FIELD_NOT_UT_RELEVANT,
    REG_FIELD_NOT_UT_RELEVANT,
    REG_FIELD_NOT_UT_RELEVANT,
    REG_FIELD_NOT_UT_RELEVANT,
    REG_FIELD_NOT_UT_RELEVANT,
    REG_FIELD_NOT_UT_RELEVANT,
    REG_FIELD_NOT_UT_RELEVANT,
};

void spi_It_ReceivesChunkOfBytes(void)
{
    uint8_t Expected_Message[] = {0xDE, 0xAD, 0xBE, 0xEF};

    uint8_t Injected_Message[] = {0xDE, 0xAD, 0xBE, 0xEF};
    bool InjectedFlags[] =       {true, true, true, true};

    SpiHelper_SetupTest(SPI_INSTANCE_2, Injected_Message, InjectedFlags, sizeof(Injected_Message));
    SpiInit(&Spi_It_Storage_2, &Spi2_It_Config);

    SpiReadIt(&Spi_It_Storage_2, Destination_Buffer, exp_len);
    SpiHelper_CallHandlerNumberOfTimes(SPI2_IRQHandler, sizeof(Injected_Message));

    TEST_ASSERT_EQUAL(true, SpiHelper_CheckIf_RxCompleteCbkCalled(SPI_INSTANCE_2));
    TEST_ASSERT_EQUAL_HEX8_ARRAY(Expected_Message, Destination_Buffer, exp_len);

    SpiHelper_Clear_RxCompleteCbkStatuses();
}

void spi_It_ReceivesMoreBytesThanRequested(void)
{
    uint8_t Expected_Message[] = {0xDE, 0xAD, 0xBE, 0xEF};

    uint8_t Injected_Message[] = {0xDE, 0xAD, 0xBE, 0xEF, 0x11, 0x22, 0x33, 0x44};
    bool InjectedFlags[] =       {true, true, true, true, true, true, true, true};

    SpiHelper_SetupTest(SPI_INSTANCE_2, Injected_Message, InjectedFlags, sizeof(Injected_Message));
    SpiInit(&Spi_It_Storage_2, &Spi2_It_Config);

    SpiReadIt(&Spi_It_Storage_2, Destination_Buffer, exp_len);
    SpiHelper_CallHandlerNumberOfTimes(SPI2_IRQHandler, sizeof(Injected_Message));

    TEST_ASSERT_EQUAL(true, SpiHelper_CheckIf_RxCompleteCbkCalled(SPI_INSTANCE_2));
    TEST_ASSERT_EQUAL_HEX8_ARRAY(Expected_Message, Destination_Buffer, exp_len);
    
    SpiHelper_Clear_RxCompleteCbkStatuses();
}

void spi_It_FailsToReceiveWholeMessage(void)
{
    uint8_t Expected_Message[] = {0xDE, 0xAD, 0xBE, 0xEF};

    uint8_t Injected_Message[] = {0xDE, 0xAD, 0xBE, 0xEF};
    bool InjectedFlags[] =       {true, true, true, true};

    SpiHelper_SetupTest(SPI_INSTANCE_2, Injected_Message, InjectedFlags, sizeof(Injected_Message));
    SpiInit(&Spi_It_Storage_2, &Spi2_It_Config);

    SpiReadIt(&Spi_It_Storage_2, Destination_Buffer, exp_len);
    SpiHelper_CallHandlerNumberOfTimes(SPI2_IRQHandler, Irq_Too_Few_Calls);

    TEST_ASSERT_EQUAL(false, SpiHelper_CheckIf_RxCompleteCbkCalled(SPI_INSTANCE_2));

    SpiHelper_Clear_RxCompleteCbkStatuses();
}


void spi_It_ProperlyAssignsCallbacks(void)
{
    /*Check if given interrupt is really calling the expected callback in the end*/
    SpiInit(&Spi_It_Storage_1, &Spi1_It_Config);
    SpiInit(&Spi_It_Storage_2, &Spi2_It_Config);

    SpiReadIt(&Spi_It_Storage_1, Destination_Buffer, exp_len);
    SpiHelper_CallHandlerNumberOfTimes(SPI1_IRQHandler, exp_len);

    TEST_ASSERT_EQUAL(true, SpiHelper_CheckIf_RxCompleteCbkCalled(SPI_INSTANCE_1));
    TEST_ASSERT_EQUAL(false, SpiHelper_CheckIf_RxCompleteCbkCalled(SPI_INSTANCE_2));
    
    SpiHelper_Clear_RxCompleteCbkStatuses();

    SpiReadIt(&Spi_It_Storage_2, Destination_Buffer, exp_len);
    SpiHelper_CallHandlerNumberOfTimes(SPI2_IRQHandler, exp_len);

    TEST_ASSERT_EQUAL(false, SpiHelper_CheckIf_RxCompleteCbkCalled(SPI_INSTANCE_1));
    TEST_ASSERT_EQUAL(true, SpiHelper_CheckIf_RxCompleteCbkCalled(SPI_INSTANCE_2));
    
    SpiHelper_Clear_RxCompleteCbkStatuses();
}

void spi_It_OneDriverCompletesReceivingBeforeSecondDriver(void)
{
    SpiInit(&Spi_It_Storage_1, &Spi1_It_Config);
    SpiInit(&Spi_It_Storage_3, &Spi3_It_Config);
    
    SpiReadIt(&Spi_It_Storage_1, Destination_Buffer, 4);
    SpiReadIt(&Spi_It_Storage_3, Destination_Buffer, 3);

    SpiHelper_CallHandlerNumberOfTimes(SPI1_IRQHandler, 3);
    SpiHelper_CallHandlerNumberOfTimes(SPI3_IRQHandler, 3);

    TEST_ASSERT_EQUAL(false, SpiHelper_CheckIf_RxCompleteCbkCalled(SPI_INSTANCE_1));
    TEST_ASSERT_EQUAL(true, SpiHelper_CheckIf_RxCompleteCbkCalled(SPI_INSTANCE_3));

    SpiHelper_Clear_RxCompleteCbkStatuses();
}

void spi_It_TwoDriversReadsIndependently(void)
{
    uint8_t Injected_Message_1[] = {0xDE, 0xAD, 0xBE, 0xEF};
    uint8_t Expected_Message_1[] = {0xDE, 0xAD, 0xBE, 0xEF};
    uint8_t Injected_Message_2[] = {0x01, 0x02, 0x03, 0x04};
    uint8_t Expected_Message_2[] = {0x01, 0x02, 0x03, 0x04};
    uint8_t Destination_Buffer_1[4] = {0};
    uint8_t Destination_Buffer_2[4] = {0};

    bool InjectedFlags[] = {true, true, true, true};
    SpiHelper_SetupTest(SPI_INSTANCE_1, Injected_Message_1, InjectedFlags, sizeof(Injected_Message_1));
    SpiHelper_SetupTest(SPI_INSTANCE_2, Injected_Message_2, InjectedFlags, sizeof(Injected_Message_2));

    SpiInit(&Spi_It_Storage_1, &Spi1_It_Config);
    SpiInit(&Spi_It_Storage_2, &Spi2_It_Config);
    
    SpiReadIt(&Spi_It_Storage_1, Destination_Buffer_1, 4);
    SpiReadIt(&Spi_It_Storage_2, Destination_Buffer_2, 4);

    for(int a=0; a<4; a++){
        SPI1_IRQHandler();
        SPI2_IRQHandler();
    }

    TEST_ASSERT_EQUAL_HEX8_ARRAY(Expected_Message_1, Destination_Buffer_1, 4);
    TEST_ASSERT_EQUAL_HEX8_ARRAY(Expected_Message_2, Destination_Buffer_2, 4);
}

/*Test when mess len = 0*/


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
    RUN_TEST(spi_It_ProperlyAssignsCallbacks);
    RUN_TEST(spi_It_OneDriverCompletesReceivingBeforeSecondDriver);
    RUN_TEST(spi_It_TwoDriversReadsIndependently);

    return UNITY_END();
}