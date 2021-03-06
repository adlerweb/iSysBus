/**
 * @file		fw/fw_34/1.0/main.c
 *
 * @brief		Firmware.
 *
 * This file includes the Firmware.
 *
 * @author		� Patrick Amrhein <trick-at-isysbus-dot-org> 01.05.2010.
 *
 * @date		$Date$
 *
 * @version		$Rev$
 *
 * @note
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see http:*www.gnu.org/licenses.
 */





#include <stdio.h>



#include <1.2.0/core/isb_fw_switch.h>



const uint8_t Isb_Firmware_Code[4] = { 0x22, 0x00, 0x01, 0x00 };



#define ISB_INF_CAN0 1
#if ISB_INF_CAN0 == 1
	#define ISB_INF_CAN0_CLOCK 4000000
	#define ISB_INF_CAN0_SPEED 50000
	#define ISB_INF_CAN0_SS PORTB_PIN0
	#define ISB_INF_CAN0_RS MCP2515_RX1BF
	#define ISB_INF_CAN0_INT INTERRUPT0
	#define ISB_INF_CAN0_MODE LIB_MCP2515_MODE_NORMAL
#endif /* ISB_INF_CAN0 == 1 */



#define ISB_CH_MAX 17



#define ISB_CH_0 0
#if defined(ISB_CH_0)
	#define ISB_CH_0_EEADDR_CTRL 0x0000
	#define ISB_APP_DIGIN_0 0
	#if defined(ISB_APP_DIGIN_0)
		#define ISB_APP_DIGIN_0_CH 0
		#define ISB_APP_DIGIN_0_EEADDR_CFG0 0x0001
		#define ISB_APP_DIGIN_0_EEADDR_CFG1 0x0002
		#define ISB_APP_DIGIN_0_EEADDR_CFG2 0x0003
		#define ISB_APP_DIGIN_0_EEADDR_CFG3 0x0004
		#define ISB_APP_DIGIN_0_PIN0 C | 0 | PULLUP
		#define ISB_APP_DIGIN_0_OBJ_1BIT_0 0
		#define ISB_APP_DIGIN_0_OBJ_1BIT_1 1
		#define ISB_APP_DIGIN_0_OBJ_1BIT_2 2
		#define ISB_APP_DIGIN_0_OBJ_4BIT_0 0
		#define ISB_APP_DIGIN_0_OBJ_8BIT_0 0
	#endif /* ISB_APP_DIGIN_0 */
	#define ISB_OBJ_1BIT_0 
	#if defined(ISB_OBJ_1BIT_0)
		#define ISB_OBJ_1BIT_0_CH 0
		#define ISB_OBJ_1BIT_0_OBJ 0
		#define ISB_OBJ_1BIT_0_EEADDR_CTRL 0x0005
		#define ISB_OBJ_1BIT_0_EEADDR_TOV 0x0006
		#define ISB_OBJ_1BIT_0_EEADDR_VALUEINIT 0x0007
	#endif /* ISB_OBJ_1BIT_0 */
	#define ISB_OBJ_1BIT_1 
	#if defined(ISB_OBJ_1BIT_1)
		#define ISB_OBJ_1BIT_1_CH 0
		#define ISB_OBJ_1BIT_1_OBJ 1
		#define ISB_OBJ_1BIT_1_EEADDR_CTRL 0x0008
		#define ISB_OBJ_1BIT_1_EEADDR_TOV 0x0009
		#define ISB_OBJ_1BIT_1_EEADDR_VALUEINIT 0x000A
	#endif /* ISB_OBJ_1BIT_1 */
	#define ISB_OBJ_1BIT_2 
	#if defined(ISB_OBJ_1BIT_2)
		#define ISB_OBJ_1BIT_2_CH 0
		#define ISB_OBJ_1BIT_2_OBJ 2
		#define ISB_OBJ_1BIT_2_EEADDR_CTRL 0x000B
		#define ISB_OBJ_1BIT_2_EEADDR_TOV 0x000C
		#define ISB_OBJ_1BIT_2_EEADDR_VALUEINIT 0x000D
	#endif /* ISB_OBJ_1BIT_2 */
	#define ISB_OBJ_4BIT_0 
	#if defined(ISB_OBJ_4BIT_0)
		#define ISB_OBJ_4BIT_0_CH 0
		#define ISB_OBJ_4BIT_0_OBJ 3
		#define ISB_OBJ_4BIT_0_EEADDR_CTRL 0x000E
		#define ISB_OBJ_4BIT_0_EEADDR_TOV 0x000F
		#define ISB_OBJ_4BIT_0_EEADDR_VALUEINIT 0x0010
	#endif /* ISB_OBJ_4BIT_0 */
	#define ISB_OBJ_8BIT_0 
	#if defined(ISB_OBJ_8BIT_0)
		#define ISB_OBJ_8BIT_0_CH 0
		#define ISB_OBJ_8BIT_0_OBJ 4
		#define ISB_OBJ_8BIT_0_EEADDR_CTRL 0x0011
		#define ISB_OBJ_8BIT_0_EEADDR_TOV 0x0012
		#define ISB_OBJ_8BIT_0_EEADDR_VALUEINIT 0x0013
	#endif /* ISB_OBJ_8BIT_0 */
	#define ISB_CH_0_EEADDR_CRC 0x0014
#endif /* ISB_CH_0 */
#define ISB_CH_1 1
#if defined(ISB_CH_1)
	#define ISB_CH_1_EEADDR_CTRL 0x0015
	#define ISB_APP_DIGIN_1 1
	#if defined(ISB_APP_DIGIN_1)
		#define ISB_APP_DIGIN_1_CH 1
		#define ISB_APP_DIGIN_1_EEADDR_CFG0 0x0016
		#define ISB_APP_DIGIN_1_EEADDR_CFG1 0x0017
		#define ISB_APP_DIGIN_1_EEADDR_CFG2 0x0018
		#define ISB_APP_DIGIN_1_EEADDR_CFG3 0x0019
		#define ISB_APP_DIGIN_1_PIN0 C | 1 | PULLUP
		#define ISB_APP_DIGIN_1_OBJ_1BIT_0 3
		#define ISB_APP_DIGIN_1_OBJ_1BIT_1 4
		#define ISB_APP_DIGIN_1_OBJ_1BIT_2 5
		#define ISB_APP_DIGIN_1_OBJ_4BIT_0 1
		#define ISB_APP_DIGIN_1_OBJ_8BIT_0 1
	#endif /* ISB_APP_DIGIN_1 */
	#define ISB_OBJ_1BIT_3 
	#if defined(ISB_OBJ_1BIT_3)
		#define ISB_OBJ_1BIT_3_CH 1
		#define ISB_OBJ_1BIT_3_OBJ 5
		#define ISB_OBJ_1BIT_3_EEADDR_CTRL 0x001A
		#define ISB_OBJ_1BIT_3_EEADDR_TOV 0x001B
		#define ISB_OBJ_1BIT_3_EEADDR_VALUEINIT 0x001C
	#endif /* ISB_OBJ_1BIT_3 */
	#define ISB_OBJ_1BIT_4 
	#if defined(ISB_OBJ_1BIT_4)
		#define ISB_OBJ_1BIT_4_CH 1
		#define ISB_OBJ_1BIT_4_OBJ 6
		#define ISB_OBJ_1BIT_4_EEADDR_CTRL 0x001D
		#define ISB_OBJ_1BIT_4_EEADDR_TOV 0x001E
		#define ISB_OBJ_1BIT_4_EEADDR_VALUEINIT 0x001F
	#endif /* ISB_OBJ_1BIT_4 */
	#define ISB_OBJ_1BIT_5 
	#if defined(ISB_OBJ_1BIT_5)
		#define ISB_OBJ_1BIT_5_CH 1
		#define ISB_OBJ_1BIT_5_OBJ 7
		#define ISB_OBJ_1BIT_5_EEADDR_CTRL 0x0020
		#define ISB_OBJ_1BIT_5_EEADDR_TOV 0x0021
		#define ISB_OBJ_1BIT_5_EEADDR_VALUEINIT 0x0022
	#endif /* ISB_OBJ_1BIT_5 */
	#define ISB_OBJ_4BIT_1 
	#if defined(ISB_OBJ_4BIT_1)
		#define ISB_OBJ_4BIT_1_CH 1
		#define ISB_OBJ_4BIT_1_OBJ 8
		#define ISB_OBJ_4BIT_1_EEADDR_CTRL 0x0023
		#define ISB_OBJ_4BIT_1_EEADDR_TOV 0x0024
		#define ISB_OBJ_4BIT_1_EEADDR_VALUEINIT 0x0025
	#endif /* ISB_OBJ_4BIT_1 */
	#define ISB_OBJ_8BIT_1 
	#if defined(ISB_OBJ_8BIT_1)
		#define ISB_OBJ_8BIT_1_CH 1
		#define ISB_OBJ_8BIT_1_OBJ 9
		#define ISB_OBJ_8BIT_1_EEADDR_CTRL 0x0026
		#define ISB_OBJ_8BIT_1_EEADDR_TOV 0x0027
		#define ISB_OBJ_8BIT_1_EEADDR_VALUEINIT 0x0028
	#endif /* ISB_OBJ_8BIT_1 */
	#define ISB_CH_1_EEADDR_CRC 0x0029
