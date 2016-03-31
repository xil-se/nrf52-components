/** @file
 *
 * @defgroup u8g_example main.c
 * @{
 * @ingroup u8g_example
 * @brief u8glib Example integration main file.
 *
 */

#include <stdio.h>

#include "nrf_delay.h"

#include "u8g/u8g.h"
#include "u8g/u8g_arm.h"
#include "draw.h"

u8g_t u8g;

int draw_state = 0;

void draw_hello(void)
{
    char s[32];
    sprintf(s, "Hello! %d", draw_state);
    u8g_DrawStr(&u8g, 20,20, s);
}

void draw(void) {
  u8g_prepare();
  switch(draw_state % 7) {
    case 0: draw_hello(); break;
    case 1: u8g_box_frame(draw_state&7); break;
    case 2: u8g_string(draw_state&7); break;
    case 3: u8g_line(draw_state&7); break;
    case 4: u8g_ascii_1(); break;
    case 5: u8g_ascii_2(); break;
    case 6: u8g_logo(); break;
  }
}

/**
 * @brief Function for application main entry.
 */
int main(void)
{
    // Init u8g
    u8g_InitComFn(&u8g, &u8g_dev_pcd8544_84x48_hw_spi, u8g_com_hw_spi_fn);

    // Flip screen if needed
    u8g_SetRot180(&u8g);

    for (;;)
    {
        /* picture loop */
        u8g_FirstPage(&u8g);
        do
        {
            draw();
        } while (u8g_NextPage(&u8g));

        draw_state++;

        /* refresh screen after some delay */
        u8g_Delay(&u8g, 1000);
    }
}


/** @} */
