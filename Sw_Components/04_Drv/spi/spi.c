/**
* @file spi.c
* @brief SPI driver implementation for STM32F401 microcontroller.
*
* This file contains the implementation of the SPI driver for the STM32F401 microcontroller.
* It includes functions for initializing the SPI interface, reading data synchronously and 
* asynchronously using interrupts, and handling SPI interrupts.
*
* @note This driver supports multiple SPI instances (SPI1, SPI2, SPI3) and can be configured 
*       for interrupt-driven or polling-based operation.
* @attention Ensure that the SPI peripheral clock is enabled before using this driver.
* @see Refer to the STM32F401 reference manual for detailed information on the SPI peripheral.
* @date day/month/year
*/

/*
|===================================================================================================================================|
    File includes 
|===================================================================================================================================|
*/
#include "stm32f401xc.h"
#include "spi.h"
#include "stdlib.h"

#ifdef _UNIT_TEST
#include "spi_helper_UT.h"
#endif

/*
|===================================================================================================================================|
    Macro definitions
|===================================================================================================================================|
*/
#define SPI_SR_RXNE_FLAG(reg) (reg & SPI_SR_RXNE_Msk)
#define MAX_HW_NUMBER 3U

/*
|===================================================================================================================================|
    Local types definitions 
|===================================================================================================================================|
*/
typedef struct
{
    SPI_TypeDef* instance;
    IRQn_Type    interrupt_id;
} Storage_Hw_Pair_T;

/*
|===================================================================================================================================|
    Object allocations 
|===================================================================================================================================|
*/
/* Assignment of interrupt handlers for given instance */
const Storage_Hw_Pair_T SpiInstanceMap[] = {
    {SPI1, SPI1_IRQn},
    {SPI2, SPI2_IRQn},
    {SPI3, SPI3_IRQn},
};

/* Dynamic mapping of instances to storages */
Spi_Storage_T* Storage_To_Hw_Map[SPI_INSTANCE_COUNT_MAX];

/*
|===================================================================================================================================|
    Local function declarations
|===================================================================================================================================|
*/
static void DoRxInterruptRoutine(Spi_Storage_T* storage);
static void SetUpDriverRegisters(const Spi_Cfg_T* config);
static void SetUpNvic(IRQn_Type interrupt_id, uint32_t priority);
static bool IsRxFlagSet(const SPI_TypeDef *instance);
static uint8_t ReadHwDrBuffer(const SPI_TypeDef *instance);
static void EnableInterruptInDriver(SPI_TypeDef *instance);
static void DisableInterruptInDriver(SPI_TypeDef *instance);

/*
|===================================================================================================================================|
    Function definitions
|===================================================================================================================================|
*/

/**
 * SpiInit - Initializes the SPI interface with the specified configuration.
 * @storage: A pointer to the storage, which configuration will be assigned to.
 * @config: A pointer to an Spi_Cfg_T structure containing the configuration parameters.
 * 
 * This function initializes the SPI2 interface by enabling its clock, clearing the control registers, and setting the control
 * register values based on the provided configuration parameters. In case of interrupt mode it also sets the NVIC configuration.
 * Finally, it enables the SPI interface.
 * To enable multiple instances, this function must be called separately for each one of them.
 */
void SpiInit(Spi_Storage_T* storage, const Spi_Cfg_T* config)
{
    SPI_TypeDef* used_driver;
    IRQn_Type    interrupt_id;

    used_driver = config->instance;
    storage->instance = used_driver;
    storage->callback = config->callback;

    if (SPI_MODE_INTERRUPT == config->mode)
    {
        for (uint8_t i = 0; i < SPI_INSTANCE_COUNT_MAX; i++)
        {
            if (SpiInstanceMap[i].instance == used_driver)
            {
                interrupt_id = SpiInstanceMap[i].interrupt_id;
            }
        }
        SetUpNvic(interrupt_id, config->int_priority);
    }
    SetUpDriverRegisters(config);
}

/**
 * SpiReadBuffer - Reads data from the SPI receive buffer.
 * @instance: A pointer to the SPI_TypeDef structure representing the SPI instance to read from.
 * 
 * This function reads a 16-bit value from the SPI data register after waiting for the RXNE (Receive Buffer Not Empty) flag to be set,
 * indicating that data is available in the receive buffer.
 * 
 * @return: The 16-bit value read from the SPI data register.
 */
uint16_t SpiReadBuffer(const SPI_TypeDef* instance)
{
    uint16_t buffer_val = 0;
    while (0U == (SPI_SR_RXNE_FLAG(instance->SR)))
    {
        /* wait for data */
    }
    buffer_val = instance->DR;

    return buffer_val;
}

/**
 * SpiReadSynch - Synchronously reads data from an SPI peripheral.
 * @instance: A pointer to the SPI_TypeDef structure representing the SPI instance to read from.
 * @dest_ptr: A pointer to the destination buffer where the read data will be stored.
 * @mess_len: The number of bytes to read from the SPI instance.
 * @timeout: The maximum time (in CPU ticks) to wait for the read operation to complete.
 * 
 * This function performs a synchronous read operation from the specified SPI instance. It reads up to the specified 
 * number of bytes (`mess_len`) and stores them in the provided buffer (`dest_ptr`). The function will continue reading 
 * until either the message length is reached or the specified timeout expires.
 * 
 * @return:
 * - E_OK: If the data is successfully read from the SPI peripheral.
 * - E_NOT_OK: If there is a timeout, invalid input (null pointers), or other errors during the operation.
 */
