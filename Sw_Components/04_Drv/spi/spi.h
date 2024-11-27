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

typedef struct
{
    SPI_TypeDef* instance;
    Spi_Mode_T mode;
    uint8_t int_priority; /* priority of interrupt - leave empty if not used */
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
void SpiReadIt(SPI_TypeDef *instance, uint8_t *dest_ptr, uint32_t mess_len);

void Spi1_RxCompleteCbk(void);
void Spi2_RxCompleteCbk(void);
void Spi3_RxCompleteCbk(void);
void SPI1_IRQHandler(void);
void SPI2_IRQHandler(void);
void SPI3_IRQHandler(void);

#endif /* SPI_H */

