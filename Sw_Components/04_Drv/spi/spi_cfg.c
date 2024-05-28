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

const Spi_Cfg_T Spi2_Config =
{
    SPI2,
    SPI_CR1_DFF,            /* 16 bit format */
    SPI_CR1_CPOL,           /* high state as idle */
    SPI_CR1_CPHA,           /* second edge latching */
    SPI_CR1_MSB_FIRST,
    SPI_CR1_SSM_HW,         /* hw slave select*/
    SPI_CR2_SSOE_DIS,       /* disable slave select output */
    SPI_CR1_MSTR_SLAVE,     /* MOSI pin is a data input */
    SPI_CR2_MOT_MODE,       /* motorola mode */
    SPI_CR1_SPE             /* enable spi */
};