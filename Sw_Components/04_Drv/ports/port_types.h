/**
 * @file port_types.h
 * @brief This header file defines GPIO mode configurations and alternate function settings
 *        for each GPIO pin of the STM32F401 microcontroller. The macros provided in this file 
 *        simplify the configuration of GPIO pins for input, output, alternate function, and analog modes.
 * @date day/month/year
 */

#ifndef PORT_TYPES_H
#define PORT_TYPES_H

/*
|===================================================================================================================================|
    File includes 
|===================================================================================================================================|
*/
#include "stm32f401xc.h"


/*
|===================================================================================================================================|
    Macro definitions
|===================================================================================================================================|
*/

/* GPIO pin 0 modes */
#define GPIO_0_INPUT_MODE   0U
#define GPIO_0_OUTPUT_MODE  GPIO_MODER_MODER0_0
#define GPIO_0_ALT_FUN_MODE GPIO_MODER_MODER0_1
#define GPIO_0_ANALOG_MODE  (GPIO_MODER_MODER0_1 | GPIO_MODER_MODER0_0)

/* GPIO pin 1 modes */
#define GPIO_1_INPUT_MODE   0U
#define GPIO_1_OUTPUT_MODE  GPIO_MODER_MODER1_0
#define GPIO_1_ALT_FUN_MODE GPIO_MODER_MODER1_1
#define GPIO_1_ANALOG_MODE  (GPIO_MODER_MODER1_1 | GPIO_MODER_MODER1_0)

/* GPIO pin 2 modes */
#define GPIO_2_INPUT_MODE   0U
#define GPIO_2_OUTPUT_MODE  GPIO_MODER_MODER2_0
#define GPIO_2_ALT_FUN_MODE GPIO_MODER_MODER2_1
#define GPIO_2_ANALOG_MODE  (GPIO_MODER_MODER2_1 | GPIO_MODER_MODER2_0)

/* GPIO pin 3 modes */
#define GPIO_3_INPUT_MODE   0U
#define GPIO_3_OUTPUT_MODE  GPIO_MODER_MODER3_0
#define GPIO_3_ALT_FUN_MODE GPIO_MODER_MODER3_1
#define GPIO_3_ANALOG_MODE  (GPIO_MODER_MODER3_1 | GPIO_MODER_MODER3_0)

/* GPIO pin 4 modes */
#define GPIO_4_INPUT_MODE   0U
#define GPIO_4_OUTPUT_MODE  GPIO_MODER_MODER4_0
#define GPIO_4_ALT_FUN_MODE GPIO_MODER_MODER4_1
#define GPIO_4_ANALOG_MODE  (GPIO_MODER_MODER4_1 | GPIO_MODER_MODER4_0)

/* GPIO pin 5 modes */
#define GPIO_5_INPUT_MODE   0U
#define GPIO_5_OUTPUT_MODE  GPIO_MODER_MODER5_0
#define GPIO_5_ALT_FUN_MODE GPIO_MODER_MODER5_1
#define GPIO_5_ANALOG_MODE  (GPIO_MODER_MODER5_1 | GPIO_MODER_MODER5_0)

/* GPIO pin 6 modes */
#define GPIO_6_INPUT_MODE   0U
#define GPIO_6_OUTPUT_MODE  GPIO_MODER_MODER6_0
#define GPIO_6_ALT_FUN_MODE GPIO_MODER_MODER6_1
#define GPIO_6_ANALOG_MODE  (GPIO_MODER_MODER6_1 | GPIO_MODER_MODER6_0)

/* GPIO pin 7 modes */
#define GPIO_7_INPUT_MODE   0U
#define GPIO_7_OUTPUT_MODE  GPIO_MODER_MODER7_0
#define GPIO_7_ALT_FUN_MODE GPIO_MODER_MODER7_1
#define GPIO_7_ANALOG_MODE  (GPIO_MODER_MODER7_1 | GPIO_MODER_MODER7_0)

/* GPIO pin 8 modes */
#define GPIO_8_INPUT_MODE   0U
#define GPIO_8_OUTPUT_MODE  GPIO_MODER_MODER8_0
#define GPIO_8_ALT_FUN_MODE GPIO_MODER_MODER8_1
#define GPIO_8_ANALOG_MODE  (GPIO_MODER_MODER8_1 | GPIO_MODER_MODER8_0)

/* GPIO pin 9 modes */
#define GPIO_9_INPUT_MODE   0U
#define GPIO_9_OUTPUT_MODE  GPIO_MODER_MODER9_0
#define GPIO_9_ALT_FUN_MODE GPIO_MODER_MODER9_1
#define GPIO_9_ANALOG_MODE  (GPIO_MODER_MODER9_1 | GPIO_MODER_MODER9_0)

/* GPIO pin 10 modes */
#define GPIO_10_INPUT_MODE  0U
#define GPIO_10_OUTPUT_MODE GPIO_MODER_MODER10_0
#define GPIO_10_ALT_FUN_MODE GPIO_MODER_MODER10_1
#define GPIO_10_ANALOG_MODE (GPIO_MODER_MODER10_1 | GPIO_MODER_MODER10_0)

/* GPIO pin 11 modes */
#define GPIO_11_INPUT_MODE  0U
#define GPIO_11_OUTPUT_MODE GPIO_MODER_MODER11_0
#define GPIO_11_ALT_FUN_MODE GPIO_MODER_MODER11_1
#define GPIO_11_ANALOG_MODE (GPIO_MODER_MODER11_1 | GPIO_MODER_MODER11_0)

/* GPIO pin 12 modes */
#define GPIO_12_INPUT_MODE  0U
#define GPIO_12_OUTPUT_MODE GPIO_MODER_MODER12_0
#define GPIO_12_ALT_FUN_MODE GPIO_MODER_MODER12_1
#define GPIO_12_ANALOG_MODE (GPIO_MODER_MODER12_1 | GPIO_MODER_MODER12_0)

