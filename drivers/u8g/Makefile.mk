# Include me in your Makefile to build and add includes
# Don't forget to set a correct ROOT

include $(ROOT)/platform/hal.mk
include $(ROOT)/platform/delay.mk


C_SOURCE_FILES +=                                            \
$(wildcard $(ROOT)/drivers/u8g/*.c)                          \
$(wildcard $(ROOT)/external/u8glib/csrc/*.c)                 \
$(wildcard $(ROOT)/external/u8glib/fntsrc/*.c)               \


INC_PATHS += -I$(ROOT)/drivers/u8g
INC_PATHS += -I$(ROOT)/external/u8glib/csrc

