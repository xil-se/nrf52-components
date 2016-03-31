PROJECT_NAME := hd44780_blank_pca10036

ifeq ("$(NRF52_SDK)","")
$(error Please set the enviroment variable NRF52_SDK to the root of the sdk)
endif

export OUTPUT_FILENAME
MAKEFILE_NAME := $(MAKEFILE_LIST)
MAKEFILE_DIR := $(dir $(MAKEFILE_NAME) )

TEMPLATE_PATH = $(NRF52_SDK)/components/toolchain/gcc
ifeq ($(OS),Windows_NT)
include $(TEMPLATE_PATH)/Makefile.windows
else
include $(TEMPLATE_PATH)/Makefile.posix
endif

MK := mkdir
RM := rm -rf

ifeq ("$(VERBOSE)","1")
NO_ECHO :=
else
NO_ECHO := @
endif

# Toolchain commands
CC              := '$(GNU_INSTALL_ROOT)/bin/$(GNU_PREFIX)-gcc'
AS              := '$(GNU_INSTALL_ROOT)/bin/$(GNU_PREFIX)-as'
AR              := '$(GNU_INSTALL_ROOT)/bin/$(GNU_PREFIX)-ar' -r
LD              := '$(GNU_INSTALL_ROOT)/bin/$(GNU_PREFIX)-ld'
NM              := '$(GNU_INSTALL_ROOT)/bin/$(GNU_PREFIX)-nm'
OBJDUMP         := '$(GNU_INSTALL_ROOT)/bin/$(GNU_PREFIX)-objdump'
OBJCOPY         := '$(GNU_INSTALL_ROOT)/bin/$(GNU_PREFIX)-objcopy'
SIZE            := '$(GNU_INSTALL_ROOT)/bin/$(GNU_PREFIX)-size'

#function for removing duplicates in a list
remduplicates = $(strip $(if $1,$(firstword $1) $(call remduplicates,$(filter-out $(firstword $1),$1))))

