/**
 * @file		fw/fw_41/trunk/main.c
 *
 * @brief		Firmware.
 *
 * This file includes the Firmware.
 *
 * @author		© Patrick Amrhein <trick-at-isysbus-dot-org> 01.05.2010.
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



#define USE_AVRLIB_ISB



#include <trunk/core/isb_fw_app.h>



const uint8_t Isb_Firmware_Code[4] = { 0x29, 0x00, 0x00, 0x00 };



#define ISB_CH_MAX 8

#define ISB_CH_0 0
#if defined(ISB_CH_0)
	#define ISB_CH_0_EEADDR_CTRL 0x0000
	#define ISB_APP_ANAIN_0 0
	#define ISB_APP_ANAIN_0_CH 0
	#define ISB_APP_ANAIN_0_EEADDR_CFG0 0x0001
	#define ISB_APP_ANAIN_0_EEADDR_CFG1 0x0002
	#define ISB_APP_ANAIN_0_EEADDR_CFG2 0x0003
	#define ISB_APP_ANAIN_0_EEADDR_CFG_SWITCH1ON 0x0004
	#define ISB_APP_ANAIN_0_EEADDR_CFG_SWITCH1OFF 0x0006
	#define ISB_APP_ANAIN_0_EEADDR_CFG_SWITCH2ON 0x0008
	#define ISB_APP_ANAIN_0_EEADDR_CFG_SWITCH2OFF 0x000A
	#define ISB_APP_ANAIN_0_OBJ_0_EEADDR_CTRL 0x000C
	#define ISB_APP_ANAIN_0_OBJ_0_EEADDR_TOV 0x000D
	#define ISB_APP_ANAIN_0_OBJ_0_EEADDR_INITVALUE 0x000E
	#define ISB_APP_ANAIN_0_OBJ_1_EEADDR_CTRL 0x0013
	#define ISB_APP_ANAIN_0_OBJ_1_EEADDR_TOV 0x0014
	#define ISB_APP_ANAIN_0_OBJ_1_EEADDR_INITVALUE 0x0015
	#define ISB_APP_ANAIN_0_OBJ_2_EEADDR_CTRL 0x001A
	#define ISB_APP_ANAIN_0_OBJ_2_EEADDR_TOV 0x001B
	#define ISB_APP_ANAIN_0_OBJ_2_EEADDR_INITVALUE 0x001C
	#define ISB_APP_ANAIN_0_OBJ_0 0
	#define ISB_OBJ_0 0
	#define ISB_OBJ_0_CH 0
	#define ISB_APP_ANAIN_0_OBJ_1 1
	#define ISB_OBJ_1 1
	#define ISB_OBJ_1_CH 0
	#define ISB_APP_ANAIN_0_OBJ_2 2
	#define ISB_OBJ_2 2
	#define ISB_OBJ_2_CH 0
	#define ISB_CH_0_EEADDR_CRC 0x0021
#endif /* ISB_CH_0 */

