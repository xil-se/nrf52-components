#include "u8g_arm.h"
#include "nrf_delay.h"
#include "nrf_drv_spi.h"
#include "nrf_gpio.h"
#include "app_util_platform.h"
#include "nrf52_components_config.h"

/*
PIN CONFIGURATION

SCK    CLOCK        max 4 Mb/s
MOSI   Data out
DC     Data/Command (high=data, low=command) - toggle on last bit
SCE    Chip Enable  (low = active)
RES    Reset        (low = active)
*/


#if !defined(U8G_PIN_SCK)
#error foo
#endif
#define U8G_PIN_SCK      (22)
#define U8G_PIN_DATA     (23)
#define U8G_PIN_DC       (24)
#define U8G_PIN_SCE      (25)
#define U8G_PIN_RST      ( 2)


static const nrf_drv_spi_t m_spi_master_0 = NRF_DRV_SPI_INSTANCE(0);

static void spi_init(int freq)
{
    uint32_t err_code;
    nrf_drv_spi_config_t const config =
    {
        .sck_pin      = U8G_PIN_SCK,
        .mosi_pin     = U8G_PIN_DATA,
        .miso_pin     = NRF_DRV_SPI_PIN_NOT_USED,
        .ss_pin       = NRF_DRV_SPI_PIN_NOT_USED,
        .irq_priority = APP_IRQ_PRIORITY_LOW,
        .orc          = 0xCC,
        .frequency    = freq,
        .mode         = NRF_DRV_SPI_MODE_0,
        .bit_order    = NRF_DRV_SPI_BIT_ORDER_MSB_FIRST,
    };

    err_code = nrf_drv_spi_init(&m_spi_master_0, &config, NULL);
    if (err_code != NRF_SUCCESS)
    {
        // Initialization failed. Take recovery action.
    }
}

void u8g_Delay(u8g_t *u8g, uint16_t val)
{
    nrf_delay_ms(val);
}

void u8g_MicroDelay(void)
{
    nrf_delay_us(1);
}

void u8g_10MicroDelay(void)
{
    nrf_delay_us(10);
}

uint8_t u8g_com_hw_spi_fn(u8g_t *u8g, uint8_t msg, uint8_t arg_val, void *arg_ptr)
{
    switch(msg)
    {
      case U8G_COM_MSG_STOP:
          break;

      case U8G_COM_MSG_INIT:
          if ( arg_val <= U8G_SPI_CLK_CYCLE_50NS )
          {
              spi_init(NRF_DRV_SPI_FREQ_8M);
          }
          else if ( arg_val <= U8G_SPI_CLK_CYCLE_300NS )
          {
              spi_init(NRF_DRV_SPI_FREQ_4M);
          }
          else if ( arg_val <= U8G_SPI_CLK_CYCLE_400NS )
          {
              spi_init(NRF_DRV_SPI_FREQ_2M);
          }
          else
          {
              spi_init(NRF_DRV_SPI_FREQ_1M);
          }

          nrf_gpio_cfg_output(U8G_PIN_SCE);
          nrf_gpio_cfg_output(U8G_PIN_DC);
          nrf_gpio_cfg_output(U8G_PIN_RST);

          u8g_MicroDelay();
          break;

      case U8G_COM_MSG_ADDRESS:
          /* define cmd (arg_val = 0) or data mode (arg_val = 1) */
          u8g_10MicroDelay();
          nrf_gpio_pin_write(U8G_PIN_DC, arg_val);
          u8g_10MicroDelay();
          break;

      case U8G_COM_MSG_CHIP_SELECT:
          if ( arg_val == 0 )
          {
              /* this delay is required to avoid that the display is switched off too early --> DOGS102 with LPC1114 */
              nrf_delay_us(50);
              nrf_gpio_pin_write(U8G_PIN_SCE, 1);
          }
          else
          {
              /* enable */
              nrf_gpio_pin_write(U8G_PIN_SCE, 0);
          }
          u8g_MicroDelay();
          break;

      case U8G_COM_MSG_RESET:
          nrf_gpio_pin_write(U8G_PIN_RST, arg_val);
          u8g_10MicroDelay();
          break;

      case U8G_COM_MSG_WRITE_BYTE:
          nrf_drv_spi_transfer(&m_spi_master_0, &arg_val, 1, NULL, 0);
          u8g_MicroDelay();
          break;

      case U8G_COM_MSG_WRITE_SEQ:
      case U8G_COM_MSG_WRITE_SEQ_P:
          nrf_drv_spi_transfer(&m_spi_master_0, arg_ptr, arg_val, NULL, 0);
          break;
  }
  return 1;
}
