/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */
#pragma once

/**
 * Arduino Mega with RAMPS v1.4 (or v1.3) pin assignments
 *
 * Applies to the following boards:
 *
 *  RAMPS_14_EFB (Hotend, Fan, Bed)
 *  RAMPS_14_EEB (Hotend0, Hotend1, Bed)
 *  RAMPS_14_EFF (Hotend, Fan0, Fan1)
 *  RAMPS_14_EEF (Hotend0, Hotend1, Fan)
 *  RAMPS_14_SF  (Spindle, Controller Fan)
 *
 *  RAMPS_13_EFB (Hotend, Fan, Bed)
 *  RAMPS_13_EEB (Hotend0, Hotend1, Bed)
 *  RAMPS_13_EFF (Hotend, Fan0, Fan1)
 *  RAMPS_13_EEF (Hotend0, Hotend1, Fan)
 *  RAMPS_13_SF  (Spindle, Controller Fan)
 *
 *  Other pins_MYBOARD.h files may override these defaults
 *
 *  Differences between
 *  RAMPS_13 | RAMPS_14
 *         7 | 11
 */

#if ENABLED(AZSMZ_12864) && DISABLED(ALLOW_SAM3X8E)
  #error "No pins defined for RAMPS with AZSMZ_12864."
#endif

#include "env_validate.h"

// Custom flags and defines for the build
//#define BOARD_CUSTOM_BUILD_FLAGS -D__FOO__

#ifndef BOARD_INFO_NAME
  #define BOARD_INFO_NAME "RAMPS 1.4"
#endif

//
// Servos
//
#ifndef SERVO0_PIN
  #ifdef IS_RAMPS_13
    #define SERVO0_PIN                         7
  #else
    #define SERVO0_PIN                        11
  #endif
#endif
#ifndef SERVO1_PIN
  #define SERVO1_PIN                           6
#endif
#ifndef SERVO2_PIN
  #define SERVO2_PIN                           5
#endif
#ifndef SERVO3_PIN
  #define SERVO3_PIN                           4
#endif

//
// Limit Switches
//
#ifndef X_STOP_PIN
  #ifndef X_MIN_PIN
    #define X_MIN_PIN                          3
  #endif
  #ifndef X_MAX_PIN
    #define X_MAX_PIN                          2
  #endif
#endif
#ifndef Y_STOP_PIN
  #ifndef Y_MIN_PIN
    #define Y_MIN_PIN                         14
  #endif
  #ifndef Y_MAX_PIN
    #define Y_MAX_PIN                         15
  #endif
#endif
#ifndef Z_STOP_PIN
  #ifndef Z_MIN_PIN
    #define Z_MIN_PIN                         18
  #endif
  #ifndef Z_MAX_PIN
    #define Z_MAX_PIN                         19
  #endif
#endif

//
// Z Probe (when not Z_MIN_PIN)
//
#ifndef Z_MIN_PROBE_PIN
  #define Z_MIN_PROBE_PIN                     32
#endif

//
// Steppers
//
#define X_STEP_PIN                            54
#define X_DIR_PIN                             55
#define X_ENABLE_PIN                          38
#ifndef X_CS_PIN
  #define X_CS_PIN                   AUX3_03_PIN
#endif

#define Y_STEP_PIN                            60
#define Y_DIR_PIN                             61
#define Y_ENABLE_PIN                          56
#ifndef Y_CS_PIN
  #define Y_CS_PIN                   AUX3_07_PIN
#endif

#ifndef Z_STEP_PIN
  #define Z_STEP_PIN                          46
#endif
#ifndef Z_DIR_PIN
  #define Z_DIR_PIN                           48
#endif
#ifndef Z_ENABLE_PIN
  #define Z_ENABLE_PIN                        62
#endif
#ifndef Z_CS_PIN
  #define Z_CS_PIN                            40
#endif

#ifndef Z2_STEP_PIN
  #define Z2_STEP_PIN                         26
