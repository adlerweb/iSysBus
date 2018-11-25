/**
 * @file		avrlib/trunk/lib/isb_inf_can_def.h
 *
 * @brief		iSysBus Interface Can Defines.
 *
 * This file includes iSysBus Interface Can Defines.
 *
 * @author		© Patrick Amrhein <trick-at-isysbus-dot-org> 01.05.2010.
 *
 * @date		$Date: 2011-08-03 15:23:38 +0200 (Mi, 03 Aug 2011) $
 *
 * @version		$Rev: 4514 $
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





#ifndef ISB_INF_CAN_DEF_H_
	#define ISB_INF_CAN_DEF_H_



	#if ISB_INF_CAN0 == 1

		#define INF_CAN0_RX
		#define INF_CAN0_TX

		#define INF_CAN0_CLOCK							ISB_INF_CAN0_CLOCK
		#define INF_CAN0_SPEED							ISB_INF_CAN0_SPEED
		#define INF_CAN0_SS								ISB_INF_CAN0_SS
		#define INF_CAN0_RS								ISB_INF_CAN0_RS
		#define INF_CAN0_INT							ISB_INF_CAN0_INT
		#define INF_CAN0_MODE							ISB_INF_CAN0_MODE

	#endif /* ISB_INF_CAN0 == 1 */



	#if ISB_INF_CAN1 == 1

		#define INF_CAN1_RX
		#define INF_CAN1_TX

		#define INF_CAN1_CLOCK							ISB_INF_CAN1_CLOCK
		#define INF_CAN1_SPEED							ISB_INF_CAN1_SPEED
		#define INF_CAN1_SS								ISB_INF_CAN1_SS
		#define INF_CAN1_RS								ISB_INF_CAN1_RS
		#define INF_CAN1_INT							ISB_INF_CAN1_INT
		#define INF_CAN1_MODE							ISB_INF_CAN1_MODE

	#endif /* ISB_INF_CAN1 == 1 */



	#if ISB_INF_CAN2 == 1

		#define INF_CAN2_RX
		#define INF_CAN2_TX

		#define INF_CAN2_CLOCK							ISB_INF_CAN2_CLOCK
		#define INF_CAN2_SPEED							ISB_INF_CAN2_SPEED
		#define INF_CAN2_SS								ISB_INF_CAN2_SS
		#define INF_CAN2_RS								ISB_INF_CAN2_RS
		#define INF_CAN2_INT							ISB_INF_CAN2_INT
		#define INF_CAN2_MODE							ISB_INF_CAN2_MODE

	#endif /* ISB_INF_CAN2 == 1 */



#endif /* ISB_INF_CAN_DEF_H_ */
