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

#include "u8g/u8g.h"
#include "u8g/u8g_arm.h"

static u8g_t u8g;



void u8g_prepare(void) {
  u8g_SetFont(&u8g, u8g_font_6x10);
  u8g_SetFontRefHeightExtendedText(&u8g);
  u8g_SetDefaultForegroundColor(&u8g);
  u8g_SetFontPosTop(&u8g);
}

void u8g_box_frame(uint8_t a) {
  u8g_DrawStr(&u8g, 0, 0, "drawBox");
  u8g_DrawBox(&u8g, 5,10,20,10);
  u8g_DrawBox(&u8g, 10+a,15,30,7);
  u8g_DrawStr(&u8g, 0, 30, "drawFrame");
  u8g_DrawFrame(&u8g, 5,10+30,20,10);
  u8g_DrawFrame(&u8g, 10+a,15+30,30,7);
}

void u8g_string(uint8_t a) {
  u8g_DrawStr(&u8g, 30+a,31, " 0");
  u8g_DrawStr90(&u8g, 30,31+a, " 90");
  u8g_DrawStr180(&u8g, 30-a,31, " 180");
  u8g_DrawStr270(&u8g, 30,31-a, " 270");
}

void u8g_line(uint8_t a) {
  u8g_DrawStr(&u8g, 0, 0, "drawLine");
  u8g_DrawLine(&u8g, 7+a, 10, 40, 55);
  u8g_DrawLine(&u8g, 7+a*2, 10, 60, 55);
  u8g_DrawLine(&u8g, 7+a*3, 10, 80, 55);
  u8g_DrawLine(&u8g, 7+a*4, 10, 100, 55);
}

void u8g_ascii_1(void) {
  char s[2] = " ";
  uint8_t x, y;
  u8g_DrawStr(&u8g, 0, 0, "ASCII page 1");
  for( y = 0; y < 6; y++ ) {
    for( x = 0; x < 16; x++ ) {
      s[0] = y*16 + x + 32;
      u8g_DrawStr(&u8g, x*7, y*10+10, s);
    }
  }
}

void u8g_ascii_2(void) {
  char s[2] = " ";
  uint8_t x, y;
  u8g_DrawStr(&u8g, 0, 0, "ASCII page 2");
  for( y = 0; y < 6; y++ ) {
    for( x = 0; x < 16; x++ ) {
      s[0] = y*16 + x + 160;
      u8g_DrawStr(&u8g, x*7, y*10+10, s);
    }
  }
}


uint8_t draw_state = 0;

void draw(void) {
  u8g_prepare();
  switch(draw_state >> 3) {
    case 0: u8g_box_frame(draw_state&7); break;
    case 1: u8g_string(draw_state&7); break;
    case 2: u8g_line(draw_state&7); break;
    case 3: u8g_ascii_1(); break;
    case 4: u8g_ascii_2(); break;
  }
}

void draw_hello(void)
{
    static int i = 0;
    char s[32];
    sprintf(s, "Hello! %4d", i++);
    u8g_SetFont(&u8g,u8g_font_profont10);//set current font
    u8g_DrawStr(&u8g, 2, 12, s);//write string - you set coordinates and string
    u8g_DrawBox(&u8g, 30, 30, 35, 35);//draw some box
}


/**
 * @brief Function for application main entry.
 */
int main(void)
{
    int i = 0;
    int draw_state = 0;

    // Init u8g
    u8g_InitComFn(&u8g, &u8g_dev_pcd8544_84x48_hw_spi, u8g_com_hw_spi_fn);

    // Flip screen
    u8g_SetRot180(&u8g);


    for (;;i++)
    {
        /* picture loop */
        u8g_FirstPage(&u8g);
        do
        {
            //draw();
            draw_hello();
        } while (u8g_NextPage(&u8g));

        draw_state++;
        if (draw_state >= 5*8) {
            draw_state = 0;
        }

        /* refresh screen after some delay */
        u8g_Delay(&u8g, 100);
    }
}


/** @} */
