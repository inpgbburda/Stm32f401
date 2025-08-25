/**
* @file main.c
* @brief Main application entry point.
*
* This file contains the main function which initializes the system and starts the application.
*
* @note - 
* @attention - 
* @see - 
* @date 09/03/2025
*/

/*
|===================================================================================================================================|
    File includes 
|===================================================================================================================================|
*/
#include "pwm.h"
#include "pwm_cfg.h"
#include "spi.h"
#include "spi_cfg.h"
#include "cmsis_gcc.h"
#include "systick.h"
#include "port.h"
#include "port_cfg.h"
#include "clock.h"
#include "clock_cfg.h"
#include "os.h"

/*
|===================================================================================================================================|
    Macro definitions
|===================================================================================================================================|
*/

/*
|===================================================================================================================================|
    Object allocations 
|===================================================================================================================================|
*/
/* Main memory allocation */
static Os_Handle_T Os_Handle;

/*
|===================================================================================================================================|
    Function definitions
|===================================================================================================================================|
*/
int main(void)
{
    ClockInit(&Clock_Config);
    PortInit(Port_Config);
    PwmInit(&Pwm2_Config);
    SpiInit(&(Os_Handle.rec_handle.spi_handle), &Spi2_It_Config);

    SystickInit();
    OsInit(&Os_Handle);
    
    PwmStart(&Pwm2_Config);
    OsStart();

    while (1)
    {
        /* Unreachable code */
    }
}