/* GPIO pin 13 modes */
#define GPIO_13_INPUT_MODE  0U
#define GPIO_13_OUTPUT_MODE GPIO_MODER_MODER13_0
#define GPIO_13_ALT_FUN_MODE GPIO_MODER_MODER13_1
#define GPIO_13_ANALOG_MODE (GPIO_MODER_MODER13_1 | GPIO_MODER_MODER13_0)

/* GPIO pin 14 modes */
#define GPIO_14_INPUT_MODE  0U
#define GPIO_14_OUTPUT_MODE GPIO_MODER_MODER14_0
#define GPIO_14_ALT_FUN_MODE GPIO_MODER_MODER14_1
#define GPIO_14_ANALOG_MODE (GPIO_MODER_MODER14_1 | GPIO_MODER_MODER14_0)

/* GPIO pin 15 modes */
#define GPIO_15_INPUT_MODE  0U
#define GPIO_15_OUTPUT_MODE GPIO_MODER_MODER15_0
#define GPIO_15_ALT_FUN_MODE GPIO_MODER_MODER15_1
#define GPIO_15_ANALOG_MODE (GPIO_MODER_MODER15_1 | GPIO_MODER_MODER15_0)


/* GPIO pin 0 alternate functions */
#define GPIO_0_ALT_FUN_0 0
#define GPIO_0_ALT_FUN_1 GPIO_AFRL_AFSEL0_0
#define GPIO_0_ALT_FUN_2 GPIO_AFRL_AFSEL0_1
#define GPIO_0_ALT_FUN_3 (GPIO_AFRL_AFSEL0_1 | GPIO_AFRL_AFSEL0_0)
#define GPIO_0_ALT_FUN_4 GPIO_AFRL_AFSEL0_2
#define GPIO_0_ALT_FUN_5 (GPIO_AFRL_AFSEL0_2 | GPIO_AFRL_AFSEL0_0)
#define GPIO_0_ALT_FUN_6 (GPIO_AFRL_AFSEL0_2 | GPIO_AFRL_AFSEL0_1)
#define GPIO_0_ALT_FUN_7 (GPIO_AFRL_AFSEL0_2 | GPIO_AFRL_AFSEL0_1 | GPIO_AFRL_AFSEL0_0)
#define GPIO_0_ALT_FUN_8 GPIO_AFRL_AFSEL0_3
#define GPIO_0_ALT_FUN_9 (GPIO_AFRL_AFSEL0_3 | GPIO_AFRL_AFSEL0_0)
#define GPIO_0_ALT_FUN_10 (GPIO_AFRL_AFSEL0_3 | GPIO_AFRL_AFSEL0_1)
#define GPIO_0_ALT_FUN_11 (GPIO_AFRL_AFSEL0_3 | GPIO_AFRL_AFSEL0_1 | GPIO_AFRL_AFSEL0_0)
#define GPIO_0_ALT_FUN_12 (GPIO_AFRL_AFSEL0_3 | GPIO_AFRL_AFSEL0_2)
#define GPIO_0_ALT_FUN_13 (GPIO_AFRL_AFSEL0_3 | GPIO_AFRL_AFSEL0_2 | GPIO_AFRL_AFSEL0_0)
#define GPIO_0_ALT_FUN_14 (GPIO_AFRL_AFSEL0_3 | GPIO_AFRL_AFSEL0_2 | GPIO_AFRL_AFSEL0_1)
#define GPIO_0_ALT_FUN_15 (GPIO_AFRL_AFSEL0_3 | GPIO_AFRL_AFSEL0_2 | GPIO_AFRL_AFSEL0_1 | GPIO_AFRL_AFSEL0_0)

/* GPIO pin 1 alternate functions */
#define GPIO_1_ALT_FUN_0 0
#define GPIO_1_ALT_FUN_1 GPIO_AFRL_AFSEL1_0
#define GPIO_1_ALT_FUN_2 GPIO_AFRL_AFSEL1_1
#define GPIO_1_ALT_FUN_3 (GPIO_AFRL_AFSEL1_1 | GPIO_AFRL_AFSEL1_0)
#define GPIO_1_ALT_FUN_4 GPIO_AFRL_AFSEL1_2
#define GPIO_1_ALT_FUN_5 (GPIO_AFRL_AFSEL1_2 | GPIO_AFRL_AFSEL1_0)
#define GPIO_1_ALT_FUN_6 (GPIO_AFRL_AFSEL1_2 | GPIO_AFRL_AFSEL1_1)
#define GPIO_1_ALT_FUN_7 (GPIO_AFRL_AFSEL1_2 | GPIO_AFRL_AFSEL1_1 | GPIO_AFRL_AFSEL1_0)
#define GPIO_1_ALT_FUN_8 GPIO_AFRL_AFSEL1_3
#define GPIO_1_ALT_FUN_9 (GPIO_AFRL_AFSEL1_3 | GPIO_AFRL_AFSEL1_0)
#define GPIO_1_ALT_FUN_10 (GPIO_AFRL_AFSEL1_3 | GPIO_AFRL_AFSEL1_1)
#define GPIO_1_ALT_FUN_11 (GPIO_AFRL_AFSEL1_3 | GPIO_AFRL_AFSEL1_1 | GPIO_AFRL_AFSEL1_0)
#define GPIO_1_ALT_FUN_12 (GPIO_AFRL_AFSEL1_3 | GPIO_AFRL_AFSEL1_2)
#define GPIO_1_ALT_FUN_13 (GPIO_AFRL_AFSEL1_3 | GPIO_AFRL_AFSEL1_2 | GPIO_AFRL_AFSEL1_0)
#define GPIO_1_ALT_FUN_14 (GPIO_AFRL_AFSEL1_3 | GPIO_AFRL_AFSEL1_2 | GPIO_AFRL_AFSEL1_1)
#define GPIO_1_ALT_FUN_15 (GPIO_AFRL_AFSEL1_3 | GPIO_AFRL_AFSEL1_2 | GPIO_AFRL_AFSEL1_1 | GPIO_AFRL_AFSEL1_0)

