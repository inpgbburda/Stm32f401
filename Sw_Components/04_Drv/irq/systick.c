#include "systick.h"
#include "stm32f401xc.h"
#include "core_cm4.h"

#define ONE_MS_PRESCALER 1000U

int SystickInit(void)
{
    int result;
    result = SysTick_Config(SystemCoreClock / ONE_MS_PRESCALER);
    return result;
}

void SysTick_Handler(void)
{
    static int a = 0;
    a++;
}