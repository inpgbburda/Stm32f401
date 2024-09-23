#include <stdbool.h>
#include <stdint.h>

bool ReadRxNeFlagMock(void);
uint8_t ReadDrMock(void);

void SetTestPreConditionsMessage(uint8_t mess[], int len);
void SetTestConditionsFlags( bool flags[], int len);
void ResetMocks(void);