/* GPIO pin 2 alternate functions */
#define GPIO_2_ALT_FUN_0 0
#define GPIO_2_ALT_FUN_1 GPIO_AFRL_AFSEL2_0
#define GPIO_2_ALT_FUN_2 GPIO_AFRL_AFSEL2_1
#define GPIO_2_ALT_FUN_3 (GPIO_AFRL_AFSEL2_1 | GPIO_AFRL_AFSEL2_0)
#define GPIO_2_ALT_FUN_4 GPIO_AFRL_AFSEL2_2
#define GPIO_2_ALT_FUN_5 (GPIO_AFRL_AFSEL2_2 | GPIO_AFRL_AFSEL2_0)
#define GPIO_2_ALT_FUN_6 (GPIO_AFRL_AFSEL2_2 | GPIO_AFRL_AFSEL2_1)
#define GPIO_2_ALT_FUN_7 (GPIO_AFRL_AFSEL2_2 | GPIO_AFRL_AFSEL2_1 | GPIO_AFRL_AFSEL2_0)
#define GPIO_2_ALT_FUN_8 GPIO_AFRL_AFSEL2_3
#define GPIO_2_ALT_FUN_9 (GPIO_AFRL_AFSEL2_3 | GPIO_AFRL_AFSEL2_0)
#define GPIO_2_ALT_FUN_10 (GPIO_AFRL_AFSEL2_3 | GPIO_AFRL_AFSEL2_1)
#define GPIO_2_ALT_FUN_11 (GPIO_AFRL_AFSEL2_3 | GPIO_AFRL_AFSEL2_1 | GPIO_AFRL_AFSEL2_0)
#define GPIO_2_ALT_FUN_12 (GPIO_AFRL_AFSEL2_3 | GPIO_AFRL_AFSEL2_2)
#define GPIO_2_ALT_FUN_13 (GPIO_AFRL_AFSEL2_3 | GPIO_AFRL_AFSEL2_2 | GPIO_AFRL_AFSEL2_0)
#define GPIO_2_ALT_FUN_14 (GPIO_AFRL_AFSEL2_3 | GPIO_AFRL_AFSEL2_2 | GPIO_AFRL_AFSEL2_1)
#define GPIO_2_ALT_FUN_15 (GPIO_AFRL_AFSEL2_3 | GPIO_AFRL_AFSEL2_2 | GPIO_AFRL_AFSEL2_1 | GPIO_AFRL_AFSEL2_0)

/* GPIO pin 3 alternate functions */
#define GPIO_3_ALT_FUN_0 0
#define GPIO_3_ALT_FUN_1 GPIO_AFRL_AFSEL3_0
#define GPIO_3_ALT_FUN_2 GPIO_AFRL_AFSEL3_1
#define GPIO_3_ALT_FUN_3 (GPIO_AFRL_AFSEL3_1 | GPIO_AFRL_AFSEL3_0)
#define GPIO_3_ALT_FUN_4 GPIO_AFRL_AFSEL3_2
#define GPIO_3_ALT_FUN_5 (GPIO_AFRL_AFSEL3_2 | GPIO_AFRL_AFSEL3_0)
#define GPIO_3_ALT_FUN_6 (GPIO_AFRL_AFSEL3_2 | GPIO_AFRL_AFSEL3_1)
#define GPIO_3_ALT_FUN_7 (GPIO_AFRL_AFSEL3_2 | GPIO_AFRL_AFSEL3_1 | GPIO_AFRL_AFSEL3_0)
#define GPIO_3_ALT_FUN_8 GPIO_AFRL_AFSEL3_3
#define GPIO_3_ALT_FUN_9 (GPIO_AFRL_AFSEL3_3 | GPIO_AFRL_AFSEL3_0)
#define GPIO_3_ALT_FUN_10 (GPIO_AFRL_AFSEL3_3 | GPIO_AFRL_AFSEL3_1)
#define GPIO_3_ALT_FUN_11 (GPIO_AFRL_AFSEL3_3 | GPIO_AFRL_AFSEL3_1 | GPIO_AFRL_AFSEL3_0)
#define GPIO_3_ALT_FUN_12 (GPIO_AFRL_AFSEL3_3 | GPIO_AFRL_AFSEL3_2)
#define GPIO_3_ALT_FUN_13 (GPIO_AFRL_AFSEL3_3 | GPIO_AFRL_AFSEL3_2 | GPIO_AFRL_AFSEL3_0)
#define GPIO_3_ALT_FUN_14 (GPIO_AFRL_AFSEL3_3 | GPIO_AFRL_AFSEL3_2 | GPIO_AFRL_AFSEL3_1)
#define GPIO_3_ALT_FUN_15 (GPIO_AFRL_AFSEL3_3 | GPIO_AFRL_AFSEL3_2 | GPIO_AFRL_AFSEL3_1 | GPIO_AFRL_AFSEL3_0)