#define ISB_CH_1 1
#if defined(ISB_CH_1)
	#define ISB_CH_1_EEADDR_CTRL 0x0022
	#define ISB_APP_ANAIN_1 1
	#define ISB_APP_ANAIN_1_CH 1
	#define ISB_APP_ANAIN_1_EEADDR_CFG0 0x0023
	#define ISB_APP_ANAIN_1_EEADDR_CFG1 0x0024
	#define ISB_APP_ANAIN_1_EEADDR_CFG2 0x0025
	#define ISB_APP_ANAIN_1_EEADDR_CFG_SWITCH1ON 0x0026
	#define ISB_APP_ANAIN_1_EEADDR_CFG_SWITCH1OFF 0x0028
	#define ISB_APP_ANAIN_1_EEADDR_CFG_SWITCH2ON 0x002A
	#define ISB_APP_ANAIN_1_EEADDR_CFG_SWITCH2OFF 0x002C
	#define ISB_APP_ANAIN_1_OBJ_0_EEADDR_CTRL 0x002E
	#define ISB_APP_ANAIN_1_OBJ_0_EEADDR_TOV 0x002F
	#define ISB_APP_ANAIN_1_OBJ_0_EEADDR_INITVALUE 0x0030
	#define ISB_APP_ANAIN_1_OBJ_1_EEADDR_CTRL 0x0035
	#define ISB_APP_ANAIN_1_OBJ_1_EEADDR_TOV 0x0036
	#define ISB_APP_ANAIN_1_OBJ_1_EEADDR_INITVALUE 0x0037
	#define ISB_APP_ANAIN_1_OBJ_2_EEADDR_CTRL 0x003C
	#define ISB_APP_ANAIN_1_OBJ_2_EEADDR_TOV 0x003D
	#define ISB_APP_ANAIN_1_OBJ_2_EEADDR_INITVALUE 0x003E
	#define ISB_APP_ANAIN_1_OBJ_0 3
	#define ISB_OBJ_3 3
	#define ISB_OBJ_3_CH 1
	#define ISB_APP_ANAIN_1_OBJ_1 4
	#define ISB_OBJ_4 4
	#define ISB_OBJ_4_CH 1
	#define ISB_APP_ANAIN_1_OBJ_2 5
	#define ISB_OBJ_5 5
	#define ISB_OBJ_5_CH 1
	#define ISB_CH_1_EEADDR_CRC 0x0043
#endif /* ISB_CH_1 */

#define ISB_CH_2 2
#if defined(ISB_CH_2)
	#define ISB_CH_2_EEADDR_CTRL 0x0044
	#define ISB_APP_ANAIN_2 2
	#define ISB_APP_ANAIN_2_CH 2
	#define ISB_APP_ANAIN_2_EEADDR_CFG0 0x0045
	#define ISB_APP_ANAIN_2_EEADDR_CFG1 0x0046
	#define ISB_APP_ANAIN_2_EEADDR_CFG2 0x0047
	#define ISB_APP_ANAIN_2_EEADDR_CFG_SWITCH1ON 0x0048
	#define ISB_APP_ANAIN_2_EEADDR_CFG_SWITCH1OFF 0x004A
	#define ISB_APP_ANAIN_2_EEADDR_CFG_SWITCH2ON 0x004C
	#define ISB_APP_ANAIN_2_EEADDR_CFG_SWITCH2OFF 0x004E
	#define ISB_APP_ANAIN_2_OBJ_0_EEADDR_CTRL 0x0050
	#define ISB_APP_ANAIN_2_OBJ_0_EEADDR_TOV 0x0051
	#define ISB_APP_ANAIN_2_OBJ_0_EEADDR_INITVALUE 0x0052
	#define ISB_APP_ANAIN_2_OBJ_1_EEADDR_CTRL 0x0057
	#define ISB_APP_ANAIN_2_OBJ_1_EEADDR_TOV 0x0058
	#define ISB_APP_ANAIN_2_OBJ_1_EEADDR_INITVALUE 0x0059
	#define ISB_APP_ANAIN_2_OBJ_2_EEADDR_CTRL 0x005E
	#define ISB_APP_ANAIN_2_OBJ_2_EEADDR_TOV 0x005F
	#define ISB_APP_ANAIN_2_OBJ_2_EEADDR_INITVALUE 0x0060
	#define ISB_APP_ANAIN_2_OBJ_0 6
	#define ISB_OBJ_6 6
	#define ISB_OBJ_6_CH 2
	#define ISB_APP_ANAIN_2_OBJ_1 7
	#define ISB_OBJ_7 7
	#define ISB_OBJ_7_CH 2
	#define ISB_APP_ANAIN_2_OBJ_2 8
	#define ISB_OBJ_8 8
	#define ISB_OBJ_8_CH 2
	#define ISB_CH_2_EEADDR_CRC 0x0065
#endif /* ISB_CH_2 */