#endif /* ISB_CH_1 */
#define ISB_CH_2 2
#if defined(ISB_CH_2)
	#define ISB_CH_2_EEADDR_CTRL 0x002A
	#define ISB_APP_DIGIN_2 2
	#if defined(ISB_APP_DIGIN_2)
		#define ISB_APP_DIGIN_2_CH 2
		#define ISB_APP_DIGIN_2_EEADDR_CFG0 0x002B
		#define ISB_APP_DIGIN_2_EEADDR_CFG1 0x002C
		#define ISB_APP_DIGIN_2_EEADDR_CFG2 0x002D
		#define ISB_APP_DIGIN_2_EEADDR_CFG3 0x002E
		#define ISB_APP_DIGIN_2_PIN0 C | 2 | PULLUP
		#define ISB_APP_DIGIN_2_OBJ_1BIT_0 6
		#define ISB_APP_DIGIN_2_OBJ_1BIT_1 7
		#define ISB_APP_DIGIN_2_OBJ_1BIT_2 8
		#define ISB_APP_DIGIN_2_OBJ_4BIT_0 2
		#define ISB_APP_DIGIN_2_OBJ_8BIT_0 2
	#endif /* ISB_APP_DIGIN_2 */
	#define ISB_OBJ_1BIT_6 
	#if defined(ISB_OBJ_1BIT_6)
		#define ISB_OBJ_1BIT_6_CH 2
		#define ISB_OBJ_1BIT_6_OBJ 10
		#define ISB_OBJ_1BIT_6_EEADDR_CTRL 0x002F
		#define ISB_OBJ_1BIT_6_EEADDR_TOV 0x0030
		#define ISB_OBJ_1BIT_6_EEADDR_VALUEINIT 0x0031
	#endif /* ISB_OBJ_1BIT_6 */
	#define ISB_OBJ_1BIT_7 
	#if defined(ISB_OBJ_1BIT_7)
		#define ISB_OBJ_1BIT_7_CH 2
		#define ISB_OBJ_1BIT_7_OBJ 11
		#define ISB_OBJ_1BIT_7_EEADDR_CTRL 0x0032
		#define ISB_OBJ_1BIT_7_EEADDR_TOV 0x0033
		#define ISB_OBJ_1BIT_7_EEADDR_VALUEINIT 0x0034
	#endif /* ISB_OBJ_1BIT_7 */
	#define ISB_OBJ_1BIT_8 
	#if defined(ISB_OBJ_1BIT_8)
		#define ISB_OBJ_1BIT_8_CH 2
		#define ISB_OBJ_1BIT_8_OBJ 12
		#define ISB_OBJ_1BIT_8_EEADDR_CTRL 0x0035
		#define ISB_OBJ_1BIT_8_EEADDR_TOV 0x0036
		#define ISB_OBJ_1BIT_8_EEADDR_VALUEINIT 0x0037
	#endif /* ISB_OBJ_1BIT_8 */
	#define ISB_OBJ_4BIT_2 
	#if defined(ISB_OBJ_4BIT_2)
		#define ISB_OBJ_4BIT_2_CH 2
		#define ISB_OBJ_4BIT_2_OBJ 13
		#define ISB_OBJ_4BIT_2_EEADDR_CTRL 0x0038
		#define ISB_OBJ_4BIT_2_EEADDR_TOV 0x0039
		#define ISB_OBJ_4BIT_2_EEADDR_VALUEINIT 0x003A
	#endif /* ISB_OBJ_4BIT_2 */
	#define ISB_OBJ_8BIT_2 
	#if defined(ISB_OBJ_8BIT_2)
		#define ISB_OBJ_8BIT_2_CH 2
		#define ISB_OBJ_8BIT_2_OBJ 14
		#define ISB_OBJ_8BIT_2_EEADDR_CTRL 0x003B
		#define ISB_OBJ_8BIT_2_EEADDR_TOV 0x003C
		#define ISB_OBJ_8BIT_2_EEADDR_VALUEINIT 0x003D
	#endif /* ISB_OBJ_8BIT_2 */
	#define ISB_CH_2_EEADDR_CRC 0x003E
#endif /* ISB_CH_2 */
#define ISB_CH_3 3
#if defined(ISB_CH_3)
	#define ISB_CH_3_EEADDR_CTRL 0x003F
	#define ISB_APP_DIGIN_3 3
	#if defined(ISB_APP_DIGIN_3)
		#define ISB_APP_DIGIN_3_CH 3
		#define ISB_APP_DIGIN_3_EEADDR_CFG0 0x0040
		#define ISB_APP_DIGIN_3_EEADDR_CFG1 0x0041
		#define ISB_APP_DIGIN_3_EEADDR_CFG2 0x0042
		#define ISB_APP_DIGIN_3_EEADDR_CFG3 0x0043
		#define ISB_APP_DIGIN_3_PIN0 C | 3 | PULLUP
		#define ISB_APP_DIGIN_3_OBJ_1BIT_0 9
		#define ISB_APP_DIGIN_3_OBJ_1BIT_1 10
		#define ISB_APP_DIGIN_3_OBJ_1BIT_2 11
		#define ISB_APP_DIGIN_3_OBJ_4BIT_0 3
		#define ISB_APP_DIGIN_3_OBJ_8BIT_0 3
	#endif /* ISB_APP_DIGIN_3 */
	#define ISB_OBJ_1BIT_9 
	#if defined(ISB_OBJ_1BIT_9)
		#define ISB_OBJ_1BIT_9_CH 3
		#define ISB_OBJ_1BIT_9_OBJ 15
		#define ISB_OBJ_1BIT_9_EEADDR_CTRL 0x0044
		#define ISB_OBJ_1BIT_9_EEADDR_TOV 0x0045
		#define ISB_OBJ_1BIT_9_EEADDR_VALUEINIT 0x0046
	#endif /* ISB_OBJ_1BIT_9 */
	#define ISB_OBJ_1BIT_10 
	#if defined(ISB_OBJ_1BIT_10)
		#define ISB_OBJ_1BIT_10_CH 3
		#define ISB_OBJ_1BIT_10_OBJ 16
		#define ISB_OBJ_1BIT_10_EEADDR_CTRL 0x0047
		#define ISB_OBJ_1BIT_10_EEADDR_TOV 0x0048
		#define ISB_OBJ_1BIT_10_EEADDR_VALUEINIT 0x0049
	#endif /* ISB_OBJ_1BIT_10 */
	#define ISB_OBJ_1BIT_11 
	#if defined(ISB_OBJ_1BIT_11)
		#define ISB_OBJ_1BIT_11_CH 3
		#define ISB_OBJ_1BIT_11_OBJ 17
		#define ISB_OBJ_1BIT_11_EEADDR_CTRL 0x004A
		#define ISB_OBJ_1BIT_11_EEADDR_TOV 0x004B
		#define ISB_OBJ_1BIT_11_EEADDR_VALUEINIT 0x004C
	#endif /* ISB_OBJ_1BIT_11 */
	#define ISB_OBJ_4BIT_3 
	#if defined(ISB_OBJ_4BIT_3)
		#define ISB_OBJ_4BIT_3_CH 3
		#define ISB_OBJ_4BIT_3_OBJ 18
		#define ISB_OBJ_4BIT_3_EEADDR_CTRL 0x004D
		#define ISB_OBJ_4BIT_3_EEADDR_TOV 0x004E
		#define ISB_OBJ_4BIT_3_EEADDR_VALUEINIT 0x004F
	#endif /* ISB_OBJ_4BIT_3 */
	#define ISB_OBJ_8BIT_3 
	#if defined(ISB_OBJ_8BIT_3)
		#define ISB_OBJ_8BIT_3_CH 3
		#define ISB_OBJ_8BIT_3_OBJ 19
		#define ISB_OBJ_8BIT_3_EEADDR_CTRL 0x0050
		#define ISB_OBJ_8BIT_3_EEADDR_TOV 0x0051
		#define ISB_OBJ_8BIT_3_EEADDR_VALUEINIT 0x0052
	#endif /* ISB_OBJ_8BIT_3 */
	#define ISB_CH_3_EEADDR_CRC 0x0053
