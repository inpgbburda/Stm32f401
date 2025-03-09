/**
* @file rtos_types_UT.h
* @brief Header supporting mocking of FreeRtos api functions.
*
* @attention - Should only be used in unit tests. Must remain consistent with FreeRtos types.
* @date 09.02.2025
*/

#ifndef RTOS_TYPES_UT_H
#define RTOS_TYPES_UT_H

#include <stdint.h>

/** Boolean values */
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

/** Queue send options */
#define queueSEND_TO_BACK                        ( ( BaseType_t ) 0 )
#define queueSEND_TO_FRONT                       ( ( BaseType_t ) 1 )
#define queueOVERWRITE                           ( ( BaseType_t ) 2 )

/** Queue types */
#define queueQUEUE_TYPE_BASE                     ( ( uint8_t ) 0U )
#define queueQUEUE_TYPE_SET                      ( ( uint8_t ) 0U )
#define queueQUEUE_TYPE_MUTEX                    ( ( uint8_t ) 1U )
#define queueQUEUE_TYPE_COUNTING_SEMAPHORE       ( ( uint8_t ) 2U )
#define queueQUEUE_TYPE_BINARY_SEMAPHORE         ( ( uint8_t ) 3U )
#define queueQUEUE_TYPE_RECURSIVE_MUTEX          ( ( uint8_t ) 4U )

/** Typedefs for queue-related types */
typedef void * QueueHandle_t;
typedef void * QueueSetHandle_t;
typedef void * QueueSetMemberHandle_t;
typedef void * StaticQueue_t;

/** Typedefs for task-related types */
typedef void * TaskHandle_t;
typedef const void * ConstTaskHandle_t;
typedef void * StaticTask_t;
typedef void (* TaskFunction_t)( void * );
typedef void (* TaskHookFunction_t)(void *);

/** Typedefs for timer-related types */
typedef void * TimerHandle_t;
typedef void * StaticTimer_t;

/** Typedefs for semaphore-related types */
typedef void * SemaphoreHandle_t;
typedef void * StaticSemaphore_t;

/** Typedefs for event group-related types */
typedef void * EventGroupHandle_t;
typedef void * StaticEventGroup_t;

/** Typedefs for basic types */
typedef uint32_t TickType_t;
typedef int32_t BaseType_t;
typedef uint32_t UBaseType_t;
typedef uint32_t StackType_t;

/** Struct typedefs */
typedef struct xTIME_OUT
{
    BaseType_t xOverflowCount;
    TickType_t xTimeOnEntering;
} TimeOut_t;

typedef struct xMEMORY_REGION { void *dummy; } MemoryRegion_t;
typedef struct xTASK_PARAMETERS { void *dummy; } TaskParameters_t;
typedef struct xTASK_STATUS { void *dummy; } TaskStatus_t;
typedef struct xLIST { void *dummy; } List_t;
typedef struct xLIST_ITEM { void *dummy; } ListItem_t;
typedef struct xMPU_SETTINGS { void *dummy; } xMPU_SETTINGS;

/** Typedefs for configuration types */
typedef uint32_t configSTACK_DEPTH_TYPE;
typedef uint32_t configRUN_TIME_COUNTER_TYPE;
typedef uint32_t eTaskState;
typedef uint32_t eNotifyAction;
typedef uint32_t eSleepModeStatus;

/** Typedefs for port types */
#define portCHAR          char
#define portFLOAT         float
#define portDOUBLE        double
#define portLONG          long
#define portSHORT         short
#define portSTACK_TYPE    uint32_t
#define portBASE_TYPE     long

typedef portSTACK_TYPE   StackType_t;

#define portMAX_DELAY    ( TickType_t ) 0xffffffffffffffffULL
#define tskDEFAULT_INDEX_TO_NOTIFY     ( 0 )

/** Macros for functions */
#define xQueueCreate( uxQueueLength, uxItemSize )    xQueueGenericCreate( ( uxQueueLength ), ( uxItemSize ), ( queueQUEUE_TYPE_BASE ) )

#define ulTaskNotifyTake( xClearCountOnExit, xTicksToWait ) \
    ulTaskGenericNotifyTake( ( tskDEFAULT_INDEX_TO_NOTIFY ), ( xClearCountOnExit ), ( xTicksToWait ) )

#define xQueueSendToFront( xQueue, pvItemToQueue, xTicksToWait ) \
    xQueueGenericSend( ( xQueue ), ( pvItemToQueue ), ( xTicksToWait ), queueSEND_TO_FRONT )

#endif // RTOS_TYPES_UT_H