//! Includes
#include "driver/uart.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "port_uart.h"

//! defines
#define ECHO_TEST_RTS (UART_PIN_NO_CHANGE)
#define ECHO_TEST_CTS (UART_PIN_NO_CHANGE)

// structure/global variables
static const uart_config_t uart0Config = {
    .baud_rate = 9600,
    .data_bits = UART_DATA_8_BITS,
    .parity = UART_PARITY_DISABLE,
    .stop_bits = UART_STOP_BITS_1,
    .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
    .source_clk = UART_SCLK_DEFAULT,
};

static const uart_config_t uart1Config = {
    .baud_rate = 9600,
    .data_bits = UART_DATA_8_BITS,
    .parity = UART_PARITY_DISABLE,
    .stop_bits = UART_STOP_BITS_1,
    .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
    .source_clk = UART_SCLK_DEFAULT,
};

// function prototypes
static uint8_t ConfigUartNum(uint8_t uartNum, uart_config_t *pUartConfig, uint8_t txPin, uint8_t rxPin);

//===================================================================================================================//
static uint8_t ConfigUartNum(uint8_t uartNum, uart_config_t *pUartConfig, uint8_t txPin, uint8_t rxPin)
{
    if (ESP_OK != uart_driver_install((uart_port_t)uartNum, CONFIG_UART_BUFF_SIZE * 2, 0, 0, NULL, 0))
    {
        return 0;
    }
    if (ESP_OK != uart_param_config((uart_port_t)uartNum, pUartConfig))
    {
        return 0;
    }
    if (ESP_OK != uart_set_pin((uart_port_t)uartNum, txPin, rxPin, ECHO_TEST_RTS, ECHO_TEST_CTS))
    {
        return 0;
    }
    return 1;
}

status_code_t port_uart_Init(uint8_t uartNum)
{
    if (!ConfigUartNum(CONFIG_UART_NUM0, &uart0Config, CONFIG_UART_NUM0_TX_PIN, CONFIG_UART_NUM0_RX_PIN))
    {
        return STATUS_FAIL;
    }
    if (!ConfigUartNum(CONFIG_UART_NUM1, &uart1Config, CONFIG_UART_NUM1_TX_PIN, CONFIG_UART_NUM1_RX_PIN))
    {
        return STATUS_FAIL;
    }
    return STATUS_OK;
}

status_code_t port_uart_Transmit(uint8_t uartNum, char *txData, uint16_t txDataLen)
{
    uint16_t bytesSent = uart_write_bytes((uart_port_t)uartNum, txData, (size_t)txDataLen);
    if (bytesSent > 0)
    {
        return STATUS_OK;
    }
    return STATUS_FAIL;
}

status_code_t port_uart_Receive(uint8_t uartNum, char *rxBuff, uint16_t rxBuffSize, uint32_t timeout_ms)
{
    uint16_t bytesRecvd = uart_read_bytes((uart_port_t)uartNum, rxBuff, (CONFIG_UART_BUFF_SIZE - 1), (timeout_ms / portTICK_PERIOD_MS));
    if (bytesRecvd > 0)
    {
        return STATUS_OK;
    }
    return STATUS_FAIL;
}

status_code_t port_uart_Deinit(uint8_t uartNum)
{
    if (ESP_OK != uart_driver_delete((uart_port_t)uartNum))
    {
        return STATUS_FAIL;
    }
    return STATUS_OK;
}