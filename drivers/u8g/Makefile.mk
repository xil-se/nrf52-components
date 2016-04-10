# Include me in your Makefile to build and add includes
# Don't forget to set a correct ROOT

C_SOURCE_FILES +=                                            \
$(NRF52_SDK)/components/drivers_nrf/delay/nrf_delay.c        \
$(NRF52_SDK)/components/drivers_nrf/common/nrf_drv_common.c  \
$(NRF52_SDK)/components/drivers_nrf/gpiote/nrf_drv_gpiote.c  \
$(NRF52_SDK)/components/drivers_nrf/spi_master/nrf_drv_spi.c \
$(wildcard $(ROOT)/drivers/u8g/*.c)                          \
$(wildcard $(ROOT)/drivers/u8g/u8glib/csrc/*.c)              \
$(wildcard $(ROOT)/drivers/u8g/u8glib/fntsrc/*.c)            \


INC_PATHS += -I$(NRF52_SDK)/components/toolchain/gcc
INC_PATHS += -I$(NRF52_SDK)/components/toolchain
INC_PATHS += -I$(ROOT)/drivers/u8g
INC_PATHS += -I$(ROOT)/drivers/u8g/u8glib/csrc
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