Std_Return_T SpiReadSynch(Spi_Storage_T* storage, uint8_t* dest_ptr, uint32_t mess_len, uint32_t timeout)
{
    Std_Return_T ret_val = E_NOT_OK;
    uint32_t     byte_num = 0;
    uint32_t     tick_cnt = 0;
    bool         mess_ready = false;

    if ((NULL == (storage->instance)) || (NULL == dest_ptr))
    {
        return E_NOT_OK;
    }

    while ((tick_cnt < timeout) && (!mess_ready))
    {
        if (IsRxFlagSet(storage->instance))
        {
            if (byte_num < mess_len)
            {
                dest_ptr[byte_num] = ReadHwDrBuffer(storage->instance);
                byte_num++;
            }
        }
        if (byte_num >= mess_len)
        {
            mess_ready = true;
            ret_val = E_OK;
        }
        tick_cnt++;
        UT_GO_TO_NEXT_SAMPLE(storage->instance);
    }
    return ret_val;
}

/**
 * SpiReadIt - Initiates an interrupt-driven SPI read operation.
 * @storage:  A pointer to the storage, which specifics and statuses of reading will be assigned to.
 * @dest_ptr: A pointer to the destination buffer where the read data will be stored.
 * @mess_len: The number of bytes to read from the SPI instance.
 * 
 * This function sets up an interrupt-driven SPI read operation. It configures
 * the SPI storage structure with the provided parameters and enables the
 * receive buffer not empty (RXNE) interrupt to start the data reception.
 * 
 * @return: none
 */
void SpiReadIt(Spi_Storage_T* storage, uint8_t* dest_ptr, uint32_t mess_len)
{
    uint8_t      residual_trash;
    SPI_TypeDef* used_instance;

    storage->mess_ready = false;
    storage->byte_cnt = 0U;
    storage->expected_length = mess_len;
    storage->dest_ptr = dest_ptr;
    used_instance = storage->instance;

    for (uint8_t i = 0; i < SPI_INSTANCE_COUNT_MAX; i++)
    {
        if (SpiInstanceMap[i].instance == used_instance)
        {
            Storage_To_Hw_Map[i] = storage;
        }
    }

    /* Read rx buffer to always start with empty one */
    residual_trash = ReadHwDrBuffer(used_instance);
    EnableInterruptInDriver(used_instance);
}

static void DoRxInterruptRoutine(Spi_Storage_T* storage)
{
    uint32_t cnt;
    uint32_t exp_len;

    cnt = storage->byte_cnt;
    exp_len = storage->expected_length;

    if (!storage->mess_ready)
    {
        if (cnt < (exp_len - 1U))
        {
            (storage->dest_ptr)[cnt] = ReadHwDrBuffer(storage->instance);
            cnt++;
        }
        else if (cnt == (exp_len - 1U))
        {
            (storage->dest_ptr)[cnt] = ReadHwDrBuffer(storage->instance);
            cnt = 0U;
            storage->mess_ready = true;
            DisableInterruptInDriver(storage->instance);
            storage->callback();
        }
        else
        {
            /* Error handling - should never get here */
            cnt = 0U;
        }
    }
    storage->byte_cnt = cnt;
    UT_GO_TO_NEXT_SAMPLE(storage->instance);
}

static void SetUpDriverRegisters(const Spi_Cfg_T* config)
{
    SPI_TypeDef* used_instance;
    used_instance = config->instance;

#ifndef _UNIT_TEST
    /* Clear register contents*/
    used_instance->CR1 = 0x0000U;
    used_instance->CR2 = 0x0000U;

    used_instance->CR1 |= config->dff;
    used_instance->CR1 |= config->clock_polarity;
    used_instance->CR1 |= config->clock_phase;
    used_instance->CR1 |= config->lsb_first;
    used_instance->CR1 |= config->ssm;
    used_instance->CR1 |= config->ssoe;
    used_instance->CR1 |= config->mstr;
    used_instance->CR2 |= config->frf;

    /* Enable spi */
    used_instance->CR1 |= SPI_CR1_SPE;
#endif
}

static void SetUpNvic(IRQn_Type int_id, uint32_t int_prio)
{
#ifndef _UNIT_TEST
    NVIC_SetPriority(int_id, int_prio);
    NVIC_EnableIRQ(int_id);
#endif
}

static bool IsRxFlagSet(const SPI_TypeDef* instance)
{
    bool result = false;

#ifndef _UNIT_TEST
    result = SPI_SR_RXNE_FLAG(instance->SR);
#else
    result = (bool)SpiHelper_ReadRxNeFlagMock(instance);
#endif
    return result;
}

static uint8_t ReadHwDrBuffer(const SPI_TypeDef* instance)
{
    uint8_t result;

#ifndef _UNIT_TEST
    /*Reading this buffer also clears the RXNE flag*/
    result = instance->DR;
#else
    result = SpiHelper_ReadDrMock(instance);
#endif
    return result;
}

static void EnableInterruptInDriver(SPI_TypeDef* instance)
{
#ifndef _UNIT_TEST
    instance->CR2 |= SPI_CR2_RXNEIE;
#endif
}

static void DisableInterruptInDriver(SPI_TypeDef* instance)
{
#ifndef _UNIT_TEST
    instance->CR2 &= ~(SPI_CR2_RXNEIE);
#endif
}

void SPI1_IRQHandler()
{
    DoRxInterruptRoutine(Storage_To_Hw_Map[SPI_INSTANCE_1]);
}

void SPI2_IRQHandler()
{
    DoRxInterruptRoutine(Storage_To_Hw_Map[SPI_INSTANCE_2]);
}

void SPI3_IRQHandler(void)
{
    DoRxInterruptRoutine(Storage_To_Hw_Map[SPI_INSTANCE_3]);
}