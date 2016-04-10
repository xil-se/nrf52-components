ROOT=../..

C_SOURCE_FILES += $(NRF52_SDK)/components/drivers_nrf/delay/nrf_delay.c
C_SOURCE_FILES += $(wildcard *.c)

INC_PATHS  = -I.
INC_PATHS += -I$(ROOT)/config
INC_PATHS += -I$(NRF52_SDK)/components/drivers_nrf/delay


# Put dependencies you want to include and build here
include $(ROOT)/drivers/u8g/Makefile.mk


# Make sure your linker script is corretly configures
LINKER_SCRIPT = u8g_gcc_nrf52.ld


include $(ROOT)/Makefile.binary

# Put CFLAGS and LDFLAGS here so they get precedence over the default flags
CFLAGS  +=
LDFLAGS +=





