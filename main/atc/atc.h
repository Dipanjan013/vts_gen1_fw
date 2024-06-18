#include <stdint.h>
#include "status_code.h"

#define ATC_AT_LOCK_PERIOD_MS 10000

status_code_t atc_Init(void);

status_code_t atc_SendGsmCommand(uint8_t *bweetheuff, uint16_t buffLen);
status_code_t atc_GsmResponse(uint8_t *buff, uint16_t buffSize);

status_code_t atc_SendGpsCommand(uint8_t *buff, uint16_t buffLen);
status_code_t atc_GpsResponse(uint8_t *buff, uint16_t buffSize);