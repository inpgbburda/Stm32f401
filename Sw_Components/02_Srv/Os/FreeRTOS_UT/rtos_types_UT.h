/**
* @file rtos_types_UT.h
* @brief Header supporting mocking of FreeRtos api functions.

* @attention - Should only be used in unit tests. Must remain consistent with FreeRtos types.
* @date 09.02.2025
*/

#ifndef RTOS_TYPES_H
#define RTOS_TYPES_H

#include <stdint.h>

#define pdFALSE                                  ( ( BaseType_t ) 0 )
#define pdTRUE                                   ( ( BaseType_t ) 1 )
#define pdFALSE_SIGNED                           ( ( BaseType_t ) 0 )
#define pdTRUE_SIGNED                            ( ( BaseType_t ) 1 )
#define pdFALSE_UNSIGNED                         ( ( UBaseType_t ) 0 )
#define pdTRUE_UNSIGNED                          ( ( UBaseType_t ) 1 )

#define pdPASS                                   ( pdTRUE )
#define pdFAIL                                   ( pdFALSE )
#define errQUEUE_EMPTY                           ( ( BaseType_t ) 0 )
#define errQUEUE_FULL                            ( ( BaseType_t ) 0 )

#define queueSEND_TO_BACK                     ( ( BaseType_t ) 0 )
#define queueSEND_TO_FRONT                    ( ( BaseType_t ) 1 )
#define queueOVERWRITE                        ( ( BaseType_t ) 2 )

/* These definitions *must* match those in queue.c. */
#define queueQUEUE_TYPE_BASE                  ( ( uint8_t ) 0U )
#define queueQUEUE_TYPE_SET                   ( ( uint8_t ) 0U )
#define queueQUEUE_TYPE_MUTEX                 ( ( uint8_t ) 1U )
#define queueQUEUE_TYPE_COUNTING_SEMAPHORE    ( ( uint8_t ) 2U )
#define queueQUEUE_TYPE_BINARY_SEMAPHORE      ( ( uint8_t ) 3U )
#define queueQUEUE_TYPE_RECURSIVE_MUTEX       ( ( uint8_t ) 4U )

/* typedefs for missing types */
typedef void * TaskHandle_t;
typedef void * TimerHandle_t;
typedef void * QueueHandle_t;
typedef void * SemaphoreHandle_t;
typedef void * EventGroupHandle_t;
typedef void * StaticTask_t;
typedef void * StaticQueue_t;
typedef void * StaticSemaphore_t;
typedef void * StaticEventGroup_t;
typedef void * StaticTimer_t;
typedef uint32_t TickType_t;
typedef int32_t BaseType_t;
typedef uint32_t UBaseType_t;
typedef void * QueueSetHandle_t;
typedef void * QueueSetMemberHandle_t;

#define xQueueCreate( uxQueueLength, uxItemSize )    xQueueGenericCreate( ( uxQueueLength ), ( uxItemSize ), ( queueQUEUE_TYPE_BASE ) )

#endif // RTOS_TYPES_H