#endif /* ISB_CH_3 */
#define ISB_CH_4 4
#if defined(ISB_CH_4)
	#define ISB_CH_4_EEADDR_CTRL 0x0054
	#define ISB_APP_DIGIN_4 4
	#if defined(ISB_APP_DIGIN_4)
		#define ISB_APP_DIGIN_4_CH 4
		#define ISB_APP_DIGIN_4_EEADDR_CFG0 0x0055
		#define ISB_APP_DIGIN_4_EEADDR_CFG1 0x0056
		#define ISB_APP_DIGIN_4_EEADDR_CFG2 0x0057
		#define ISB_APP_DIGIN_4_EEADDR_CFG3 0x0058
		#define ISB_APP_DIGIN_4_PIN0 C | 4 | PULLUP
		#define ISB_APP_DIGIN_4_OBJ_1BIT_0 12
		#define ISB_APP_DIGIN_4_OBJ_1BIT_1 13
		#define ISB_APP_DIGIN_4_OBJ_1BIT_2 14
		#define ISB_APP_DIGIN_4_OBJ_4BIT_0 4
		#define ISB_APP_DIGIN_4_OBJ_8BIT_0 4
	#endif /* ISB_APP_DIGIN_4 */
	#define ISB_OBJ_1BIT_12 
	#if defined(ISB_OBJ_1BIT_12)
		#define ISB_OBJ_1BIT_12_CH 4
		#define ISB_OBJ_1BIT_12_OBJ 20
		#define ISB_OBJ_1BIT_12_EEADDR_CTRL 0x0059
		#define ISB_OBJ_1BIT_12_EEADDR_TOV 0x005A
		#define ISB_OBJ_1BIT_12_EEADDR_VALUEINIT 0x005B
	#endif /* ISB_OBJ_1BIT_12 */
	#define ISB_OBJ_1BIT_13 
	#if defined(ISB_OBJ_1BIT_13)
		#define ISB_OBJ_1BIT_13_CH 4
		#define ISB_OBJ_1BIT_13_OBJ 21
		#define ISB_OBJ_1BIT_13_EEADDR_CTRL 0x005C
		#define ISB_OBJ_1BIT_13_EEADDR_TOV 0x005D
		#define ISB_OBJ_1BIT_13_EEADDR_VALUEINIT 0x005E
	#endif /* ISB_OBJ_1BIT_13 */
	#define ISB_OBJ_1BIT_14 
	#if defined(ISB_OBJ_1BIT_14)
		#define ISB_OBJ_1BIT_14_CH 4
		#define ISB_OBJ_1BIT_14_OBJ 22
		#define ISB_OBJ_1BIT_14_EEADDR_CTRL 0x005F
		#define ISB_OBJ_1BIT_14_EEADDR_TOV 0x0060
		#define ISB_OBJ_1BIT_14_EEADDR_VALUEINIT 0x0061
	#endif /* ISB_OBJ_1BIT_14 */
	#define ISB_OBJ_4BIT_4 
	#if defined(ISB_OBJ_4BIT_4)
		#define ISB_OBJ_4BIT_4_CH 4
		#define ISB_OBJ_4BIT_4_OBJ 23
		#define ISB_OBJ_4BIT_4_EEADDR_CTRL 0x0062
		#define ISB_OBJ_4BIT_4_EEADDR_TOV 0x0063
		#define ISB_OBJ_4BIT_4_EEADDR_VALUEINIT 0x0064
	#endif /* ISB_OBJ_4BIT_4 */
	#define ISB_OBJ_8BIT_4 
	#if defined(ISB_OBJ_8BIT_4)
		#define ISB_OBJ_8BIT_4_CH 4
		#define ISB_OBJ_8BIT_4_OBJ 24
		#define ISB_OBJ_8BIT_4_EEADDR_CTRL 0x0065
		#define ISB_OBJ_8BIT_4_EEADDR_TOV 0x0066
		#define ISB_OBJ_8BIT_4_EEADDR_VALUEINIT 0x0067
	#endif /* ISB_OBJ_8BIT_4 */
	#define ISB_CH_4_EEADDR_CRC 0x0068
#endif /* ISB_CH_4 */
#define ISB_CH_5 5
#if defined(ISB_CH_5)
	#define ISB_CH_5_EEADDR_CTRL 0x0069
	#define ISB_APP_DIGIN_5 5
	#if defined(ISB_APP_DIGIN_5)
		#define ISB_APP_DIGIN_5_CH 5
		#define ISB_APP_DIGIN_5_EEADDR_CFG0 0x006A
		#define ISB_APP_DIGIN_5_EEADDR_CFG1 0x006B
		#define ISB_APP_DIGIN_5_EEADDR_CFG2 0x006C
		#define ISB_APP_DIGIN_5_EEADDR_CFG3 0x006D
		#define ISB_APP_DIGIN_5_PIN0 C | 5 | PULLUP
		#define ISB_APP_DIGIN_5_OBJ_1BIT_0 15
		#define ISB_APP_DIGIN_5_OBJ_1BIT_1 16
		#define ISB_APP_DIGIN_5_OBJ_1BIT_2 17
		#define ISB_APP_DIGIN_5_OBJ_4BIT_0 5
		#define ISB_APP_DIGIN_5_OBJ_8BIT_0 5
	#endif /* ISB_APP_DIGIN_5 */
	#define ISB_OBJ_1BIT_15 
	#if defined(ISB_OBJ_1BIT_15)
		#define ISB_OBJ_1BIT_15_CH 5
		#define ISB_OBJ_1BIT_15_OBJ 25
		#define ISB_OBJ_1BIT_15_EEADDR_CTRL 0x006E
		#define ISB_OBJ_1BIT_15_EEADDR_TOV 0x006F
		#define ISB_OBJ_1BIT_15_EEADDR_VALUEINIT 0x0070
	#endif /* ISB_OBJ_1BIT_15 */
	#define ISB_OBJ_1BIT_16 
	#if defined(ISB_OBJ_1BIT_16)
		#define ISB_OBJ_1BIT_16_CH 5
		#define ISB_OBJ_1BIT_16_OBJ 26
		#define ISB_OBJ_1BIT_16_EEADDR_CTRL 0x0071
		#define ISB_OBJ_1BIT_16_EEADDR_TOV 0x0072
		#define ISB_OBJ_1BIT_16_EEADDR_VALUEINIT 0x0073
	#endif /* ISB_OBJ_1BIT_16 */
	#define ISB_OBJ_1BIT_17 
	#if defined(ISB_OBJ_1BIT_17)
		#define ISB_OBJ_1BIT_17_CH 5
		#define ISB_OBJ_1BIT_17_OBJ 27
		#define ISB_OBJ_1BIT_17_EEADDR_CTRL 0x0074
		#define ISB_OBJ_1BIT_17_EEADDR_TOV 0x0075
		#define ISB_OBJ_1BIT_17_EEADDR_VALUEINIT 0x0076
	#endif /* ISB_OBJ_1BIT_17 */
	#define ISB_OBJ_4BIT_5 
	#if defined(ISB_OBJ_4BIT_5)
		#define ISB_OBJ_4BIT_5_CH 5
		#define ISB_OBJ_4BIT_5_OBJ 28
		#define ISB_OBJ_4BIT_5_EEADDR_CTRL 0x0077
		#define ISB_OBJ_4BIT_5_EEADDR_TOV 0x0078
		#define ISB_OBJ_4BIT_5_EEADDR_VALUEINIT 0x0079
	#endif /* ISB_OBJ_4BIT_5 */
	#define ISB_OBJ_8BIT_5 
	#if defined(ISB_OBJ_8BIT_5)
		#define ISB_OBJ_8BIT_5_CH 5
		#define ISB_OBJ_8BIT_5_OBJ 29
		#define ISB_OBJ_8BIT_5_EEADDR_CTRL 0x007A
		#define ISB_OBJ_8BIT_5_EEADDR_TOV 0x007B
		#define ISB_OBJ_8BIT_5_EEADDR_VALUEINIT 0x007C
	#endif /* ISB_OBJ_8BIT_5 */
	#define ISB_CH_5_EEADDR_CRC 0x007D
