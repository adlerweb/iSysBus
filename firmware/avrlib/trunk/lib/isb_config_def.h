/**
 * @file		avrlib/trunk/lib/isb_config_def.h
 *
 * @brief		iSysBus Configuration Defines.
 *
 * This file includes iSysBus Configuration Defines.
 *
 * @author		© Patrick Amrhein <trick-at-isysbus-dot-org> 01.05.2010.
 *
 * @date		$Date: 2010-05-28 11:38:03 +0200 (Fr, 28. Mai 2010) $
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





#ifndef ISB_CONFIG_DEF_H_
	#define ISB_CONFIG_DEF_H_



	#define ISB_CONFIG_CMD_MASK						0x3F

	#define ISB_CONFIG_CMD_NONE						0x00
	#define ISB_CONFIG_CMD_SETNODEID				0x01
	#define ISB_CONFIG_CMD_SETMODE					0x02
	#define ISB_CONFIG_CMD_SETCRC					0x03
	#define ISB_CONFIG_CMD_SETPAGE					0x04
	#define ISB_CONFIG_CMD_WRITEFLASH				0x05
	#define ISB_CONFIG_CMD_INITEEPROM				0x06
	#define ISB_CONFIG_CMD_READEEPROMBLOCK			0x07
	#define ISB_CONFIG_CMD_WRITEEEPROMBLOCK			0x08
	#define ISB_CONFIG_CMD_RESETERRORMEMORY			0x09



	#define ISB_CONFIG_ANSWER_MASK					0xC0

	#define ISB_CONFIG_ANSWER_NONE					0x00
	#define ISB_CONFIG_ANSWER_NACK					0x40
	#define ISB_CONFIG_ANSWER_NOT_ALLOWED			0x80
	#define ISB_CONFIG_ANSWER_ACK					0xC0



#endif /* ISB_CONFIG_DEF_H_ */