#define ISB_CH_3 3
#if defined(ISB_CH_3)
	#define ISB_CH_3_EEADDR_CTRL 0x0066
	#define ISB_APP_ANAIN_3 3
	#define ISB_APP_ANAIN_3_CH 3
	#define ISB_APP_ANAIN_3_EEADDR_CFG0 0x0067
	#define ISB_APP_ANAIN_3_EEADDR_CFG1 0x0068
	#define ISB_APP_ANAIN_3_EEADDR_CFG2 0x0069
	#define ISB_APP_ANAIN_3_EEADDR_CFG_SWITCH1ON 0x006A
	#define ISB_APP_ANAIN_3_EEADDR_CFG_SWITCH1OFF 0x006C
	#define ISB_APP_ANAIN_3_EEADDR_CFG_SWITCH2ON 0x006E
	#define ISB_APP_ANAIN_3_EEADDR_CFG_SWITCH2OFF 0x0070
	#define ISB_APP_ANAIN_3_OBJ_0_EEADDR_CTRL 0x0072
	#define ISB_APP_ANAIN_3_OBJ_0_EEADDR_TOV 0x0073
	#define ISB_APP_ANAIN_3_OBJ_0_EEADDR_INITVALUE 0x0074
	#define ISB_APP_ANAIN_3_OBJ_1_EEADDR_CTRL 0x0079
	#define ISB_APP_ANAIN_3_OBJ_1_EEADDR_TOV 0x007A
	#define ISB_APP_ANAIN_3_OBJ_1_EEADDR_INITVALUE 0x007B
	#define ISB_APP_ANAIN_3_OBJ_2_EEADDR_CTRL 0x0080
	#define ISB_APP_ANAIN_3_OBJ_2_EEADDR_TOV 0x0081
	#define ISB_APP_ANAIN_3_OBJ_2_EEADDR_INITVALUE 0x0082
	#define ISB_APP_ANAIN_3_OBJ_0 9
	#define ISB_OBJ_9 9
	#define ISB_OBJ_9_CH 3
	#define ISB_APP_ANAIN_3_OBJ_1 10
	#define ISB_OBJ_10 10
	#define ISB_OBJ_10_CH 3
	#define ISB_APP_ANAIN_3_OBJ_2 11
	#define ISB_OBJ_11 11
	#define ISB_OBJ_11_CH 3
	#define ISB_CH_3_EEADDR_CRC 0x0087
#endif /* ISB_CH_3 */

#define ISB_CH_4 4
#if defined(ISB_CH_4)
	#define ISB_CH_4_EEADDR_CTRL 0x0088
	#define ISB_APP_ANAIN_4 4
	#define ISB_APP_ANAIN_4_CH 4
	#define ISB_APP_ANAIN_4_EEADDR_CFG0 0x0089
	#define ISB_APP_ANAIN_4_EEADDR_CFG1 0x008A
	#define ISB_APP_ANAIN_4_EEADDR_CFG2 0x008B
	#define ISB_APP_ANAIN_4_EEADDR_CFG_SWITCH1ON 0x008C
	#define ISB_APP_ANAIN_4_EEADDR_CFG_SWITCH1OFF 0x008E
	#define ISB_APP_ANAIN_4_EEADDR_CFG_SWITCH2ON 0x0090
	#define ISB_APP_ANAIN_4_EEADDR_CFG_SWITCH2OFF 0x0092
	#define ISB_APP_ANAIN_4_OBJ_0_EEADDR_CTRL 0x0094
	#define ISB_APP_ANAIN_4_OBJ_0_EEADDR_TOV 0x0095
	#define ISB_APP_ANAIN_4_OBJ_0_EEADDR_INITVALUE 0x0096
	#define ISB_APP_ANAIN_4_OBJ_1_EEADDR_CTRL 0x009B
	#define ISB_APP_ANAIN_4_OBJ_1_EEADDR_TOV 0x009C
	#define ISB_APP_ANAIN_4_OBJ_1_EEADDR_INITVALUE 0x009D
	#define ISB_APP_ANAIN_4_OBJ_2_EEADDR_CTRL 0x00A2
	#define ISB_APP_ANAIN_4_OBJ_2_EEADDR_TOV 0x00A3
	#define ISB_APP_ANAIN_4_OBJ_2_EEADDR_INITVALUE 0x00A4
	#define ISB_APP_ANAIN_4_OBJ_0 12
	#define ISB_OBJ_12 12
	#define ISB_OBJ_12_CH 4
	#define ISB_APP_ANAIN_4_OBJ_1 13
	#define ISB_OBJ_13 13
	#define ISB_OBJ_13_CH 4
	#define ISB_APP_ANAIN_4_OBJ_2 14
	#define ISB_OBJ_14 14
	#define ISB_OBJ_14_CH 4
	#define ISB_CH_4_EEADDR_CRC 0x00A9
