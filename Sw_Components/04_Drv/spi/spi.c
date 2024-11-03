/**
* File contains spi implementation
*
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
static bool IsRxFlagSet(const SPI_TypeDef *instance);
static uint8_t ReadHwDrBuffer(const SPI_TypeDef *instance);


/*
|===================================================================================================================================|
    Function definitions
|===================================================================================================================================|
*/



/**
 * SpiInit - Initializes the SPI interface with the specified configuration.
 * @config: A pointer to an Spi_Cfg_T structure containing the configuration parameters.
 * 
 * This function initializes the SPI2 interface by enabling its clock, clearing the control registers, and setting the control
 * register values based on the provided configuration parameters. Finally, it enables the SPI interface.
 */
void SpiInit(const Spi_Cfg_T* config)
{
    SPI_TypeDef* used_driver;
    IRQn_Type interrupt_id;

    used_driver = config->instance;
    
    if(SPI_MODE_INTERRUPT == config->mode){

        used_driver->CR2 |= SPI_CR2_RXNEIE;  /* Set the RXNEIE bit to enable RXNE interrupt */

        if(SPI1 == used_driver){
            interrupt_id = SPI1_IRQn;
        }
        else if(SPI2 == used_driver){
            interrupt_id = SPI2_IRQn;
        }
        else if(SPI3 == used_driver){
            interrupt_id = SPI3_IRQn;
        }
        else{

        }
        NVIC_SetPriority(interrupt_id, config->int_priority);     /* Set priority */
        NVIC_EnableIRQ(interrupt_id);                             /* Enable SPI2 interrupt */
    }

    /* Clear register contents*/
    used_driver->CR1 = 0x0000U;
    used_driver->CR2 = 0x0000U;

    used_driver->CR1 |= config->dff;
    used_driver->CR1 |= config->clock_polarity;
    used_driver->CR1 |= config->clock_phase;
    used_driver->CR1 |= config->lsb_first;
    used_driver->CR1 |= config->ssm;
    used_driver->CR1 |= config->ssoe;
    used_driver->CR1 |= config->mstr;
    used_driver->CR2 |= config->frf;

    /* Enable spi */
    used_driver->CR1 |= config->spe;
}

/**
 * SpiReadBuffer - Reads data from the SPI receive buffer.
 * @instance: A pointer to the SPI_TypeDef structure representing the SPI instance to read from.
 * 
 * This function reads a 16-bit value from the SPI data register after waiting for the RXNE (Receive Buffer Not Empty) flag to be set,
 * indicating that data is available in the receive buffer.
 * 
 * Returns: The 16-bit value read from the SPI data register.
 */
uint16_t SpiReadBuffer(const SPI_TypeDef *instance)
{
    uint16_t buffer_val = 0;
    while(0U == (SPI_SR_RXNE_FLAG(instance->SR))){
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
 * Returns: 
 * - E_OK: If the data is successfully read from the SPI peripheral.
 * - E_NOT_OK: If there is a timeout, invalid input (null pointers), or other errors during the operation.
 */
Std_Return_T SpiReadSynch(const SPI_TypeDef *instance, uint8_t* dest_ptr, uint32_t mess_len, uint32_t timeout)
{
    Std_Return_T ret_val = E_NOT_OK;
    uint32_t byte_num = 0;
    uint32_t tick_cnt = 0;
    bool mess_ready = false;

    if((NULL == instance)||(NULL == dest_ptr)){
        return E_NOT_OK;
    }

    while((tick_cnt < timeout) && (!mess_ready)){
        if(IsRxFlagSet(instance)){
            if(byte_num < mess_len){
                dest_ptr[byte_num] = ReadHwDrBuffer(instance);
                byte_num++;
            }
        }
        if(byte_num >= mess_len){
            mess_ready = true;
            ret_val = E_OK;
        }
        tick_cnt++;
        UT_GO_TO_NEXT_SAMPLE();
    }
    return ret_val;
}


uint8_t* pointer_to_save;
static bool mess_ready = false;
static uint32_t expected_length = 0U;

void SpiReadIt(const SPI_TypeDef *instance, uint8_t* dest_ptr, uint32_t mess_len)
{
    uint8_t residual_trash;
    
    residual_trash = ReadHwDrBuffer(SPI2);
    
    mess_ready = false;
    pointer_to_save = dest_ptr;
    expected_length = mess_len;
#ifndef _UNIT_TEST
    SPI2->CR2 |= SPI_CR2_RXNEIE;
#endif
}

static bool IsRxFlagSet(const SPI_TypeDef *instance)
{
    bool result = false;
#ifndef _UNIT_TEST
    result = SPI_SR_RXNE_FLAG(instance->SR);
#else
    result = SpiHelper_ReadRxNeFlagMock();
#endif
    return result;
}

static uint8_t ReadHwDrBuffer(const SPI_TypeDef *instance)
{
    uint8_t result;

#ifndef _UNIT_TEST
    /*Reading this buffer also clears the RXNE flag*/
    result = instance->DR;
#else
    result = SpiHelper_ReadDrMock();
#endif
    return result;
}

void SPI2_IRQHandler()
{
    static uint32_t byte_cnt = 0U;

    if(!mess_ready){
        if(byte_cnt < (expected_length - 1U)){
            pointer_to_save[byte_cnt] = ReadHwDrBuffer(SPI2);
            byte_cnt++;
        }
        else if(byte_cnt == (expected_length - 1U)){
            pointer_to_save[byte_cnt] = ReadHwDrBuffer(SPI2);
            byte_cnt = 0U;
            mess_ready = true;
#ifndef _UNIT_TEST
            SPI2->CR2 &= ~(SPI_CR2_RXNEIE);
#endif
            Spi2_RxCompleteCbk();
        }
        else{
            /* Error handling */
            byte_cnt = 0U;
        }
    }
    UT_GO_TO_NEXT_SAMPLE();
}