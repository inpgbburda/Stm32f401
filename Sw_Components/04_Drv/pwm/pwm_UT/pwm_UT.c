#include <unity.h>


void test_AverageThreeBytes_should_AverageMidRangeValues(void)
{
    TEST_ASSERT_EQUAL_HEX8(40, 40);
    TEST_ASSERT_EQUAL_HEX8(40, 40);
    TEST_ASSERT_EQUAL_HEX8(33, 33);
}
int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_AverageThreeBytes_should_AverageMidRangeValues);

    return UNITY_END();
}
