# Include me in your Makefile to build and add includes
# Don't forget to set a correct ROOT

C_SOURCE_FILES += $(ROOT)/drivers/hd44780/nrf_hd44780.c
C_SOURCE_FILES += $(NRF52_SDK)/components/drivers_nrf/delay/nrf_delay.c

INC_PATHS += -I$(ROOT)/drivers/hd44780
INC_PATHS += -I$(NRF52_SDK)/components/drivers_nrf/delay
INC_PATHS += -I$(NRF52_SDK)/components/drivers_nrf/hal

