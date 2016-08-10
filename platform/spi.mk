# Include me in your Makefile to build and add includes
# Don't forget to set a correct ROOT

C_SOURCE_FILES += $(NRF5_SDK)/components/drivers_nrf/common/nrf_drv_common.c
C_SOURCE_FILES += $(NRF5_SDK)/components/drivers_nrf/spi_master/nrf_drv_spi.c


INC_PATHS += -I$(NRF5_SDK)/components/drivers_nrf/nrf_soc_nosd
INC_PATHS += -I$(NRF5_SDK)/components/drivers_nrf/config
INC_PATHS += -I$(NRF5_SDK)/components/drivers_nrf/spi_master
INC_PATHS += -I$(NRF5_SDK)/components/drivers_nrf/common
INC_PATHS += -I$(NRF5_SDK)/components/libraries/util


