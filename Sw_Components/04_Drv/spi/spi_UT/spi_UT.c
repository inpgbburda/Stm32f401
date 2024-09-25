#include <unity.h>
#include "spi.h"
#include "spi_helper_UT.h"

#define EXPECTED_MESS_LEN 4U

uint8_t Destination_Buffer[] = {0,0,0,0};

void setUp(void)
{
    /* Initialize variables or objects before each test */
}

void tearDown(void)
{
    ResetBuffer(Destination_Buffer, EXPECTED_MESS_LEN);
    ResetReadIdx();
}

const uint32_t timeout = 20;
const uint32_t exp_len = 4;

void spi_ReceivesChunkOfBytes(void)
{
    const uint32_t arbitrary_len = 4;

    uint8_t Expected_Message[] = {0x11, 0x22, 0x33, 0x44};
    uint8_t Injected_Message[] = { 0x11, 0x22, 0x33, 0x44};
    bool InjectedFlags[] =       {true, true, true, true};

    SetTestPreConditionsMessage(Injected_Message, sizeof(Injected_Message));
    SetTestConditionsFlags(InjectedFlags, sizeof(InjectedFlags));

    TEST_ASSERT_EQUAL(SpiReadSynch(SPI2, Destination_Buffer, exp_len, timeout), RET_OK);
    TEST_ASSERT_EQUAL_HEX8_ARRAY(Expected_Message, Destination_Buffer, exp_len);
}

void spi_ReceivesChunkOfBytesWithFewSpaces(void)
{
    uint8_t Expected_Message[] = {0x11, 0x22, 0x33, 0x44};

    uint8_t Injected_Message[] = {0x11, 0x22, 0x00,  0x00,  0x33, 0x00,  0x44, 0x00 };
    bool InjectedFlags[] =       {true, true, false, false, true, false, true, false};

    SetTestPreConditionsMessage(Injected_Message, sizeof(Injected_Message));
    SetTestConditionsFlags(InjectedFlags, sizeof(InjectedFlags));

    TEST_ASSERT_EQUAL(SpiReadSynch(SPI2, Destination_Buffer, exp_len, timeout), RET_OK);
    TEST_ASSERT_EQUAL_HEX8_ARRAY(Expected_Message, Destination_Buffer, exp_len);
}

void spi_ReceivesTwoChunksOfBytesWhenOnlyFirstOneIsExpected(void)
{
    uint8_t Expected_Message[] = {0x11, 0x22, 0x33, 0x44};

    uint8_t Injected_Message[] = {0x11, 0x22, 0x33, 0x44, 0x00,  0x55, 0x66, 0x77, 0x88};
    bool InjectedFlags[] =       {true, true, true, true, false, true, true, true, true};

    SetTestPreConditionsMessage(Injected_Message, sizeof(Injected_Message));
    SetTestConditionsFlags(InjectedFlags, sizeof(InjectedFlags));

    TEST_ASSERT_EQUAL(SpiReadSynch(SPI2, Destination_Buffer, exp_len, timeout), RET_OK);
    TEST_ASSERT_EQUAL_HEX8_ARRAY(Expected_Message, Destination_Buffer, exp_len);

}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(spi_ReceivesChunkOfBytes);
    RUN_TEST(spi_ReceivesChunkOfBytesWithFewSpaces);
    RUN_TEST(spi_ReceivesTwoChunksOfBytesWhenOnlyFirstOneIsExpected);
    return UNITY_END();
}