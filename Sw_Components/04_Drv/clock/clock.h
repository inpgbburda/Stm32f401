/**
 * @file clock.h
 * @brief Functions for initializing and handling the clocks of microcontroller.
 * @date 28/07/2024
 */

#ifndef CLOCK_H
#define CLOCK_H

#include "stdint.h"
#include "stm32f401xc.h"

typedef struct
{
    uint32_t rcc_ahb1;
    uint32_t rcc_apb1;
    uint32_t rcc_apb2;
}
Clock_Cfg_T;

void ClockInit(const Clock_Cfg_T* config);

#endif /* CLOCK_H */