ROOT=../..

C_SOURCE_FILES += $(wildcard *.c)

INC_PATHS  = -I.

# Put dependencies you want to include and build here
include $(ROOT)/platform/hal.mk
include $(ROOT)/platform/uart.mk


C_SOURCE_FILES += $(NRF5_SDK)/components/drivers_nrf/delay/nrf_delay.c
C_SOURCE_FILES += $(wildcard *.c)

INC_PATHS += -I$(NRF5_SDK)/components/drivers_nrf/delay


# Make sure your linker script is corretly configures
LINKER_SCRIPT = uart_gcc_nrf52.ld


include $(ROOT)/Makefile.binary

# Put CFLAGS and LDFLAGS here so they get precedence over the default flags
CFLAGS  +=
LDFLAGS +=