#endif /* ISB_CH_5 */
#define ISB_CH_6 6
#if defined(ISB_CH_6)
	#define ISB_CH_6_EEADDR_CTRL 0x007E
	#define ISB_APP_DIGIN_6 6
	#if defined(ISB_APP_DIGIN_6)
		#define ISB_APP_DIGIN_6_CH 6
		#define ISB_APP_DIGIN_6_EEADDR_CFG0 0x007F
		#define ISB_APP_DIGIN_6_EEADDR_CFG1 0x0080
		#define ISB_APP_DIGIN_6_EEADDR_CFG2 0x0081
		#define ISB_APP_DIGIN_6_EEADDR_CFG3 0x0082
		#define ISB_APP_DIGIN_6_PIN0 D | 0 | PULLUP
		#define ISB_APP_DIGIN_6_OBJ_1BIT_0 18
		#define ISB_APP_DIGIN_6_OBJ_1BIT_1 19
		#define ISB_APP_DIGIN_6_OBJ_1BIT_2 20
		#define ISB_APP_DIGIN_6_OBJ_4BIT_0 6
		#define ISB_APP_DIGIN_6_OBJ_8BIT_0 6
	#endif /* ISB_APP_DIGIN_6 */
	#define ISB_OBJ_1BIT_18 
	#if defined(ISB_OBJ_1BIT_18)
		#define ISB_OBJ_1BIT_18_CH 6
		#define ISB_OBJ_1BIT_18_OBJ 30
		#define ISB_OBJ_1BIT_18_EEADDR_CTRL 0x0083
		#define ISB_OBJ_1BIT_18_EEADDR_TOV 0x0084
		#define ISB_OBJ_1BIT_18_EEADDR_VALUEINIT 0x0085
	#endif /* ISB_OBJ_1BIT_18 */
	#define ISB_OBJ_1BIT_19 
	#if defined(ISB_OBJ_1BIT_19)
		#define ISB_OBJ_1BIT_19_CH 6
		#define ISB_OBJ_1BIT_19_OBJ 31
		#define ISB_OBJ_1BIT_19_EEADDR_CTRL 0x0086
		#define ISB_OBJ_1BIT_19_EEADDR_TOV 0x0087
		#define ISB_OBJ_1BIT_19_EEADDR_VALUEINIT 0x0088
	#endif /* ISB_OBJ_1BIT_19 */
	#define ISB_OBJ_1BIT_20 
	#if defined(ISB_OBJ_1BIT_20)
		#define ISB_OBJ_1BIT_20_CH 6
		#define ISB_OBJ_1BIT_20_OBJ 32
		#define ISB_OBJ_1BIT_20_EEADDR_CTRL 0x0089
		#define ISB_OBJ_1BIT_20_EEADDR_TOV 0x008A
		#define ISB_OBJ_1BIT_20_EEADDR_VALUEINIT 0x008B
	#endif /* ISB_OBJ_1BIT_20 */
	#define ISB_OBJ_4BIT_6 
	#if defined(ISB_OBJ_4BIT_6)
		#define ISB_OBJ_4BIT_6_CH 6
		#define ISB_OBJ_4BIT_6_OBJ 33
		#define ISB_OBJ_4BIT_6_EEADDR_CTRL 0x008C
		#define ISB_OBJ_4BIT_6_EEADDR_TOV 0x008D
		#define ISB_OBJ_4BIT_6_EEADDR_VALUEINIT 0x008E
	#endif /* ISB_OBJ_4BIT_6 */
	#define ISB_OBJ_8BIT_6 
	#if defined(ISB_OBJ_8BIT_6)
		#define ISB_OBJ_8BIT_6_CH 6
		#define ISB_OBJ_8BIT_6_OBJ 34
		#define ISB_OBJ_8BIT_6_EEADDR_CTRL 0x008F
		#define ISB_OBJ_8BIT_6_EEADDR_TOV 0x0090
		#define ISB_OBJ_8BIT_6_EEADDR_VALUEINIT 0x0091
	#endif /* ISB_OBJ_8BIT_6 */
	#define ISB_CH_6_EEADDR_CRC 0x0092
#endif /* ISB_CH_6 */
#define ISB_CH_7 7
#if defined(ISB_CH_7)
	#define ISB_CH_7_EEADDR_CTRL 0x0093
	#define ISB_APP_DIGIN_7 7
	#if defined(ISB_APP_DIGIN_7)
		#define ISB_APP_DIGIN_7_CH 7
		#define ISB_APP_DIGIN_7_EEADDR_CFG0 0x0094
		#define ISB_APP_DIGIN_7_EEADDR_CFG1 0x0095
		#define ISB_APP_DIGIN_7_EEADDR_CFG2 0x0096
		#define ISB_APP_DIGIN_7_EEADDR_CFG3 0x0097
		#define ISB_APP_DIGIN_7_PIN0 D | 1 | PULLUP
		#define ISB_APP_DIGIN_7_OBJ_1BIT_0 21
		#define ISB_APP_DIGIN_7_OBJ_1BIT_1 22
		#define ISB_APP_DIGIN_7_OBJ_1BIT_2 23
		#define ISB_APP_DIGIN_7_OBJ_4BIT_0 7
		#define ISB_APP_DIGIN_7_OBJ_8BIT_0 7
	#endif /* ISB_APP_DIGIN_7 */
	#define ISB_OBJ_1BIT_21 
	#if defined(ISB_OBJ_1BIT_21)
		#define ISB_OBJ_1BIT_21_CH 7
		#define ISB_OBJ_1BIT_21_OBJ 35
		#define ISB_OBJ_1BIT_21_EEADDR_CTRL 0x0098
		#define ISB_OBJ_1BIT_21_EEADDR_TOV 0x0099
		#define ISB_OBJ_1BIT_21_EEADDR_VALUEINIT 0x009A
	#endif /* ISB_OBJ_1BIT_21 */
	#define ISB_OBJ_1BIT_22 
	#if defined(ISB_OBJ_1BIT_22)
		#define ISB_OBJ_1BIT_22_CH 7
		#define ISB_OBJ_1BIT_22_OBJ 36
		#define ISB_OBJ_1BIT_22_EEADDR_CTRL 0x009B
		#define ISB_OBJ_1BIT_22_EEADDR_TOV 0x009C
		#define ISB_OBJ_1BIT_22_EEADDR_VALUEINIT 0x009D
	#endif /* ISB_OBJ_1BIT_22 */
	#define ISB_OBJ_1BIT_23 
	#if defined(ISB_OBJ_1BIT_23)
		#define ISB_OBJ_1BIT_23_CH 7
		#define ISB_OBJ_1BIT_23_OBJ 37
		#define ISB_OBJ_1BIT_23_EEADDR_CTRL 0x009E
		#define ISB_OBJ_1BIT_23_EEADDR_TOV 0x009F
		#define ISB_OBJ_1BIT_23_EEADDR_VALUEINIT 0x00A0
	#endif /* ISB_OBJ_1BIT_23 */
	#define ISB_OBJ_4BIT_7 
	#if defined(ISB_OBJ_4BIT_7)
		#define ISB_OBJ_4BIT_7_CH 7
		#define ISB_OBJ_4BIT_7_OBJ 38
		#define ISB_OBJ_4BIT_7_EEADDR_CTRL 0x00A1
		#define ISB_OBJ_4BIT_7_EEADDR_TOV 0x00A2
		#define ISB_OBJ_4BIT_7_EEADDR_VALUEINIT 0x00A3
	#endif /* ISB_OBJ_4BIT_7 */
	#define ISB_OBJ_8BIT_7 
	#if defined(ISB_OBJ_8BIT_7)
		#define ISB_OBJ_8BIT_7_CH 7
		#define ISB_OBJ_8BIT_7_OBJ 39
		#define ISB_OBJ_8BIT_7_EEADDR_CTRL 0x00A4
		#define ISB_OBJ_8BIT_7_EEADDR_TOV 0x00A5
		#define ISB_OBJ_8BIT_7_EEADDR_VALUEINIT 0x00A6
	#endif /* ISB_OBJ_8BIT_7 */
	#define ISB_CH_7_EEADDR_CRC 0x00A7
