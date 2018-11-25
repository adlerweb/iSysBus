/**
 * @file		avrlib/trunk/lib/isb_eep_def.h
 *
 * @brief		iSysBus Eeprom Defines.
 *
 * This file includes iSysBus Eeprom Defines.
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





#ifndef ISB_EEP_DEF_H_
	#define ISB_EEP_DEF_H_



	#define EEP__ISB_HARDWARE_CODE_0				0x0000
	#define EEP__ISB_HARDWARE_CODE_1				0x0001
	#define EEP__ISB_HARDWARE_CODE_2				0x0002
	#define EEP__ISB_HARDWARE_CODE_3				0x0003

	#define EEP__ISB_NODE_SERIAL_NUMBER_0			0x0004
	#define EEP__ISB_NODE_SERIAL_NUMBER_1			0x0005
	#define EEP__ISB_NODE_SERIAL_NUMBER_2			0x0006
	#define EEP__ISB_NODE_SERIAL_NUMBER_3			0x0007

	#define EEP__ISB_BOOTLOADER_CODE_0				0x0008
	#define EEP__ISB_BOOTLOADER_CODE_1				0x0009
	#define EEP__ISB_BOOTLOADER_CODE_2				0x000A
	#define EEP__ISB_BOOTLOADER_CODE_3				0x000B

	#define EEP__ISB_FIRMWARE_CODE_0				0x000C
	#define EEP__ISB_FIRMWARE_CODE_1				0x000D
	#define EEP__ISB_FIRMWARE_CODE_2				0x000E
	#define EEP__ISB_FIRMWARE_CODE_3				0x000F

	#define EEP__ISB_NODE_ID_0						0x0010
	#define EEP__ISB_NODE_ID_1						0x0011

	#define EEP__ISB_NODE_OPERATING_MODE			0x0012
	#define EEP__ISB_NODE_OPERATING_RESETSOURCE		0x0013

//	#define EEP__ISB_NODE_OPERATING_ERROR			0x0014

//	#define EEP__ISB_ERROR_0						0x0015
//	#define EEP__ISB_ERROR_1						0x0016
//	#define EEP__ISB_ERROR_2						0x0017

	#define EEP__ISB_FIRMWARE_CRC_0					0x0018
	#define EEP__ISB_FIRMWARE_CRC_1					0x0019

	#define EEP__ISB_FIRMWARE_OFFSET				0x001A

	#define EEP__ISB_CONFIG_CRC						0x001B

	#define EEP__ISB_CONFIG_CODE_0					0x001C
	#define EEP__ISB_CONFIG_CODE_1					0x001D
	#define EEP__ISB_CONFIG_CODE_2					0x001E
	#define EEP__ISB_CONFIG_CODE_3					0x001F



	#if defined(__AVR_ATmega8__)
		#define EEP_SIZE							0
		#error "No definition for this MCU available."
	#elif defined(__AVR_ATmega16__)
		#define EEP_SIZE							512
	#elif defined(__AVR_ATmega32__)
		#define EEP_SIZE							0
		#error "No definition for this MCU available."
	#elif defined(__AVR_ATmega64__)
		#define EEP_SIZE							0
		#error "No definition for this MCU available."
	#elif defined(__AVR_ATmega128__)
		#define EEP_SIZE							0
		#error "No definition for this MCU available."
	#elif defined(__AVR_ATmega168__)
		#define EEP_SIZE							512
	#elif defined(__AVR_ATmega644__)
		#define EEP_SIZE							2048
	#elif defined(__AVR_AT90CAN32__)
		#define EEP_SIZE							0
		#error "No definition for this MCU available."
	#elif defined(__AVR_AT90CAN64__)
		#define EEP_SIZE							0
		#error "No definition for this MCU available."
	#elif defined(__AVR_AT90CAN128__)
		#define EEP_SIZE							0
		#error "No definition for this MCU available."
	#else
		#define EEP_SIZE							0
		#error "No definition for this MCU available."
	#endif



#endif /* ISB_EEP_DEF_H_ */
