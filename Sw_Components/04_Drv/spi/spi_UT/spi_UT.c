#include <unity.h>
#include "spi.h"

uint8_t Fake_Message[] = {0x11, 0x22, 0x33, 0x44};
bool Fake_Flags[] = {true, true, true, true};
void spi_ReceivesChunkOfBytes(void)
{
    const uint32_t arbitrary_len = 4;
    const uint32_t arbitrary_timeout = 4;

    uint8_t Destination_Buffer[] = {0, 0, 0, 0};
    uint8_t Expected_Message[] = {0x11, 0x22, 0x33, 0x44};

    TEST_ASSERT_EQUAL(SpiReadSynch(SPI2, Destination_Buffer, arbitrary_len, 4), RET_OK);
    TEST_ASSERT_EQUAL_HEX8_ARRAY(Destination_Buffer, Expected_Message, arbitrary_len);
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(spi_ReceivesChunkOfBytes);

    return UNITY_END();
}
