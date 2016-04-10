# Include me in your Makefile to build and add includes
# Don't forget to set a correct ROOT

include $(ROOT)/platform/hal.mk
include $(ROOT)/platform/delay.mk

C_SOURCE_FILES += $(ROOT)/drivers/hd44780/nrf_hd44780.c

INC_PATHS += -I$(ROOT)/drivers/hd44780

