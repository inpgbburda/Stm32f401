/**
* File contains configuration of SPI
*
*/
#ifndef SPI_H_CFG
#define SPI_H_CFG

#include "spi.h"

extern Spi_Storage_T Spi_Storage;
extern const Spi_Cfg_T Spi2_It_Config;

extern void Spi2_RxCompleteCbk(void);

#endif /* SPI_H_CFG */