/* GPIO pin 4 alternate functions */
#define GPIO_4_ALT_FUN_0 0
#define GPIO_4_ALT_FUN_1 GPIO_AFRL_AFSEL4_0
#define GPIO_4_ALT_FUN_2 GPIO_AFRL_AFSEL4_1
#define GPIO_4_ALT_FUN_3 (GPIO_AFRL_AFSEL4_1 | GPIO_AFRL_AFSEL4_0)
#define GPIO_4_ALT_FUN_4 GPIO_AFRL_AFSEL4_2
#define GPIO_4_ALT_FUN_5 (GPIO_AFRL_AFSEL4_2 | GPIO_AFRL_AFSEL4_0)
#define GPIO_4_ALT_FUN_6 (GPIO_AFRL_AFSEL4_2 | GPIO_AFRL_AFSEL4_1)
#define GPIO_4_ALT_FUN_7 (GPIO_AFRL_AFSEL4_2 | GPIO_AFRL_AFSEL4_1 | GPIO_AFRL_AFSEL4_0)
#define GPIO_4_ALT_FUN_8 GPIO_AFRL_AFSEL4_3
#define GPIO_4_ALT_FUN_9 (GPIO_AFRL_AFSEL4_3 | GPIO_AFRL_AFSEL4_0)
#define GPIO_4_ALT_FUN_10 (GPIO_AFRL_AFSEL4_3 | GPIO_AFRL_AFSEL4_1)
#define GPIO_4_ALT_FUN_11 (GPIO_AFRL_AFSEL4_3 | GPIO_AFRL_AFSEL4_1 | GPIO_AFRL_AFSEL4_0)
#define GPIO_4_ALT_FUN_12 (GPIO_AFRL_AFSEL4_3 | GPIO_AFRL_AFSEL4_2)
#define GPIO_4_ALT_FUN_13 (GPIO_AFRL_AFSEL4_3 | GPIO_AFRL_AFSEL4_2 | GPIO_AFRL_AFSEL4_0)
#define GPIO_4_ALT_FUN_14 (GPIO_AFRL_AFSEL4_3 | GPIO_AFRL_AFSEL4_2 | GPIO_AFRL_AFSEL4_1)
#define GPIO_4_ALT_FUN_15 (GPIO_AFRL_AFSEL4_3 | GPIO_AFRL_AFSEL4_2 | GPIO_AFRL_AFSEL4_1 | GPIO_AFRL_AFSEL4_0)

/* GPIO pin 5 alternate functions */
#define GPIO_5_ALT_FUN_0 0
#define GPIO_5_ALT_FUN_1 GPIO_AFRL_AFSEL5_0
#define GPIO_5_ALT_FUN_2 GPIO_AFRL_AFSEL5_1
#define GPIO_5_ALT_FUN_3 (GPIO_AFRL_AFSEL5_1 | GPIO_AFRL_AFSEL5_0)
#define GPIO_5_ALT_FUN_4 GPIO_AFRL_AFSEL5_2
#define GPIO_5_ALT_FUN_5 (GPIO_AFRL_AFSEL5_2 | GPIO_AFRL_AFSEL5_0)
#define GPIO_5_ALT_FUN_6 (GPIO_AFRL_AFSEL5_2 | GPIO_AFRL_AFSEL5_1)
#define GPIO_5_ALT_FUN_7 (GPIO_AFRL_AFSEL5_2 | GPIO_AFRL_AFSEL5_1 | GPIO_AFRL_AFSEL5_0)
#define GPIO_5_ALT_FUN_8 GPIO_AFRL_AFSEL5_3
#define GPIO_5_ALT_FUN_9 (GPIO_AFRL_AFSEL5_3 | GPIO_AFRL_AFSEL5_0)
#define GPIO_5_ALT_FUN_10 (GPIO_AFRL_AFSEL5_3 | GPIO_AFRL_AFSEL5_1)
#define GPIO_5_ALT_FUN_11 (GPIO_AFRL_AFSEL5_3 | GPIO_AFRL_AFSEL5_1 | GPIO_AFRL_AFSEL5_0)
#define GPIO_5_ALT_FUN_12 (GPIO_AFRL_AFSEL5_3 | GPIO_AFRL_AFSEL5_2)
#define GPIO_5_ALT_FUN_13 (GPIO_AFRL_AFSEL5_3 | GPIO_AFRL_AFSEL5_2 | GPIO_AFRL_AFSEL5_0)
#define GPIO_5_ALT_FUN_14 (GPIO_AFRL_AFSEL5_3 | GPIO_AFRL_AFSEL5_2 | GPIO_AFRL_AFSEL5_1)
#define GPIO_5_ALT_FUN_15 (GPIO_AFRL_AFSEL5_3 | GPIO_AFRL_AFSEL5_2 | GPIO_AFRL_AFSEL5_1 | GPIO_AFRL_AFSEL5_0)

/* GPIO pin 6 alternate functions */
#define GPIO_6_ALT_FUN_0 0
#define GPIO_6_ALT_FUN_1 GPIO_AFRL_AFSEL6_0
#define GPIO_6_ALT_FUN_2 GPIO_AFRL_AFSEL6_1
#define GPIO_6_ALT_FUN_3 (GPIO_AFRL_AFSEL6_1 | GPIO_AFRL_AFSEL6_0)
#define GPIO_6_ALT_FUN_4 GPIO_AFRL_AFSEL6_2
#define GPIO_6_ALT_FUN_5 (GPIO_AFRL_AFSEL6_2 | GPIO_AFRL_AFSEL6_0)
#define GPIO_6_ALT_FUN_6 (GPIO_AFRL_AFSEL6_2 | GPIO_AFRL_AFSEL6_1)
#define GPIO_6_ALT_FUN_7 (GPIO_AFRL_AFSEL6_2 | GPIO_AFRL_AFSEL6_1 | GPIO_AFRL_AFSEL6_0)
#define GPIO_6_ALT_FUN_8 GPIO_AFRL_AFSEL6_3
#define GPIO_6_ALT_FUN_9 (GPIO_AFRL_AFSEL6_3 | GPIO_AFRL_AFSEL6_0)
#define GPIO_6_ALT_FUN_10 (GPIO_AFRL_AFSEL6_3 | GPIO_AFRL_AFSEL6_1)
#define GPIO_6_ALT_FUN_11 (GPIO_AFRL_AFSEL6_3 | GPIO_AFRL_AFSEL6_1 | GPIO_AFRL_AFSEL6_0)
#define GPIO_6_ALT_FUN_12 (GPIO_AFRL_AFSEL6_3 | GPIO_AFRL_AFSEL6_2)
#define GPIO_6_ALT_FUN_13 (GPIO_AFRL_AFSEL6_3 | GPIO_AFRL_AFSEL6_2 | GPIO_AFRL_AFSEL6_0)
#define GPIO_6_ALT_FUN_14 (GPIO_AFRL_AFSEL6_3 | GPIO_AFRL_AFSEL6_2 | GPIO_AFRL_AFSEL6_1)
#define GPIO_6_ALT_FUN_15 (GPIO_AFRL_AFSEL6_3 | GPIO_AFRL_AFSEL6_2 | GPIO_AFRL_AFSEL6_1 | GPIO_AFRL_AFSEL6_0)

