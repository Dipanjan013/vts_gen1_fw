#ifndef _PORT_UART_H_
#define _PORT_UART_H_

#include <stdint.h>
#include "status_code.h"
#include "config.h"

status_code_t port_uart_Init(void);

status_code_t port_uart_Transmit(uint8_t uartNum, char *txData, uint16_t txDataLen);

status_code_t port_uart_Receive(uint8_t uartNum, char *rxBuff, uint16_t rxBuffSize, uint32_t timeout_ms);

status_code_t
#endif /*_PORT_UART_H_*/