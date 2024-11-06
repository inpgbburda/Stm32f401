#include <stdbool.h>
#include <stdint.h>

typedef enum
{
    SPI_HELPER_DRV_1 = 0,
    SPI_HELPER_DRV_2,
    SPI_HELPER_DRV_3,
    SPI_HELPER_DRV_MAX
}
SpiHelper_Driver_T;

/* Api called from tested source file */
bool SpiHelper_ReadRxNeFlagMock(void);
uint8_t SpiHelper_ReadDrMock(void);
void SpiHelper_GoToNextSample(void);

/* Api called from test file to control used mocks*/
void SpiHelper_SetTestPreCondMess(uint8_t mess[], int len);
void SpiHelper_SetTestPreCondFlags( bool flags[], int len);
void SpiHelper_ResetReadIdx(void);
void SpiHelper_ResetBuffer(uint8_t buffer[], int len);
bool SpiHelper_CheckIf_RxCompleteCbkCalled(SpiHelper_Driver_T driver);
void SpiHelper_Clear_RxCompleteCbkStatuses(void);

/* Other functions called from test file - provided for readability */
void SpiHelper_SetupTest(uint8_t* injected_message, bool* injected_flags, int len);