#endif /* ISB_CH_7 */
#define ISB_CH_8 8
#if defined(ISB_CH_8)
	#define ISB_CH_8_EEADDR_CTRL 0x00A8
	#define ISB_APP_DIGOUT_0 0
	#if defined(ISB_APP_DIGOUT_0)
		#define ISB_APP_DIGOUT_0_CH 8
		#define ISB_APP_DIGOUT_0_EEADDR_CFG0 0x00A9
		#define ISB_APP_DIGOUT_0_EEADDR_CFG1 0x00AA
		#define ISB_APP_DIGOUT_0_EEADDR_CFG2 0x00AB
		#define ISB_APP_DIGOUT_0_EEADDR_CFG3 0x00AC
		#define ISB_APP_DIGOUT_0_EEADDR_CFG4 0x00AD
		#define ISB_APP_DIGOUT_0_EEADDR_CFG5 0x00AE
		#define ISB_APP_DIGOUT_0_EEADDR_CFG6 0x00AF
		#define ISB_APP_DIGOUT_0_EEADDR_CFG7 0x00B0
		#define ISB_APP_DIGOUT_0_EEADDR_CFG8 0x00B1
		#define ISB_APP_DIGOUT_0_EEADDR_CFG9 0x00B2
		#define ISB_APP_DIGOUT_0_PIN0 D | 3
		#define ISB_APP_DIGOUT_0_PIN1 C | 0 | PULLUP
		#define ISB_APP_DIGOUT_0_OBJ_1BIT_0 24
		#define ISB_APP_DIGOUT_0_OBJ_1BIT_1 25
		#define ISB_APP_DIGOUT_0_OBJ_1BIT_2 26
		#define ISB_APP_DIGOUT_0_OBJ_1BIT_3 27
	#endif /* ISB_APP_DIGOUT_0 */
	#define ISB_OBJ_1BIT_24 
	#if defined(ISB_OBJ_1BIT_24)
		#define ISB_OBJ_1BIT_24_CH 8
		#define ISB_OBJ_1BIT_24_OBJ 40
		#define ISB_OBJ_1BIT_24_EEADDR_CTRL 0x00B3
		#define ISB_OBJ_1BIT_24_EEADDR_TOV 0x00B4
		#define ISB_OBJ_1BIT_24_EEADDR_VALUEINIT 0x00B5
	#endif /* ISB_OBJ_1BIT_24 */
	#define ISB_OBJ_1BIT_25 
	#if defined(ISB_OBJ_1BIT_25)
		#define ISB_OBJ_1BIT_25_CH 8
		#define ISB_OBJ_1BIT_25_OBJ 41
		#define ISB_OBJ_1BIT_25_EEADDR_CTRL 0x00B6
		#define ISB_OBJ_1BIT_25_EEADDR_TOV 0x00B7
		#define ISB_OBJ_1BIT_25_EEADDR_VALUEINIT 0x00B8
	#endif /* ISB_OBJ_1BIT_25 */
	#define ISB_OBJ_1BIT_26 
	#if defined(ISB_OBJ_1BIT_26)
		#define ISB_OBJ_1BIT_26_CH 8
		#define ISB_OBJ_1BIT_26_OBJ 42
		#define ISB_OBJ_1BIT_26_EEADDR_CTRL 0x00B9
		#define ISB_OBJ_1BIT_26_EEADDR_TOV 0x00BA
		#define ISB_OBJ_1BIT_26_EEADDR_VALUEINIT 0x00BB
	#endif /* ISB_OBJ_1BIT_26 */
	#define ISB_OBJ_1BIT_27 
	#if defined(ISB_OBJ_1BIT_27)
		#define ISB_OBJ_1BIT_27_CH 8
		#define ISB_OBJ_1BIT_27_OBJ 43
		#define ISB_OBJ_1BIT_27_EEADDR_CTRL 0x00BC
		#define ISB_OBJ_1BIT_27_EEADDR_TOV 0x00BD
		#define ISB_OBJ_1BIT_27_EEADDR_VALUEINIT 0x00BE
	#endif /* ISB_OBJ_1BIT_27 */
	#define ISB_CH_8_EEADDR_CRC 0x00BF
#endif /* ISB_CH_8 */
#define ISB_CH_9 9
#if defined(ISB_CH_9)
	#define ISB_CH_9_EEADDR_CTRL 0x00C0
	#define ISB_APP_DIGOUT_1 1
	#if defined(ISB_APP_DIGOUT_1)
		#define ISB_APP_DIGOUT_1_CH 9
		#define ISB_APP_DIGOUT_1_EEADDR_CFG0 0x00C1
		#define ISB_APP_DIGOUT_1_EEADDR_CFG1 0x00C2
		#define ISB_APP_DIGOUT_1_EEADDR_CFG2 0x00C3
		#define ISB_APP_DIGOUT_1_EEADDR_CFG3 0x00C4
		#define ISB_APP_DIGOUT_1_EEADDR_CFG4 0x00C5
		#define ISB_APP_DIGOUT_1_EEADDR_CFG5 0x00C6
		#define ISB_APP_DIGOUT_1_EEADDR_CFG6 0x00C7
		#define ISB_APP_DIGOUT_1_EEADDR_CFG7 0x00C8
		#define ISB_APP_DIGOUT_1_EEADDR_CFG8 0x00C9
		#define ISB_APP_DIGOUT_1_EEADDR_CFG9 0x00CA
		#define ISB_APP_DIGOUT_1_PIN0 D | 4
		#define ISB_APP_DIGOUT_1_PIN1 C | 1 | PULLUP
		#define ISB_APP_DIGOUT_1_OBJ_1BIT_0 28
		#define ISB_APP_DIGOUT_1_OBJ_1BIT_1 29
		#define ISB_APP_DIGOUT_1_OBJ_1BIT_2 30
		#define ISB_APP_DIGOUT_1_OBJ_1BIT_3 31
	#endif /* ISB_APP_DIGOUT_1 */
	#define ISB_OBJ_1BIT_28 
	#if defined(ISB_OBJ_1BIT_28)
		#define ISB_OBJ_1BIT_28_CH 9
		#define ISB_OBJ_1BIT_28_OBJ 44
		#define ISB_OBJ_1BIT_28_EEADDR_CTRL 0x00CB
		#define ISB_OBJ_1BIT_28_EEADDR_TOV 0x00CC
		#define ISB_OBJ_1BIT_28_EEADDR_VALUEINIT 0x00CD
	#endif /* ISB_OBJ_1BIT_28 */
	#define ISB_OBJ_1BIT_29 
	#if defined(ISB_OBJ_1BIT_29)
		#define ISB_OBJ_1BIT_29_CH 9
		#define ISB_OBJ_1BIT_29_OBJ 45
		#define ISB_OBJ_1BIT_29_EEADDR_CTRL 0x00CE
		#define ISB_OBJ_1BIT_29_EEADDR_TOV 0x00CF
		#define ISB_OBJ_1BIT_29_EEADDR_VALUEINIT 0x00D0
	#endif /* ISB_OBJ_1BIT_29 */
	#define ISB_OBJ_1BIT_30 
	#if defined(ISB_OBJ_1BIT_30)
		#define ISB_OBJ_1BIT_30_CH 9
		#define ISB_OBJ_1BIT_30_OBJ 46
		#define ISB_OBJ_1BIT_30_EEADDR_CTRL 0x00D1
		#define ISB_OBJ_1BIT_30_EEADDR_TOV 0x00D2
		#define ISB_OBJ_1BIT_30_EEADDR_VALUEINIT 0x00D3
	#endif /* ISB_OBJ_1BIT_30 */
	#define ISB_OBJ_1BIT_31 
	#if defined(ISB_OBJ_1BIT_31)
		#define ISB_OBJ_1BIT_31_CH 9
		#define ISB_OBJ_1BIT_31_OBJ 47
		#define ISB_OBJ_1BIT_31_EEADDR_CTRL 0x00D4
		#define ISB_OBJ_1BIT_31_EEADDR_TOV 0x00D5
		#define ISB_OBJ_1BIT_31_EEADDR_VALUEINIT 0x00D6
	#endif /* ISB_OBJ_1BIT_31 */
	#define ISB_CH_9_EEADDR_CRC 0x00D7
#endif /* ISB_CH_9 */
#define ISB_CH_10 10
#if defined(ISB_CH_10)
	#define ISB_CH_10_EEADDR_CTRL 0x00D8
	#define ISB_APP_DIGOUT_2 2
	#if defined(ISB_APP_DIGOUT_2)
		#define ISB_APP_DIGOUT_2_CH 10
		#define ISB_APP_DIGOUT_2_EEADDR_CFG0 0x00D9
		#define ISB_APP_DIGOUT_2_EEADDR_CFG1 0x00DA
		#define ISB_APP_DIGOUT_2_EEADDR_CFG2 0x00DB
		#define ISB_APP_DIGOUT_2_EEADDR_CFG3 0x00DC
		#define ISB_APP_DIGOUT_2_EEADDR_CFG4 0x00DD
		#define ISB_APP_DIGOUT_2_EEADDR_CFG5 0x00DE
		#define ISB_APP_DIGOUT_2_EEADDR_CFG6 0x00DF
		#define ISB_APP_DIGOUT_2_EEADDR_CFG7 0x00E0
		#define ISB_APP_DIGOUT_2_EEADDR_CFG8 0x00E1
		#define ISB_APP_DIGOUT_2_EEADDR_CFG9 0x00E2
		#define ISB_APP_DIGOUT_2_PIN0 B | 6
		#define ISB_APP_DIGOUT_2_PIN1 C | 2 | PULLUP
		#define ISB_APP_DIGOUT_2_OBJ_1BIT_0 32
		#define ISB_APP_DIGOUT_2_OBJ_1BIT_1 33
		#define ISB_APP_DIGOUT_2_OBJ_1BIT_2 34
		#define ISB_APP_DIGOUT_2_OBJ_1BIT_3 35
	#endif /* ISB_APP_DIGOUT_2 */
	#define ISB_OBJ_1BIT_32 
	#if defined(ISB_OBJ_1BIT_32)
		#define ISB_OBJ_1BIT_32_CH 10
		#define ISB_OBJ_1BIT_32_OBJ 48
		#define ISB_OBJ_1BIT_32_EEADDR_CTRL 0x00E3
		#define ISB_OBJ_1BIT_32_EEADDR_TOV 0x00E4
		#define ISB_OBJ_1BIT_32_EEADDR_VALUEINIT 0x00E5
	#endif /* ISB_OBJ_1BIT_32 */
	#define ISB_OBJ_1BIT_33 
	#if defined(ISB_OBJ_1BIT_33)
		#define ISB_OBJ_1BIT_33_CH 10
		#define ISB_OBJ_1BIT_33_OBJ 49
		#define ISB_OBJ_1BIT_33_EEADDR_CTRL 0x00E6
		#define ISB_OBJ_1BIT_33_EEADDR_TOV 0x00E7
		#define ISB_OBJ_1BIT_33_EEADDR_VALUEINIT 0x00E8
	#endif /* ISB_OBJ_1BIT_33 */
	#define ISB_OBJ_1BIT_34 
	#if defined(ISB_OBJ_1BIT_34)
		#define ISB_OBJ_1BIT_34_CH 10
		#define ISB_OBJ_1BIT_34_OBJ 50
		#define ISB_OBJ_1BIT_34_EEADDR_CTRL 0x00E9
		#define ISB_OBJ_1BIT_34_EEADDR_TOV 0x00EA
		#define ISB_OBJ_1BIT_34_EEADDR_VALUEINIT 0x00EB
	#endif /* ISB_OBJ_1BIT_34 */
	#define ISB_OBJ_1BIT_35 
	#if defined(ISB_OBJ_1BIT_35)
		#define ISB_OBJ_1BIT_35_CH 10
		#define ISB_OBJ_1BIT_35_OBJ 51
		#define ISB_OBJ_1BIT_35_EEADDR_CTRL 0x00EC
		#define ISB_OBJ_1BIT_35_EEADDR_TOV 0x00ED
		#define ISB_OBJ_1BIT_35_EEADDR_VALUEINIT 0x00EE
	#endif /* ISB_OBJ_1BIT_35 */
	#define ISB_CH_10_EEADDR_CRC 0x00EF