#endif
#ifndef Z2_DIR_PIN
  #define Z2_DIR_PIN                          28
#endif
#ifndef Z2_ENABLE_PIN
  #define Z2_ENABLE_PIN                       24
#endif
#ifndef Z2_CS_PIN
  #define Z2_CS_PIN                           42
#endif

#ifndef E0_STEP_PIN
  #define E0_STEP_PIN                         36
#endif
#ifndef E0_DIR_PIN
  #define E0_DIR_PIN                          34
#endif
#ifndef E0_ENABLE_PIN
  #define E0_ENABLE_PIN                       30
#endif
#ifndef E0_CS_PIN
  #define E0_CS_PIN                           44
#endif

//
// Temperature Sensors
//
#ifndef TEMP_0_PIN
  #define TEMP_0_PIN                          13  // Analog Input
#endif
#ifndef TEMP_1_PIN
  #define TEMP_1_PIN                          15  // Analog Input
#endif
#ifndef TEMP_BED_PIN
  #define TEMP_BED_PIN                        14  // Analog Input
#endif

//
// SPI for MAX Thermocouple
//
#ifndef TEMP_0_CS_PIN
  #define TEMP_0_CS_PIN                       66  // Don't use 53 if using Display/SD card (SDSS) or 49 (SD_DETECT_PIN)
#endif

//
// Heaters / Fans
//
#ifndef MOSFET_A_PIN
  #define MOSFET_A_PIN                        10
#endif
#ifndef MOSFET_B_PIN
  #define MOSFET_B_PIN                         9
#endif
#ifndef MOSFET_C_PIN
  #define MOSFET_C_PIN                         8
#endif
#ifndef MOSFET_D_PIN
  #define MOSFET_D_PIN                        -1
#endif

#define HEATER_0_PIN                MOSFET_A_PIN

#if FET_ORDER_EFB                                 // Hotend, Fan, Bed
  #define HEATER_BED_PIN            MOSFET_C_PIN
#elif FET_ORDER_EEF                               // Hotend, Hotend, Fan
  #define HEATER_1_PIN              MOSFET_B_PIN
#elif FET_ORDER_EEB                               // Hotend, Hotend, Bed
  #define HEATER_1_PIN              MOSFET_B_PIN
  #define HEATER_BED_PIN            MOSFET_C_PIN
#elif FET_ORDER_EFF                               // Hotend, Fan, Fan
  #define FAN1_PIN                  MOSFET_C_PIN
#elif DISABLED(FET_ORDER_SF)                      // Not Spindle, Fan (i.e., "EFBF" or "EFBE")
  #define HEATER_BED_PIN            MOSFET_C_PIN
  #if EITHER(HAS_MULTI_HOTEND, HEATERS_PARALLEL)
    #define HEATER_1_PIN            MOSFET_D_PIN
  #else
    #define FAN1_PIN                MOSFET_D_PIN
  #endif
#endif

#ifndef FAN_PIN
  #if EITHER(FET_ORDER_EFB, FET_ORDER_EFF)        // Hotend, Fan, Bed or Hotend, Fan, Fan
    #define FAN_PIN                 MOSFET_B_PIN
  #elif EITHER(FET_ORDER_EEF, FET_ORDER_SF)       // Hotend, Hotend, Fan or Spindle, Fan
    #define FAN_PIN                 MOSFET_C_PIN
  #elif FET_ORDER_EEB                             // Hotend, Hotend, Bed
    #define FAN_PIN                            4  // IO pin. Buffer needed
  #else                                           // Non-specific are "EFB" (i.e., "EFBF" or "EFBE")
    #define FAN_PIN                 MOSFET_B_PIN
  #endif
#endif

//
// Misc. Functions
//
#ifndef SDSS
  #define SDSS                       AUX3_03_PIN
#endif
#define LED_PIN                               13

#ifndef FILWIDTH_PIN
  #define FILWIDTH_PIN                         5  // Analog Input on AUX2
#endif

