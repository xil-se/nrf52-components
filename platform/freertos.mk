# Include me in your Makefile to build and add includes
# Don't forget to set a correct ROOT

C_SOURCE_FILES += $(NRF5_SDK)/external/freertos/source/croutine.c
C_SOURCE_FILES += $(NRF5_SDK)/external/freertos/source/event_groups.c
C_SOURCE_FILES += $(NRF5_SDK)/external/freertos/source/portable/MemMang/heap_1.c
C_SOURCE_FILES += $(NRF5_SDK)/external/freertos/source/list.c
C_SOURCE_FILES += $(NRF5_SDK)/external/freertos/portable/GCC/nrf52/port.c
C_SOURCE_FILES += $(NRF5_SDK)/external/freertos/portable/CMSIS/nrf52/port_cmsis.c
C_SOURCE_FILES += $(NRF5_SDK)/external/freertos/portable/CMSIS/nrf52/port_cmsis_systick.c
C_SOURCE_FILES += $(NRF5_SDK)/external/freertos/source/queue.c
C_SOURCE_FILES += $(NRF5_SDK)/external/freertos/source/tasks.c
C_SOURCE_FILES += $(NRF5_SDK)/external/freertos/source/timers.c



INC_PATHS += -I$(NRF5_SDK)/external/freertos/portable/GCC/nrf52
INC_PATHS += -I$(NRF5_SDK)/external/freertos/portable/CMSIS/nrf52
INC_PATHS += -I$(NRF5_SDK)/external/freertos/source/include
INC_PATHS += -I$(NRF5_SDK)/external/freertos/config/

