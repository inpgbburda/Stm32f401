/**
* File contains 
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
bool IsRxFlagSet(const SPI_TypeDef *instance);
uint8_t ReadHwDrBuffer(const SPI_TypeDef *instance);


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
    used_driver = config->instance;

    /* Clear register contents*/
    SPI2->CR1 = 0x0000U;
    SPI2->CR2 = 0x0000U;

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

Succes_T SpiReadSynch(const SPI_TypeDef *instance, uint8_t* dest_ptr, uint32_t mess_len, uint32_t timeout)
{
    Succes_T ret_val = RET_NOK;
    uint32_t byte_num = 0;
    uint32_t tick_cnt = 0;
    bool mess_ready = false;

    if((NULL == instance)||(NULL == dest_ptr)){
        return RET_NOK;
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
            ret_val = RET_OK;
        }
        tick_cnt++;
    }
    return ret_val;
}

bool IsRxFlagSet(const SPI_TypeDef *instance)
{
    bool result = false;
#ifndef _UNIT_TEST
    result = SPI_SR_RXNE_FLAG(instance->SR);
#else
    result = ReadRxNeFlagMock();
#endif
    return result;
}

uint8_t ReadHwDrBuffer(const SPI_TypeDef *instance)
{
    uint8_t result;

#ifndef _UNIT_TEST
    /*Reading this buffer also clears the RXNE flag*/
    result = instance->DR;
#else
    result = ReadDrMock();
#endif
    return result;
}