// RAMPS 1.4 DIO 4 on the servos connector
#ifndef FIL_RUNOUT_PIN
  #define FIL_RUNOUT_PIN                       4
#endif

#ifndef PS_ON_PIN
  #define PS_ON_PIN                           12
#endif

#if ENABLED(CASE_LIGHT_ENABLE) && !defined(CASE_LIGHT_PIN) && !defined(SPINDLE_LASER_ENA_PIN)
  #if NUM_SERVOS <= 1                             // Prefer the servo connector
    #define CASE_LIGHT_PIN                     6  // Hardware PWM
  #elif HAS_FREE_AUX2_PINS
    #define CASE_LIGHT_PIN                    44  // Hardware PWM
  #endif
#endif

//
// M3/M4/M5 - Spindle/Laser Control
//
#if HAS_CUTTER && !defined(SPINDLE_LASER_ENA_PIN)
  #if !NUM_SERVOS                                 // Use servo connector if possible
    #define SPINDLE_LASER_ENA_PIN              4  // Pullup or pulldown!
    #define SPINDLE_LASER_PWM_PIN              6  // Hardware PWM
    #define SPINDLE_DIR_PIN                    5
  #elif HAS_FREE_AUX2_PINS
    #define SPINDLE_LASER_ENA_PIN             40  // Pullup or pulldown!
    #define SPINDLE_LASER_PWM_PIN             44  // Hardware PWM
    #define SPINDLE_DIR_PIN                   65
  #else
    #error "No auto-assignable Spindle/Laser pins available."
  #endif
#endif

//
// TMC software SPI
//
#if ENABLED(TMC_USE_SW_SPI)
  #ifndef TMC_SW_MOSI
    #define TMC_SW_MOSI                       66
  #endif
  #ifndef TMC_SW_MISO
    #define TMC_SW_MISO                       44
  #endif
  #ifndef TMC_SW_SCK
    #define TMC_SW_SCK                        64
  #endif
#endif

