#include "systick.h"
#include "stm32f401xc.h"
#include "core_cm4.h"

void SystickInit(void)
{
    SysTick_Config(100);
}

void SysTick_Handler(void)
{
    static int a = 0;
    a++;
}