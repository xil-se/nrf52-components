/** @file
 *
 * @defgroup hd44780_example main.c
 * @{
 * @ingroup hd44780_example
 * @brief hd44780 Example Application main file.
 *
 */

#include <stdio.h>
#include "nrf_delay.h"
#include "nrf_hd44780.h"

/**
 * @brief Function for application main entry.
 */
int main(void)
{
    char _s[32];
    int j = 0;

    // Init the LCD
    lcd_init();
    lcd_enable_4bit_mode(true, true);
    lcd_on_off_control(true, false, false);
    lcd_clear_display();

    while (true)
    {
        j++;
        sprintf(_s, "Count: %d", j);
        lcd_write_string("Hello world!", 2, false);
        lcd_write_string((char*)_s, 0, true);
        nrf_delay_ms(200);
    }
}


/** @} */
