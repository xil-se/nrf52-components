ROOT=../..

C_SOURCE_FILES += $(wildcard *.c)

INC_PATHS  = -I.
INC_PATHS += -I$(ROOT)/config

# Put dependencies you want to include and build here
include $(ROOT)/drivers/u8g/Makefile.mk
include $(ROOT)/platform/hal.mk
include $(ROOT)/platform/spi.mk
include $(ROOT)/platform/uart.mk
include $(ROOT)/platform/delay.mk


C_SOURCE_FILES += $(wildcard *.c)


# Make sure your linker script is corretly configures
LINKER_SCRIPT = uart_gcc_nrf52.ld


include $(ROOT)/Makefile.binary

# Put CFLAGS and LDFLAGS here so they get precedence over the default flags
CFLAGS  +=
LDFLAGS +=
