# Include me in your Makefile to build and add includes
# Don't forget to set a correct ROOT

C_SOURCE_FILES += $(NRF5_SDK)/components/drivers_nrf/delay/nrf_delay.c

INC_PATHS += -I$(NRF5_SDK)/components/drivers_nrf/delay

