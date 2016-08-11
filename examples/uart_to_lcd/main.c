/** @file
 *
 * @defgroup u8g_example main.c
 * @{
 * @ingroup u8g_example
 * @brief u8glib Example integration main file.
 *
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

#include "nrf_delay.h"
#include "app_uart.h"
#include "app_error.h"
#include "nrf_delay.h"
#include "nrf.h"
#include "nrf_uart.h"
#include "nrf_drv_config.h"

#include "u8g.h"
#include "u8g_arm.h"

#define UART_TX_BUF_SIZE 256                         /**< UART TX buffer size. */
#define UART_RX_BUF_SIZE 1                           /**< UART RX buffer size. */

u8g_t u8g;

#define LCD_WIDTH  14
#define LCD_LINES   5
char buf[LCD_WIDTH * LCD_LINES] = { 0 };
int uart_pos = 1;


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
    else if (p_event->evt_type == APP_UART_DATA)
    {
        // When we get a byte from UART, echo it and update our buffer.
        uint8_t chr;
        app_uart_get(&chr);
        app_uart_put(chr);
        if (chr == '\r') {
            uart_pos = (uart_pos + LCD_WIDTH) % sizeof(buf);
            uart_pos = uart_pos - (uart_pos % LCD_WIDTH);
        }
        else if (chr == '\b') {
            uart_pos = (uart_pos - 1) >= 0 ? (uart_pos - 1) : 0;
            buf[uart_pos] = ' ';
        }
        else {
            buf[uart_pos] = chr;
            uart_pos = (uart_pos + 1) % sizeof(buf);
        }
    }
}

// Had to fork this function to print fixed length string. There is probably a better API
// but I didn't feel like digging more in the u8g code, I'm lazy.
static u8g_uint_t u8g_DrawStrN(u8g_t *u8g, u8g_uint_t x, u8g_uint_t y, const char *s, int n)
{
    u8g_uint_t t = 0;
    int8_t d;

    y += u8g->font_calc_vref(u8g);

    while( n-- )
    {
        d = u8g_draw_glyph(u8g, x, y, *s);
        x += d;
        t += d;
        s++;
    }
    return t;
}

void u8g_prepare(void) {
  u8g_SetFont(&u8g, u8g_font_6x10);
  u8g_SetFontRefHeightExtendedText(&u8g);
  u8g_SetDefaultForegroundColor(&u8g);
  u8g_SetFontPosTop(&u8g);
}

// Simply draw five lines of text.
void draw(void) {
    int i;
    u8g_prepare();
    for (i = 0; i < 5; i++) {
        u8g_DrawStrN(&u8g, 0, i * 10, &buf[14 * i], 14);
    }
}

void init_uart() {
    uint32_t err_code;

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
}

/**
 * @brief Function for application main entry.
 */
int main(void)
{
    init_uart();
    buf[0] = '>';

    u8g_InitComFn(&u8g, &u8g_dev_pcd8544_84x48_hw_spi, u8g_com_hw_spi_fn);
    u8g_SetRot180(&u8g);

    for (;;)
    {
        u8g_FirstPage(&u8g);
        do
        {
            draw();
        } while (u8g_NextPage(&u8g));

        u8g_Delay(1);
    }
}


/** @} */
