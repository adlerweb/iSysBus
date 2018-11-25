#ifndef IF_TWI_C_
	#define IF_TWI_C_



	void If_Twi_Init(const uint8_t aTwsr, const uint8_t aTwbr) {
		#if defined(__AVR_ATmega16__)
			TWSR = aTwsr;
			TWBR = aTwbr;
		#elif defined(__AVR_ATmega32__)
			TWSR = aTwsr;
			TWBR = aTwbr;
		#elif defined(__AVR_ATmega64__)
			TWSR = aTwsr;
			TWBR = aTwbr;
		#elif defined(__AVR_ATmega644__)
			TWSR = aTwsr;
			TWBR = aTwbr;
		#elif defined(__AVR_ATmega169P__)
			USISR = aTwsr;
			USICR = aTwbr;
		#else
			#error "if_twi.c -> No definition for this MCU available."
		#endif
	}



	uint8_t If_Twi_Start(uint8_t aSlaRW) {
		uint8_t State;
		TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTA);
		while (! (TWCR & (1<<TWINT))) {
			;
		}
		State = TWSR;
		if ((State != TW_START) && (State != TW_REP_START)) {
			return FALSE;
		}
		TWDR = aSlaRW;
		TWCR = (1<<TWINT) | (1<<TWEN);
		while (! (TWCR & (1<<TWINT))) {
			;
		}
		State = TWSR;
		if ((State != TW_MT_SLA_ACK) && (State != TW_MR_SLA_ACK)) {
			return FALSE;
		}
		return TRUE;
	}



	uint8_t If_Twi_RepStart(uint8_t aSlaRW) {
		return If_Twi_Start(aSlaRW);
	}



	uint8_t If_Twi_Write(uint8_t aData) {
		uint8_t State;
		TWDR = aData;
		TWCR = (1<<TWINT) | (1<<TWEN);
		while (! (TWCR & (1<<TWINT))) {
			;
		}
		State = TWSR;
		if (State != TW_MT_DATA_ACK) {
			return FALSE;
		}
		return TRUE;
	}



	uint8_t If_Twi_ReadAck(void) {
		TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWEA);
		while (! (TWCR & (1<<TWINT))) {
			;
		}
		return TWDR;
	}



	uint8_t If_Twi_ReadNack(void) {
		TWCR = (1<<TWINT) | (1<<TWEN);
		while (! (TWCR & (1<<TWINT))) {
			;
		}
		return TWDR;
	}



	void If_Twi_Stop(void) {
		uint16_t Counter = 0;
		TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
		while ((! (TWCR & (1<<TWINT))) && (Counter++ < 1000)) {
			;
		}
	}



#endif /* IF_TWI_C_ */
