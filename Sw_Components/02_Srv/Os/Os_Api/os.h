/**
 * @file os.h
 * @brief Header file for the operating system functions.
 *
 * This header file contains declarations for the operating system initialization and start functions.
 */

#ifndef OS_H
#define OS_H

/*
|===================================================================================================================================|
    File includes 
|===================================================================================================================================|
*/
#include "motor_ctrl.h"

/*
|===================================================================================================================================|
    Macro definitions
|===================================================================================================================================|
*/


/*
|===================================================================================================================================|
    Exported types declarations
|===================================================================================================================================|
*/

typedef struct
{
    Receiver_Handler_T rec_handler;
} Os_Handler_T;

/*
|===================================================================================================================================|
    Exported objects declarations
|===================================================================================================================================|
*/


/*
|===================================================================================================================================|
    Exported functions declarations
|===================================================================================================================================|
*/

/**
 * @brief This function initializes the operating system (OS) by creating tasks.
 *
 * @return This function does not return.
 */
void OsInit(Os_Handler_T* os_handler);

/**
 * @brief This function starts the operating system scheduler.
 *
 * Starts the FreeRTOS scheduler, allowing the created tasks to run.
 *
 * @return This function does not return. It enters an infinite loop once the scheduler has started.
 */
void OsStart(void);

#endif /* OS_H */