/*
  Copyright 2014 Ralf Schmitt <ralf@bunkertor.net>

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef CONFIG_SPECIFIC_H
#define CONFIG_SPECIFIC_H

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6050
#define DEVICE_VER      0x0104
#define MANUFACTURER    Costar
#define PRODUCT         Majestouch TKL

/* message strings */
#define DESCRIPTION     t.m.k. keyboard firmware for Majestouch TKL

/* matrix size */
#define MATRIX_ROWS 18
#define MATRIX_COLS 8

/* Set 0 if need no debouncing */
#define DEBOUNCE    7

/* key combination for command */
#define IS_COMMAND() (keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)))

#define CONFIG_LED_IO \
  DDRC |= (1<<5) | (1<<6);

#define USB_LED_CAPS_LOCK_ON    PORTC &= ~(1<<6)
#define USB_LED_CAPS_LOCK_OFF   PORTC  |= (1<<6)
#define USB_LED_NUM_LOCK_ON     
#define USB_LED_NUM_LOCK_OFF    
#define USB_LED_SCROLL_LOCK_ON  PORTC &= ~(1<<5)
#define USB_LED_SCROLL_LOCK_OFF PORTC  |= (1<<5)

#define CONFIG_MATRIX_IO   \
  /* Column output pins */ \
  DDRD  |=  0b01111011;    \
  /* Row input pins */     \
  DDRC  &= ~0b10000000;    \
  DDRB  &= ~0b01111111;    \
  PORTC |=  0b10000000;    \
  PORTB |=  0b01111111;

#define MATRIX_ROW_SCAN                      \
  (PINB&(1<<5) ? 0 : ((matrix_row_t)1<<0)) | \
  (PINC&(1<<7) ? 0 : ((matrix_row_t)1<<1)) | \
  (PINB&(1<<4) ? 0 : ((matrix_row_t)1<<2)) | \
  (PINB&(1<<6) ? 0 : ((matrix_row_t)1<<3)) | \
  (PINB&(1<<1) ? 0 : ((matrix_row_t)1<<4)) | \
  (PINB&(1<<2) ? 0 : ((matrix_row_t)1<<5)) | \
  (PINB&(1<<3) ? 0 : ((matrix_row_t)1<<6)) | \
  (PINB&(1<<0) ? 0 : ((matrix_row_t)1<<7))

#define MATRIX_ROW_SELECT                                     \
  case  0: PORTD = (PORTD & ~0b01111011) | 0b00011011; break; \
  case  1: PORTD = (PORTD & ~0b01111011) | 0b01000011; break; \
  case  2: PORTD = (PORTD & ~0b01111011) | 0b01100000; break; \
  case  3: PORTD = (PORTD & ~0b01111011) | 0b01111001; break; \
  case  4: PORTD = (PORTD & ~0b01111011) | 0b01100010; break; \
  case  5: PORTD = (PORTD & ~0b01111011) | 0b01101010; break; \
  case  6: PORTD = (PORTD & ~0b01111011) | 0b01110001; break; \
  case  7: PORTD = (PORTD & ~0b01111011) | 0b01101001; break; \
  case  8: PORTD = (PORTD & ~0b01111011) | 0b01100001; break; \
  case  9: PORTD = (PORTD & ~0b01111011) | 0b01111000; break; \
  case 10: PORTD = (PORTD & ~0b01111011) | 0b00100011; break; \
  case 11: PORTD = (PORTD & ~0b01111011) | 0b00101011; break; \
  case 12: PORTD = (PORTD & ~0b01111011) | 0b00110011; break; \
  case 13: PORTD = (PORTD & ~0b01111011) | 0b01110000; break; \
  case 14: PORTD = (PORTD & ~0b01111011) | 0b00010011; break; \
  case 15: PORTD = (PORTD & ~0b01111011) | 0b01101000; break; \
  case 16: PORTD = (PORTD & ~0b01111011) | 0b00001011; break; \
  case 17: PORTD = (PORTD & ~0b01111011) | 0b00111011; break;

#endif