#endif /* ISB_CH_4 */

#define ISB_CH_5 5
#if defined(ISB_CH_5)
	#define ISB_CH_5_EEADDR_CTRL 0x00AA
	#define ISB_APP_ANAIN_5 5
	#define ISB_APP_ANAIN_5_CH 5
	#define ISB_APP_ANAIN_5_EEADDR_CFG0 0x00AB
	#define ISB_APP_ANAIN_5_EEADDR_CFG1 0x00AC
	#define ISB_APP_ANAIN_5_EEADDR_CFG2 0x00AD
	#define ISB_APP_ANAIN_5_EEADDR_CFG_SWITCH1ON 0x00AE
	#define ISB_APP_ANAIN_5_EEADDR_CFG_SWITCH1OFF 0x00B0
	#define ISB_APP_ANAIN_5_EEADDR_CFG_SWITCH2ON 0x00B2
	#define ISB_APP_ANAIN_5_EEADDR_CFG_SWITCH2OFF 0x00B4
	#define ISB_APP_ANAIN_5_OBJ_0_EEADDR_CTRL 0x00B6
	#define ISB_APP_ANAIN_5_OBJ_0_EEADDR_TOV 0x00B7
	#define ISB_APP_ANAIN_5_OBJ_0_EEADDR_INITVALUE 0x00B8
	#define ISB_APP_ANAIN_5_OBJ_1_EEADDR_CTRL 0x00BD
	#define ISB_APP_ANAIN_5_OBJ_1_EEADDR_TOV 0x00BE
	#define ISB_APP_ANAIN_5_OBJ_1_EEADDR_INITVALUE 0x00BF
	#define ISB_APP_ANAIN_5_OBJ_2_EEADDR_CTRL 0x00C4
	#define ISB_APP_ANAIN_5_OBJ_2_EEADDR_TOV 0x00C5
	#define ISB_APP_ANAIN_5_OBJ_2_EEADDR_INITVALUE 0x00C6
	#define ISB_APP_ANAIN_5_OBJ_0 15
	#define ISB_OBJ_15 15
	#define ISB_OBJ_15_CH 5
	#define ISB_APP_ANAIN_5_OBJ_1 16
	#define ISB_OBJ_16 16
	#define ISB_OBJ_16_CH 5
	#define ISB_APP_ANAIN_5_OBJ_2 17
	#define ISB_OBJ_17 17
	#define ISB_OBJ_17_CH 5
	#define ISB_CH_5_EEADDR_CRC 0x00CB
#endif /* ISB_CH_5 */

#define ISB_CH_6 6
#if defined(ISB_CH_6)
	#define ISB_CH_6_EEADDR_CTRL 0x00CC
	#define ISB_APP_ANAIN_6 6
	#define ISB_APP_ANAIN_6_CH 6
	#define ISB_APP_ANAIN_6_EEADDR_CFG0 0x00CD
	#define ISB_APP_ANAIN_6_EEADDR_CFG1 0x00CE
	#define ISB_APP_ANAIN_6_EEADDR_CFG2 0x00CF
	#define ISB_APP_ANAIN_6_EEADDR_CFG_SWITCH1ON 0x00D0
	#define ISB_APP_ANAIN_6_EEADDR_CFG_SWITCH1OFF 0x00D2
	#define ISB_APP_ANAIN_6_EEADDR_CFG_SWITCH2ON 0x00D4
	#define ISB_APP_ANAIN_6_EEADDR_CFG_SWITCH2OFF 0x00D6
	#define ISB_APP_ANAIN_6_OBJ_0_EEADDR_CTRL 0x00D8
	#define ISB_APP_ANAIN_6_OBJ_0_EEADDR_TOV 0x00D9
	#define ISB_APP_ANAIN_6_OBJ_0_EEADDR_INITVALUE 0x00DA
	#define ISB_APP_ANAIN_6_OBJ_1_EEADDR_CTRL 0x00DF
	#define ISB_APP_ANAIN_6_OBJ_1_EEADDR_TOV 0x00E0
	#define ISB_APP_ANAIN_6_OBJ_1_EEADDR_INITVALUE 0x00E1
	#define ISB_APP_ANAIN_6_OBJ_2_EEADDR_CTRL 0x00E6
	#define ISB_APP_ANAIN_6_OBJ_2_EEADDR_TOV 0x00E7
	#define ISB_APP_ANAIN_6_OBJ_2_EEADDR_INITVALUE 0x00E8
	#define ISB_APP_ANAIN_6_OBJ_0 18
	#define ISB_OBJ_18 18
	#define ISB_OBJ_18_CH 6
	#define ISB_APP_ANAIN_6_OBJ_1 19
	#define ISB_OBJ_19 19
	#define ISB_OBJ_19_CH 6
	#define ISB_APP_ANAIN_6_OBJ_2 20
	#define ISB_OBJ_20 20
	#define ISB_OBJ_20_CH 6
	#define ISB_CH_6_EEADDR_CRC 0x00ED
