#include <stdbool.h>
#include <stdint.h>

#ifdef _UNIT_TEST
    #define UT_GO_TO_NEXT_SAMPLE() do { GoToNextSample(); } while (0)
#else
    #define UT_GO_TO_NEXT_SAMPLE() do {} while (0)
#endif


bool ReadRxNeFlagMock(void);
uint8_t ReadDrMock(void);

void GoToNextSample(void);
void SetTestPreConditionsMessage(uint8_t mess[], int len);
void SetTestConditionsFlags( bool flags[], int len);
void ResetReadIdx(void);
void ResetBuffer(uint8_t buffer[], int len);