/* GPIO pin 7 alternate functions */
#define GPIO_7_ALT_FUN_0 0
#define GPIO_7_ALT_FUN_1 GPIO_AFRL_AFSEL7_0
#define GPIO_7_ALT_FUN_2 GPIO_AFRL_AFSEL7_1
#define GPIO_7_ALT_FUN_3 (GPIO_AFRL_AFSEL7_1 | GPIO_AFRL_AFSEL7_0)
#define GPIO_7_ALT_FUN_4 GPIO_AFRL_AFSEL7_2
#define GPIO_7_ALT_FUN_5 (GPIO_AFRL_AFSEL7_2 | GPIO_AFRL_AFSEL7_0)
#define GPIO_7_ALT_FUN_6 (GPIO_AFRL_AFSEL7_2 | GPIO_AFRL_AFSEL7_1)
#define GPIO_7_ALT_FUN_7 (GPIO_AFRL_AFSEL7_2 | GPIO_AFRL_AFSEL7_1 | GPIO_AFRL_AFSEL7_0)
#define GPIO_7_ALT_FUN_8 GPIO_AFRL_AFSEL7_3
#define GPIO_7_ALT_FUN_9 (GPIO_AFRL_AFSEL7_3 | GPIO_AFRL_AFSEL7_0)
#define GPIO_7_ALT_FUN_10 (GPIO_AFRL_AFSEL7_3 | GPIO_AFRL_AFSEL7_1)
#define GPIO_7_ALT_FUN_11 (GPIO_AFRL_AFSEL7_3 | GPIO_AFRL_AFSEL7_1 | GPIO_AFRL_AFSEL7_0)
#define GPIO_7_ALT_FUN_12 (GPIO_AFRL_AFSEL7_3 | GPIO_AFRL_AFSEL7_2)
#define GPIO_7_ALT_FUN_13 (GPIO_AFRL_AFSEL7_3 | GPIO_AFRL_AFSEL7_2 | GPIO_AFRL_AFSEL7_0)
#define GPIO_7_ALT_FUN_14 (GPIO_AFRL_AFSEL7_3 | GPIO_AFRL_AFSEL7_2 | GPIO_AFRL_AFSEL7_1)
#define GPIO_7_ALT_FUN_15 (GPIO_AFRL_AFSEL7_3 | GPIO_AFRL_AFSEL7_2 | GPIO_AFRL_AFSEL7_1 | GPIO_AFRL_AFSEL7_0)

/* GPIO pin 8 alternate functions */
#define GPIO_8_ALT_FUN_0 0
#define GPIO_8_ALT_FUN_1 GPIO_AFRH_AFSEL8_0
#define GPIO_8_ALT_FUN_2 GPIO_AFRH_AFSEL8_1
#define GPIO_8_ALT_FUN_3 (GPIO_AFRH_AFSEL8_1 | GPIO_AFRH_AFSEL8_0)
#define GPIO_8_ALT_FUN_4 GPIO_AFRH_AFSEL8_2
#define GPIO_8_ALT_FUN_5 (GPIO_AFRH_AFSEL8_2 | GPIO_AFRH_AFSEL8_0)
#define GPIO_8_ALT_FUN_6 (GPIO_AFRH_AFSEL8_2 | GPIO_AFRH_AFSEL8_1)
#define GPIO_8_ALT_FUN_7 (GPIO_AFRH_AFSEL8_2 | GPIO_AFRH_AFSEL8_1 | GPIO_AFRH_AFSEL8_0)
#define GPIO_8_ALT_FUN_8 GPIO_AFRH_AFSEL8_3
#define GPIO_8_ALT_FUN_9 (GPIO_AFRH_AFSEL8_3 | GPIO_AFRH_AFSEL8_0)
#define GPIO_8_ALT_FUN_10 (GPIO_AFRH_AFSEL8_3 | GPIO_AFRH_AFSEL8_1)
#define GPIO_8_ALT_FUN_11 (GPIO_AFRH_AFSEL8_3 | GPIO_AFRH_AFSEL8_1 | GPIO_AFRH_AFSEL8_0)
#define GPIO_8_ALT_FUN_12 (GPIO_AFRH_AFSEL8_3 | GPIO_AFRH_AFSEL8_2)
#define GPIO_8_ALT_FUN_13 (GPIO_AFRH_AFSEL8_3 | GPIO_AFRH_AFSEL8_2 | GPIO_AFRH_AFSEL8_0)
#define GPIO_8_ALT_FUN_14 (GPIO_AFRH_AFSEL8_3 | GPIO_AFRH_AFSEL8_2 | GPIO_AFRH_AFSEL8_1)
#define GPIO_8_ALT_FUN_15 (GPIO_AFRH_AFSEL8_3 | GPIO_AFRH_AFSEL8_2 | GPIO_AFRH_AFSEL8_1 | GPIO_AFRH_AFSEL8_0)

