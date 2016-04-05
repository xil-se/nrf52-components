ROOT=../..

# Put dependencies you want to include and build here
include $(ROOT)/drivers/hd44780/Makefile.mk


C_SOURCE_FILES += $(NRF52_SDK)/components/drivers_nrf/delay/nrf_delay.c
C_SOURCE_FILES += main.c

INC_PATHS += -I$(NRF52_SDK)/components/drivers_nrf/delay


# Make sure your linker script is corretly configures
LINKER_SCRIPT = hd44780_gcc_nrf52.ld


include $(ROOT)/Makefile.binary

# Put CFLAGS and LDFLAGS here so they get precedence over the default flags
CFLAGS  +=
LDFLAGS +=
