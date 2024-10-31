#include <stdbool.h>
#include <stdint.h>

/* Api called from tested source file */
bool SpiHelper_ReadRxNeFlagMock(void);
uint8_t SpiHelper_ReadDrMock(void);
void SpiHelper_GoToNextSample(void);

/* Api called from test file to control used mocks*/
void SpiHelper_SetTestPreCondMess(uint8_t mess[], int len);
void SpiHelper_SetTestPreCondFlags( bool flags[], int len);
void SpiHelper_ResetReadIdx(void);
void SpiHelper_ResetBuffer(uint8_t buffer[], int len);
bool SpiHelper_CheckIf_Spi2_RxCompleteCbkCalled(void);
void SpiHelper_Clear_Spi2_RxCompleteCbkStatus(void);

/* Other functions called from test file - provided for readability */
void SpiHelper_SetupTest(uint8_t* injected_message, bool* injected_flags, int len);