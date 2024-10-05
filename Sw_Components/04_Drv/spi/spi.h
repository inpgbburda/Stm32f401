/**
* File contains Spi interface
*
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
    Exported types declarations
|===================================================================================================================================|
*/
typedef struct
{
    SPI_TypeDef* instance;
    uint16_t dff;    /* frame format - 8 or 16 bit */
    uint16_t clock_polarity; /* clock_polarity */
    uint16_t clock_phase;    /* clock_phase */
    uint16_t lsb_first;      /* bit order */
    uint16_t ssm;    /* configure NSS (chip select) pin behaviour - hw or sw*/
    uint16_t ssoe;   /* NSS as output */
    uint16_t mstr;   /* master or slave selection*/
    uint16_t frf;    /* frame format - Motorola or TI*/
    uint16_t spe;    /* enable spi */
}
Spi_Cfg_T;


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
void SpiInit(const Spi_Cfg_T* config);

uint16_t SpiReadBuffer(const SPI_TypeDef* instance);

Std_Return_T SpiReadSynch(const SPI_TypeDef *instance, uint8_t* dest_ptr, uint32_t mess_len, uint32_t timeout);

#endif /* SPI_H */

