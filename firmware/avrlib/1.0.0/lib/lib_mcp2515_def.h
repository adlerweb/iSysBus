/**
 * @file		avrlib/trunk/lib/lib_mcp2515_def.h
 *
 * @brief		Library Mcp2515 Defines.
 *
 * This file includes Library Mcp2515 Defines.
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





#ifndef LIB_MCP2515_DEF_H_
	#define LIB_MCP2515_DEF_H_



	// Register 3-1 (Seite 18)
	// TXBnCTRL - TRANSMIT BUFFER n CONTROL REGISTER
	#define LIB_MCP2515_TXB0CTRL					0x30
	#define LIB_MCP2515_TXB1CTRL					0x40
	#define LIB_MCP2515_TXB2CTRL					0x50
	// Bits
	#define LIB_MCP2515_TXBnCTRL_TXP0				0
	#define LIB_MCP2515_TXBnCTRL_TXP1				1
	#define LIB_MCP2515_TXBnCTRL_TXREQ				3
	#define LIB_MCP2515_TXBnCTRL_TXERR				4
	#define LIB_MCP2515_TXBnCTRL_MLOA				5
	#define LIB_MCP2515_TXBnCTRL_ABTF				6

	// Register 3-2 (Seite 19)
	// TXRTSCTRL - TXnRTS PIN CONTROL AND STATUS REGISTER
	#define LIB_MCP2515_TXRTSCTRL					0x0D
	// Bits
	#define LIB_MCP2515_TXRTSCTRL_B0RTSM			0
	#define LIB_MCP2515_TXRTSCTRL_B1RTSM			1
	#define LIB_MCP2515_TXRTSCTRL_B2RTSM			2
	#define LIB_MCP2515_TXRTSCTRL_B0RTS				3
	#define LIB_MCP2515_TXRTSCTRL_B1RTS				4
	#define LIB_MCP2515_TXRTSCTRL_B2RTS				5

	// Register 3-3 (Seite 19)
	// TXBnSIDH - TRANSMIT BUFFER n STANDARD IDENTIFIER HIGH
	#define LIB_MCP2515_TXB0SIDH					0x31
	#define LIB_MCP2515_TXB1SIDH					0x41
	#define LIB_MCP2515_TXB2SIDH					0x51
	// Bits
	#define LIB_MCP2515_TXBnSIDH_SID3				0
	#define LIB_MCP2515_TXBnSIDH_SID4				1
	#define LIB_MCP2515_TXBnSIDH_SID5				2
	#define LIB_MCP2515_TXBnSIDH_SID6				3
	#define LIB_MCP2515_TXBnSIDH_SID7				4
	#define LIB_MCP2515_TXBnSIDH_SID8				5
	#define LIB_MCP2515_TXBnSIDH_SID9				6
	#define LIB_MCP2515_TXBnSIDH_SID10				7

	// Register 3-4 (Seite 20)
	// TXBnSIDL - TRANSMIT BUFFER n STANDARD IDENTIFIER LOW
	#define LIB_MCP2515_TXB0SIDL					0x32
	#define LIB_MCP2515_TXB1SIDL					0x42
	#define LIB_MCP2515_TXB2SIDL					0x52
	// Bits
	#define LIB_MCP2515_TXBnSIDH_EID16				0
	#define LIB_MCP2515_TXBnSIDH_EID17				1
	#define LIB_MCP2515_TXBnSIDH_EXIDE				3
	#define LIB_MCP2515_TXBnSIDH_SID0				5
	#define LIB_MCP2515_TXBnSIDH_SID1				6
	#define LIB_MCP2515_TXBnSIDH_SID2				7

	// Register 3-5 (Seite 20)
	// TXBnEID8 - TRANSMIT BUFFER n EXTENDED IDENTIFIER HIGH
	#define LIB_MCP2515_TXB0EID8					0x33
	#define LIB_MCP2515_TXB1EID8					0x43
	#define LIB_MCP2515_TXB2EID8					0x53
	// Bits
	#define LIB_MCP2515_TXBnEID8_EID8				0
	#define LIB_MCP2515_TXBnEID8_EID9				1
	#define LIB_MCP2515_TXBnEID8_EID10				2
	#define LIB_MCP2515_TXBnEID8_EID11				3
	#define LIB_MCP2515_TXBnEID8_EID12				4
	#define LIB_MCP2515_TXBnEID8_EID13				5
	#define LIB_MCP2515_TXBnEID8_EID14				6
	#define LIB_MCP2515_TXBnEID8_EID15				7

	// Register 3-6 (Seite 20)
	// TXBnEID0 - TRANSMIT BUFFER n EXTENDED IDENTIFIER LOW
	#define LIB_MCP2515_TXB0EID0					0x34
	#define LIB_MCP2515_TXB1EID0					0x44
	#define LIB_MCP2515_TXB2EID0					0x54
	// Bits
	#define LIB_MCP2515_TXBnEID0_EID0				0
	#define LIB_MCP2515_TXBnEID0_EID1				1
	#define LIB_MCP2515_TXBnEID0_EID2				2
	#define LIB_MCP2515_TXBnEID0_EID3				3
	#define LIB_MCP2515_TXBnEID0_EID4				4
	#define LIB_MCP2515_TXBnEID0_EID5				5
	#define LIB_MCP2515_TXBnEID0_EID6				6
	#define LIB_MCP2515_TXBnEID0_EID7				7

	// Register 3-7 (Seite 21)
	// TXBnDLC - TRANSMIT BUFFER n DATA LENGTH CODE
	#define LIB_MCP2515_TXB0DLC						0x35
	#define LIB_MCP2515_TXB1DLC						0x45
	#define LIB_MCP2515_TXB2DLC						0x55
	// Bits
	#define LIB_MCP2515_TXBnDLC_DLC0				0
	#define LIB_MCP2515_TXBnDLC_DLC1				1
	#define LIB_MCP2515_TXBnDLC_DLC2				2
	#define LIB_MCP2515_TXBnDLC_DLC3				3
	#define LIB_MCP2515_TXBnDLC_RTR					6

	// Register 3-8 (Seite 21)
	// TXBnDm - TRANSMIT BUFFER n DATA BYTE m
	#define LIB_MCP2515_TXB0D0						0x36
	#define LIB_MCP2515_TXB0D1						0x37
	#define LIB_MCP2515_TXB0D2						0x38
	#define LIB_MCP2515_TXB0D3						0x39
	#define LIB_MCP2515_TXB0D4						0x3A
	#define LIB_MCP2515_TXB0D5						0x3B
	#define LIB_MCP2515_TXB0D6						0x3C
	#define LIB_MCP2515_TXB0D7						0x3D
	#define LIB_MCP2515_TXB1D0						0x46
	#define LIB_MCP2515_TXB1D1						0x47
	#define LIB_MCP2515_TXB1D2						0x48
	#define LIB_MCP2515_TXB1D3						0x49
	#define LIB_MCP2515_TXB1D4						0x4A
	#define LIB_MCP2515_TXB1D5						0x4B
	#define LIB_MCP2515_TXB1D6						0x4C
	#define LIB_MCP2515_TXB1D7						0x4D
	#define LIB_MCP2515_TXB2D0						0x56
	#define LIB_MCP2515_TXB2D1						0x57
	#define LIB_MCP2515_TXB2D2						0x58
	#define LIB_MCP2515_TXB2D3						0x59
	#define LIB_MCP2515_TXB2D4						0x5A
	#define LIB_MCP2515_TXB2D5						0x5B
	#define LIB_MCP2515_TXB2D6						0x5C
	#define LIB_MCP2515_TXB2D7						0x5D
	// Bits
	#define LIB_MCP2515_TXBnDm_0					0
	#define LIB_MCP2515_TXBnDm_1					1
	#define LIB_MCP2515_TXBnDm_2					2
	#define LIB_MCP2515_TXBnDm_3					3
	#define LIB_MCP2515_TXBnDm_4					4
	#define LIB_MCP2515_TXBnDm_5					5
	#define LIB_MCP2515_TXBnDm_6					6
	#define LIB_MCP2515_TXBnDm_7					7



	// Register 4-1 (Seite 27)
	// RXB0CTRL - RECEIVE BUFFER 0 CONTROL
	#define LIB_MCP2515_RXB0CTRL					0x60
	// Bits
	#define LIB_MCP2515_RXB0CTRL_FILHIT0			0
	#define LIB_MCP2515_RXB0CTRL_BUKT1				1
	#define LIB_MCP2515_RXB0CTRL_BUKT				2
	#define LIB_MCP2515_RXB0CTRL_RXRTR				3
	#define LIB_MCP2515_RXB0CTRL_RXM0				5
	#define LIB_MCP2515_RXB0CTRL_RXM1				6

	// Register 4-2 (Seite 28)
	// RXB1CTRL - RECEIVE BUFFER 1 CONTROL
	#define LIB_MCP2515_RXB1CTRL					0x70
	// Bits
	#define LIB_MCP2515_RXB1CTRL_FILHIT0			0
	#define LIB_MCP2515_RXB1CTRL_FILHIT1			1
	#define LIB_MCP2515_RXB1CTRL_FILHIT2			2
	#define LIB_MCP2515_RXB1CTRL_RXRTR				3
	#define LIB_MCP2515_RXB1CTRL_RXM0				5
	#define LIB_MCP2515_RXB1CTRL_RXM1				6

	// Register 4-3 (Seite 29)
	// BFPCTRL - RXnBF PIN CONTROL AND STATUS
	#define LIB_MCP2515_BFPCTRL						0x0C
	// Bits
	#define LIB_MCP2515_BFPCTRL_B0BFM				0
	#define LIB_MCP2515_BFPCTRL_B1BFM				1
	#define LIB_MCP2515_BFPCTRL_B0BFE				2
	#define LIB_MCP2515_BFPCTRL_B1BFE				3
	#define LIB_MCP2515_BFPCTRL_B0BFS				4
	#define LIB_MCP2515_BFPCTRL_B1BFS				5

	// Register 4-4 (Seite 29)
	// RXBnSIDH - RECEIVE BUFFER n STANDARD IDENTIFIER HIGH
	#define LIB_MCP2515_RXB0SIDH					0x61
	#define LIB_MCP2515_RXB1SIDH					0x71
	// Bits
	#define LIB_MCP2515_RXBnSIDH_SID3				0
	#define LIB_MCP2515_RXBnSIDH_SID4				1
	#define LIB_MCP2515_RXBnSIDH_SID5				2
	#define LIB_MCP2515_RXBnSIDH_SID6				3
	#define LIB_MCP2515_RXBnSIDH_SID7				4
	#define LIB_MCP2515_RXBnSIDH_SID8				5
	#define LIB_MCP2515_RXBnSIDH_SID9				6
	#define LIB_MCP2515_RXBnSIDH_SID10				7

	// Register 4-5 (Seite 30)
	// RXBnSIDL - TRANSMIT BUFFER n STANDARD IDENTIFIER LOW
	#define LIB_MCP2515_RXB0SIDL					0x62
	#define LIB_MCP2515_RXB1SIDL					0x72
	// Bits
	#define LIB_MCP2515_RXBnSIDL_EID16				0
	#define LIB_MCP2515_RXBnSIDL_EID17				1
	#define LIB_MCP2515_RXBnSIDL_IDE				3
	#define LIB_MCP2515_RXBnSIDL_SRR				4
	#define LIB_MCP2515_RXBnSIDL_SID0				5
	#define LIB_MCP2515_RXBnSIDL_SID1				6
	#define LIB_MCP2515_RXBnSIDL_SID2				7

	// Register 4-6 (Seite 30)
	// RXBnEID8 - RECEIVE BUFFER n EXTENDED IDENTIFIER HIGH
	#define LIB_MCP2515_RXB0EID8					0x63
	#define LIB_MCP2515_RXB1EID8					0x73
	// Bits
	#define LIB_MCP2515_RXBnEID8_EID8				0
	#define LIB_MCP2515_RXBnEID8_EID9				1
	#define LIB_MCP2515_RXBnEID8_EID10				2
	#define LIB_MCP2515_RXBnEID8_EID11				3
	#define LIB_MCP2515_RXBnEID8_EID12				4
	#define LIB_MCP2515_RXBnEID8_EID13				5
	#define LIB_MCP2515_RXBnEID8_EID14				6
	#define LIB_MCP2515_RXBnEID8_EID15				7

	// Register 4-7 (Seite 31)
	// RXBnEID0 - RECEIVE BUFFER n EXTENDED IDENTIFIER LOW
	#define LIB_MCP2515_RXB0EID0					0x64
	#define LIB_MCP2515_RXB1EID0					0x74
	// Bits
	#define LIB_MCP2515_RXBnEID0_EID0				0
	#define LIB_MCP2515_RXBnEID0_EID1				1
	#define LIB_MCP2515_RXBnEID0_EID2				2
	#define LIB_MCP2515_RXBnEID0_EID3				3
	#define LIB_MCP2515_RXBnEID0_EID4				4
	#define LIB_MCP2515_RXBnEID0_EID5				5
	#define LIB_MCP2515_RXBnEID0_EID6				6
	#define LIB_MCP2515_RXBnEID0_EID7				7

	// Register 4-8 (Seite 31)
	// RXBnDLC - RECEIVE BUFFER n DATA LENGTH CODE
	#define LIB_MCP2515_RXB0DLC						0x65
	#define LIB_MCP2515_RXB1DLC						0x75
	// Bits
	#define LIB_MCP2515_RXBnDLC_DLC0				0
	#define LIB_MCP2515_RXBnDLC_DLC1				1
	#define LIB_MCP2515_RXBnDLC_DLC2				2
	#define LIB_MCP2515_RXBnDLC_DLC3				3
	#define LIB_MCP2515_RXBnDLC_RB0					4
	#define LIB_MCP2515_RXBnDLC_RB1					5
	#define LIB_MCP2515_RXBnDLC_RTR					6

	// Register 4-9 (Seite 31)
	// RXBnDm - TRANSMIT BUFFER n DATA BYTE m
	#define LIB_MCP2515_RXB0D0						0x66
	#define LIB_MCP2515_RXB0D1						0x67
	#define LIB_MCP2515_RXB0D2						0x68
	#define LIB_MCP2515_RXB0D3						0x69
	#define LIB_MCP2515_RXB0D4						0x6A
	#define LIB_MCP2515_RXB0D5						0x6B
	#define LIB_MCP2515_RXB0D6						0x6C
	#define LIB_MCP2515_RXB0D7						0x6D
	#define LIB_MCP2515_RXB1D0						0x76
	#define LIB_MCP2515_RXB1D1						0x77
	#define LIB_MCP2515_RXB1D2						0x78
	#define LIB_MCP2515_RXB1D3						0x79
	#define LIB_MCP2515_RXB1D4						0x7A
	#define LIB_MCP2515_RXB1D5						0x7B
	#define LIB_MCP2515_RXB1D6						0x7C
	#define LIB_MCP2515_RXB1D7						0x7D
	// Bits
	#define LIB_MCP2515_RXBnDm_0					0
	#define LIB_MCP2515_RXBnDm_1					1
	#define LIB_MCP2515_RXBnDm_2					2
	#define LIB_MCP2515_RXBnDm_3					3
	#define LIB_MCP2515_RXBnDm_4					4
	#define LIB_MCP2515_RXBnDm_5					5
	#define LIB_MCP2515_RXBnDm_6					6
	#define LIB_MCP2515_RXBnDm_7					7

	// Register 4-10 (Seite 34)
	// RXFnSIDH - FILTER n STANDARD IDENTIFIER HIGH
	#define LIB_MCP2515_RXF0SIDH					0x00
	#define LIB_MCP2515_RXF1SIDH					0x04
	#define LIB_MCP2515_RXF2SIDH					0x08
	#define LIB_MCP2515_RXF3SIDH					0x10
	#define LIB_MCP2515_RXF4SIDH					0x14
	#define LIB_MCP2515_RXF5SIDH					0x18
	// Bits
	#define LIB_MCP2515_RXFnSIDH_SID3				0
	#define LIB_MCP2515_RXFnSIDH_SID4				1
	#define LIB_MCP2515_RXFnSIDH_SID5				2
	#define LIB_MCP2515_RXFnSIDH_SID6				3
	#define LIB_MCP2515_RXFnSIDH_SID7				4
	#define LIB_MCP2515_RXFnSIDH_SID8				5
	#define LIB_MCP2515_RXFnSIDH_SID9				6
	#define LIB_MCP2515_RXFnSIDH_SID10				7

	// Register 4-11 (Seite 34)
	// RXFnSIDL - FILTER n STANDARD IDENTIFIER LOW
	#define LIB_MCP2515_RXF0SIDL					0x01
	#define LIB_MCP2515_RXF1SIDL					0x05
	#define LIB_MCP2515_RXF2SIDL					0x09
	#define LIB_MCP2515_RXF3SIDL					0x11
	#define LIB_MCP2515_RXF4SIDL					0x15
	#define LIB_MCP2515_RXF5SIDL					0x19
	// Bits
	#define LIB_MCP2515_RXFnSIDL_EID16				0
	#define LIB_MCP2515_RXFnSIDL_EID17				1
	#define LIB_MCP2515_RXFnSIDL_IDE				3
	#define LIB_MCP2515_RXFnSIDL_SID0				5
	#define LIB_MCP2515_RXFnSIDL_SID1				6
	#define LIB_MCP2515_RXFnSIDL_SID2				7

	// Register 4-12 (Seite 35)
	// RXFnEID8 - FILTER n EXTENDED IDENTIFIER HIGH
	#define LIB_MCP2515_RXF0EID8					0x02
	#define LIB_MCP2515_RXF1EID8					0x06
	#define LIB_MCP2515_RXF2EID8					0x0A
	#define LIB_MCP2515_RXF3EID8					0x12
	#define LIB_MCP2515_RXF4EID8					0x16
	#define LIB_MCP2515_RXF5EID8					0x1A
	// Bits
	#define LIB_MCP2515_RXFnEID8_EID8				0
	#define LIB_MCP2515_RXFnEID8_EID9				1
	#define LIB_MCP2515_RXFnEID8_EID10				2
	#define LIB_MCP2515_RXFnEID8_EID11				3
	#define LIB_MCP2515_RXFnEID8_EID12				4
	#define LIB_MCP2515_RXFnEID8_EID13				5
	#define LIB_MCP2515_RXFnEID8_EID14				6
	#define LIB_MCP2515_RXFnEID8_EID15				7

	// Register 4-13 (Seite 35)
	// RXFnEID0 - FILTER n EXTENDED IDENTIFIER LOW
	#define LIB_MCP2515_RXF0EID0					0x03
	#define LIB_MCP2515_RXF1EID0					0x07
	#define LIB_MCP2515_RXF2EID0					0x0B
	#define LIB_MCP2515_RXF3EID0					0x13
	#define LIB_MCP2515_RXF4EID0					0x17
	#define LIB_MCP2515_RXF5EID0					0x1B
	// Bits
	#define LIB_MCP2515_RXFnEID0_EID0				0
	#define LIB_MCP2515_RXFnEID0_EID1				1
	#define LIB_MCP2515_RXFnEID0_EID2				2
	#define LIB_MCP2515_RXFnEID0_EID3				3
	#define LIB_MCP2515_RXFnEID0_EID4				4
	#define LIB_MCP2515_RXFnEID0_EID5				5
	#define LIB_MCP2515_RXFnEID0_EID6				6
	#define LIB_MCP2515_RXFnEID0_EID7				7

	// Register 4-14 (Seite 35)
	// RXMnSIDH - MASK n STANDARD IDENTIFIER HIGH
	#define LIB_MCP2515_RXM0SIDH					0x20
	#define LIB_MCP2515_RXM1SIDH					0x24
	// Bits
	#define LIB_MCP2515_RXMnSIDH_SID3				0
	#define LIB_MCP2515_RXMnSIDH_SID4				1
	#define LIB_MCP2515_RXMnSIDH_SID5				2
	#define LIB_MCP2515_RXMnSIDH_SID6				3
	#define LIB_MCP2515_RXMnSIDH_SID7				4
	#define LIB_MCP2515_RXMnSIDH_SID8				5
	#define LIB_MCP2515_RXMnSIDH_SID9				6
	#define LIB_MCP2515_RXMnSIDH_SID10				7

	// Register 4-15 (Seite 36)
	// RXMnSIDL - MASK n STANDARD IDENTIFIER LOW
	#define LIB_MCP2515_RXM0SIDL					0x21
	#define LIB_MCP2515_RXM1SIDL					0x25
	// Bits
	#define LIB_MCP2515_RXMnSIDL_EID16				0
	#define LIB_MCP2515_RXMnSIDL_EID17				1
	#define LIB_MCP2515_RXMnSIDL_SID0				5
	#define LIB_MCP2515_RXMnSIDL_SID1				6
	#define LIB_MCP2515_RXMnSIDL_SID2				7

	// Register 4-16 (Seite 36)
	// RXMnEID8 - MASK n EXTENDED IDENTIFIER HIGH
	#define LIB_MCP2515_RXM0EID8					0x22
	#define LIB_MCP2515_RXM1EID8					0x26
	// Bits
	#define LIB_MCP2515_RXMnEID8_EID8				0
	#define LIB_MCP2515_RXMnEID8_EID9				1
	#define LIB_MCP2515_RXMnEID8_EID10				2
	#define LIB_MCP2515_RXMnEID8_EID11				3
	#define LIB_MCP2515_RXMnEID8_EID12				4
	#define LIB_MCP2515_RXMnEID8_EID13				5
	#define LIB_MCP2515_RXMnEID8_EID14				6
	#define LIB_MCP2515_RXMnEID8_EID15				7

	// Register 4-17 (Seite 36)
	// RXMnEID0 - MASK n EXTENDED IDENTIFIER LOW
	#define LIB_MCP2515_RXM0EID0					0x23
	#define LIB_MCP2515_RXM1EID0					0x27
	// Bits
	#define LIB_MCP2515_RXMnEID0_EID0				0
	#define LIB_MCP2515_RXMnEID0_EID1				1
	#define LIB_MCP2515_RXMnEID0_EID2				2
	#define LIB_MCP2515_RXMnEID0_EID3				3
	#define LIB_MCP2515_RXMnEID0_EID4				4
	#define LIB_MCP2515_RXMnEID0_EID5				5
	#define LIB_MCP2515_RXMnEID0_EID6				6
	#define LIB_MCP2515_RXMnEID0_EID7				7



	// Register 5-1 (Seite 42)
	// CNF1 - CONFIGURATION 1
	#define LIB_MCP2515_CNF1						0x2A
	// Bits
	#define LIB_MCP2515_CNF1_BRP0					0
	#define LIB_MCP2515_CNF1_BRP1					1
	#define LIB_MCP2515_CNF1_BRP2					2
	#define LIB_MCP2515_CNF1_BRP3					3
	#define LIB_MCP2515_CNF1_BRP4					4
	#define LIB_MCP2515_CNF1_BRP5					5
	#define LIB_MCP2515_CNF1_SJW0					6
	#define LIB_MCP2515_CNF1_SJW1					7

	// Register 5-2 (Seite 42)
	// CNF2 - CONFIGURATION 1
	#define LIB_MCP2515_CNF2						0x29
	// Bits
	#define LIB_MCP2515_CNF2_PRSEG0					0
	#define LIB_MCP2515_CNF2_PRSEG1					1
	#define LIB_MCP2515_CNF2_PRSEG2					2
	#define LIB_MCP2515_CNF2_PRSEG10				3
	#define LIB_MCP2515_CNF2_PRSEG11				4
	#define LIB_MCP2515_CNF2_PRSEG12				5
	#define LIB_MCP2515_CNF2_SAM					6
	#define LIB_MCP2515_CNF2_BTLMODE				7

	// Register 5-3 (Seite 43)
	// CNF3 - CONFIGURATION 1
	#define LIB_MCP2515_CNF3						0x28
	// Bits
	#define LIB_MCP2515_CNF3_PHSEG20				0
	#define LIB_MCP2515_CNF3_PHSEG21				1
	#define LIB_MCP2515_CNF3_PHSEG22				2
	#define LIB_MCP2515_CNF3_WAKFIL					6
	#define LIB_MCP2515_CNF3_SOF					7



	// Register 6-1 (Seite 46)
	// TEC - TRANSMIT ERROR COUNTER
	#define LIB_MCP2515_TEC							0x1C
	// Bits
	#define ISB_MCP2515_TEC_0						0
	#define ISB_MCP2515_TEC_1						1
	#define ISB_MCP2515_TEC_2						2
	#define ISB_MCP2515_TEC_3						3
	#define ISB_MCP2515_TEC_4						4
	#define ISB_MCP2515_TEC_5						5
	#define ISB_MCP2515_TEC_6						6
	#define ISB_MCP2515_TEC_7						7

	// Register 6-2 (Seite 46)
	// REC - RECEIVE ERROR COUNTER
	#define LIB_MCP2515_REC							0x1D
	// Bits
	#define ISB_MCP2515_REC_0						0
	#define ISB_MCP2515_REC_1						1
	#define ISB_MCP2515_REC_2						2
	#define ISB_MCP2515_REC_3						3
	#define ISB_MCP2515_REC_4						4
	#define ISB_MCP2515_REC_5						5
	#define ISB_MCP2515_REC_6						6
	#define ISB_MCP2515_REC_7						7

	// Register 6-3 (Seite 47)
	// EFLG - ERROR FLAG
	#define LIB_MCP2515_EFLG						0x2D
	// Bits
	#define ISB_MCP2515_EFLG_EWARN					0
	#define ISB_MCP2515_EFLG_RXWAR					1
	#define ISB_MCP2515_EFLG_TXWAR					2
	#define ISB_MCP2515_EFLG_RXEP					3
	#define ISB_MCP2515_EFLG_TXEP					4
	#define ISB_MCP2515_EFLG_TXBO					5
	#define ISB_MCP2515_EFLG_RX0OVR					6
	#define ISB_MCP2515_EFLG_RX1OVR					7



	// Register 7-1 (Seite 50)
	// CANINTE - CAN INTERRUPT ENABLE
	#define LIB_MCP2515_CANINTE						0x2B
	// Bits
	#define	LIB_MCP2515_CANINTE_RX0IE				0
	#define LIB_MCP2515_CANINTE_RX1IE				1
	#define LIB_MCP2515_CANINTE_TX0IE				2
	#define LIB_MCP2515_CANINTE_TX1IE				3
	#define LIB_MCP2515_CANINTE_TX2IE				4
	#define LIB_MCP2515_CANINTE_ERRIE				5
	#define LIB_MCP2515_CANINTE_WAKIE				6
	#define LIB_MCP2515_CANINTE_MERRE				7

	// Register 7-2 (Seite 51)
	// CANINTF - CAN INTERRUPT FLAG
	#define LIB_MCP2515_CANINTF						0x2C
	// Bits
	#define LIB_MCP2515_CANINTF_RX0IF				0
	#define LIB_MCP2515_CANINTF_RX1IF				1
	#define LIB_MCP2515_CANINTF_TX0IF				2
	#define LIB_MCP2515_CANINTF_TX1IF				3
	#define LIB_MCP2515_CANINTF_TX2IF				4
	#define LIB_MCP2515_CANINTF_ERRIF				5
	#define LIB_MCP2515_CANINTF_WAKIF				6
	#define LIB_MCP2515_CANINTF_MERRF				7



	// Register 10-1 (Seite 58)
	// CANCTRL - CAN CONTROL REGISTER
	#define LIB_MCP2515_CANCTRL						0x0F
	// Bits
	#define LIB_MCP2515_CANCTRL_CLKPRE0				0
	#define LIB_MCP2515_CANCTRL_CLKPRE1				1
	#define LIB_MCP2515_CANCTRL_CLKEN				2
	#define LIB_MCP2515_CANCTRL_OSM					3
	#define LIB_MCP2515_CANCTRL_ABAT				4
	#define LIB_MCP2515_CANCTRL_REQOP0				5
	#define LIB_MCP2515_CANCTRL_REQOP1				6
	#define LIB_MCP2515_CANCTRL_REQOP2				7
	// Values
	#define LIB_MCP2515_MODE_NORMAL     			0x00
	#define LIB_MCP2515_MODE_SLEEP      			0x20
	#define LIB_MCP2515_MODE_LOOPBACK   			0x40
	#define LIB_MCP2515_MODE_LISTENONLY 			0x60
	#define LIB_MCP2515_MODE_CONFIG					0x80
	#define LIB_MCP2515_MODE_POWERUP				0xE0
	#define LIB_MCP2515_MODE_MASK					0xE0
	#define LIB_MCP2515_ABORT_TX        			0x10
	#define LIB_MCP2515_MODE_ONESHOT				0x08
	#define LIB_MCP2515_CLKOUT_ENABLE				0x04
	#define LIB_MCP2515_CLKOUT_DISABLE				0x00
	#define LIB_MCP2515_CLKOUT_PS1					0x00
	#define LIB_MCP2515_CLKOUT_PS2					0x01
	#define LIB_MCP2515_CLKOUT_PS4					0x02
	#define LIB_MCP2515_CLKOUT_PS8					0x03

	// Register 10-2 (Seite 59)
	// CANSTAT - CAN STATUS REGISTER
	#define LIB_MCP2515_CANSTAT						0x0E
	// Bits
	#define LIB_MCP2515_CANSTAT_ICOD0				1
	#define LIB_MCP2515_CANSTAT_ICOD1				2
	#define LIB_MCP2515_CANSTAT_ICOD2				3
	#define LIB_MCP2515_CANSTAT_OPMOD0				5
	#define LIB_MCP2515_CANSTAT_OPMOD1				6
	#define LIB_MCP2515_CANSTAT_OPMOD2				7



	// Reset Instruction 12.2 (Seite 63)
	#define LIB_MCP2515_RESET						0xC0

	// Read Instruction 12.3 (Seite 63)
	#define LIB_MCP2515_READ						0x03

	// Read Rx Buffer Instruction 12.4 (Seite 63)
	#define LIB_MCP2515_READ_RX_BUFFER0				0x90
	#define LIB_MCP2515_READ_RX_BUFFER1				0x94

	// Write Instruction 12.5 (Seite 63)
	#define LIB_MCP2515_WRITE						0x02

	// Load Tx Buffer Instruction 12.6 (Seite 63)
	#define LIB_MCP2515_LOAD_TX_BUFFER0				0x40
	#define LIB_MCP2515_LOAD_TX_BUFFER1				0x42
	#define LIB_MCP2515_LOAD_TX_BUFFER2				0x44

	// Request to Send (RTS) Instruction 12.7 (Seite 63)
	#define LIB_MCP2515_RTS_TX0						0x81
	#define LIB_MCP2515_RTS_TX1						0x82
	#define LIB_MCP2515_RTS_TX2						0x84
	#define LIB_MCP2515_RTS_ALL						0x87

	// Read Status Instruction 12.8 (Seite 63)
	#define LIB_MCP2515_READ_STATUS					0xA0
	// Antwort
	#define LIB_MCP2515_READ_STATUS_CANINTF_RX0IF	0
	#define LIB_MCP2515_READ_STATUS_CANINTF_RX1IF	1
	#define LIB_MCP2515_READ_STATUS_TXB0CTRL_TXREQ	2
	#define LIB_MCP2515_READ_STATUS_CANINTF_TX0IF	3
	#define LIB_MCP2515_READ_STATUS_TXB1CTRL_TXREQ	4
	#define LIB_MCP2515_READ_STATUS_CANINTF_TX1IF	5
	#define LIB_MCP2515_READ_STATUS_TXB2CTRL_TXREQ	6
	#define LIB_MCP2515_READ_STATUS_CANINTF_TX2IF	7

	// Rx Status Instruction 12.9 (Seite 64)
	#define LIB_MCP2515_RX_STATUS					0xB0
	// Antwort
	//#define LIB_MCP2515_RX_STATUS_INSTRUCTION_	0
	//#define LIB_MCP2515_RX_STATUS_INSTRUCTION_	1
	//#define LIB_MCP2515_RX_STATUS_INSTRUCTION_	2
	//#define LIB_MCP2515_RX_STATUS_INSTRUCTION_	3
	//#define LIB_MCP2515_RX_STATUS_INSTRUCTION_	4
	//#define LIB_MCP2515_RX_STATUS_INSTRUCTION_	5
	#define LIB_MCP2515_RX_STATUS_INSTRUCTION_CANINTF_RX0IF	6
	#define LIB_MCP2515_RX_STATUS_INSTRUCTION_CANINTF_RX1IF	7

	// Bit Modify Instruction 12.10 (Seite 64)
	#define LIB_MCP2515_BIT_MODIFY					0x05



#endif /* LIB_MCP2515_DEF_H_ */
