#include "u8g/u8g.h"

extern u8g_t u8g;

// Just a bunch of demo draw code

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

// logo


/* select, which color background to use  */
#define COLOR_BOX draw_color_box2

void draw_color_box1(void)
{
  u8g_uint_t w,h;
  u8g_uint_t r, g, b;

  w = u8g_GetWidth(&u8g)/64;
  h = u8g_GetHeight(&u8g)/32;
  for( b = 0; b < 4; b++ )
    for( g = 0; g < 16; g++ )
      for( r = 0; r < 32; r++ )
      {
	u8g_SetRGB(&u8g, r<<3, g<<4, b<<6);
	u8g_DrawBox(&u8g, g*w + b*w*16, r*h, w, h);

      }
}

void draw_color_box2(void)
{
  u8g_uint_t w,h;
  u8g_uint_t r, g, b;

  b = 1;

  w = u8g_GetWidth(&u8g)/64;
  h = u8g_GetHeight(&u8g)/32;
    for( g = 0; g < 16; g++ )
      for( r = 0; r < 32; r++ )
      {
	u8g_SetRGB(&u8g, r<<3, g<<4, b<<6);
	u8g_DrawBox(&u8g, g*w + 0*w*16, r*h, w, h);
	u8g_DrawBox(&u8g, (16-1-g)*w + 1*w*16, r*h, w, h);
	u8g_DrawBox(&u8g, g*w + 2*w*16, r*h, w, h);
	u8g_DrawBox(&u8g, (16-1-g)*w + 3*w*16, r*h, w, h);

      }
}

void draw_color_box3(void)
{
    u8g_uint_t r, g, b;
    /* assumes 128x128 display */
    for( b = 0; b < 4; b++ )
    {
      for( g = 0; g < 32; g++ )
      {
	for( r = 0; r < 32; r++ )
	{
	  u8g_SetRGB(&u8g, r<<3, g<<3, b<<4 );
	  u8g_DrawPixel(&u8g, g + b*32, r);
	  u8g_SetRGB(&u8g, r<<3, g<<3, (b<<4)+64 );
	  u8g_DrawPixel(&u8g, g + b*32, r+32);
	  u8g_SetRGB(&u8g, r<<3, g<<3, (b<<4)+128 );
	  u8g_DrawPixel(&u8g, g + b*32, r+32+32);
	  u8g_SetRGB(&u8g, r<<3, g<<3, (b<<4)+128+64 );
	  u8g_DrawPixel(&u8g, g + b*32, r+32+32+32);
	}
      }
    }
}


void draw_logo(uint8_t d)
{
  u8g_SetFont(&u8g, u8g_font_gdr25r);
  u8g_DrawStr(&u8g, 0+d, 30+d, "U");
  u8g_SetFont(&u8g, u8g_font_gdr30n);
  u8g_DrawStr90(&u8g, 23+d,10+d,"8");
  u8g_SetFont(&u8g, u8g_font_gdr25r);
  u8g_DrawStr(&u8g, 53+d,30+d,"g");

  u8g_DrawHLine(&u8g, 2+d, 35+d, 47);
  u8g_DrawVLine(&u8g, 45+d, 32+d, 12);
}

void draw_url(void)
{
  u8g_SetFont(&u8g, u8g_font_4x6);
  if ( u8g_GetHeight(&u8g) < 59 )
  {
    u8g_DrawStr(&u8g, 53,9,"code.google.com");
    u8g_DrawStr(&u8g, 77,18,"/p/u8glib");
  }
  else
  {
    u8g_DrawStr(&u8g, 1,54,"code.google.com/p/u8glib");
  }
}

void u8g_logo(void)
{
  if ( u8g_GetMode(&u8g) == U8G_MODE_HICOLOR || u8g_GetMode(&u8g) == U8G_MODE_R3G3B2)
  {
    COLOR_BOX();
  }
  if ( u8g_GetMode(&u8g) == U8G_MODE_HICOLOR || u8g_GetMode(&u8g) == U8G_MODE_R3G3B2)
  {
      u8g_SetRGB(&u8g, 0x080, 0x040, 0);
      draw_logo(2);
      u8g_SetRGB(&u8g, 0x080, 0x080, 0);
      draw_logo(1);
      u8g_SetRGB(&u8g, 0x0ff, 0x0ff, 0);
  }
  else
  {
    u8g_SetColorIndex(&u8g, 1);
    if ( U8G_MODE_GET_BITS_PER_PIXEL(u8g_GetMode(&u8g)) > 1 )
    {
      draw_logo(2);
      u8g_SetColorIndex(&u8g, 2);
      draw_logo(1);
      u8g_SetColorIndex(&u8g, 3);
    }
  }
  draw_logo(0);
  draw_url();
}
