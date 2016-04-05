# Include me in your Makefile to build and add includes
# Don't forget to set a correct ROOT

C_SOURCE_FILES += \
$(NRF52_SDK)/components/drivers_nrf/delay/nrf_delay.c \
$(NRF52_SDK)/components/drivers_nrf/common/nrf_drv_common.c \
$(NRF52_SDK)/components/drivers_nrf/gpiote/nrf_drv_gpiote.c \
$(NRF52_SDK)/components/drivers_nrf/spi_master/nrf_drv_spi.c \
$(ROOT)/drivers/u8g/u8g_arm.c \
$(ROOT)/drivers/u8g/u8g_bitmap.c \
$(ROOT)/drivers/u8g/u8g_circle.c \
$(ROOT)/drivers/u8g/u8g_clip.c \
$(ROOT)/drivers/u8g/u8g_com_api_16gr.c \
$(ROOT)/drivers/u8g/u8g_com_api.c \
$(ROOT)/drivers/u8g/u8g_com_i2c.c \
$(ROOT)/drivers/u8g/u8g_com_io.c \
$(ROOT)/drivers/u8g/u8g_com_null.c \
$(ROOT)/drivers/u8g/u8g_cursor.c \
$(ROOT)/drivers/u8g/u8g_delay.c \
$(ROOT)/drivers/u8g/u8g_dev_a2_micro_printer.c \
$(ROOT)/drivers/u8g/u8g_dev_flipdisc_2x7.c \
$(ROOT)/drivers/u8g/u8g_dev_gprof.c \
$(ROOT)/drivers/u8g/u8g_dev_ht1632.c \
$(ROOT)/drivers/u8g/u8g_dev_ili9325d_320x240.c \
$(ROOT)/drivers/u8g/u8g_dev_ks0108_128x64.c \
$(ROOT)/drivers/u8g/u8g_dev_lc7981_160x80.c \
$(ROOT)/drivers/u8g/u8g_dev_lc7981_240x128.c \
$(ROOT)/drivers/u8g/u8g_dev_lc7981_240x64.c \
$(ROOT)/drivers/u8g/u8g_dev_lc7981_320x64.c \
$(ROOT)/drivers/u8g/u8g_dev_ld7032_60x32.c \
$(ROOT)/drivers/u8g/u8g_dev_null.c \
$(ROOT)/drivers/u8g/u8g_dev_pcd8544_84x48.c \
$(ROOT)/drivers/u8g/u8g_dev_pcf8812_96x65.c \
$(ROOT)/drivers/u8g/u8g_dev_sbn1661_122x32.c \
$(ROOT)/drivers/u8g/u8g_dev_ssd1306_128x32.c \
$(ROOT)/drivers/u8g/u8g_dev_ssd1306_128x64.c \
$(ROOT)/drivers/u8g/u8g_dev_ssd1306_64x48.c \
$(ROOT)/drivers/u8g/u8g_dev_ssd1309_128x64.c \
$(ROOT)/drivers/u8g/u8g_dev_ssd1322_nhd31oled_bw.c \
$(ROOT)/drivers/u8g/u8g_dev_ssd1322_nhd31oled_gr.c \
$(ROOT)/drivers/u8g/u8g_dev_ssd1325_nhd27oled_bw.c \
$(ROOT)/drivers/u8g/u8g_dev_ssd1325_nhd27oled_bw_new.c \
$(ROOT)/drivers/u8g/u8g_dev_ssd1325_nhd27oled_gr.c \
$(ROOT)/drivers/u8g/u8g_dev_ssd1325_nhd27oled_gr_new.c \
$(ROOT)/drivers/u8g/u8g_dev_ssd1327_96x96_gr.c \
$(ROOT)/drivers/u8g/u8g_dev_ssd1351_128x128.c \
$(ROOT)/drivers/u8g/u8g_dev_ssd1353_160x128.c \
$(ROOT)/drivers/u8g/u8g_dev_st7565_64128n.c \
$(ROOT)/drivers/u8g/u8g_dev_st7565_dogm128.c \
$(ROOT)/drivers/u8g/u8g_dev_st7565_dogm132.c \
$(ROOT)/drivers/u8g/u8g_dev_st7565_lm6059.c \
$(ROOT)/drivers/u8g/u8g_dev_st7565_lm6063.c \
$(ROOT)/drivers/u8g/u8g_dev_st7565_nhd_c12832.c \
$(ROOT)/drivers/u8g/u8g_dev_st7565_nhd_c12864.c \
$(ROOT)/drivers/u8g/u8g_dev_st7687_c144mvgd.c \
$(ROOT)/drivers/u8g/u8g_dev_st7920_128x64.c \
$(ROOT)/drivers/u8g/u8g_dev_st7920_192x32.c \
$(ROOT)/drivers/u8g/u8g_dev_st7920_202x32.c \
$(ROOT)/drivers/u8g/u8g_dev_t6963_128x128.c \
$(ROOT)/drivers/u8g/u8g_dev_t6963_128x64.c \
$(ROOT)/drivers/u8g/u8g_dev_t6963_240x128.c \
$(ROOT)/drivers/u8g/u8g_dev_t6963_240x64.c \
$(ROOT)/drivers/u8g/u8g_dev_tls8204_84x48.c \
$(ROOT)/drivers/u8g/u8g_dev_uc1601_c128032.c \
$(ROOT)/drivers/u8g/u8g_dev_uc1608_240x128.c \
$(ROOT)/drivers/u8g/u8g_dev_uc1608_240x64.c \
$(ROOT)/drivers/u8g/u8g_dev_uc1610_dogxl160.c \
$(ROOT)/drivers/u8g/u8g_dev_uc1611_dogm240.c \
$(ROOT)/drivers/u8g/u8g_dev_uc1611_dogxl240.c \
$(ROOT)/drivers/u8g/u8g_dev_uc1701_dogs102.c \
$(ROOT)/drivers/u8g/u8g_dev_uc1701_mini12864.c \
$(ROOT)/drivers/u8g/u8g_ellipse.c \
$(ROOT)/drivers/u8g/u8g_font.c \
$(ROOT)/drivers/u8g/u8g_font_data.c \
$(ROOT)/drivers/u8g/u8g_line.c \
$(ROOT)/drivers/u8g/u8g_ll_api.c \
$(ROOT)/drivers/u8g/u8g_page.c \
$(ROOT)/drivers/u8g/u8g_pb14v1.c \
$(ROOT)/drivers/u8g/u8g_pb16h1.c \
$(ROOT)/drivers/u8g/u8g_pb16h2.c \
$(ROOT)/drivers/u8g/u8g_pb16v1.c \
$(ROOT)/drivers/u8g/u8g_pb16v2.c \
$(ROOT)/drivers/u8g/u8g_pb32h1.c \
$(ROOT)/drivers/u8g/u8g_pb8h1.c \
$(ROOT)/drivers/u8g/u8g_pb8h1f.c \
$(ROOT)/drivers/u8g/u8g_pb8h2.c \
$(ROOT)/drivers/u8g/u8g_pb8h8.c \
$(ROOT)/drivers/u8g/u8g_pb8v1.c \
$(ROOT)/drivers/u8g/u8g_pb8v2.c \
$(ROOT)/drivers/u8g/u8g_pb.c \
$(ROOT)/drivers/u8g/u8g_pbxh16.c \
$(ROOT)/drivers/u8g/u8g_pbxh24.c \
$(ROOT)/drivers/u8g/u8g_polygon.c \
$(ROOT)/drivers/u8g/u8g_rect.c \
$(ROOT)/drivers/u8g/u8g_rot.c \
$(ROOT)/drivers/u8g/u8g_scale.c \
$(ROOT)/drivers/u8g/u8g_state.c \
$(ROOT)/drivers/u8g/u8g_u16toa.c \
$(ROOT)/drivers/u8g/u8g_u8toa.c \
$(ROOT)/drivers/u8g/u8g_virtual_screen.c \


INC_PATHS += -I$(NRF52_SDK)/components/toolchain/gcc
INC_PATHS += -I$(NRF52_SDK)/components/toolchain
INC_PATHS += -I$(ROOT)/drivers/u8g
INC_PATHS += -I$(NRF52_SDK)/components/device
INC_PATHS += -I$(NRF52_SDK)/components/drivers_nrf/nrf_soc_nosd
INC_PATHS += -I$(NRF52_SDK)/components/drivers_nrf/delay
INC_PATHS += -I$(NRF52_SDK)/components/drivers_nrf/hal
INC_PATHS += -I$(NRF52_SDK)/components/drivers_nrf/config
INC_PATHS += -I$(NRF52_SDK)/components/drivers_nrf/spi_master
INC_PATHS += -I$(NRF52_SDK)/components/drivers_nrf/gpiote
INC_PATHS += -I$(NRF52_SDK)/components/drivers_nrf/common
INC_PATHS += -I$(NRF52_SDK)/components/libraries/util
INC_PATHS += -I$(NRF52_SDK)/components/libraries/timer
INC_PATHS += -I$(NRF52_SDK)/examples/bsp

