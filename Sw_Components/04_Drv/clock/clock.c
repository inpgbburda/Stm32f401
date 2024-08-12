/**
 * @file clock.c
 * @brief Functions for initializing and handling the clocks of microcontroller.
 * @date 28/07/2024
 */

#include "clock.h"

void ClockInit(const Clock_Cfg_T* config)
{
    RCC->AHB1ENR |= config->rcc_ahb1;
    RCC->APB1ENR |= config->rcc_apb1;
}