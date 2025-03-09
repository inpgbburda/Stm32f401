/**
* @file spi_cfg.h
* @brief Configuration header for SPI driver.
*
* This file contains the configuration definitions for the SPI driver.
*
*/

#ifndef SPI_H_CFG
#define SPI_H_CFG

/*
|===================================================================================================================================|
    File includes 
|===================================================================================================================================|
*/
#include "spi.h"

/*
|===================================================================================================================================|
    Exported objects declarations
|===================================================================================================================================|
*/
extern const Spi_Cfg_T Spi2_It_Config;

extern void Spi2_RxCompleteCbk(void);

#endif /* SPI_H_CFG */