#endif /* ISB_CH_10 */
#define ISB_CH_11 11
#if defined(ISB_CH_11)
	#define ISB_CH_11_EEADDR_CTRL 0x00F0
	#define ISB_APP_DIGOUT_3 3
	#if defined(ISB_APP_DIGOUT_3)
		#define ISB_APP_DIGOUT_3_CH 11
		#define ISB_APP_DIGOUT_3_EEADDR_CFG0 0x00F1
		#define ISB_APP_DIGOUT_3_EEADDR_CFG1 0x00F2
		#define ISB_APP_DIGOUT_3_EEADDR_CFG2 0x00F3
		#define ISB_APP_DIGOUT_3_EEADDR_CFG3 0x00F4
		#define ISB_APP_DIGOUT_3_EEADDR_CFG4 0x00F5
		#define ISB_APP_DIGOUT_3_EEADDR_CFG5 0x00F6
		#define ISB_APP_DIGOUT_3_EEADDR_CFG6 0x00F7
		#define ISB_APP_DIGOUT_3_EEADDR_CFG7 0x00F8
		#define ISB_APP_DIGOUT_3_EEADDR_CFG8 0x00F9
		#define ISB_APP_DIGOUT_3_EEADDR_CFG9 0x00FA
		#define ISB_APP_DIGOUT_3_PIN0 B | 7
		#define ISB_APP_DIGOUT_3_PIN1 C | 3 | PULLUP
		#define ISB_APP_DIGOUT_3_OBJ_1BIT_0 36
		#define ISB_APP_DIGOUT_3_OBJ_1BIT_1 37
		#define ISB_APP_DIGOUT_3_OBJ_1BIT_2 38
		#define ISB_APP_DIGOUT_3_OBJ_1BIT_3 39
	#endif /* ISB_APP_DIGOUT_3 */
	#define ISB_OBJ_1BIT_36 
	#if defined(ISB_OBJ_1BIT_36)
		#define ISB_OBJ_1BIT_36_CH 11
		#define ISB_OBJ_1BIT_36_OBJ 52
		#define ISB_OBJ_1BIT_36_EEADDR_CTRL 0x00FB
		#define ISB_OBJ_1BIT_36_EEADDR_TOV 0x00FC
		#define ISB_OBJ_1BIT_36_EEADDR_VALUEINIT 0x00FD
	#endif /* ISB_OBJ_1BIT_36 */
	#define ISB_OBJ_1BIT_37 
	#if defined(ISB_OBJ_1BIT_37)
		#define ISB_OBJ_1BIT_37_CH 11
		#define ISB_OBJ_1BIT_37_OBJ 53
		#define ISB_OBJ_1BIT_37_EEADDR_CTRL 0x00FE
		#define ISB_OBJ_1BIT_37_EEADDR_TOV 0x00FF
		#define ISB_OBJ_1BIT_37_EEADDR_VALUEINIT 0x0100
	#endif /* ISB_OBJ_1BIT_37 */
	#define ISB_OBJ_1BIT_38 
	#if defined(ISB_OBJ_1BIT_38)
		#define ISB_OBJ_1BIT_38_CH 11
		#define ISB_OBJ_1BIT_38_OBJ 54
		#define ISB_OBJ_1BIT_38_EEADDR_CTRL 0x0101
		#define ISB_OBJ_1BIT_38_EEADDR_TOV 0x0102
		#define ISB_OBJ_1BIT_38_EEADDR_VALUEINIT 0x0103
	#endif /* ISB_OBJ_1BIT_38 */
	#define ISB_OBJ_1BIT_39 
	#if defined(ISB_OBJ_1BIT_39)
		#define ISB_OBJ_1BIT_39_CH 11
		#define ISB_OBJ_1BIT_39_OBJ 55
		#define ISB_OBJ_1BIT_39_EEADDR_CTRL 0x0104
		#define ISB_OBJ_1BIT_39_EEADDR_TOV 0x0105
		#define ISB_OBJ_1BIT_39_EEADDR_VALUEINIT 0x0106
	#endif /* ISB_OBJ_1BIT_39 */
	#define ISB_CH_11_EEADDR_CRC 0x0107
#endif /* ISB_CH_11 */
#define ISB_CH_12 12
#if defined(ISB_CH_12)
	#define ISB_CH_12_EEADDR_CTRL 0x0108
	#define ISB_APP_DIGOUT_4 4
	#if defined(ISB_APP_DIGOUT_4)
		#define ISB_APP_DIGOUT_4_CH 12
		#define ISB_APP_DIGOUT_4_EEADDR_CFG0 0x0109
		#define ISB_APP_DIGOUT_4_EEADDR_CFG1 0x010A
		#define ISB_APP_DIGOUT_4_EEADDR_CFG2 0x010B
		#define ISB_APP_DIGOUT_4_EEADDR_CFG3 0x010C
		#define ISB_APP_DIGOUT_4_EEADDR_CFG4 0x010D
		#define ISB_APP_DIGOUT_4_EEADDR_CFG5 0x010E
		#define ISB_APP_DIGOUT_4_EEADDR_CFG6 0x010F
		#define ISB_APP_DIGOUT_4_EEADDR_CFG7 0x0110
		#define ISB_APP_DIGOUT_4_EEADDR_CFG8 0x0111
		#define ISB_APP_DIGOUT_4_EEADDR_CFG9 0x0112
		#define ISB_APP_DIGOUT_4_PIN0 D | 5
		#define ISB_APP_DIGOUT_4_PIN1 C | 4 | PULLUP
		#define ISB_APP_DIGOUT_4_OBJ_1BIT_0 40
		#define ISB_APP_DIGOUT_4_OBJ_1BIT_1 41
		#define ISB_APP_DIGOUT_4_OBJ_1BIT_2 42
		#define ISB_APP_DIGOUT_4_OBJ_1BIT_3 43
	#endif /* ISB_APP_DIGOUT_4 */
	#define ISB_OBJ_1BIT_40 
	#if defined(ISB_OBJ_1BIT_40)
		#define ISB_OBJ_1BIT_40_CH 12
		#define ISB_OBJ_1BIT_40_OBJ 56
		#define ISB_OBJ_1BIT_40_EEADDR_CTRL 0x0113
		#define ISB_OBJ_1BIT_40_EEADDR_TOV 0x0114
		#define ISB_OBJ_1BIT_40_EEADDR_VALUEINIT 0x0115
	#endif /* ISB_OBJ_1BIT_40 */
	#define ISB_OBJ_1BIT_41 
	#if defined(ISB_OBJ_1BIT_41)
		#define ISB_OBJ_1BIT_41_CH 12
		#define ISB_OBJ_1BIT_41_OBJ 57
		#define ISB_OBJ_1BIT_41_EEADDR_CTRL 0x0116
		#define ISB_OBJ_1BIT_41_EEADDR_TOV 0x0117
		#define ISB_OBJ_1BIT_41_EEADDR_VALUEINIT 0x0118
	#endif /* ISB_OBJ_1BIT_41 */
	#define ISB_OBJ_1BIT_42 
	#if defined(ISB_OBJ_1BIT_42)
		#define ISB_OBJ_1BIT_42_CH 12
		#define ISB_OBJ_1BIT_42_OBJ 58
		#define ISB_OBJ_1BIT_42_EEADDR_CTRL 0x0119
		#define ISB_OBJ_1BIT_42_EEADDR_TOV 0x011A
		#define ISB_OBJ_1BIT_42_EEADDR_VALUEINIT 0x011B
	#endif /* ISB_OBJ_1BIT_42 */
	#define ISB_OBJ_1BIT_43 
	#if defined(ISB_OBJ_1BIT_43)
		#define ISB_OBJ_1BIT_43_CH 12
		#define ISB_OBJ_1BIT_43_OBJ 59
		#define ISB_OBJ_1BIT_43_EEADDR_CTRL 0x011C
		#define ISB_OBJ_1BIT_43_EEADDR_TOV 0x011D
		#define ISB_OBJ_1BIT_43_EEADDR_VALUEINIT 0x011E
	#endif /* ISB_OBJ_1BIT_43 */
	#define ISB_CH_12_EEADDR_CRC 0x011F
