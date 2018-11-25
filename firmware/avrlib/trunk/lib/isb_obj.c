/**
 * @file		avrlib/trunk/lib/isb_obj.c
 *
 * @brief		iSysBus Object.
 *
 * This file includes the iSysBus Object.
 *
 * @author		© Patrick Amrhein <trick-at-isysbus-dot-org> 01.05.2010.
 *
 * @date		$Date: 2012-05-03 16:09:41 +0200 (Do, 03. Mai 2012) $
 *
 * @version		$Rev: 7505 $
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





#ifndef ISB_OBJ_C_
	#define ISB_OBJ_C_



	void Isb_Obj_Exec(void)
	{

		#if defined(ISB_OBJ_MAX)
		if (bit_is_set(Isb_Obj_Ctrl, ISB_CTRL_SOFTIRQ_EXEC))
		{
			for (uint8_t ObjIndex = 0; ObjIndex < ISB_OBJ_MAX; ObjIndex++)
			{
				uint8_t Ch = pgm_read_byte(&pgmIsb_Obj_Ch_Array[ObjIndex]);
				if (bit_is_set(Isb_Ch[Ch].Ctrl, ISB_CH_CTRL_ENABLED))
				{
					if (bit_is_set(Isb_Obj[ObjIndex].Ctrl, ISB_OBJ_CTRL_ENABLED))
					{
						if (bit_is_set(Isb_Obj[ObjIndex].Ctrl, ISB_OBJ_CTRL_SEND))
						{
							if (Isb_Obj[ObjIndex].IsChanged == TRUE)
							{
								for (uint8_t GrpIndex = 0; GrpIndex < ISB_GRP_MAX; GrpIndex++)
								{
//									uint8_t Obj = pgm_read_byte(&pgmIsb_Obj_Obj_Array[ObjIndex]);
// TODO:
uint8_t Obj = ObjIndex;
									if ((Isb_Grp[GrpIndex].Obj == Obj) & (Isb_Grp[GrpIndex].Id != 0))
									{
										Isb_Msg_t TxMsg;
										uint8_t Dlc = Isb_Obj_getDlc(Isb_Obj[ObjIndex].Top);
										TxMsg.Flags = ISB_MSG_FLAGS_TOF_MULTICAST | Dlc;
										TxMsg.DestId = Isb_Grp[GrpIndex].Id;
										TxMsg.SourceId = Isb_Node_Id;
										TxMsg.Data[0] = Isb_Obj[ObjIndex].Top;
										TxMsg.Data[1] = ISB_MSG_CTRL_CMD_WRITE;
										TxMsg.Data[2] = Isb_Obj[ObjIndex].Tov;
										for (uint8_t i = 0; i < (Dlc - 3); i++)
										{
											TxMsg.Data[i + 3] = Isb_Obj[ObjIndex].Data[i];
										}
										Isb_SendMsg(&TxMsg);
										break;
									}
								}
								Isb_Obj[ObjIndex].IsChanged = FALSE;
							}
						}
						if (bit_is_set(Isb_Obj[ObjIndex].Ctrl, ISB_OBJ_CTRL_READONINIT))
						{
							for (uint8_t GrpIndex = 0; GrpIndex < ISB_GRP_MAX; GrpIndex++)
							{
//								uint8_t Obj = pgm_read_byte(&pgmIsb_Obj_Obj_Array[ObjIndex]);
// TODO:
uint8_t Obj = ObjIndex;
								if ((Isb_Grp[GrpIndex].Obj == Obj) & (Isb_Grp[GrpIndex].Id != 0))
								{
									Isb_Msg_t TxMsg;
									uint8_t Dlc = Isb_Obj_getDlc(Isb_Obj[ObjIndex].Top);
									TxMsg.Flags = ISB_MSG_FLAGS_TOF_MULTICAST | Dlc;
									TxMsg.DestId = Isb_Grp[GrpIndex].Id;
									TxMsg.SourceId = Isb_Node_Id;
									TxMsg.Data[0] = Isb_Obj[ObjIndex].Top;
									TxMsg.Data[1] = ISB_MSG_CTRL_CMD_READ;
									TxMsg.Data[2] = Isb_Obj[ObjIndex].Tov;
									for (uint8_t i = 0; i < (Dlc - 3); i++)
									{
										TxMsg.Data[i + 3] = Isb_Obj[ObjIndex].Data[i];
									}
									Isb_SendMsg(&TxMsg);
									Isb_Obj[ObjIndex].Ctrl &= ~(1 << ISB_OBJ_CTRL_READONINIT);
									break;
								}
							}
						}
					}
				}
			}
			Isb_Obj_Ctrl &= ~(1 << ISB_CTRL_SOFTIRQ_EXEC);
		}
		#endif /* ISB_OBJ_MAX */

	}



	void Isb_Obj_Rx(const Isb_Msg_t * aIsb_Msg)
	{
		for (uint8_t GrpIndex = 0; GrpIndex < ISB_GRP_MAX; GrpIndex++)
		{
			if ((aIsb_Msg->DestId == Isb_Grp[GrpIndex].Id) & (aIsb_Msg->DestId != 0))
			{

				#if defined(ISB_OBJ_MAX)
					for (uint8_t ObjIndex = 0; ObjIndex < ISB_OBJ_MAX; ObjIndex++)
					{
//						uint8_t Ch = pgm_read_byte(&pgmIsb_Obj_Ch_Array[ObjIndex]);
//						uint8_t Obj = pgm_read_byte(&pgmIsb_Obj_Obj_Array[ObjIndex]);
// TODO:
uint8_t Obj = ObjIndex;
						if (bit_is_set(Isb_Obj[ObjIndex].Ctrl, ISB_OBJ_CTRL_ENABLED))
						{
							if (Obj == Isb_Grp[GrpIndex].Obj)
							{
								uint8_t Dlc = Isb_Obj_getDlc(Isb_Obj[ObjIndex].Top);
								if ((aIsb_Msg->Flags & ISB_MSG_FLAGS_DLC_MASK) == Dlc)
								{
									if (aIsb_Msg->Data[0] == Isb_Obj[ObjIndex].Top)
									{
										if ((aIsb_Msg->Data[1] & ISB_MSG_CTRL_CMD_MASK) == ISB_MSG_CTRL_CMD_READ)
										{
											if (bit_is_set(Isb_Obj[ObjIndex].Ctrl, ISB_OBJ_CTRL_READ))
											{
												Isb_Msg_t TxMsg;
												TxMsg.Flags = ISB_MSG_FLAGS_TOF_MULTICAST | Dlc;
												TxMsg.DestId = aIsb_Msg->DestId;
												TxMsg.SourceId = Isb_Node_Id;
												TxMsg.Data[0] = Isb_Obj[ObjIndex].Top;
												TxMsg.Data[1] = ISB_MSG_CTRL_CMD_ANSWER;
												TxMsg.Data[2] = Isb_Obj[ObjIndex].Tov;
												for (uint8_t i = 0; i < (Dlc - 3); i++)
												{
													TxMsg.Data[i + 3] = Isb_Obj[ObjIndex].Data[i];
												}
												Isb_SendMsg(&TxMsg);
											}
										}
										if ((aIsb_Msg->Data[1] & ISB_MSG_CTRL_CMD_MASK) == ISB_MSG_CTRL_CMD_ANSWER)
										{
											if (bit_is_set(Isb_Obj[ObjIndex].Ctrl, ISB_OBJ_CTRL_UPDATE))
											{
												if (aIsb_Msg->Data[2] == Isb_Obj[ObjIndex].Tov)
												{
													for (uint8_t i = 0; i < (Dlc - 3); i++)
													{
														Isb_Obj[ObjIndex].Data[i] = aIsb_Msg->Data[i + 3];
													}
													Isb_Obj[ObjIndex].Ctrl &= ~(1 << ISB_OBJ_CTRL_READONINIT);
												}
											}
										}
										if ((aIsb_Msg->Data[1] & ISB_MSG_CTRL_CMD_MASK) == ISB_MSG_CTRL_CMD_WRITE)
										{
											if (bit_is_set(Isb_Obj[ObjIndex].Ctrl, ISB_OBJ_CTRL_WRITE))
											{
												if (aIsb_Msg->Data[2] == Isb_Obj[ObjIndex].Tov)
												{
													for (uint8_t i = 0; i < (Dlc - 3); i++)
													{
														if (Isb_Obj[ObjIndex].Data[i] != aIsb_Msg->Data[i + 3])
														{
															Isb_Obj[ObjIndex].Data[i] = aIsb_Msg->Data[i + 3];
															Isb_Obj[ObjIndex].IsChanged = TRUE;
														}
													}
													Isb_Obj[ObjIndex].Ctrl &= ~(1 << ISB_OBJ_CTRL_READONINIT);
												}
											}
										}
									}
								}
							}
						}
					}
				#endif /* ISB_OBJ_MAX */

			}
		}
	}



	uint8_t Isb_Obj_getDlc(uint8_t aTop)
	{

		uint8_t Dlc = 0;

		switch (aTop)
		{
			case ISB_MSG_TOP_1BIT:
				Dlc = 4;
				break;
//			case ISB_MSG_TOP_4BIT:
//				Dlc = 4;
//				break;
			case ISB_MSG_TOP_FLOAT:
				Dlc = 5;
				break;
			case ISB_MSG_TOP_TIME:
				Dlc = 6;
				break;
			case ISB_MSG_TOP_DATE:
				Dlc = 8;
				break;
//			case ISB_MSG_TOP_U8BIT:
//				Dlc = 5;
//				break;
//			case ISB_MSG_TOP_U16BIT:
//				Dlc = 6;
//				break;
//			case ISB_MSG_TOP_U32BIT:
//				Dlc = 8;
//				break;
//			case ISB_MSG_TOP_S8BIT:
//				Dlc = 5;
//				break;
//			case ISB_MSG_TOP_S16BIT:
//				Dlc = 6;
//				break;
//			case ISB_MSG_TOP_S32BIT:
//				Dlc = 8;
//				break;
		}

		return Dlc;

	}



#endif /* ISB_OBJ_C_ */
