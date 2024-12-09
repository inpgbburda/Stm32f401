#include <stdbool.h>
#include <stdint.h>
#include "stm32f401xc.h"

#include "spi.h"

/* Api called from tested source file */
bool SpiHelper_ReadRxNeFlagMock(const SPI_TypeDef* driver);
uint8_t SpiHelper_ReadDrMock(const SPI_TypeDef* driver);
void SpiHelper_GoToNextSample(const SPI_TypeDef* driver);

/* Api called from test file to control used mocks*/
void SpiHelper_SetTestPreCondMess(Spi_Instance_Id_T driver, uint8_t mess[], int len);
void SpiHelper_SetTestPreCondFlags(Spi_Instance_Id_T driver, bool flags[], int len);
void SpiHelper_ResetReadIdx(void);
void SpiHelper_ResetBuffer(uint8_t buffer[], int len);
bool SpiHelper_CheckIf_RxCompleteCbkCalled(Spi_Instance_Id_T driver);
void SpiHelper_Clear_RxCompleteCbkStatuses(void);

/* Other functions called from test file - provided for readability */
void SpiHelper_SetupTest(Spi_Instance_Id_T driver, uint8_t* injected_message, bool* injected_flags, int len);
void SpiHelper_CallHandlerNumberOfTimes(void (*handler)(void), uint32_t number);