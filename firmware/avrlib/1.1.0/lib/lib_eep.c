/**
 * @file		avrlib/trunk/lib/lib_eep.c
 *
 * @brief		Library Eeprom.
 *
 * This file includes Library Eeprom.
 *
 * @author		© Patrick Amrhein <trick-at-isysbus-dot-org> 01.05.2010.
 *
 * @date		$Date: 2010-05-28 11:38:03 +0200 (Fr, 28 Mai 2010) $
 *
 * @version		$Rev: 3913 $
 *
 * @note
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version. \n
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details. \n
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see http:*www.gnu.org/licenses. \n
 */





#ifndef LIB_EEP_C_
	#define LIB_EEP_C_



	uint8_t __attribute__((always_inline)) lib_eep_read_byte(uint8_t * aAddr) {
		return eeprom_read_byte(aAddr);;
	}



	uint16_t __attribute__((always_inline)) lib_eep_read_word(uint16_t * aAddr) {
		return eeprom_read_word(aAddr);;
	}



	void __attribute__((always_inline)) lib_eep_write_byte(uint8_t * aAddr, uint8_t aData) {
		if (eeprom_read_byte(aAddr) != aData) {
			eeprom_write_byte(aAddr, aData);
		}
	}



	uint8_t __attribute__((always_inline)) lib_eep_fw_read_byte(uint8_t * aAddr) {
		return eeprom_read_byte(Isb_Firmware_Offset + aAddr);;
	}



	uint16_t __attribute__((always_inline)) lib_eep_fw_read_word(uint16_t * aAddr) {
		return eeprom_read_word(Isb_Firmware_Offset + aAddr);;
	}



	void __attribute__((always_inline)) lib_eep_fw_write_byte(uint8_t * aAddr, uint8_t aData) {
		if (eeprom_read_byte(Isb_Firmware_Offset + aAddr) != aData) {
			eeprom_write_byte(Isb_Firmware_Offset + aAddr, aData);
		}
	}



#endif /* LIB_EEP_C_ */
