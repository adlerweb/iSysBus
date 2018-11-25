/**
 * @file		avrlib/trunk/lib/isb_def.h
 *
 * @brief		iSysBus Defines.
 *
 * This file includes iSysBus Defines.
 *
 * @author		© Patrick Amrhein <trick-at-isysbus-dot-org> 01.05.2010.
 *
 * @date		$Date: 2011-09-24 20:15:53 +0200 (Sa, 24. Sep 2011) $
 *
 * @version		$Rev: 5208 $
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





#ifndef ISB_DEF_H_
	#define ISB_DEF_H_



	#define USART0									1
	#define CAN0									2



	#define ERROR__CONFIG_CODE						1



	#define ISB_MSG_FLAGS_TOF_MASK					0x30

	#define ISB_MSG_FLAGS_TOF_UNICAST				0x00
//	#define ISB_MSG_FLAGS_TOF_RESERVED				0x10
	#define ISB_MSG_FLAGS_TOF_MULTICAST				0x20
//	#define ISB_MSG_FLAGS_TOF_BROADCAST				0x30



	#define ISB_MSG_FLAGS_RTR_MASK					0x40

	#define ISB_MSG_FLAGS_RTR						0x40



	#define ISB_MSG_FLAGS_DLC_MASK					0x0F

	#define ISB_MSG_FLAGS_DLC_0						0
	#define ISB_MSG_FLAGS_DLC_1						1
	#define ISB_MSG_FLAGS_DLC_2						2
	#define ISB_MSG_FLAGS_DLC_3						3
	#define ISB_MSG_FLAGS_DLC_4						4
	#define ISB_MSG_FLAGS_DLC_5						5
	#define ISB_MSG_FLAGS_DLC_6						6
	#define ISB_MSG_FLAGS_DLC_7						7
	#define ISB_MSG_FLAGS_DLC_8						8



	#define ISB_MSG_UNICAST_NODEID_MASK				0x07FF


	#define ISB_MSG_UNICAST_PORT_MASK				0xF800

	#define ISB_MSG_UNICAST_PORT_CONFIG				0x0000



	#define ISB_MSG_MULTICAST_GROUPID_BL_START		0xF001
	#define ISB_MSG_MULTICAST_GROUPID_FW_START		0xF002



	#define ISB_MSG_CTRL_CMD_MASK					0x03

	#define ISB_MSG_CTRL_CMD_READ					0x00
	#define ISB_MSG_CTRL_CMD_ANSWER					0x01
	#define ISB_MSG_CTRL_CMD_WRITE					0x02



	#define ISB_MSG_TOP_1BIT						0x01
	#define ISB_MSG_TOP_4BIT						0x02
	#define ISB_MSG_TOP_8BIT						0x03
//	#define ISB_MSG_TOP_							0x04
//	#define ISB_MSG_TOP_							0x05
//	#define ISB_MSG_TOP_							0x06
	#define ISB_MSG_TOP_FLOAT						0x07

	#define ISB_MSG_TOP__SERIAL_NUMBER__MODE__RESETSOURCE_ERROR	0x20
	#define ISB_MSG_TOP__SERIAL_NUMBER__MODE__ERROR			0x21





	#define ISB_MSG_TOP_1BIT_TOV_BOOL			0x01
	#define ISB_MSG_TOP_1BIT_TOV_SWITCH			0x02

//	#define ISB_MSG_TOP_FLOAT_TOV_TEMP			0x01



	#define ISB_NODE_OPERATING_MODE__MASK					0x0F

	#define ISB_NODE_OPERATING_MODE__BL_NORM				0x00
	#define ISB_NODE_OPERATING_MODE__BL_FLASH				0x01
	#define ISB_NODE_OPERATING_MODE__FW_NORM				0x08
	#define ISB_NODE_OPERATING_MODE__FW_CFG					0x09



#endif /* ISB_DEF_H_ */
