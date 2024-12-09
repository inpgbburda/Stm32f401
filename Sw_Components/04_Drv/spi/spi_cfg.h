/**
* File contains configuration of SPI
*
*/
#ifndef SPI_H_CFG
#define SPI_H_CFG

#include "spi.h"

extern Spi_Storage_T spi_storage;
extern const Spi_Cfg_T Spi2_Config;

extern void Spi2_RxCompleteCbk(void);

#endif /* SPI_H_CFG */
