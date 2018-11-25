#ifndef IF_TWI_H_
	#define IF_TWI_H_



	void If_Twi_Init(const uint8_t aTwsr, const uint8_t aTwbr);
	uint8_t If_Twi_Start(uint8_t aSlaRW);
	uint8_t If_Twi_RepStart(uint8_t aSlaRW);
	uint8_t If_Twi_Write(uint8_t aData);
	uint8_t If_Twi_ReadAck(void);
	uint8_t If_Twi_ReadNack(void);
	void If_Twi_Stop(void);



#endif /* IF_TWI_H_ */
