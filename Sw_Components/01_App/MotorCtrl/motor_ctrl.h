/**
* @file motor_ctrl.c
* @brief Module for converting received data into motor control signals.
*
* This module handles the processing of received data and converts it into
* control signals for motors. It provides functions for assigning input queues,
* executing periodic tasks, and handling receiver operations.
*
* @note - Ensure proper initialization of SPI and FreeRTOS components before use.
* @attention - This module is not thread-safe; ensure proper synchronization.
* @see - Refer to the SPI and FreeRTOS documentation for integration details.
* @date - 03.05.2025
*/

#ifndef MOTOR_CTRL_H
#define MOTOR_CTRL_H

/*
|===================================================================================================================================|
    File includes 
|===================================================================================================================================|
*/
#ifndef _UNIT_TEST
#include "FreeRTOS.h"
#endif

#include <stdint.h>
#include "queue.h"
#include "spi.h"

/*
|===================================================================================================================================|
    Macro definitions
|===================================================================================================================================|
*/
#define MOTORS_NUMBER 4U

/*
|===================================================================================================================================|
    Exported types declarations
|===================================================================================================================================|
*/
typedef struct
{
    uint8_t req_vals[MOTORS_NUMBER];
} PowerRequestsPackage_T;

typedef struct
{
    Spi_Storage_T spi_handle;
} Receiver_Handle_T;

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
 * MotorCtrlAsignInputQueue
 * @brief: Assigns the input queue for motor control commands.
 * @param inbox_queue_handle: Handle to the FreeRTOS queue for receiving motor control commands.
 * 
 * This function sets the queue that will be used to receive motor control commands.
 * 
 * @return: None
 * 
 * @note - Call this function before using other motor control functions.
 */
void MotorCtrlAsignInputQueue(QueueHandle_t inbox_queue_handle);

/**
 * MotorCtrlExecutePeriodic
 * @brief: Executes periodic motor control tasks.
 * 
 * This function processes the motor control commands from the input queue
 * and generates the appropriate control signals for the motors.
 * 
 * @return: None
 * 
 * @note - This function should be called periodically in a FreeRTOS task.
 */
void MotorCtrlExecutePeriodic(void);

/**
 * MotorCtrlGetInboxQueueHandle
 * @brief: Retrieves the handle of the input queue for motor control.
 * 
 * @return: QueueHandle_t Handle to the input queue.
 * 
 * This function provides access to the input queue used for motor control commands.
 */
QueueHandle_t MotorCtrlGetInboxQueueHandle(void);

/**
 * ReceiverExecute
 * @brief: Executes receiver-specific tasks.
 * @param rec_handle: Pointer to the receiver handler structure.
 * 
 * This function processes received data and prepares it for motor control.
 * 
 * @return: None
 * 
 * @note - Ensure the receiver handler is properly initialized before calling this function.
 */
void ReceiverExecute(Receiver_Handle_T* rec_handle);

/**
 * ReceiverCallRxCompleted
 * @brief: Notifies the receiver task of completed RX operations.
 * @param rx_task_handle: Handle to the FreeRTOS task to be notified.
 * 
 * This function signals the specified task that an RX operation has completed.
 * 
 * @return: None
 * 
 * @note - This function should be called from the RX interrupt or callback.
 */
void ReceiverCallRxCompleted(TaskHandle_t rx_task_handle);

#endif /* MOTOR_CTRL_H */