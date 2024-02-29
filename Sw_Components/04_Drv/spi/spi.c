/**
* File contains 
*
*/

/*
|===================================================================================================================================|
    File includes 
|===================================================================================================================================|
*/

#include "pwm.h"
#include "pwm_cfg.h"
#include "stm32f401xc.h"
#include "spi.h"

/*
|===================================================================================================================================|
    Macro definitions
|===================================================================================================================================|
*/
#define GPIO_AFRL 0x00U
#define MODER0_ALT_FUN_MODE      GPIO_MODER_MODER0_1
#define AFRL_TIM1TIM2_SEL        GPIO_AFRL_AFSEL0_0
#define FIRST_PERIOD 0xFFU

/*
|===================================================================================================================================|
    Local types definitions 
|===================================================================================================================================|
*/


/*
|===================================================================================================================================|
    Object allocations 
|===================================================================================================================================|
*/


/*
|===================================================================================================================================|
    Local function declarations
|===================================================================================================================================|
*/

/*
|===================================================================================================================================|
    Function definitions
|===================================================================================================================================|
*/

void SpiInit(void)
{

}