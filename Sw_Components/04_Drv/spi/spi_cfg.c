/**
* @file spi_cfg.c
* @brief Configuration source file for SPI driver.
*
* This file contains the configuration definitions for the SPI driver.
*
*/

/*
|===================================================================================================================================|
    File includes 
|===================================================================================================================================|
*/
#include "spi_cfg.h"
#include "stm32f401xc.h"

/*
|===================================================================================================================================|
    Macro definitions
|===================================================================================================================================|
*/
#define SPI_CR1_MSB_FIRST 0U
#define SPI_CR1_DFF_8_BIT 0U
#define SPI_CR1_CPOL_LOW_IDLE 0U
#define SPI_CR1_CPHA_FIRST_EDGE 0U
#define SPI_CR1_MSTR_SLAVE 0U
#define SPI_CR2_MOT_MODE 0U
#define SPI_CR1_SSM_HW 0U
#define SPI_CR2_SSOE_DIS 0U

#define SPI2_INTER_PRIO 0x07U

/*
|===================================================================================================================================|
    Object allocations 
|===================================================================================================================================|
*/
const Spi_Cfg_T Spi2_It_Config =
{
    SPI2,
    SPI_MODE_INTERRUPT,
    SPI2_INTER_PRIO,
    &Spi2_RxCompleteCbk,

    SPI_CR1_DFF_8_BIT,       /* 8 bit format of data frame*/
    SPI_CR1_CPOL_LOW_IDLE,   /* low sck state as idle */
    SPI_CR1_CPHA_FIRST_EDGE, /* first edge of sck as latching */
    SPI_CR1_MSB_FIRST,
    SPI_CR1_SSM_HW,          /* hw slave select*/
    SPI_CR2_SSOE_DIS,        /* disable slave select output */
    SPI_CR1_MSTR_SLAVE,      /* MOSI pin is a data input */
    SPI_CR2_MOT_MODE,        /* motorola mode */
};