#if HAS_TMC_UART
  /**
   * TMC2208/TMC2209 stepper drivers
   *
   * Hardware serial communication ports.
   * If undefined software serial is used according to the pins below
   *
   * Serial2 -- AUX-4 Pin 18 (D16 TX2) and AUX-4 Pin 17 (D17 RX2)
   * Serial1 -- Pins D18 and D19 are used for Z-MIN and Z-MAX
   */
  //#define X_HARDWARE_SERIAL Serial1
  //#define X2_HARDWARE_SERIAL Serial1
  //#define Y_HARDWARE_SERIAL Serial1
  //#define Y2_HARDWARE_SERIAL Serial1
  //#define Z_HARDWARE_SERIAL Serial1
  //#define Z2_HARDWARE_SERIAL Serial1
  //#define E0_HARDWARE_SERIAL Serial1
  //#define E1_HARDWARE_SERIAL Serial1
  //#define E2_HARDWARE_SERIAL Serial1
  //#define E3_HARDWARE_SERIAL Serial1
  //#define E4_HARDWARE_SERIAL Serial1

  #ifndef X_SERIAL_TX_PIN
    #define X_SERIAL_TX_PIN                   40
  #endif
  #ifndef X_SERIAL_RX_PIN
    #define X_SERIAL_RX_PIN                   63
  #endif
  #ifndef X2_SERIAL_TX_PIN
    #define X2_SERIAL_TX_PIN                  -1
  #endif
  #ifndef X2_SERIAL_RX_PIN
    #define X2_SERIAL_RX_PIN                  -1
  #endif

  #ifndef Y_SERIAL_TX_PIN
    #define Y_SERIAL_TX_PIN                   59
  #endif
  #ifndef Y_SERIAL_RX_PIN
    #define Y_SERIAL_RX_PIN                   64
  #endif
  #ifndef Y2_SERIAL_TX_PIN
    #define Y2_SERIAL_TX_PIN                  -1
  #endif
  #ifndef Y2_SERIAL_RX_PIN
    #define Y2_SERIAL_RX_PIN                  -1
  #endif

  #ifndef Z_SERIAL_TX_PIN
    #define Z_SERIAL_TX_PIN                   42
  #endif
  #ifndef Z_SERIAL_RX_PIN
    #define Z_SERIAL_RX_PIN                   65
  #endif
  #ifndef E0_SERIAL_TX_PIN
    #define E0_SERIAL_TX_PIN                  -1
  #endif
  #ifndef E0_SERIAL_RX_PIN
    #define E0_SERIAL_RX_PIN                  -1
  #endif

  #ifndef Z2_SERIAL_TX_PIN
    #define Z2_SERIAL_TX_PIN                  44
  #endif
  #ifndef Z2_SERIAL_RX_PIN
    #define Z2_SERIAL_RX_PIN                  66
  #endif
  #ifndef E1_SERIAL_TX_PIN
    #define E1_SERIAL_TX_PIN                  -1
  #endif
  #ifndef E1_SERIAL_RX_PIN
    #define E1_SERIAL_RX_PIN                  -1
  #endif
  #ifndef E2_SERIAL_TX_PIN
    #define E2_SERIAL_TX_PIN                  -1
  #endif
  #ifndef E2_SERIAL_RX_PIN
    #define E2_SERIAL_RX_PIN                  -1
  #endif
  #ifndef E3_SERIAL_TX_PIN
    #define E3_SERIAL_TX_PIN                  -1
  #endif
  #ifndef E3_SERIAL_RX_PIN
    #define E3_SERIAL_RX_PIN                  -1
  #endif
  #ifndef E4_SERIAL_TX_PIN
    #define E4_SERIAL_TX_PIN                  -1
  #endif
  #ifndef E4_SERIAL_RX_PIN
    #define E4_SERIAL_RX_PIN                  -1
  #endif
  #ifndef E5_SERIAL_TX_PIN
    #define E5_SERIAL_TX_PIN                  -1
  #endif
  #ifndef E5_SERIAL_RX_PIN
    #define E5_SERIAL_RX_PIN                  -1
  #endif
  #ifndef E6_SERIAL_TX_PIN
    #define E6_SERIAL_TX_PIN                  -1
  #endif
  #ifndef E6_SERIAL_RX_PIN
    #define E6_SERIAL_RX_PIN                  -1
  #endif
  #ifndef E7_SERIAL_TX_PIN
    #define E7_SERIAL_TX_PIN                  -1
  #endif
  #ifndef E7_SERIAL_RX_PIN
    #define E7_SERIAL_RX_PIN                  -1
  #endif
#endif

//
// Průša i3 MK2 Multiplexer Support
//
#ifndef E_MUX0_PIN
  #define E_MUX0_PIN                          40  // Z_CS_PIN
#endif
#ifndef E_MUX1_PIN
  #define E_MUX1_PIN                          42  // E0_CS_PIN
#endif
#ifndef E_MUX2_PIN
  #define E_MUX2_PIN                          44  // E1_CS_PIN
#endif

//
// AUX3 : GND D52 D50 5V
//        NC  D53 D51 D49

#define AUX3_03_PIN                           53
#define AUX3_04_PIN                           52
#define AUX3_05_PIN                           51
#define AUX3_06_PIN                           50
#define AUX3_07_PIN                           49

//
// AUX4 : D16 D17 D23 D25 D27 D29 D31 D33 D35 D37 D39 D41 D43 D45 D47 D32 GND 5V
//

#define AUX4_03_PIN                           32
#define AUX4_04_PIN                           47
#define AUX4_05_PIN                           45
#define AUX4_06_PIN                           43
#define AUX4_07_PIN                           41
#define AUX4_08_PIN                           39
#define AUX4_09_PIN                           37
#define AUX4_10_PIN                           35
#define AUX4_11_PIN                           33
#define AUX4_12_PIN                           31
#define AUX4_13_PIN                           29
#define AUX4_14_PIN                           27
#define AUX4_15_PIN                           25
#define AUX4_16_PIN                           23
#define AUX4_17_PIN                           17
#define AUX4_18_PIN                           16