#source common to all targets
C_SOURCE_FILES += \
$(NRF52_SDK)/components/toolchain/system_nrf52.c \
$(NRF52_SDK)/components/drivers_nrf/delay/nrf_delay.c \
$(NRF52_SDK)/components/drivers_nrf/common/nrf_drv_common.c \
$(NRF52_SDK)/components/drivers_nrf/gpiote/nrf_drv_gpiote.c \
$(NRF52_SDK)/components/drivers_nrf/spi_master/nrf_drv_spi.c \
./main.c \
./draw.c \
./u8g/u8g_arm.c \
./u8g/u8g_bitmap.c \
./u8g/u8g_circle.c \
./u8g/u8g_clip.c \
./u8g/u8g_com_api_16gr.c \
./u8g/u8g_com_api.c \
./u8g/u8g_com_i2c.c \
./u8g/u8g_com_io.c \
./u8g/u8g_com_null.c \
./u8g/u8g_cursor.c \
./u8g/u8g_delay.c \
./u8g/u8g_dev_a2_micro_printer.c \
./u8g/u8g_dev_flipdisc_2x7.c \
./u8g/u8g_dev_gprof.c \
./u8g/u8g_dev_ht1632.c \
./u8g/u8g_dev_ili9325d_320x240.c \
./u8g/u8g_dev_ks0108_128x64.c \
./u8g/u8g_dev_lc7981_160x80.c \
./u8g/u8g_dev_lc7981_240x128.c \
./u8g/u8g_dev_lc7981_240x64.c \
./u8g/u8g_dev_lc7981_320x64.c \
./u8g/u8g_dev_ld7032_60x32.c \
./u8g/u8g_dev_null.c \
./u8g/u8g_dev_pcd8544_84x48.c \
./u8g/u8g_dev_pcf8812_96x65.c \
./u8g/u8g_dev_sbn1661_122x32.c \
./u8g/u8g_dev_ssd1306_128x32.c \
./u8g/u8g_dev_ssd1306_128x64.c \
./u8g/u8g_dev_ssd1306_64x48.c \
./u8g/u8g_dev_ssd1309_128x64.c \
./u8g/u8g_dev_ssd1322_nhd31oled_bw.c \
./u8g/u8g_dev_ssd1322_nhd31oled_gr.c \
./u8g/u8g_dev_ssd1325_nhd27oled_bw.c \
./u8g/u8g_dev_ssd1325_nhd27oled_bw_new.c \
./u8g/u8g_dev_ssd1325_nhd27oled_gr.c \
./u8g/u8g_dev_ssd1325_nhd27oled_gr_new.c \
./u8g/u8g_dev_ssd1327_96x96_gr.c \
./u8g/u8g_dev_ssd1351_128x128.c \
./u8g/u8g_dev_ssd1353_160x128.c \
./u8g/u8g_dev_st7565_64128n.c \
./u8g/u8g_dev_st7565_dogm128.c \
./u8g/u8g_dev_st7565_dogm132.c \
./u8g/u8g_dev_st7565_lm6059.c \
./u8g/u8g_dev_st7565_lm6063.c \
./u8g/u8g_dev_st7565_nhd_c12832.c \
./u8g/u8g_dev_st7565_nhd_c12864.c \
./u8g/u8g_dev_st7687_c144mvgd.c \
./u8g/u8g_dev_st7920_128x64.c \
./u8g/u8g_dev_st7920_192x32.c \
./u8g/u8g_dev_st7920_202x32.c \
./u8g/u8g_dev_t6963_128x128.c \
./u8g/u8g_dev_t6963_128x64.c \
./u8g/u8g_dev_t6963_240x128.c \
./u8g/u8g_dev_t6963_240x64.c \
./u8g/u8g_dev_tls8204_84x48.c \
./u8g/u8g_dev_uc1601_c128032.c \
./u8g/u8g_dev_uc1608_240x128.c \
./u8g/u8g_dev_uc1608_240x64.c \
./u8g/u8g_dev_uc1610_dogxl160.c \
./u8g/u8g_dev_uc1611_dogm240.c \
./u8g/u8g_dev_uc1611_dogxl240.c \
./u8g/u8g_dev_uc1701_dogs102.c \
./u8g/u8g_dev_uc1701_mini12864.c \
./u8g/u8g_ellipse.c \
./u8g/u8g_font.c \
./u8g/u8g_font_data.c \
./u8g/u8g_line.c \
./u8g/u8g_ll_api.c \
./u8g/u8g_page.c \
./u8g/u8g_pb14v1.c \
./u8g/u8g_pb16h1.c \
./u8g/u8g_pb16h2.c \
./u8g/u8g_pb16v1.c \
./u8g/u8g_pb16v2.c \
./u8g/u8g_pb32h1.c \
./u8g/u8g_pb8h1.c \
./u8g/u8g_pb8h1f.c \
./u8g/u8g_pb8h2.c \
./u8g/u8g_pb8h8.c \
./u8g/u8g_pb8v1.c \
./u8g/u8g_pb8v2.c \
./u8g/u8g_pb.c \
./u8g/u8g_pbxh16.c \
./u8g/u8g_pbxh24.c \
./u8g/u8g_polygon.c \
./u8g/u8g_rect.c \
./u8g/u8g_rot.c \
./u8g/u8g_scale.c \
./u8g/u8g_state.c \
./u8g/u8g_u16toa.c \
./u8g/u8g_u8toa.c \
./u8g/u8g_virtual_screen.c \


#assembly files common to all targets
ASM_SOURCE_FILES  = $(NRF52_SDK)/components/toolchain/gcc/gcc_startup_nrf52.s

#includes common to all targets
INC_PATHS  = -I$(NRF52_SDK)/components/toolchain/gcc
INC_PATHS += -I$(NRF52_SDK)/components/toolchain
INC_PATHS += -I.
INC_PATHS += -I../../drivers/hd44780
INC_PATHS += -I$(NRF52_SDK)/examples/bsp
INC_PATHS += -I$(NRF52_SDK)/components/device
INC_PATHS += -I$(NRF52_SDK)/components/drivers_nrf/nrf_soc_nosd
INC_PATHS += -I$(NRF52_SDK)/components/drivers_nrf/delay
INC_PATHS += -I$(NRF52_SDK)/components/drivers_nrf/hal
INC_PATHS += -I$(NRF52_SDK)/components/libraries/util
INC_PATHS += -I$(NRF52_SDK)/components/drivers_nrf/common
INC_PATHS += -I$(NRF52_SDK)/components/toolchain
INC_PATHS += -I$(NRF52_SDK)/components/libraries/timer
INC_PATHS += -I$(NRF52_SDK)/components/drivers_nrf/config
INC_PATHS += -I$(NRF52_SDK)/components/drivers_nrf/spi_master
INC_PATHS += -I$(NRF52_SDK)/components/drivers_nrf/gpiote
INC_PATHS += -I$(NRF52_SDK)/components/toolchain/gcc


