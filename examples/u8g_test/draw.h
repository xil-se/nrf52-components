#ifndef _DRAW_H
#define _DRAW_H

#include "u8g/u8g.h"

void u8g_prepare(void);
void u8g_box_frame(uint8_t x);
void u8g_string(uint8_t x);
void u8g_line(uint8_t x);
void u8g_ascii_1(void);
void u8g_ascii_2(void);
void u8g_logo(void);

#endif //_DRAW_H