/**
 * LCD adapter. NOTE: These come in two variants. The socket keys can be
 * on either side, and may be backwards on some boards / displays.
 *         ------                     ------
 *    D37 |10  9 | D35    (MISO) D50 |10  9 | D52 (SCK)
 *    D17 | 8  7 | D16           D31 | 8  7 | D53
 *    D23   6  5   D25           D33   6  5   D51 (MOSI)
 *    D27 | 4  3 | D29           D49 | 4  3 | D41
 *    GND | 2  1 | 5V            GND | 2  1 | --
 *         ------                     ------
 *          EXP1                       EXP2
 */
#ifndef EXP1_03_PIN
  #define EXP1_03_PIN                AUX4_13_PIN
  #define EXP1_04_PIN                AUX4_14_PIN
  #define EXP1_05_PIN                AUX4_15_PIN
  #define EXP1_06_PIN                AUX4_16_PIN
  #define EXP1_07_PIN                AUX4_18_PIN
  #define EXP1_08_PIN                AUX4_17_PIN
  #define EXP1_09_PIN                AUX4_10_PIN
  #define EXP1_10_PIN                AUX4_09_PIN

  #define EXP2_03_PIN                AUX4_07_PIN
  #define EXP2_04_PIN                AUX3_07_PIN
  #define EXP2_05_PIN                AUX3_05_PIN
  #define EXP2_06_PIN                AUX4_11_PIN
  #define EXP2_07_PIN                AUX3_03_PIN
  #define EXP2_08_PIN                AUX4_12_PIN
  #define EXP2_09_PIN                AUX3_04_PIN
  #define EXP2_10_PIN                AUX3_06_PIN
#endif

//////////////////////////
// LCDs and Controllers //
//////////////////////////

#if HAS_WIRED_LCD

  // Uncomment screen orientation
  //#define LCD_SCREEN_ROT_90
  //#define LCD_SCREEN_ROT_180
  //#define LCD_SCREEN_ROT_270

  //
  // LCD Display output pins
  //
  // #if ENABLED(REPRAPWORLD_GRAPHICAL_LCD)

  //   #define LCD_PINS_RS              EXP2_04_PIN  // CS chip select /SS chip slave select
  //   #define LCD_PINS_ENABLE          EXP2_05_PIN  // SID (MOSI)
  //   #define LCD_PINS_D4              EXP2_09_PIN  // SCK (CLK) clock


/**
 * LCD adapter. NOTE: These come in two variants. The socket keys can be
 * on either side, and may be backwards on some boards / displays.
 *         ------                     ------
 *    D37 |10  9 | D35    (MISO) D50 |10  9 | D52 (SCK)
 *    D17 | 8  7 | D16           D31 | 8  7 | D53
 *    D23   6  5   D25           D33   6  5   D51 (MOSI)
 *    D27 | 4  3 | D29           D49 | 4  3 | D41
 *    GND | 2  1 | 5V            GND | 2  1 | --
 *         ------                     ------
 *          EXP1                       EXP2
 * */
      #if ENABLED(REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER)
      
      #define LCD_PINS_RS              EXP2_04_PIN  // CS chip select /SS chip slave select
      #define LCD_PINS_ENABLE          EXP2_05_PIN  // SID (MOSI)
      #define LCD_PINS_D4              EXP2_09_PIN  // SCK (CLK) clock
      #define BEEPER_PIN                      27
      #define LCD_PINS_RS                     29
      #define LCD_PINS_ENABLE                 16
      #define LCD_PINS_D4                     11
      #define BTN_EN1                         28
      #define BTN_EN2                         10
      #define BTN_ENC                         17
      #define BOARD_ST7920_DELAY_1           250
      #define BOARD_ST7920_DELAY_2           250
      #define BOARD_ST7920_DELAY_3           250
      #endif

      #define LCD_PINS_D7            EXP1_03_PIN


    #endif