OBJECT_DIRECTORY = _build
LISTING_DIRECTORY = $(OBJECT_DIRECTORY)
OUTPUT_BINARY_DIRECTORY = $(OBJECT_DIRECTORY)

# Sorting removes duplicates
BUILD_DIRECTORIES := $(sort $(OBJECT_DIRECTORY) $(OUTPUT_BINARY_DIRECTORY) $(LISTING_DIRECTORY) )

#flags common to all targets
CFLAGS  = -DCONFIG_GPIO_AS_PINRESET
CFLAGS += -DBOARD_PCA10036
CFLAGS += -DNRF52
CFLAGS += -DBSP_DEFINES_ONLY
CFLAGS += -mcpu=cortex-m4
CFLAGS += -mthumb -mabi=aapcs --std=gnu99
CFLAGS += -Wall -Werror -O3
CFLAGS += -mfloat-abi=hard -mfpu=fpv4-sp-d16
# keep every function in separate section. This will allow linker to dump unused functions
CFLAGS += -ffunction-sections -fdata-sections -fno-strict-aliasing
CFLAGS += -fno-builtin --short-enums

# keep every function in separate section. This will allow linker to dump unused functions
LDFLAGS += -Xlinker -Map=$(LISTING_DIRECTORY)/$(OUTPUT_FILENAME).map
LDFLAGS += -mthumb -mabi=aapcs -L $(TEMPLATE_PATH) -T$(LINKER_SCRIPT)
LDFLAGS += -mcpu=cortex-m4
LDFLAGS += -mfloat-abi=hard -mfpu=fpv4-sp-d16
# let linker to dump unused sections
LDFLAGS += -Wl,--gc-sections
# use newlib in nano version
LDFLAGS += --specs=nano.specs -lc -lnosys

# Assembler flags
ASMFLAGS += -x assembler-with-cpp
ASMFLAGS += -DCONFIG_GPIO_AS_PINRESET
ASMFLAGS += -DBOARD_PCA10036
ASMFLAGS += -DNRF52
ASMFLAGS += -DBSP_DEFINES_ONLY
#default target - first one defined
default: clean nrf52832_xxaa

#building all targets
all: clean
	$(NO_ECHO)$(MAKE) -f $(MAKEFILE_NAME) -C $(MAKEFILE_DIR) -e cleanobj
	$(NO_ECHO)$(MAKE) -f $(MAKEFILE_NAME) -C $(MAKEFILE_DIR) -e nrf52832_xxaa

#target for printing all targets
help:
	@echo following targets are available:
	@echo 	nrf52832_xxaa


C_SOURCE_FILE_NAMES = $(notdir $(C_SOURCE_FILES))
C_PATHS = $(call remduplicates, $(dir $(C_SOURCE_FILES) ) )
C_OBJECTS = $(addprefix $(OBJECT_DIRECTORY)/, $(C_SOURCE_FILE_NAMES:.c=.o) )

ASM_SOURCE_FILE_NAMES = $(notdir $(ASM_SOURCE_FILES))
ASM_PATHS = $(call remduplicates, $(dir $(ASM_SOURCE_FILES) ))
ASM_OBJECTS = $(addprefix $(OBJECT_DIRECTORY)/, $(ASM_SOURCE_FILE_NAMES:.s=.o) )

vpath %.c $(C_PATHS)
vpath %.s $(ASM_PATHS)

OBJECTS = $(C_OBJECTS) $(ASM_OBJECTS)

