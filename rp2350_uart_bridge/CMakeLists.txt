cmake_minimum_required(VERSION 3.13)
include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)
project(rp2350_uart_bridge C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
pico_sdk_init()

add_executable(rp2350_uart_bridge main.c)
# Make our config header visible to ALL TinyUSB/stdio sources
target_include_directories(rp2350_uart_bridge PRIVATE ${CMAKE_CURRENT_LIST_DIR})
# Tell TinyUSB explicitly where the config is
target_compile_definitions(rp2350_uart_bridge PRIVATE CFG_TUSB_CONFIG_FILE="tusb_config.h")

# Ensure interface libs also see the config header
target_include_directories(tinyusb_device INTERFACE ${CMAKE_CURRENT_LIST_DIR})
target_include_directories(pico_stdio_usb  INTERFACE ${CMAKE_CURRENT_LIST_DIR})

# (If not already present) link tinyusb
target_link_libraries(rp2350_uart_bridge
    pico_stdlib
    tinyusb_device
    tinyusb_board
    hardware_uart
)

# Optional but fine to keep:
# pico_enable_stdio_usb(rp2350_uart_bridge 1)
# pico_enable_stdio_uart(rp2350_uart_bridge 0)



target_link_libraries(rp2350_uart_bridge
  pico_stdlib
  hardware_uart
  tinyusb_device
  tinyusb_board
)

pico_add_extra_outputs(rp2350_uart_bridge)
pico_enable_stdio_usb(rp2350_uart_bridge 1)
pico_enable_stdio_uart(rp2350_uart_bridge 0)
