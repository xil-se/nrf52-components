ROOT=../..

# Put dependencies you want to include and build here
include $(ROOT)/platform/delay.mk
include $(ROOT)/drivers/hd44780/Makefile.mk


C_SOURCE_FILES += $(wildcard *.c)

INC_PATHS +=


# Make sure your linker script is corretly configured
LINKER_SCRIPT = hd44780_gcc_nrf52.ld


include $(ROOT)/Makefile.binary

# Put CFLAGS and LDFLAGS here so they get precedence over the default flags
CFLAGS  +=
LDFLAGS +=
