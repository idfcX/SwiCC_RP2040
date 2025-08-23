cmake_minimum_required(VERSION 3.13)
include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)
project(rp2350_uart_bridge C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
pico_sdk_init()

add_executable(rp2350_uart_bridge main.c)
target_compile_definitions(rp2350_uart_bridge PUBLIC CFG_TUSB_CONFIG_FILE="tusb_config.h")


target_link_libraries(rp2350_uart_bridge
  pico_stdlib
  hardware_uart
  tinyusb_device
  tinyusb_board
)

pico_add_extra_outputs(rp2350_uart_bridge)
pico_enable_stdio_usb(rp2350_uart_bridge 1)
pico_enable_stdio_uart(rp2350_uart_bridge 0)
