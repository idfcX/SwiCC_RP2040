#include "pico/stdlib.h"
#include "hardware/uart.h"
#include "bsp/board.h"
#include "tusb.h"

#define BRIDGE_UART   uart0     // UART0
#define BRIDGE_TX_PIN 0         // GP0 → TX
#define BRIDGE_RX_PIN 1         // GP1 → RX
#define BRIDGE_BAUD   1000000   // change if your app needs another rate

int main() {
  board_init();
  tusb_init();

  uart_init(BRIDGE_UART, BRIDGE_BAUD);
  gpio_set_function(BRIDGE_TX_PIN, GPIO_FUNC_UART);
  gpio_set_function(BRIDGE_RX_PIN, GPIO_FUNC_UART);

  for (;;) {
    tud_task();

    // USB -> UART
    if (tud_cdc_available()) {
      uint8_t buf[64];
      uint32_t n = tud_cdc_read(buf, sizeof(buf));
      for (uint32_t i = 0; i < n; i++) uart_putc_raw(BRIDGE_UART, buf[i]);
    }

    // UART -> USB
    while (uart_is_readable(BRIDGE_UART)) {
      uint8_t ch = uart_getc(BRIDGE_UART);
      if (tud_cdc_connected() && tud_cdc_write_available()) {
        tud_cdc_write_char(ch);
        tud_cdc_write_flush();
      }
    }
  }
}
