/**
 * @file clock_cfg.h
 * @brief Content of clock configuration.
 * @date 12/08/2024
 * 
 */

#include "clock_cfg.h"

const Clock_Cfg_T Clock_Config =
{
    /* rcc_ahb1 */
    RCC_AHB1LPENR_GPIOALPEN|   /* Enable clock for GPIO PORT A */
    RCC_AHB1LPENR_GPIOBLPEN,   /* Enable clock for GPIO PORT B */

    /* rcc_apb1*/
    RCC_APB1ENR_TIM2EN|        /* Enable clock for Timer 2 */
    RCC_APB1ENR_SPI2EN         /* Enable clock for SPI2 */
};