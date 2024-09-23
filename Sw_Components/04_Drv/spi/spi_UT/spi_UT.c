#include <unity.h>
#include "spi.h"
#include "spi_helper_UT.h"

// Define setUp and tearDown if needed
void setUp(void)
{
    // Initialize variables or objects before each test
    // For example, setting up default values or mocking initial conditions
}

void tearDown(void)
{
    ResetMocks();
}

void spi_ReceivesChunkOfBytes(void)
{
    const uint32_t arbitrary_len = 4;
    const uint32_t arbitrary_timeout = 4;

    uint8_t Destination_Buffer[] = {0, 0, 0, 0};
    uint8_t Injected_Message[] = { 0x11, 0x22, 0x33, 0x44};
    bool InjectedFlags[] = {true, true, true, true};

    SetTestPreConditionsMessage(Injected_Message, 4);
    SetTestConditionsFlags(InjectedFlags,4);

    TEST_ASSERT_EQUAL(SpiReadSynch(SPI2, Destination_Buffer, arbitrary_len, 4), RET_OK);
    TEST_ASSERT_EQUAL_HEX8_ARRAY(Injected_Message, Destination_Buffer, arbitrary_len);
}

void spi_ReceivesChunkOfBytesWithFewSpaces(void)
{
    uint8_t Destination_Buffer[] = {0, 0, 0, 0};

    uint8_t Expected_Message[] = {0x11, 0x22, 0x33, 0x44};

    uint8_t Injected_Message[] = {0x11, 0x22, 0x00,  0x00,  0x33, 0x00,  0x44, 0x00 };
    bool InjectedFlags[] =       {true, true, false, false, true, false, true, false};

    SetTestPreConditionsMessage(Injected_Message, 8);
    SetTestConditionsFlags(InjectedFlags, 8);

    TEST_ASSERT_EQUAL(SpiReadSynch(SPI2, Destination_Buffer, 4, 10), RET_OK);
    TEST_ASSERT_EQUAL_HEX8_ARRAY(Expected_Message, Destination_Buffer, 4);
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(spi_ReceivesChunkOfBytes);
    RUN_TEST(spi_ReceivesChunkOfBytesWithFewSpaces);
    return UNITY_END();
}