/* GPIO pin 9 alternate functions */
#define GPIO_9_ALT_FUN_0 0
#define GPIO_9_ALT_FUN_1 GPIO_AFRH_AFSEL9_0
#define GPIO_9_ALT_FUN_2 GPIO_AFRH_AFSEL9_1
#define GPIO_9_ALT_FUN_3 (GPIO_AFRH_AFSEL9_1 | GPIO_AFRH_AFSEL9_0)
#define GPIO_9_ALT_FUN_4 GPIO_AFRH_AFSEL9_2
#define GPIO_9_ALT_FUN_5 (GPIO_AFRH_AFSEL9_2 | GPIO_AFRH_AFSEL9_0)
#define GPIO_9_ALT_FUN_6 (GPIO_AFRH_AFSEL9_2 | GPIO_AFRH_AFSEL9_1)
#define GPIO_9_ALT_FUN_7 (GPIO_AFRH_AFSEL9_2 | GPIO_AFRH_AFSEL9_1 | GPIO_AFRH_AFSEL9_0)
#define GPIO_9_ALT_FUN_8 GPIO_AFRH_AFSEL9_3
#define GPIO_9_ALT_FUN_9 (GPIO_AFRH_AFSEL9_3 | GPIO_AFRH_AFSEL9_0)
#define GPIO_9_ALT_FUN_10 (GPIO_AFRH_AFSEL9_3 | GPIO_AFRH_AFSEL9_1)
#define GPIO_9_ALT_FUN_11 (GPIO_AFRH_AFSEL9_3 | GPIO_AFRH_AFSEL9_1 | GPIO_AFRH_AFSEL9_0)
#define GPIO_9_ALT_FUN_12 (GPIO_AFRH_AFSEL9_3 | GPIO_AFRH_AFSEL9_2)
#define GPIO_9_ALT_FUN_13 (GPIO_AFRH_AFSEL9_3 | GPIO_AFRH_AFSEL9_2 | GPIO_AFRH_AFSEL9_0)
#define GPIO_9_ALT_FUN_14 (GPIO_AFRH_AFSEL9_3 | GPIO_AFRH_AFSEL9_2 | GPIO_AFRH_AFSEL9_1)
#define GPIO_9_ALT_FUN_15 (GPIO_AFRH_AFSEL9_3 | GPIO_AFRH_AFSEL9_2 | GPIO_AFRH_AFSEL9_1 | GPIO_AFRH_AFSEL9_0)

/* GPIO pin 10 alternate functions */
#define GPIO_10_ALT_FUN_0 0
#define GPIO_10_ALT_FUN_1 GPIO_AFRH_AFSEL10_0
#define GPIO_10_ALT_FUN_2 GPIO_AFRH_AFSEL10_1
#define GPIO_10_ALT_FUN_3 (GPIO_AFRH_AFSEL10_1 | GPIO_AFRH_AFSEL10_0)
#define GPIO_10_ALT_FUN_4 GPIO_AFRH_AFSEL10_2
#define GPIO_10_ALT_FUN_5 (GPIO_AFRH_AFSEL10_2 | GPIO_AFRH_AFSEL10_0)
#define GPIO_10_ALT_FUN_6 (GPIO_AFRH_AFSEL10_2 | GPIO_AFRH_AFSEL10_1)
#define GPIO_10_ALT_FUN_7 (GPIO_AFRH_AFSEL10_2 | GPIO_AFRH_AFSEL10_1 | GPIO_AFRH_AFSEL10_0)
#define GPIO_10_ALT_FUN_8 GPIO_AFRH_AFSEL10_3
#define GPIO_10_ALT_FUN_9 (GPIO_AFRH_AFSEL10_3 | GPIO_AFRH_AFSEL10_0)
#define GPIO_10_ALT_FUN_10 (GPIO_AFRH_AFSEL10_3 | GPIO_AFRH_AFSEL10_1)
#define GPIO_10_ALT_FUN_11 (GPIO_AFRH_AFSEL10_3 | GPIO_AFRH_AFSEL10_1 | GPIO_AFRH_AFSEL10_0)
#define GPIO_10_ALT_FUN_12 (GPIO_AFRH_AFSEL10_3 | GPIO_AFRH_AFSEL10_2)
#define GPIO_10_ALT_FUN_13 (GPIO_AFRH_AFSEL10_3 | GPIO_AFRH_AFSEL10_2 | GPIO_AFRH_AFSEL10_0)
#define GPIO_10_ALT_FUN_14 (GPIO_AFRH_AFSEL10_3 | GPIO_AFRH_AFSEL10_2 | GPIO_AFRH_AFSEL10_1)
#define GPIO_10_ALT_FUN_15 (GPIO_AFRH_AFSEL10_3 | GPIO_AFRH_AFSEL10_2 | GPIO_AFRH_AFSEL10_1 | GPIO_AFRH_AFSEL10_0)

