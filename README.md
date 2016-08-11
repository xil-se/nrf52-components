# nrf52-components

This repository contains useful components to use on the nRF52 such as LCD drivers. More stuff is on the way.

It also contains some example applications.

This repository is basically just a playground, not something to depend on or trust.

Modules/drivers:
- [x] hd44780
- [x] u8glib
- [x] uart
- [ ] uart proxy (forward from one uart to another)
- [ ] SD card

Feel free to create issues with feature requests.



### Examples

  | Location                   | Description  |
  | -------------------------- |:------------:|
  | /examples/hd44780          | Prints text to a 2-row hd44780 display using the provided driver. |
  | /examples/u8g_test         | Displays test graphics on an LCD usisng U8G |
  | /examples/uart_test        | Prints text to UART and echos input. |
  | /examples/uart_to_lcd      | Echos UART and prints received bytes on an LCD using U8G. |