nrf52832_xxaa: OUTPUT_FILENAME := nrf52832_xxaa
nrf52832_xxaa: LINKER_SCRIPT=hd44780_gcc_nrf52.ld
nrf52832_xxaa: $(BUILD_DIRECTORIES) $(OBJECTS)
	@echo Linking target: $(OUTPUT_FILENAME).out
	$(NO_ECHO)$(CC) $(LDFLAGS) $(OBJECTS) $(LIBS) -o $(OUTPUT_BINARY_DIRECTORY)/$(OUTPUT_FILENAME).out
	$(NO_ECHO)$(MAKE) -f $(MAKEFILE_NAME) -C $(MAKEFILE_DIR) -e finalize

## Create build directories
$(BUILD_DIRECTORIES):
	echo $(MAKEFILE_NAME)
	$(MK) $@

# Create objects from C SRC files
$(OBJECT_DIRECTORY)/%.o: %.c
	@echo Compiling file: $(notdir $<)
	$(NO_ECHO)$(CC) $(CFLAGS) $(INC_PATHS) -c -o $@ $<

# Assemble files
$(OBJECT_DIRECTORY)/%.o: %.s
	@echo Compiling file: $(notdir $<)
	$(NO_ECHO)$(CC) $(ASMFLAGS) $(INC_PATHS) -c -o $@ $<


# Link
$(OUTPUT_BINARY_DIRECTORY)/$(OUTPUT_FILENAME).out: $(BUILD_DIRECTORIES) $(OBJECTS)
	@echo Linking target: $(OUTPUT_FILENAME).out
	$(NO_ECHO)$(CC) $(LDFLAGS) $(OBJECTS) $(LIBS) -o $(OUTPUT_BINARY_DIRECTORY)/$(OUTPUT_FILENAME).out


## Create binary .bin file from the .out file
$(OUTPUT_BINARY_DIRECTORY)/$(OUTPUT_FILENAME).bin: $(OUTPUT_BINARY_DIRECTORY)/$(OUTPUT_FILENAME).out
	@echo Preparing: $(OUTPUT_FILENAME).bin
	$(NO_ECHO)$(OBJCOPY) -O binary $(OUTPUT_BINARY_DIRECTORY)/$(OUTPUT_FILENAME).out $(OUTPUT_BINARY_DIRECTORY)/$(OUTPUT_FILENAME).bin

## Create binary .hex file from the .out file
$(OUTPUT_BINARY_DIRECTORY)/$(OUTPUT_FILENAME).hex: $(OUTPUT_BINARY_DIRECTORY)/$(OUTPUT_FILENAME).out
	@echo Preparing: $(OUTPUT_FILENAME).hex
	$(NO_ECHO)$(OBJCOPY) -O ihex $(OUTPUT_BINARY_DIRECTORY)/$(OUTPUT_FILENAME).out $(OUTPUT_BINARY_DIRECTORY)/$(OUTPUT_FILENAME).hex

finalize: genbin genhex echosize

genbin:
	@echo Preparing: $(OUTPUT_FILENAME).bin
	$(NO_ECHO)$(OBJCOPY) -O binary $(OUTPUT_BINARY_DIRECTORY)/$(OUTPUT_FILENAME).out $(OUTPUT_BINARY_DIRECTORY)/$(OUTPUT_FILENAME).bin

## Create binary .hex file from the .out file
genhex:
	@echo Preparing: $(OUTPUT_FILENAME).hex
	$(NO_ECHO)$(OBJCOPY) -O ihex $(OUTPUT_BINARY_DIRECTORY)/$(OUTPUT_FILENAME).out $(OUTPUT_BINARY_DIRECTORY)/$(OUTPUT_FILENAME).hex

echosize:
	-@echo ''
	$(NO_ECHO)$(SIZE) $(OUTPUT_BINARY_DIRECTORY)/$(OUTPUT_FILENAME).out
	-@echo ''

clean:
	$(RM) $(BUILD_DIRECTORIES)

cleanobj:
	$(RM) $(BUILD_DIRECTORIES)/*.o

flash: $(MAKECMDGOALS)
	@echo Flashing: $(OUTPUT_BINARY_DIRECTORY)/nrf52832_xxaa.hex
	nrfjprog --erasepage 0x0-0x80000 -f nrf52
	nrfjprog --program $(OUTPUT_BINARY_DIRECTORY)/nrf52832_xxaa.hex -f nrf52
	nrfjprog --reset

## Flash softdevice