/* GPIO pin 11 alternate functions */
#define GPIO_11_ALT_FUN_0 0
#define GPIO_11_ALT_FUN_1 GPIO_AFRH_AFSEL11_0
#define GPIO_11_ALT_FUN_2 GPIO_AFRH_AFSEL11_1
#define GPIO_11_ALT_FUN_3 (GPIO_AFRH_AFSEL11_1 | GPIO_AFRH_AFSEL11_0)
#define GPIO_11_ALT_FUN_4 GPIO_AFRH_AFSEL11_2
#define GPIO_11_ALT_FUN_5 (GPIO_AFRH_AFSEL11_2 | GPIO_AFRH_AFSEL11_0)
#define GPIO_11_ALT_FUN_6 (GPIO_AFRH_AFSEL11_2 | GPIO_AFRH_AFSEL11_1)
#define GPIO_11_ALT_FUN_7 (GPIO_AFRH_AFSEL11_2 | GPIO_AFRH_AFSEL11_1 | GPIO_AFRH_AFSEL11_0)
#define GPIO_11_ALT_FUN_8 GPIO_AFRH_AFSEL11_3
#define GPIO_11_ALT_FUN_9 (GPIO_AFRH_AFSEL11_3 | GPIO_AFRH_AFSEL11_0)
#define GPIO_11_ALT_FUN_10 (GPIO_AFRH_AFSEL11_3 | GPIO_AFRH_AFSEL11_1)
#define GPIO_11_ALT_FUN_11 (GPIO_AFRH_AFSEL11_3 | GPIO_AFRH_AFSEL11_1 | GPIO_AFRH_AFSEL11_0)
#define GPIO_11_ALT_FUN_12 (GPIO_AFRH_AFSEL11_3 | GPIO_AFRH_AFSEL11_2)
#define GPIO_11_ALT_FUN_13 (GPIO_AFRH_AFSEL11_3 | GPIO_AFRH_AFSEL11_2 | GPIO_AFRH_AFSEL11_0)
#define GPIO_11_ALT_FUN_14 (GPIO_AFRH_AFSEL11_3 | GPIO_AFRH_AFSEL11_2 | GPIO_AFRH_AFSEL11_1)
#define GPIO_11_ALT_FUN_15 (GPIO_AFRH_AFSEL11_3 | GPIO_AFRH_AFSEL11_2 | GPIO_AFRH_AFSEL11_1 | GPIO_AFRH_AFSEL11_0)

/* GPIO pin 12 alternate functions */
#define GPIO_12_ALT_FUN_0 0
#define GPIO_12_ALT_FUN_1 GPIO_AFRH_AFSEL12_0
#define GPIO_12_ALT_FUN_2 GPIO_AFRH_AFSEL12_1
#define GPIO_12_ALT_FUN_3 (GPIO_AFRH_AFSEL12_1 | GPIO_AFRH_AFSEL12_0)
#define GPIO_12_ALT_FUN_4 GPIO_AFRH_AFSEL12_2
#define GPIO_12_ALT_FUN_5 (GPIO_AFRH_AFSEL12_2 | GPIO_AFRH_AFSEL12_0)
#define GPIO_12_ALT_FUN_6 (GPIO_AFRH_AFSEL12_2 | GPIO_AFRH_AFSEL12_1)
#define GPIO_12_ALT_FUN_7 (GPIO_AFRH_AFSEL12_2 | GPIO_AFRH_AFSEL12_1 | GPIO_AFRH_AFSEL12_0)
#define GPIO_12_ALT_FUN_8 GPIO_AFRH_AFSEL12_3
#define GPIO_12_ALT_FUN_9 (GPIO_AFRH_AFSEL12_3 | GPIO_AFRH_AFSEL12_0)
#define GPIO_12_ALT_FUN_10 (GPIO_AFRH_AFSEL12_3 | GPIO_AFRH_AFSEL12_1)
#define GPIO_12_ALT_FUN_11 (GPIO_AFRH_AFSEL12_3 | GPIO_AFRH_AFSEL12_1 | GPIO_AFRH_AFSEL12_0)
#define GPIO_12_ALT_FUN_12 (GPIO_AFRH_AFSEL12_3 | GPIO_AFRH_AFSEL12_2)
#define GPIO_12_ALT_FUN_13 (GPIO_AFRH_AFSEL12_3 | GPIO_AFRH_AFSEL12_2 | GPIO_AFRH_AFSEL12_0)
#define GPIO_12_ALT_FUN_14 (GPIO_AFRH_AFSEL12_3 | GPIO_AFRH_AFSEL12_2 | GPIO_AFRH_AFSEL12_1)
#define GPIO_12_ALT_FUN_15 (GPIO_AFRH_AFSEL12_3 | GPIO_AFRH_AFSEL12_2 | GPIO_AFRH_AFSEL12_1 | GPIO_AFRH_AFSEL12_0)

/* GPIO pin 13 alternate functions */
#define GPIO_13_ALT_FUN_0 0
#define GPIO_13_ALT_FUN_1 GPIO_AFRH_AFSEL13_0
#define GPIO_13_ALT_FUN_2 GPIO_AFRH_AFSEL13_1
#define GPIO_13_ALT_FUN_3 (GPIO_AFRH_AFSEL13_1 | GPIO_AFRH_AFSEL13_0)
#define GPIO_13_ALT_FUN_4 GPIO_AFRH_AFSEL13_2
#define GPIO_13_ALT_FUN_5 (GPIO_AFRH_AFSEL13_2 | GPIO_AFRH_AFSEL13_0)
#define GPIO_13_ALT_FUN_6 (GPIO_AFRH_AFSEL13_2 | GPIO_AFRH_AFSEL13_1)
#define GPIO_13_ALT_FUN_7 (GPIO_AFRH_AFSEL13_2 | GPIO_AFRH_AFSEL13_1 | GPIO_AFRH_AFSEL13_0)
#define GPIO_13_ALT_FUN_8 GPIO_AFRH_AFSEL13_3
#define GPIO_13_ALT_FUN_9 (GPIO_AFRH_AFSEL13_3 | GPIO_AFRH_AFSEL13_0)
#define GPIO_13_ALT_FUN_10 (GPIO_AFRH_AFSEL13_3 | GPIO_AFRH_AFSEL13_1)
#define GPIO_13_ALT_FUN_11 (GPIO_AFRH_AFSEL13_3 | GPIO_AFRH_AFSEL13_1 | GPIO_AFRH_AFSEL13_0)
#define GPIO_13_ALT_FUN_12 (GPIO_AFRH_AFSEL13_3 | GPIO_AFRH_AFSEL13_2)
#define GPIO_13_ALT_FUN_13 (GPIO_AFRH_AFSEL13_3 | GPIO_AFRH_AFSEL13_2 | GPIO_AFRH_AFSEL13_0)
#define GPIO_13_ALT_FUN_14 (GPIO_AFRH_AFSEL13_3 | GPIO_AFRH_AFSEL13_2 | GPIO_AFRH_AFSEL13_1)
#define GPIO_13_ALT_FUN_15 (GPIO_AFRH_AFSEL13_3 | GPIO_AFRH_AFSEL13_2 | GPIO_AFRH_AFSEL13_1 | GPIO_AFRH_AFSEL13_0)

