/** @file
 *
 * @defgroup hd44780_example main.c
 * @{
 * @ingroup hd44780_example
 * @brief hd44780 Example Application main file.
 *
 */

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include "app_uart.h"
#include "app_error.h"
#include "nrf_delay.h"
#include "nrf.h"
#include "nrf_uart.h"
#include "nrf_drv_config.h"


#define UART_TX_BUF_SIZE 256                         /**< UART TX buffer size. */
#define UART_RX_BUF_SIZE 1                           /**< UART RX buffer size. */

void uart_error_handle(app_uart_evt_t * p_event)
{
    if (p_event->evt_type == APP_UART_COMMUNICATION_ERROR)
    {
        APP_ERROR_HANDLER(p_event->data.error_communication);
    }
    else if (p_event->evt_type == APP_UART_FIFO_ERROR)
    {
        APP_ERROR_HANDLER(p_event->data.error_code);
    }
}


/**
 * @brief Function for application main entry.
 */
int main(void)
{
    uint32_t err_code;
    (void)err_code;

    const app_uart_comm_params_t comm_params =
    {
        UART0_CONFIG_PSEL_RXD,
        UART0_CONFIG_PSEL_TXD,
        UART0_CONFIG_PSEL_CTS,
        UART0_CONFIG_PSEL_RTS,
        APP_UART_FLOW_CONTROL_DISABLED,
        false,
        UART_BAUDRATE_BAUDRATE_Baud115200
    };

    APP_UART_FIFO_INIT(&comm_params,
                       UART_RX_BUF_SIZE,
                       UART_TX_BUF_SIZE,
                       uart_error_handle,
                       APP_IRQ_PRIORITY_LOW,
                       err_code);

    while (1)
    {
        uint8_t cr;

        while(app_uart_get(&cr) != NRF_SUCCESS);
        while(app_uart_put(cr) != NRF_SUCCESS);
    }
}


/** @} */