#endif /* ISB_CH_12 */
#define ISB_CH_13 13
#if defined(ISB_CH_13)
	#define ISB_CH_13_EEADDR_CTRL 0x0120
	#define ISB_APP_DIGOUT_5 5
	#if defined(ISB_APP_DIGOUT_5)
		#define ISB_APP_DIGOUT_5_CH 13
		#define ISB_APP_DIGOUT_5_EEADDR_CFG0 0x0121
		#define ISB_APP_DIGOUT_5_EEADDR_CFG1 0x0122
		#define ISB_APP_DIGOUT_5_EEADDR_CFG2 0x0123
		#define ISB_APP_DIGOUT_5_EEADDR_CFG3 0x0124
		#define ISB_APP_DIGOUT_5_EEADDR_CFG4 0x0125
		#define ISB_APP_DIGOUT_5_EEADDR_CFG5 0x0126
		#define ISB_APP_DIGOUT_5_EEADDR_CFG6 0x0127
		#define ISB_APP_DIGOUT_5_EEADDR_CFG7 0x0128
		#define ISB_APP_DIGOUT_5_EEADDR_CFG8 0x0129
		#define ISB_APP_DIGOUT_5_EEADDR_CFG9 0x012A
		#define ISB_APP_DIGOUT_5_PIN0 D | 6
		#define ISB_APP_DIGOUT_5_PIN1 C | 5 | PULLUP
		#define ISB_APP_DIGOUT_5_OBJ_1BIT_0 44
		#define ISB_APP_DIGOUT_5_OBJ_1BIT_1 45
		#define ISB_APP_DIGOUT_5_OBJ_1BIT_2 46
		#define ISB_APP_DIGOUT_5_OBJ_1BIT_3 47
	#endif /* ISB_APP_DIGOUT_5 */
	#define ISB_OBJ_1BIT_44 
	#if defined(ISB_OBJ_1BIT_44)
		#define ISB_OBJ_1BIT_44_CH 13
		#define ISB_OBJ_1BIT_44_OBJ 60
		#define ISB_OBJ_1BIT_44_EEADDR_CTRL 0x012B
		#define ISB_OBJ_1BIT_44_EEADDR_TOV 0x012C
		#define ISB_OBJ_1BIT_44_EEADDR_VALUEINIT 0x012D
	#endif /* ISB_OBJ_1BIT_44 */
	#define ISB_OBJ_1BIT_45 
	#if defined(ISB_OBJ_1BIT_45)
		#define ISB_OBJ_1BIT_45_CH 13
		#define ISB_OBJ_1BIT_45_OBJ 61
		#define ISB_OBJ_1BIT_45_EEADDR_CTRL 0x012E
		#define ISB_OBJ_1BIT_45_EEADDR_TOV 0x012F
		#define ISB_OBJ_1BIT_45_EEADDR_VALUEINIT 0x0130
	#endif /* ISB_OBJ_1BIT_45 */
	#define ISB_OBJ_1BIT_46 
	#if defined(ISB_OBJ_1BIT_46)
		#define ISB_OBJ_1BIT_46_CH 13
		#define ISB_OBJ_1BIT_46_OBJ 62
		#define ISB_OBJ_1BIT_46_EEADDR_CTRL 0x0131
		#define ISB_OBJ_1BIT_46_EEADDR_TOV 0x0132
		#define ISB_OBJ_1BIT_46_EEADDR_VALUEINIT 0x0133
	#endif /* ISB_OBJ_1BIT_46 */
	#define ISB_OBJ_1BIT_47 
	#if defined(ISB_OBJ_1BIT_47)
		#define ISB_OBJ_1BIT_47_CH 13
		#define ISB_OBJ_1BIT_47_OBJ 63
		#define ISB_OBJ_1BIT_47_EEADDR_CTRL 0x0134
		#define ISB_OBJ_1BIT_47_EEADDR_TOV 0x0135
		#define ISB_OBJ_1BIT_47_EEADDR_VALUEINIT 0x0136
	#endif /* ISB_OBJ_1BIT_47 */
	#define ISB_CH_13_EEADDR_CRC 0x0137
#endif /* ISB_CH_13 */
#define ISB_CH_14 14
#if defined(ISB_CH_14)
	#define ISB_CH_14_EEADDR_CTRL 0x0138
	#define ISB_APP_DIGOUT_6 6
	#if defined(ISB_APP_DIGOUT_6)
		#define ISB_APP_DIGOUT_6_CH 14
		#define ISB_APP_DIGOUT_6_EEADDR_CFG0 0x0139
		#define ISB_APP_DIGOUT_6_EEADDR_CFG1 0x013A
		#define ISB_APP_DIGOUT_6_EEADDR_CFG2 0x013B
		#define ISB_APP_DIGOUT_6_EEADDR_CFG3 0x013C
		#define ISB_APP_DIGOUT_6_EEADDR_CFG4 0x013D
		#define ISB_APP_DIGOUT_6_EEADDR_CFG5 0x013E
		#define ISB_APP_DIGOUT_6_EEADDR_CFG6 0x013F
		#define ISB_APP_DIGOUT_6_EEADDR_CFG7 0x0140
		#define ISB_APP_DIGOUT_6_EEADDR_CFG8 0x0141
		#define ISB_APP_DIGOUT_6_EEADDR_CFG9 0x0142
		#define ISB_APP_DIGOUT_6_PIN0 D | 7
		#define ISB_APP_DIGOUT_6_PIN1 D | 0 | PULLUP
		#define ISB_APP_DIGOUT_6_OBJ_1BIT_0 48
		#define ISB_APP_DIGOUT_6_OBJ_1BIT_1 49
		#define ISB_APP_DIGOUT_6_OBJ_1BIT_2 50
		#define ISB_APP_DIGOUT_6_OBJ_1BIT_3 51
	#endif /* ISB_APP_DIGOUT_6 */
	#define ISB_OBJ_1BIT_48 
	#if defined(ISB_OBJ_1BIT_48)
		#define ISB_OBJ_1BIT_48_CH 14
		#define ISB_OBJ_1BIT_48_OBJ 64
		#define ISB_OBJ_1BIT_48_EEADDR_CTRL 0x0143
		#define ISB_OBJ_1BIT_48_EEADDR_TOV 0x0144
		#define ISB_OBJ_1BIT_48_EEADDR_VALUEINIT 0x0145
	#endif /* ISB_OBJ_1BIT_48 */
	#define ISB_OBJ_1BIT_49 
	#if defined(ISB_OBJ_1BIT_49)
		#define ISB_OBJ_1BIT_49_CH 14
		#define ISB_OBJ_1BIT_49_OBJ 65
		#define ISB_OBJ_1BIT_49_EEADDR_CTRL 0x0146
		#define ISB_OBJ_1BIT_49_EEADDR_TOV 0x0147
		#define ISB_OBJ_1BIT_49_EEADDR_VALUEINIT 0x0148
	#endif /* ISB_OBJ_1BIT_49 */
	#define ISB_OBJ_1BIT_50 
	#if defined(ISB_OBJ_1BIT_50)
		#define ISB_OBJ_1BIT_50_CH 14
		#define ISB_OBJ_1BIT_50_OBJ 66
		#define ISB_OBJ_1BIT_50_EEADDR_CTRL 0x0149
		#define ISB_OBJ_1BIT_50_EEADDR_TOV 0x014A
		#define ISB_OBJ_1BIT_50_EEADDR_VALUEINIT 0x014B
	#endif /* ISB_OBJ_1BIT_50 */
	#define ISB_OBJ_1BIT_51 
	#if defined(ISB_OBJ_1BIT_51)
		#define ISB_OBJ_1BIT_51_CH 14
		#define ISB_OBJ_1BIT_51_OBJ 67
		#define ISB_OBJ_1BIT_51_EEADDR_CTRL 0x014C
		#define ISB_OBJ_1BIT_51_EEADDR_TOV 0x014D
		#define ISB_OBJ_1BIT_51_EEADDR_VALUEINIT 0x014E
	#endif /* ISB_OBJ_1BIT_51 */
	#define ISB_CH_14_EEADDR_CRC 0x014F