#endif /* ISB_CH_6 */

#define ISB_CH_7 7
#if defined(ISB_CH_7)
	#define ISB_CH_7_EEADDR_CTRL 0x00EE
	#define ISB_APP_ANAIN_7 7
	#define ISB_APP_ANAIN_7_CH 7
	#define ISB_APP_ANAIN_7_EEADDR_CFG0 0x00EF
	#define ISB_APP_ANAIN_7_EEADDR_CFG1 0x00F0
	#define ISB_APP_ANAIN_7_EEADDR_CFG2 0x00F1
	#define ISB_APP_ANAIN_7_EEADDR_CFG_SWITCH1ON 0x00F2
	#define ISB_APP_ANAIN_7_EEADDR_CFG_SWITCH1OFF 0x00F4
	#define ISB_APP_ANAIN_7_EEADDR_CFG_SWITCH2ON 0x00F6
	#define ISB_APP_ANAIN_7_EEADDR_CFG_SWITCH2OFF 0x00F8
	#define ISB_APP_ANAIN_7_OBJ_0_EEADDR_CTRL 0x00FA
	#define ISB_APP_ANAIN_7_OBJ_0_EEADDR_TOV 0x00FB
	#define ISB_APP_ANAIN_7_OBJ_0_EEADDR_INITVALUE 0x00FC
	#define ISB_APP_ANAIN_7_OBJ_1_EEADDR_CTRL 0x0101
	#define ISB_APP_ANAIN_7_OBJ_1_EEADDR_TOV 0x0102
	#define ISB_APP_ANAIN_7_OBJ_1_EEADDR_INITVALUE 0x0103
	#define ISB_APP_ANAIN_7_OBJ_2_EEADDR_CTRL 0x0108
	#define ISB_APP_ANAIN_7_OBJ_2_EEADDR_TOV 0x0109
	#define ISB_APP_ANAIN_7_OBJ_2_EEADDR_INITVALUE 0x010A
	#define ISB_APP_ANAIN_7_OBJ_0 21
	#define ISB_OBJ_21 21
	#define ISB_OBJ_21_CH 7
	#define ISB_APP_ANAIN_7_OBJ_1 22
	#define ISB_OBJ_22 22
	#define ISB_OBJ_22_CH 7
	#define ISB_APP_ANAIN_7_OBJ_2 23
	#define ISB_OBJ_23 23
	#define ISB_OBJ_23_CH 7
	#define ISB_CH_7_EEADDR_CRC 0x010F
#endif /* ISB_CH_7 */



#define ISB_APP_ANAIN_MAX 8
#define ISB_APP_ANAIN_EXECTIME 10
#define ISB_APP_ANAIN_SOURCE_FEATURE_DS1621 TRUE

#define ISB_OBJ_MAX 24
#define ISB_OBJ_EXECTIME 1

#define ISB_GRP_MAX 24
#define ISB_GRP_EEADDR_START 0x0110



#define LIB_DS1621



#include <trunk/core/isb_fw_app.c>
