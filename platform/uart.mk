# Include me in your Makefile to build and add includes
# Don't forget to set a correct ROOT

C_SOURCE_FILES += $(NRF5_SDK)/components/drivers_nrf/common/nrf_drv_common.c
C_SOURCE_FILES += $(NRF5_SDK)/components/drivers_nrf/uart/nrf_drv_uart.c
C_SOURCE_FILES += $(NRF5_SDK)/components/libraries/uart/app_uart.c
C_SOURCE_FILES += $(NRF5_SDK)/components/libraries/util/app_util_platform.c
C_SOURCE_FILES += $(NRF5_SDK)/components/libraries/util/app_error.c

INC_PATHS += -I$(NRF5_SDK)/components/libraries/uart
INC_PATHS += -I$(NRF5_SDK)/components/libraries/util

INC_PATHS += -I$(NRF5_SDK)/components/drivers_nrf/uart
INC_PATHS += -I$(NRF5_SDK)/components/drivers_nrf/gpiote
INC_PATHS += -I$(NRF5_SDK)/components/drivers_nrf/nrf_soc_nosd/
INC_PATHS += -I$(NRF5_SDK)/components/drivers_nrf/config/
INC_PATHS += -I$(NRF5_SDK)/components/drivers_nrf/common/

#INC_PATHS += -I$(NRF5_SDK)/components/libraries/util