#endif /* ISB_CH_14 */
#define ISB_CH_15 15
#if defined(ISB_CH_15)
	#define ISB_CH_15_EEADDR_CTRL 0x0150
	#define ISB_APP_DIGOUT_7 7
	#if defined(ISB_APP_DIGOUT_7)
		#define ISB_APP_DIGOUT_7_CH 15
		#define ISB_APP_DIGOUT_7_EEADDR_CFG0 0x0151
		#define ISB_APP_DIGOUT_7_EEADDR_CFG1 0x0152
		#define ISB_APP_DIGOUT_7_EEADDR_CFG2 0x0153
		#define ISB_APP_DIGOUT_7_EEADDR_CFG3 0x0154
		#define ISB_APP_DIGOUT_7_EEADDR_CFG4 0x0155
		#define ISB_APP_DIGOUT_7_EEADDR_CFG5 0x0156
		#define ISB_APP_DIGOUT_7_EEADDR_CFG6 0x0157
		#define ISB_APP_DIGOUT_7_EEADDR_CFG7 0x0158
		#define ISB_APP_DIGOUT_7_EEADDR_CFG8 0x0159
		#define ISB_APP_DIGOUT_7_EEADDR_CFG9 0x015A
		#define ISB_APP_DIGOUT_7_PIN0 B | 1
		#define ISB_APP_DIGOUT_7_PIN1 D | 1 | PULLUP
		#define ISB_APP_DIGOUT_7_OBJ_1BIT_0 52
		#define ISB_APP_DIGOUT_7_OBJ_1BIT_1 53
		#define ISB_APP_DIGOUT_7_OBJ_1BIT_2 54
		#define ISB_APP_DIGOUT_7_OBJ_1BIT_3 55
	#endif /* ISB_APP_DIGOUT_7 */
	#define ISB_OBJ_1BIT_52 
	#if defined(ISB_OBJ_1BIT_52)
		#define ISB_OBJ_1BIT_52_CH 15
		#define ISB_OBJ_1BIT_52_OBJ 68
		#define ISB_OBJ_1BIT_52_EEADDR_CTRL 0x015B
		#define ISB_OBJ_1BIT_52_EEADDR_TOV 0x015C
		#define ISB_OBJ_1BIT_52_EEADDR_VALUEINIT 0x015D
	#endif /* ISB_OBJ_1BIT_52 */
	#define ISB_OBJ_1BIT_53 
	#if defined(ISB_OBJ_1BIT_53)
		#define ISB_OBJ_1BIT_53_CH 15
		#define ISB_OBJ_1BIT_53_OBJ 69
		#define ISB_OBJ_1BIT_53_EEADDR_CTRL 0x015E
		#define ISB_OBJ_1BIT_53_EEADDR_TOV 0x015F
		#define ISB_OBJ_1BIT_53_EEADDR_VALUEINIT 0x0160
	#endif /* ISB_OBJ_1BIT_53 */
	#define ISB_OBJ_1BIT_54 
	#if defined(ISB_OBJ_1BIT_54)
		#define ISB_OBJ_1BIT_54_CH 15
		#define ISB_OBJ_1BIT_54_OBJ 70
		#define ISB_OBJ_1BIT_54_EEADDR_CTRL 0x0161
		#define ISB_OBJ_1BIT_54_EEADDR_TOV 0x0162
		#define ISB_OBJ_1BIT_54_EEADDR_VALUEINIT 0x0163
	#endif /* ISB_OBJ_1BIT_54 */
	#define ISB_OBJ_1BIT_55 
	#if defined(ISB_OBJ_1BIT_55)
		#define ISB_OBJ_1BIT_55_CH 15
		#define ISB_OBJ_1BIT_55_OBJ 71
		#define ISB_OBJ_1BIT_55_EEADDR_CTRL 0x0164
		#define ISB_OBJ_1BIT_55_EEADDR_TOV 0x0165
		#define ISB_OBJ_1BIT_55_EEADDR_VALUEINIT 0x0166
	#endif /* ISB_OBJ_1BIT_55 */
	#define ISB_CH_15_EEADDR_CRC 0x0167
#endif /* ISB_CH_15 */
#define ISB_CH_16 16
#if defined(ISB_CH_16)
	#define ISB_CH_16_EEADDR_CTRL 0x0168
	#define ISB_APP_DIGOUT_8 8
	#if defined(ISB_APP_DIGOUT_8)
		#define ISB_APP_DIGOUT_8_CH 16
		#define ISB_APP_DIGOUT_8_EEADDR_CFG0 0x0169
		#define ISB_APP_DIGOUT_8_EEADDR_CFG1 0x016A
		#define ISB_APP_DIGOUT_8_EEADDR_CFG2 0x016B
		#define ISB_APP_DIGOUT_8_EEADDR_CFG3 0x016C
		#define ISB_APP_DIGOUT_8_EEADDR_CFG4 0x016D
		#define ISB_APP_DIGOUT_8_EEADDR_CFG5 0x016E
		#define ISB_APP_DIGOUT_8_EEADDR_CFG6 0x016F
		#define ISB_APP_DIGOUT_8_EEADDR_CFG7 0x0170
		#define ISB_APP_DIGOUT_8_EEADDR_CFG8 0x0171
		#define ISB_APP_DIGOUT_8_EEADDR_CFG9 0x0172
		#define ISB_APP_DIGOUT_8_PIN0 B | 2
		#define ISB_APP_DIGOUT_8_PIN1 NONE
		#define ISB_APP_DIGOUT_8_OBJ_1BIT_0 56
		#define ISB_APP_DIGOUT_8_OBJ_1BIT_1 57
		#define ISB_APP_DIGOUT_8_OBJ_1BIT_2 58
		#define ISB_APP_DIGOUT_8_OBJ_1BIT_3 59
	#endif /* ISB_APP_DIGOUT_8 */
	#define ISB_OBJ_1BIT_56 
	#if defined(ISB_OBJ_1BIT_56)
		#define ISB_OBJ_1BIT_56_CH 16
		#define ISB_OBJ_1BIT_56_OBJ 72
		#define ISB_OBJ_1BIT_56_EEADDR_CTRL 0x0173
		#define ISB_OBJ_1BIT_56_EEADDR_TOV 0x0174
		#define ISB_OBJ_1BIT_56_EEADDR_VALUEINIT 0x0175
	#endif /* ISB_OBJ_1BIT_56 */
	#define ISB_OBJ_1BIT_57 
	#if defined(ISB_OBJ_1BIT_57)
		#define ISB_OBJ_1BIT_57_CH 16
		#define ISB_OBJ_1BIT_57_OBJ 73
		#define ISB_OBJ_1BIT_57_EEADDR_CTRL 0x0176
		#define ISB_OBJ_1BIT_57_EEADDR_TOV 0x0177
		#define ISB_OBJ_1BIT_57_EEADDR_VALUEINIT 0x0178
	#endif /* ISB_OBJ_1BIT_57 */
	#define ISB_OBJ_1BIT_58 
	#if defined(ISB_OBJ_1BIT_58)
		#define ISB_OBJ_1BIT_58_CH 16
		#define ISB_OBJ_1BIT_58_OBJ 74
		#define ISB_OBJ_1BIT_58_EEADDR_CTRL 0x0179
		#define ISB_OBJ_1BIT_58_EEADDR_TOV 0x017A
		#define ISB_OBJ_1BIT_58_EEADDR_VALUEINIT 0x017B
	#endif /* ISB_OBJ_1BIT_58 */
	#define ISB_OBJ_1BIT_59 
	#if defined(ISB_OBJ_1BIT_59)
		#define ISB_OBJ_1BIT_59_CH 16
		#define ISB_OBJ_1BIT_59_OBJ 75
		#define ISB_OBJ_1BIT_59_EEADDR_CTRL 0x017C
		#define ISB_OBJ_1BIT_59_EEADDR_TOV 0x017D
		#define ISB_OBJ_1BIT_59_EEADDR_VALUEINIT 0x017E
	#endif /* ISB_OBJ_1BIT_59 */
	#define ISB_CH_16_EEADDR_CRC 0x017F
#endif /* ISB_CH_16 */



#define ISB_APP_DIGOUT_MAX 9
#define ISB_APP_DIGOUT_EXECTIME 10

#define ISB_APP_DIGIN_MAX 8
#define ISB_APP_DIGIN_EXECTIME 10

#define ISB_OBJ_1BIT_MAX 60
#define ISB_OBJ_1BIT_EXECTIME 10

#define ISB_OBJ_4BIT_MAX 8
#define ISB_OBJ_4BIT_EXECTIME 10

#define ISB_OBJ_8BIT_MAX 8
#define ISB_OBJ_8BIT_EXECTIME 10

#define ISB_GRP_MAX 40
#define ISB_GRP_EEADDR_START 0x0180



#include <1.2.0/core/isb_fw_switch.c>
