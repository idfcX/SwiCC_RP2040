#pragma once
#include "tusb_option.h"

#define CFG_TUSB_MCU OPT_MCU_RP2040   
#define CFG_TUSB_OS  OPT_OS_PICO
#define CFG_TUD_ENABLED   1
#define CFG_TUD_CDC       1

#define CFG_TUD_ENDPOINT0_SIZE 64
#define CFG_TUD_CDC_RX_BUFSIZE 512
#define CFG_TUD_CDC_TX_BUFSIZE 512
#define CFG_TUD_CDC_EP_BUFSIZE 64

// MCU/OS for Pico SDK (RP2350 uses the RP2040 TinyUSB port)
#define CFG_TUSB_MCU OPT_MCU_RP2040
#define CFG_TUSB_OS  OPT_OS_PICO

// Device stack enabled on rhport 0
#define CFG_TUD_ENABLED   1
#define CFG_TUD_MAX_SPEED OPT_MODE_FULL_SPEED

// === Enable CDC (others off) ===
#define CFG_TUD_CDC    1
#define CFG_TUD_MSC    0
#define CFG_TUD_HID    0
#define CFG_TUD_MIDI   0
#define CFG_TUD_VENDOR 0
#define CFG_TUD_NET    0
#define CFG_TUD_BTH    0

// Endpoints & buffers
#define CFG_TUD_ENDPOINT0_SIZE 64
#define CFG_TUD_CDC_RX_BUFSIZE 512
#define CFG_TUD_CDC_TX_BUFSIZE 512
#define CFG_TUD_TASK_QUEUE_SZ  32
#define CFG_TUD_CDC_EP_BUFSIZE 64
