/**
 * @file motor_ctrl.c
 * @brief Module for converting received data into motor control signals.
 *
 * This module handles the processing of motor control commands received via
 * a FreeRTOS queue and generates the appropriate PWM signals to control motors.
 * It also includes functionality for SPI-based data reception and task notification.
 *
 * @note - Ensure proper initialization of FreeRTOS components and SPI handlers before use.
 * @attention - This module is designed for STM32F401 and may require modifications for other platforms.
 * @see - motor_ctrl.h, pwm.h, spi.h
 * @author
 * @date 03/05/2025
 */

/*
|===================================================================================================================================|
    File includes
|===================================================================================================================================|
*/
#ifndef _UNIT_TEST
#include "FreeRTOS.h"
#endif

#include "task.h"
#include "queue.h"

#include "motor_ctrl.h"
#include "pwm.h"
#include "pwm_cfg.h"

#include "spi.h"
/*
|===================================================================================================================================|
    Macro definitions
|===================================================================================================================================|
*/
#define MAX_QUEUE_LENGTH 10
#define MAX_WAIT_TICKS 100
#define LUT_SIZE 256
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
static QueueHandle_t Assigned_Queue;

static const uint16_t Req2Pwm_Lut[LUT_SIZE] = {
    1000, 1004, 1008, 1012, 1016, 1020, 1024, 1027, 1031, 1035,
    1039, 1043, 1047, 1051, 1055, 1059, 1063, 1067, 1071, 1075,
    1078, 1082, 1086, 1090, 1094, 1098, 1102, 1106, 1110, 1114,
    1118, 1122, 1125, 1129, 1133, 1137, 1141, 1145, 1149, 1153,
    1157, 1161, 1165, 1169, 1173, 1176, 1180, 1184, 1188, 1192,
    1196, 1200, 1204, 1208, 1212, 1216, 1220, 1224, 1227, 1231,
    1235, 1239, 1243, 1247, 1251, 1255, 1259, 1263, 1267, 1271,
    1275, 1278, 1282, 1286, 1290, 1294, 1298, 1302, 1306, 1310,
    1314, 1318, 1322, 1325, 1329, 1333, 1337, 1341, 1345, 1349,
    1353, 1357, 1361, 1365, 1369, 1373, 1376, 1380, 1384, 1388,
    1392, 1396, 1400, 1404, 1408, 1412, 1416, 1420, 1424, 1427,
    1431, 1435, 1439, 1443, 1447, 1451, 1455, 1459, 1463, 1467,
    1471, 1475, 1478, 1482, 1486, 1490, 1494, 1498, 1502, 1506,
    1510, 1514, 1518, 1522, 1525, 1529, 1533, 1537, 1541, 1545,
    1549, 1553, 1557, 1561, 1565, 1569, 1573, 1576, 1580, 1584,
    1588, 1592, 1596, 1600, 1604, 1608, 1612, 1616, 1620, 1624,
    1627, 1631, 1635, 1639, 1643, 1647, 1651, 1655, 1659, 1663,
    1667, 1671, 1675, 1678, 1682, 1686, 1690, 1694, 1698, 1702,
    1706, 1710, 1714, 1718, 1722, 1725, 1729, 1733, 1737, 1741,
    1745, 1749, 1753, 1757, 1761, 1765, 1769, 1773, 1776, 1780,
    1784, 1788, 1792, 1796, 1800, 1804, 1808, 1812, 1816, 1820,
    1824, 1827, 1831, 1835, 1839, 1843, 1847, 1851, 1855, 1859,
    1863, 1867, 1871, 1875, 1878, 1882, 1886, 1890, 1894, 1898,
    1902, 1906, 1910, 1914, 1918, 1922, 1925, 1929, 1933, 1937,
    1941, 1945, 1949, 1953, 1957, 1961, 1965, 1969, 1973, 1976,
    1980, 1984, 1988, 1992, 1996, 2000};
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
void MotorCtrlAsignInputQueue(QueueHandle_t inbox_queue_handle)
{
    Assigned_Queue = inbox_queue_handle;
}

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
void MotorCtrlExecutePeriodic(void)
{
    PowerRequestsPackage_T receivedMessage;
    BaseType_t             queue_rx_status;
    uint16_t               converted_value = 0;
    uint8_t                snapshot = 0;

    queue_rx_status = xQueueReceive(Assigned_Queue, &receivedMessage, (TickType_t)MAX_WAIT_TICKS);
    if (queue_rx_status == pdTRUE)
    {
        for (uint8_t i = 0; i < MOTORS_NUMBER; i++)
        {
            snapshot = receivedMessage.req_vals[i];
            converted_value = Req2Pwm_Lut[snapshot];
            PwmSetDuty(&Pwm2_Config, (Pwm_Timer_Chan_T)i, converted_value);
        }
    }
    else
    {
        /* Do nothing */
    }
}

/**
 * MotorCtrlGetInboxQueueHandle
 * @brief: Retrieves the handle of the input queue for motor control.
 *
 * @return: QueueHandle_t Handle to the input queue.
 *
 * This function provides access to the input queue used for motor control commands.
 */
QueueHandle_t MotorCtrlGetInboxQueueHandle(void)
{
    return Assigned_Queue;
}

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
void ReceiverExecute(Receiver_Handler_T* rec_handle)
{
    PowerRequestsPackage_T data_to_pass;

    SpiReadIt(&(rec_handle->spi_handler), data_to_pass.req_vals, MOTORS_NUMBER);

    /*Switch task to Blocked State - Wait here for single notification for maximum allowed time*/
    ulTaskNotifyTake(pdTRUE, portMAX_DELAY);

    xQueueSendToFront(Assigned_Queue, (void*)&data_to_pass, (TickType_t)MAX_WAIT_TICKS);
}

/**
 * ReceiverCallRxCompleted
 * @brief: Notifies a task that an SPI receive operation has been completed.
 * @param rx_task_handle: Handle to the task that should be notified.
 *
 * This function is called from an interrupt service routine (ISR) to notify
 * a specific task that an SPI receive operation has been completed.
 *
 * @return: None
 *
 * @note - This function should be called from the RX interrupt or callback.
 */
void ReceiverCallRxCompleted(TaskHandle_t rx_task_handle)
{
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;
    /* Notify the SPI task */
    vTaskNotifyGiveFromISR(rx_task_handle, &xHigherPriorityTaskWoken);
#ifndef _UNIT_TEST
    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
#endif
}
