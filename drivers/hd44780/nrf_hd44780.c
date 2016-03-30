// Based on https://devzone.nordicsemi.com/question/58042/lcd-display-driver/?answer=58611#post-id-58611

#include "nrf_hd44780.h"
#include "nrf_delay.h"
#include "nrf_gpio.h"

void lcd_output_upper(uint8_t data)
{
    if(data & 0x80) nrf_gpio_pin_set(LCD_PIN_B7);
    else nrf_gpio_pin_clear(LCD_PIN_B7);
    if(data & 0x40) nrf_gpio_pin_set(LCD_PIN_B6);
    else nrf_gpio_pin_clear(LCD_PIN_B6);
    if(data & 0x20) nrf_gpio_pin_set(LCD_PIN_B5);
    else nrf_gpio_pin_clear(LCD_PIN_B5);
    if(data & 0x10) nrf_gpio_pin_set(LCD_PIN_B4);
    else nrf_gpio_pin_clear(LCD_PIN_B4);
}

void lcd_write8(uint8_t data)
{
    lcd_output_upper(data);
    LCD_PULSE_CLOCK;
    lcd_output_upper(data << 4);
    LCD_PULSE_CLOCK;
}

void lcd_enable_4bit_mode(bool two_line_display, bool big_characters)
{
    uint8_t cmd_byte = LCD_CMD_FUNCTION_SET;
    cmd_byte |= (two_line_display ? 0x08 : 0x00);
    cmd_byte |= (big_characters ? 0x04 : 0x00);

    lcd_write8(cmd_byte);

    nrf_delay_us(40);
}

void lcd_clear_display()
{
    LCD_REGISTER_SELECT_COMMAND;
    lcd_write8(0x01);
    nrf_delay_us(5000);
}

void lcd_on_off_control(bool on, bool cursor_on, bool cursor_blink)
{
    LCD_REGISTER_SELECT_COMMAND;
    lcd_write8(0x08 | (on ? 0x04 : 0x00) | (cursor_on ? 0x02 : 0x00) | (cursor_blink ? 0x01 : 0x00));
    nrf_delay_us(50);
}

void lcd_set_cgram_address(uint8_t addr)
{
    LCD_REGISTER_SELECT_COMMAND;
    lcd_write8(0x40 | (addr & 0x3F));
    nrf_delay_us(37);
}

void lcd_set_ddram_address(uint8_t addr)
{
    LCD_REGISTER_SELECT_COMMAND;
    lcd_write8(0x80 | (addr & 0x7F));
    nrf_delay_us(37);
}

void lcd_write_string(char *string, uint32_t pos, bool lower_line)
{
    lcd_set_ddram_address(pos + (lower_line ? 0x40 : 0x00));
    while(*string)
    {
        LCD_REGISTER_SELECT_DATA;
        lcd_write8(*string++);
        nrf_delay_us(37);
    }
}

void lcd_init()
{
    nrf_gpio_range_cfg_output(LCD_PIN_BASE, LCD_PIN_BASE+5);

    nrf_delay_us(15000);

    nrf_gpio_pin_clear(LCD_PIN_RS);  // Register select command
    nrf_gpio_pin_clear(LCD_PIN_CLK); // CLK idle
}
