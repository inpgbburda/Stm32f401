/**
* @file spi.h
* @brief Header to SPI driver implementation for STM32F401 microcontroller.
*
* This file contains the implementation of the SPI driver for the STM32F401 microcontroller.
* It includes functions for initializing the SPI interface, reading data synchronously and 
* asynchronously using interrupts, and handling SPI interrupts.
*
* @note Term "instance" means specific hardware that this driver can use - eg. SPI1, SPI2
*       In general module is stateless and doesn't own memory. The only exception is dynamic Storage_To_Hw_Map.
* @attention Ensure that the SPI peripheral clock is enabled before using this driver.
* @see Refer to the STM32F401 reference manual for detailed information on the SPI peripheral.
* @date day/month/year
*/

#ifndef SPI_H
#define SPI_H
/*
|===================================================================================================================================|
    File includes 
|===================================================================================================================================|
*/
#include <stdbool.h>
#include <stdint.h>
#include "stm32f401xc.h"
#include "type_reuse.h"

/*
|===================================================================================================================================|
    Macro definitions
|===================================================================================================================================|
*/
/* Macros needed for Unit Tests */
#ifdef _UNIT_TEST
    #define UT_GO_TO_NEXT_SAMPLE(drv) do { SpiHelper_GoToNextSample(drv); } while (0)
#else
    #define UT_GO_TO_NEXT_SAMPLE(drv) do {} while (0)
#endif


/*
|===================================================================================================================================|
    Exported types declarations
|===================================================================================================================================|
*/
typedef enum
{
    SPI_MODE_SYNCHRONOUS = 0,
    SPI_MODE_INTERRUPT,
}
Spi_Mode_T;

typedef void (*Complete_Clb_Ptr_T)(void);

typedef struct
{
    Complete_Clb_Ptr_T callback;
    uint32_t byte_cnt;
    bool mess_ready;
    SPI_TypeDef* instance;
    uint32_t expected_length;
    uint8_t* dest_ptr;
}
Spi_Storage_T;

typedef struct
{
    SPI_TypeDef* instance;  /* hw instance that will be assigned */
    Spi_Mode_T mode;        /* synchronous, interrupt */
    uint8_t int_priority;   /* priority of interrupt - place 0 if interrupt mode not used */
    Complete_Clb_Ptr_T callback; /* pointer to function called after succ. reception  - leave null ptr in synchronous mode*/

    uint16_t dff;    /* frame format - 8 or 16 bit */
    uint16_t clock_polarity; /* clock_polarity */
    uint16_t clock_phase;    /* clock_phase */
    uint16_t lsb_first;      /* bit order */
    uint16_t ssm;    /* configure NSS (chip select) pin behaviour - hw or sw*/
    uint16_t ssoe;   /* NSS as output */
    uint16_t mstr;   /* master or slave selection*/
    uint16_t frf;    /* frame format - Motorola or TI*/
}
Spi_Cfg_T;

/* Number of instances must match their number in hardware */
typedef enum
{
    SPI_INSTANCE_1 = 0,
    SPI_INSTANCE_2,
    SPI_INSTANCE_3,
    SPI_INSTANCE_COUNT_MAX
} 
Spi_Instance_Id_T;

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
 * SpiInit - Initializes the SPI interface with the specified configuration.
 * @storage: A pointer to the storage, which configuration will be assigned to.
 * @config: A pointer to an Spi_Cfg_T structure containing the configuration parameters.
 * 
 * This function initializes the SPI2 interface by enabling its clock, clearing the control registers, and setting the control
 * register values based on the provided configuration parameters. In case of interrupt mode it also sets the NVIC configuration.
 * Finally, it enables the SPI interface.
 * To enable multiple instances, this function must be called separately for each one of them.
 */
void SpiInit(Spi_Storage_T* storage, const Spi_Cfg_T* config);

/**
 * SpiReadBuffer - Reads data from the SPI receive buffer.
 * @instance: A pointer to the SPI_TypeDef structure representing the SPI instance to read from.
 * 
 * This function reads a 16-bit value from the SPI data register after waiting for the RXNE (Receive Buffer Not Empty) flag to be set,
 * indicating that data is available in the receive buffer.
 * 
 * @return: The 16-bit value read from the SPI data register.
 */
uint16_t SpiReadBuffer(const SPI_TypeDef* instance);

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
Std_Return_T SpiReadSynch(Spi_Storage_T* storage, uint8_t* dest_ptr, uint32_t mess_len, uint32_t timeout);

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
void SpiReadIt(Spi_Storage_T* storage, uint8_t *dest_ptr, uint32_t mess_len);

/**
*Spi interrupts declarations
 */
void Spi1_RxCompleteCbk(void);
void Spi2_RxCompleteCbk(void);
void Spi3_RxCompleteCbk(void);
void SPI1_IRQHandler(void);
void SPI2_IRQHandler(void);
void SPI3_IRQHandler(void);

#endif /* SPI_H */