/* GPIO pin 14 alternate functions */
#define GPIO_14_ALT_FUN_0 0
#define GPIO_14_ALT_FUN_1 GPIO_AFRH_AFSEL14_0
#define GPIO_14_ALT_FUN_2 GPIO_AFRH_AFSEL14_1
#define GPIO_14_ALT_FUN_3 (GPIO_AFRH_AFSEL14_1 | GPIO_AFRH_AFSEL14_0)
#define GPIO_14_ALT_FUN_4 GPIO_AFRH_AFSEL14_2
#define GPIO_14_ALT_FUN_5 (GPIO_AFRH_AFSEL14_2 | GPIO_AFRH_AFSEL14_0)
#define GPIO_14_ALT_FUN_6 (GPIO_AFRH_AFSEL14_2 | GPIO_AFRH_AFSEL14_1)
#define GPIO_14_ALT_FUN_7 (GPIO_AFRH_AFSEL14_2 | GPIO_AFRH_AFSEL14_1 | GPIO_AFRH_AFSEL14_0)
#define GPIO_14_ALT_FUN_8 GPIO_AFRH_AFSEL14_3
#define GPIO_14_ALT_FUN_9 (GPIO_AFRH_AFSEL14_3 | GPIO_AFRH_AFSEL14_0)
#define GPIO_14_ALT_FUN_10 (GPIO_AFRH_AFSEL14_3 | GPIO_AFRH_AFSEL14_1)
#define GPIO_14_ALT_FUN_11 (GPIO_AFRH_AFSEL14_3 | GPIO_AFRH_AFSEL14_1 | GPIO_AFRH_AFSEL14_0)
#define GPIO_14_ALT_FUN_12 (GPIO_AFRH_AFSEL14_3 | GPIO_AFRH_AFSEL14_2)
#define GPIO_14_ALT_FUN_13 (GPIO_AFRH_AFSEL14_3 | GPIO_AFRH_AFSEL14_2 | GPIO_AFRH_AFSEL14_0)
#define GPIO_14_ALT_FUN_14 (GPIO_AFRH_AFSEL14_3 | GPIO_AFRH_AFSEL14_2 | GPIO_AFRH_AFSEL14_1)
#define GPIO_14_ALT_FUN_15 (GPIO_AFRH_AFSEL14_3 | GPIO_AFRH_AFSEL14_2 | GPIO_AFRH_AFSEL14_1 | GPIO_AFRH_AFSEL14_0)

/* GPIO pin 15 alternate functions */
#define GPIO_15_ALT_FUN_0 0
#define GPIO_15_ALT_FUN_1 GPIO_AFRH_AFSEL15_0
#define GPIO_15_ALT_FUN_2 GPIO_AFRH_AFSEL15_1
#define GPIO_15_ALT_FUN_3 (GPIO_AFRH_AFSEL15_1 | GPIO_AFRH_AFSEL15_0)
#define GPIO_15_ALT_FUN_4 GPIO_AFRH_AFSEL15_2
#define GPIO_15_ALT_FUN_5 (GPIO_AFRH_AFSEL15_2 | GPIO_AFRH_AFSEL15_0)
#define GPIO_15_ALT_FUN_6 (GPIO_AFRH_AFSEL15_2 | GPIO_AFRH_AFSEL15_1)
#define GPIO_15_ALT_FUN_7 (GPIO_AFRH_AFSEL15_2 | GPIO_AFRH_AFSEL15_1 | GPIO_AFRH_AFSEL15_0)
#define GPIO_15_ALT_FUN_8 GPIO_AFRH_AFSEL15_3
#define GPIO_15_ALT_FUN_9 (GPIO_AFRH_AFSEL15_3 | GPIO_AFRH_AFSEL15_0)
#define GPIO_15_ALT_FUN_10 (GPIO_AFRH_AFSEL15_3 | GPIO_AFRH_AFSEL15_1)
#define GPIO_15_ALT_FUN_11 (GPIO_AFRH_AFSEL15_3 | GPIO_AFRH_AFSEL15_1 | GPIO_AFRH_AFSEL15_0)
#define GPIO_15_ALT_FUN_12 (GPIO_AFRH_AFSEL15_3 | GPIO_AFRH_AFSEL15_2)
#define GPIO_15_ALT_FUN_13 (GPIO_AFRH_AFSEL15_3 | GPIO_AFRH_AFSEL15_2 | GPIO_AFRH_AFSEL15_0)
#define GPIO_15_ALT_FUN_14 (GPIO_AFRH_AFSEL15_3 | GPIO_AFRH_AFSEL15_2 | GPIO_AFRH_AFSEL15_1)
#define GPIO_15_ALT_FUN_15 (GPIO_AFRH_AFSEL15_3 | GPIO_AFRH_AFSEL15_2 | GPIO_AFRH_AFSEL15_1 | GPIO_AFRH_AFSEL15_0)

#endif /* PORT_TYPES_H */