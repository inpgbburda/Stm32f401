/**
* File contains configuration of SPI
*
*/

#include "spi_cfg.h"
#include "stm32f401xc.h"

#define SPI_CR1_MSB_FIRST 0U
#define SPI_CR1_MSTR_SLAVE 0U
#define SPI_CR2_MOT_MODE 0U
#define SPI_CR1_SSM_HW 0U
#define SPI_CR2_SSOE_DIS 0U

Spi_Cfg_T Spi_Config =
{
    SPI2,
    SPI_CR1_DFF,            /* 16 bit format */
    SPI_CR1_CPOL,
    SPI_CR1_CPHA,
    SPI_CR1_MSB_FIRST,
    SPI_CR1_SSM_HW,
    SPI_CR2_SSOE_DIS,
    SPI_CR1_MSTR_SLAVE,     /* MOSI pin is a data input */
    SPI_CR2_MOT_MODE,       /* Choose motorola mode */
    SPI_CR1_SPE             /* enable spi */
};