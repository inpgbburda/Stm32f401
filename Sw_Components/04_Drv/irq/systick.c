/**
 * @file systick.c
 * @brief Functions for initializing and handling the Systick timer.
 *
 * This file contains the implementation of the Systick timer initialization and interrupt handler.
 * The Systick timer is used to generate interrupts at regular intervals, such as for implementing a millisecond timer.
 *
 */

#include "systick.h"
#include "stm32f401xc.h"
#include "core_cm4.h"

#define ONE_MS_PRESCALER 1000U

/**
 * @brief Initializes the Systick timer for millisecond resolution.
 *
 * This function configures the Systick timer to generate an interrupt every millisecond.
 * It uses the SystemCoreClock divided by the prescaler value (ONE_MS_PRESCALER) to set the reload value.
 *
 * @return None
 */
void SystickInit(void)
{
    SysTick_Config(SystemCoreClock / ONE_MS_PRESCALER);
}

/**
 * @brief Systick interrupt handler.
 *
 * This function is called whenever the Systick timer generates an interrupt.
 * Intended to be used for implementing an operating system (OS) handler.
 *
 * @return None
 */
void SysTick_Handler(void)
{
    /* OS handler */
}