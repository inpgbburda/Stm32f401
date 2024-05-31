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
    RCC->APB1ENR |= RCC_APB1ENR_SPI2EN; /* Enable clock for SPI2*/
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
