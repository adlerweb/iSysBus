/**
 * @file		avrlib/trunk/core/isb_bl.c
 *
 * @brief		iSysBus Bootloader-Core.
 *
 * This file includes the iSysBus bootloader-core.
 *
 * @author		© Patrick Amrhein <trick-at-isysbus-dot-org> 01.05.2010.
 *
 * @date		$Date: 2012-05-06 15:19:48 +0200 (So, 06. Mai 2012) $
 *
 * @version		$Rev: 7712 $
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





#ifndef ISB_BL_C_
	#define ISB_BL_C_



	#include "./../lib/isb_node_identify_def.h"



	#ifndef _STDIO_H_
		#error "main.c -> stdio.h not includet."
	#endif /* _STDIO_H_ */

	#ifndef ISB_BL_H_
		#error "main.c -> isb_bl.h not includet."
	#endif /* ISB_BL_H_ */

	#ifndef ISB_NODE_IDENTIFY
		#warning "main.c -> ISB_NODE_IDENTIFY not defined use default NONE."
		#define ISB_NODE_IDENTIFY						NONE
	#endif /* ISB_NODE_IDENTIFY */

	#if ISB_INF == USART0

		#ifndef ISB_INF_USART0
			#warning "main.c -> ISB_INF_USART0 not defined use default 1."
			#define ISB_INF_USART0							1
		#endif /* ISB_INF_USART0 */

		#ifndef ISB_INF_USART0_BAUDRATE
			#warning "main.c -> ISB_INF_USART0_BAUDRATE not defined use default 115200."
			#define ISB_INF_USART0_BAUDRATE					115200
		#endif /* ISB_INF_USART0_BAUDRATE */

		#ifndef ISB_INF_USART0_STARTBITS
			#warning "main.c -> ISB_INF_USART0_STARTBITS not defined use default 1."
			#define ISB_INF_USART0_STARTBITS				1
		#endif /* ISB_INF_USART0_STARTBITS */

		#ifndef ISB_INF_USART0_DATABITS
			#warning "main.c -> ISB_INF_USART0_DATABITS not defined use default 8."
			#define ISB_INF_USART0_DATABITS					8
		#endif /* ISB_INF_USART0_DATABITS */

		#ifndef ISB_INF_USART0_PARITY
			#warning "main.c -> ISB_INF_USART0_PARITY not defined use default NONE."
			#define ISB_INF_USART0_PARITY					NONE
		#endif /* ISB_INF_USART0_PARITY */

		#ifndef ISB_INF_USART0_STOPBITS
			#warning "main.c -> ISB_INF_USART0_STOPBITS not defined use default 1."
			#define ISB_INF_USART0_STOPBITS					1
		#endif /* ISB_INF_USART0_STOPBITS */

		#include "./../lib/isb_inf_usart_def.h"
		#include "./../lib/inf_usart_def.h"
		#include "./../lib/lib_crc.h"
		#include "./../lib/lib_crc.c"

	#elif ISB_INF == CAN0

		#ifndef ISB_INF_CAN0
			#warning "main.c -> ISB_INF_CAN0 not defined."
			#define ISB_INF_CAN0							1
		#endif /* ISB_INF_CAN0 */

		#ifndef ISB_INF_CAN0_CLOCK
			#warning "main.c -> ISB_INF_CAN0_CLOCK not defined."
			#define ISB_INF_CAN0_CLOCK						NONE
		#endif /* ISB_INF_CAN0_CLOCK */

		#ifndef ISB_INF_CAN0_SPEED
			#warning "main.c -> ISB_INF_CAN0_SPEED not defined."
			#define ISB_INF_CAN0_SPEED						NONE
		#endif /* ISB_INF_CAN0_SPEED */

		#ifndef ISB_INF_CAN0_SS
			#warning "main.c -> ISB_INF_CAN0_SS not defined."
			#define ISB_INF_CAN0_SS							NONE
		#endif /* ISB_INF_CAN0_SS */

		#ifndef ISB_INF_CAN0_RS
			#warning "main.c -> ISB_INF_CAN0_RS not defined."
			#define ISB_INF_CAN0_RS							NONE
		#endif /* ISB_INF_CAN0_RS */

		#ifndef ISB_INF_CAN0_INT
			#warning "main.c -> ISB_INF_CAN0_INT not defined."
			#define ISB_INF_CAN0_INT						NONE
		#endif /* ISB_INF_CAN0_INT */

		#include "./../lib/isb_inf_can_def.h"
		#include "./../lib/inf_can_def.h"
		#include "./../lib/inf_spi_def.h"
		#include "./../lib/lib_mcp2515_def.h"

	#else

		#error "main.c -> ISB_INF is not USART0 or CAN0."

	#endif /* ISB_INF */



	#if defined(__AVR_ATmega8__)
		#define BOOTSIZE 1024
	#elif defined(__AVR_ATmega16__)
		#define BOOTSIZE 1024
	#elif defined(__AVR_ATmega32__)
		#define BOOTSIZE 1024
	#elif defined(__AVR_ATmega48__)
		#define BOOTSIZE 1024
	#elif defined(__AVR_ATmega48V__)
		#define BOOTSIZE 1024
	#elif defined(__AVR_ATmega64__)
		#define BOOTSIZE 1024
	#elif defined(__AVR_ATmega88__)
		#define BOOTSIZE 1024
	#elif defined(__AVR_ATmega88V__)
		#define BOOTSIZE 1024
	#elif defined(__AVR_ATmega128__)
		#define BOOTSIZE 1024
	#elif defined(__AVR_ATmega168__)
		#define BOOTSIZE 1024
	#elif defined(__AVR_ATmega168V__)
		#define BOOTSIZE 1024
	#elif defined(__AVR_ATmega169P__)
		#define BOOTSIZE 1024
	#elif defined(__AVR_ATmega169PV__)
		#define BOOTSIZE 1024
	#elif defined(__AVR_ATmega644__)
		#define BOOTSIZE 2048
	#elif defined(__AVR_AT90CAN32__)
		#define BOOTSIZE 1024
	#elif defined(__AVR_AT90CAN64__)
		#define BOOTSIZE 1024
	#elif defined(__AVR_AT90CAN128__)
		#define BOOTSIZE 1024
	#else
		#define BOOTSIZE 0
		#error "No definition for this MCU available."
	#endif
	#define APP_END (FLASHEND - (2 * BOOTSIZE) + 1)
	#define FLASHPAGES ((APP_END / SPM_PAGESIZE) - 1)



	uint16_t __attribute__((always_inline)) ByteToShort(uint8_t hi, uint8_t lo) {
		uint16_t ret;
		((unsigned char *) & ret)[0] = lo;
		((unsigned char *) & ret)[1] = hi;
		return ret;
	}



	void __attribute__((noreturn)) (* JumpToFirmware) (void) = 0x0000;



	void __attribute__ ((noinline)) eep_write_byte(uint8_t * aAddr, uint8_t aData) {
		if (eeprom_read_byte(aAddr) != aData) {
			eeprom_write_byte(aAddr, aData);
		}
	}



	void get_ResetSource(void) __attribute__((naked)) __attribute__((section(".init3")));
	void get_ResetSource(void) {
		wdt_disable();
		uint8_t ResetSource = eeprom_read_byte((uint8_t *)EEP__ISB_NODE_OPERATING_RESETSOURCE);
		#if defined(__AVR_ATmega8__)
			ResetSource |= MCUCSR & ((1 << PORF) | (1 << EXTRF) | (1 << BORF) | (1 << WDRF));
			MCUCSR = 0;
		#elif defined(__AVR_ATmega16__)
			ResetSource |= MCUCSR & ((1 << PORF) | (1 << EXTRF) | (1 << BORF) | (1 << WDRF));
			MCUCSR = 0;
		#elif defined(__AVR_ATmega32__)
			ResetSource |= MCUCSR & ((1 << PORF) | (1 << EXTRF) | (1 << BORF) | (1 << WDRF));
			MCUCSR = 0;
		#elif defined(__AVR_ATmega48__)
			ResetSource |= MCUSR & ((1 << PORF) | (1 << EXTRF) | (1 << BORF) | (1 << WDRF));
			MCUSR = 0;
		#elif defined(__AVR_ATmega48V__)
			ResetSource |= MCUSR & ((1 << PORF) | (1 << EXTRF) | (1 << BORF) | (1 << WDRF));
			MCUSR = 0;
		#elif defined(__AVR_ATmega64__)
			ResetSource |= MCUCSR & ((1 << PORF) | (1 << EXTRF) | (1 << BORF) | (1 << WDRF));
			MCUCSR = 0;
		#elif defined(__AVR_ATmega88__)
			ResetSource |= MCUSR & ((1 << PORF) | (1 << EXTRF) | (1 << BORF) | (1 << WDRF));
			MCUSR = 0;
		#elif defined(__AVR_ATmega88V__)
			ResetSource |= MCUSR & ((1 << PORF) | (1 << EXTRF) | (1 << BORF) | (1 << WDRF));
			MCUSR = 0;
		#elif defined(__AVR_ATmega128__)
			ResetSource |= MCUCSR & ((1 << PORF) | (1 << EXTRF) | (1 << BORF) | (1 << WDRF));
			MCUCSR = 0;
		#elif defined(__AVR_ATmega168__)
			ResetSource |= MCUSR & ((1 << PORF) | (1 << EXTRF) | (1 << BORF) | (1 << WDRF));
			MCUSR = 0;
		#elif defined(__AVR_ATmega168V__)
			ResetSource |= MCUSR & ((1 << PORF) | (1 << EXTRF) | (1 << BORF) | (1 << WDRF));
			MCUSR = 0;
		#elif defined(__AVR_ATmega169P__)
			ResetSource |= MCUSR & ((1 << PORF) | (1 << EXTRF) | (1 << BORF) | (1 << WDRF));
			MCUSR = 0;
		#elif defined(__AVR_ATmega169PV__)
			ResetSource |= MCUSR & ((1 << PORF) | (1 << EXTRF) | (1 << BORF) | (1 << WDRF));
			MCUSR = 0;
		#elif defined(__AVR_ATmega644__)
			ResetSource |= MCUSR & ((1 << PORF) | (1 << EXTRF) | (1 << BORF) | (1 << WDRF));
			MCUSR = 0;
		#elif defined(__AVR_AT90CAN32__)
			ResetSource |= MCUSR & ((1 << PORF) | (1 << EXTRF) | (1 << BORF) | (1 << WDRF));
			MCUSR = 0;
		#elif defined(__AVR_AT90CAN64__)
			ResetSource |= MCUSR & ((1 << PORF) | (1 << EXTRF) | (1 << BORF) | (1 << WDRF));
			MCUSR = 0;
		#elif defined(__AVR_AT90CAN128__)
			ResetSource |= MCUSR & ((1 << PORF) | (1 << EXTRF) | (1 << BORF) | (1 << WDRF));
			MCUSR = 0;
		#else
			#error "No definition for this MCU available."
		#endif
		if (bit_is_set(ResetSource, 7)) {
			ResetSource = 0;
		}
		eep_write_byte((uint8_t *)EEP__ISB_NODE_OPERATING_RESETSOURCE, ResetSource);
	}



	#if ISB_INF == USART0
		static void sendchar(uint8_t Data) {
			#if defined (__AVR_ATmega8__)
				UDR = Data;
				while (! (UCSRA & (1 << TXC))) {
					;
				}
				UCSRA |= (1 << TXC);
			#elif defined (__AVR_ATmega16__)
				UDR = Data;
				while (! (UCSRA & (1 << TXC))) {
					;
				}
				UCSRA |= (1 << TXC);
			#elif defined (__AVR_ATmega32__)
				UDR = Data;
				while (! (UCSRA & (1 << TXC))) {
					;
				}
				UCSRA |= (1 << TXC);
			#elif defined(__AVR_ATmega48__)
				UDR0 = Data;
				while (! (UCSR0A & (1 << TXC0))) {
					;
				}
				UCSR0A |= (1 << TXC0);
			#elif defined(__AVR_ATmega48V__)
				UDR0 = Data;
				while (! (UCSR0A & (1 << TXC0))) {
					;
				}
				UCSR0A |= (1 << TXC0);
			#elif defined (__AVR_ATmega64__)
				UDR0 = Data;
				while (! (UCSR0A & (1 << TXC0))) {
					;
				}
				UCSR0A |= (1 << TXC0);
			#elif defined(__AVR_ATmega88__)
				UDR0 = Data;
				while (! (UCSR0A & (1 << TXC0))) {
					;
				}
				UCSR0A |= (1 << TXC0);
			#elif defined(__AVR_ATmega88V__)
				UDR0 = Data;
				while (! (UCSR0A & (1 << TXC0))) {
					;
				}
				UCSR0A |= (1 << TXC0);
			#elif defined (__AVR_ATmega128__)
				UDR0 = Data;
				while (! (UCSR0A & (1 << TXC0))) {
					;
				}
				UCSR0A |= (1 << TXC0);
			#elif defined(__AVR_ATmega168__)
				UDR0 = Data;
				while (! (UCSR0A & (1 << TXC0))) {
					;
				}
				UCSR0A |= (1 << TXC0);
			#elif defined(__AVR_ATmega168V__)
				UDR0 = Data;
				while (! (UCSR0A & (1 << TXC0))) {
					;
				}
				UCSR0A |= (1 << TXC0);
			#elif defined(__AVR_ATmega169P__)
				UDR0 = Data;
				while (! (UCSR0A & (1 << TXC0))) {
					;
				}
				UCSR0A |= (1 << TXC0);
			#elif defined(__AVR_ATmega169PV__)
				UDR0 = Data;
				while (! (UCSR0A & (1 << TXC0))) {
					;
				}
				UCSR0A |= (1 << TXC0);
			#elif defined(__AVR_ATmega644__)
				UDR0 = Data;
				while (! (UCSR0A & (1 << TXC0))) {
					;
				}
				UCSR0A |= (1 << TXC0);
			#elif defined (__AVR_AT90CAN32__)
				UDR0 = Data;
				while (! (UCSR0A & (1 << TXC0))) {
					;
				}
				UCSR0A |= (1 << TXC0);
			#elif defined (__AVR_AT90CAN64__)
				UDR0 = Data;
				while (! (UCSR0A & (1 << TXC0))) {
					;
				}
				UCSR0A |= (1 << TXC0);
			#elif defined (__AVR_AT90CAN128__)
				UDR0 = Data;
				while (! (UCSR0A & (1 << TXC0))) {
					;
				}
				UCSR0A |= (1 << TXC0);
			#else
				#error "No definition for this MCU available."
			#endif
		}
	#endif /* ISB_INF == USART0 */



	#if ISB_INF == USART0
		void Send_Message(const Isb_Msg_t * Msg) {
			sendchar(ISB_INF_USART0_STARTBYTE);
			sendchar(Msg->Flags);
			sendchar((uint8_t)Msg->DestId);
			sendchar((uint8_t)(Msg->DestId >> 8));
			sendchar((uint8_t)Msg->SourceId);
			sendchar((uint8_t)(Msg->SourceId >> 8));
			for (uint8_t i = 0; i < (Msg->Flags & ISB_MSG_FLAGS_DLC_MASK); i++) {
				sendchar(Msg->Data[i]);
			}
			sendchar(0x00);
			sendchar(Lib_Crc_Calc8(Msg, (5 + (Msg->Flags & ISB_MSG_FLAGS_DLC_MASK))));
			sendchar(ISB_INF_USART0_STOPBYTE);
		}
	#endif /* ISB_INF == USART0 */



	#if ISB_INF == CAN0
		void Inf_Spi_Init(void) {
			INF_SPI_DDR = (INF_SPI_DDR | (1 << INF_SPI_DD_MOSI) | (1 << INF_SPI_DD_SCK)) & ~(1 << INF_SPI_DD_MISO);
			SPCR |= (1 << MSTR) | (1 << SPR0) | (1 << SPE);
		}
	#endif /* ISB_INF == CAN0 */



	#if ISB_INF == CAN0
		uint8_t __attribute__((noinline)) Inf_Spi_WriteRead(uint8_t aData) {
			SPDR = aData;
			loop_until_bit_is_set(SPSR, SPIF);
			return SPDR;
		}
	#endif /* ISB_INF == CAN0 */



	#if ISB_INF == CAN0
		void Lib_Mcp2515_Write(const uint8_t aAddr, const uint8_t aData) {
			INF_CAN0_SS_LOW;
			Inf_Spi_WriteRead(LIB_MCP2515_WRITE);
			Inf_Spi_WriteRead(aAddr);
			Inf_Spi_WriteRead(aData);
			INF_CAN0_SS_HIGH;
		}
	#endif /* ISB_INF == CAN0 */



	#if ISB_INF == CAN0
		void Send_Message(const Isb_Msg_t * Msg) {
			INF_CAN0_SS_LOW;
			Inf_Spi_WriteRead(LIB_MCP2515_LOAD_TX_BUFFER0);
			Inf_Spi_WriteRead(((Msg->Flags << 2) & 0xC0) | (Msg->DestId >> 10));
			Inf_Spi_WriteRead(((Msg->DestId >> 2) & 0xE0) | (1 << LIB_MCP2515_TXBnSIDH_EXIDE) | ((Msg->DestId >> 5) & 0x03));
			Inf_Spi_WriteRead((Msg->DestId << 3) | ((Msg->SourceId >> 8) & 0x07));
			Inf_Spi_WriteRead(Msg->SourceId);
			uint8_t len = (Msg->Flags & ISB_MSG_FLAGS_DLC_MASK);
			Inf_Spi_WriteRead(len);
			for(uint8_t i = 0; i < len; i++) {
				Inf_Spi_WriteRead(Msg->Data[i]);
			}
			INF_CAN0_SS_HIGH;
			Lib_Mcp2515_Write(LIB_MCP2515_TXB0CTRL, (1 << 3));
		}
	#endif /* ISB_INF == CAN0 */



	int main(void) {

		wdt_enable(WDTO_500MS);
		wdt_reset();

		#if defined(ISB_NODE_IDENTIFY_REGISTER)
			#if defined(ISB_NODE_IDENTIFY_INIT)
				ISB_NODE_IDENTIFY_INIT;
				#if defined(ISB_NODE_IDENTIFY_PULLUP)
					ISB_NODE_IDENTIFY_PULLUP;
				#endif /* ISB_NODE_IDENTIFY_PULLUP */
			#endif /* ISB_NODE_IDENTIFY_INIT */
		#endif /* ISB_NODE_IDENTIFY_REGISTER */

		uint8_t Isb_Node_Serial_Number[4];
		for (uint8_t i = 0; i < 4; i++) {
			Isb_Node_Serial_Number[i] = eeprom_read_byte((uint8_t *)(EEP__ISB_NODE_SERIAL_NUMBER_0 + i));
		}

		for (uint8_t i = 0; i < 4; i++) {
			eep_write_byte((uint8_t *)(EEP__ISB_BOOTLOADER_CODE_0 + i), Isb_Bootloader_Code[i]);
		}

		uint8_t Isb_Node_Operating_Mode = 0;
		Isb_Node_Operating_Mode = eeprom_read_byte((uint8_t *)EEP__ISB_NODE_OPERATING_MODE);

		uint8_t Isb_Node_Operating_ResetSource = 0;
		Isb_Node_Operating_ResetSource = eeprom_read_byte((uint8_t *)EEP__ISB_NODE_OPERATING_RESETSOURCE);

		uint8_t Isb_Node_Operating_Error = 0;

		uint16_t Isb_Node_Id = 0;
		Isb_Node_Id = eeprom_read_byte((uint8_t *)EEP__ISB_NODE_ID_0);
		Isb_Node_Id |= eeprom_read_byte((uint8_t *)EEP__ISB_NODE_ID_1) << 8;
		if (Isb_Node_Id > 2047) {
			Isb_Node_Id = 0;
			Isb_Node_Operating_Mode = ISB_NODE_OPERATING_MODE__BL_NORM;
			Isb_Node_Operating_Error |= 0x01;
		}

		#if defined(ISB_NODE_IDENTIFY_REGISTER)
			if (bit_is_clear(ISB_NODE_IDENTIFY_REGISTER, ISB_NODE_IDENTIFY_BIT)) {
				Isb_Node_Operating_Mode = ISB_NODE_OPERATING_MODE__BL_NORM;
				Isb_Node_Operating_Error |= 0x02;
			}
		#endif /* ISB_NODE_IDENTIFY_REGISTER */

		if (Isb_Node_Operating_Mode == ISB_NODE_OPERATING_MODE__BL_FLASH) {
			for (uint8_t i = 0; i < 4; i++) {
				eep_write_byte((uint8_t *)(EEP__ISB_FIRMWARE_CODE_0 + i), 0x00);
			}
			for (uint16_t i = 0; i < FLASHPAGES; i++) {
				wdt_reset();
				boot_page_erase(i * SPM_PAGESIZE);
				boot_spm_busy_wait();
			}
		}

		#if ISB_INF == USART0
			uint8_t tempByte = 0;
			uint8_t relPos = 0;
			#if defined(__AVR_ATmega8__)
				UCSRA = INF_USART0_UCSRA;
				UBRRH = INF_USART0_UBRRH;
				UBRRL = INF_USART0_UBRRL;
				UCSRC = INF_USART0_UCSRC;
				UCSRB = INF_USART0_UCSRB;
			#elif defined(__AVR_ATmega16__)
				UCSRA = INF_USART0_UCSRA;
				UBRRH = INF_USART0_UBRRH;
				UBRRL = INF_USART0_UBRRL;
				UCSRC = INF_USART0_UCSRC;
				UCSRB = INF_USART0_UCSRB;
			#elif defined(__AVR_ATmega32__)
				UCSRA = INF_USART0_UCSRA;
				UBRRH = INF_USART0_UBRRH;
				UBRRL = INF_USART0_UBRRL;
				UCSRC = INF_USART0_UCSRC;
				UCSRB = INF_USART0_UCSRB;
			#elif defined(__AVR_ATmega48__)
				UCSR0A = INF_USART0_UCSRA;
				UBRR0H = INF_USART0_UBRRH;
				UBRR0L = INF_USART0_UBRRL;
				UCSR0C = INF_USART0_UCSRC;
				UCSR0B = INF_USART0_UCSRB;
			#elif defined(__AVR_ATmega48V__)
				UCSR0A = INF_USART0_UCSRA;
				UBRR0H = INF_USART0_UBRRH;
				UBRR0L = INF_USART0_UBRRL;
				UCSR0C = INF_USART0_UCSRC;
				UCSR0B = INF_USART0_UCSRB;
			#elif defined(__AVR_ATmega64__)
				UCSR0A = INF_USART0_UCSRA;
				UBRR0H = INF_USART0_UBRRH;
				UBRR0L = INF_USART0_UBRRL;
				UCSR0C = INF_USART0_UCSRC;
				UCSR0B = INF_USART0_UCSRB;
			#elif defined(__AVR_ATmega88__)
				UCSR0A = INF_USART0_UCSRA;
				UBRR0H = INF_USART0_UBRRH;
				UBRR0L = INF_USART0_UBRRL;
				UCSR0C = INF_USART0_UCSRC;
				UCSR0B = INF_USART0_UCSRB;
			#elif defined(__AVR_ATmega88V__)
				UCSR0A = INF_USART0_UCSRA;
				UBRR0H = INF_USART0_UBRRH;
				UBRR0L = INF_USART0_UBRRL;
				UCSR0C = INF_USART0_UCSRC;
				UCSR0B = INF_USART0_UCSRB;
			#elif defined(__AVR_ATmega128__)
				UCSR0A = INF_USART0_UCSRA;
				UBRR0H = INF_USART0_UBRRH;
				UBRR0L = INF_USART0_UBRRL;
				UCSR0C = INF_USART0_UCSRC;
				UCSR0B = INF_USART0_UCSRB;
			#elif defined(__AVR_ATmega168__)
				UCSR0A = INF_USART0_UCSRA;
				UBRR0H = INF_USART0_UBRRH;
				UBRR0L = INF_USART0_UBRRL;
				UCSR0C = INF_USART0_UCSRC;
				UCSR0B = INF_USART0_UCSRB;
			#elif defined(__AVR_ATmega168V__)
				UCSR0A = INF_USART0_UCSRA;
				UBRR0H = INF_USART0_UBRRH;
				UBRR0L = INF_USART0_UBRRL;
				UCSR0C = INF_USART0_UCSRC;
				UCSR0B = INF_USART0_UCSRB;
			#elif defined(__AVR_ATmega169P__)
				UCSR0A = INF_USART0_UCSRA;
				UBRR0H = INF_USART0_UBRRH;
				UBRR0L = INF_USART0_UBRRL;
				UCSR0C = INF_USART0_UCSRC;
				UCSR0B = INF_USART0_UCSRB;
			#elif defined(__AVR_ATmega169PV__)
				UCSR0A = INF_USART0_UCSRA;
				UBRR0H = INF_USART0_UBRRH;
				UBRR0L = INF_USART0_UBRRL;
				UCSR0C = INF_USART0_UCSRC;
				UCSR0B = INF_USART0_UCSRB;
			#elif defined(__AVR_ATmega644__)
				UCSR0A = INF_USART0_UCSRA;
				UBRR0H = INF_USART0_UBRRH;
				UBRR0L = INF_USART0_UBRRL;
				UCSR0C = INF_USART0_UCSRC;
				UCSR0B = INF_USART0_UCSRB;
			#elif defined(__AVR_AT90CAN32__)
				UCSR0A = INF_USART0_UCSRA;
				UBRR0H = INF_USART0_UBRRH;
				UBRR0L = INF_USART0_UBRRL;
				UCSR0C = INF_USART0_UCSRC;
				UCSR0B = INF_USART0_UCSRB;
			#elif defined(__AVR_AT90CAN64__)
				UCSR0A = INF_USART0_UCSRA;
				UBRR0H = INF_USART0_UBRRH;
				UBRR0L = INF_USART0_UBRRL;
				UCSR0C = INF_USART0_UCSRC;
				UCSR0B = INF_USART0_UCSRB;
			#elif defined(__AVR_AT90CAN128__)
				UCSR0A = INF_USART0_UCSRA;
				UBRR0H = INF_USART0_UBRRH;
				UBRR0L = INF_USART0_UBRRL;
				UCSR0C = INF_USART0_UCSRC;
				UCSR0B = INF_USART0_UCSRB;
			#else
				#error "No definition for this MCU available."
			#endif
		#endif /* ISB_INF == USART0 */

		#if ISB_INF == CAN0
			INF_CAN0_SS_INIT;
			INF_CAN0_SS_HIGH;
			Inf_Spi_Init();
			INF_CAN0_SS_LOW;
			Inf_Spi_WriteRead(LIB_MCP2515_RESET);
			INF_CAN0_SS_HIGH;
			_delay_ms(2);
			Lib_Mcp2515_Write(LIB_MCP2515_CNF1, INF_CAN0_CNF1);
			Lib_Mcp2515_Write(LIB_MCP2515_CNF2, INF_CAN0_CNF2);
			Lib_Mcp2515_Write(LIB_MCP2515_CNF3, INF_CAN0_CNF3);
			Lib_Mcp2515_Write(LIB_MCP2515_RXB0CTRL, 0x60);
			#if INF_CAN0_RS == NONE
			#elif INF_CAN0_RS == MCP2515_RX0BF
				Lib_Mcp2515_Write(LIB_MCP2515_BFPCTRL, 0x04);
			#elif INF_CAN0_RS == MCP2515_RX1BF
				Lib_Mcp2515_Write(LIB_MCP2515_BFPCTRL, 0x08);
			#else
				INF_CAN0_RS_INIT;
				INF_CAN0_RS_HIGH;
			#endif /* ISB_INF_CAN0_RS */
			Lib_Mcp2515_Write(LIB_MCP2515_CANCTRL, LIB_MCP2515_MODE_NORMAL);
		#endif /* ISB_INF == CAN0 */

		if (Isb_Node_Operating_Mode >= ISB_NODE_OPERATING_MODE__FW_NORM) {

			uint16_t Isb_Firmware_Crc = 0;
			Isb_Firmware_Crc = eeprom_read_byte((uint8_t *)EEP__ISB_FIRMWARE_CRC_0);
			Isb_Firmware_Crc |= (eeprom_read_byte((uint8_t *)EEP__ISB_FIRMWARE_CRC_1) << 8);

			uint16_t Isb_Firmware_Crc_Calc = 0;
			for (uint16_t flashAddr = 0; flashAddr < APP_END; flashAddr++) {
				Isb_Firmware_Crc_Calc += pgm_read_byte(flashAddr);
			}

			if (Isb_Firmware_Crc_Calc != Isb_Firmware_Crc) {
				Isb_Node_Operating_Mode = ISB_NODE_OPERATING_MODE__BL_NORM;
				Isb_Node_Operating_Error |= 0x04;
			}

		}

		Isb_Msg_t Isb_Msg;
		uint8_t Isb_Msg_Dlc = 0;
		Isb_Msg.Flags = ISB_MSG_FLAGS_TOF_MULTICAST | ISB_MSG_FLAGS_DLC_8;
		Isb_Msg.DestId = ISB_MSG_MULTICAST_GROUPID_BL_START;
		Isb_Msg.SourceId = Isb_Node_Id;
		Isb_Msg.Data[0] = ISB_MSG_TOP__SERIAL_NUMBER__MODE__RESETSOURCE_ERROR;
		memcpy(Isb_Msg.Data + 1, Isb_Node_Serial_Number, 4);
		Isb_Msg.Data[5] = Isb_Node_Operating_Mode;
		Isb_Msg.Data[6] = Isb_Node_Operating_ResetSource;
		Isb_Msg.Data[7] = Isb_Node_Operating_Error;
		Send_Message(&Isb_Msg);

		uint16_t flashAddr = 0;
		uint8_t flashWord = 0;
		uint16_t flashPage = 0xFFFF;

		#if defined(__AVR_ATmega8__)
			TCNT1 = 0;
			OCR1A = (F_CPU / 1024) / 1;
			TCCR1A = (1 << WGM12);
			TCCR1B = (1 << CS12) | (1 << CS10);
		#elif defined(__AVR_ATmega16__)
			TCNT1 = 0;
			OCR1A = (F_CPU / 1024) / 1;
			TCCR1A = (1 << WGM12);
			TCCR1B = (1 << CS12) | (1 << CS10);
		#elif defined(__AVR_ATmega32__)
			TCNT1 = 0;
			OCR1A = (F_CPU / 1024) / 1;
			TCCR1A = (1 << WGM12);
			TCCR1B = (1 << CS12) | (1 << CS10);
		#elif defined(__AVR_ATmega48__)
			TCNT1 = 0;
			OCR1A = (F_CPU / 1024) / 1;
			TCCR1B = (1 << WGM12) | (1 << CS12) | (1 << CS10);
		#elif defined(__AVR_ATmega48V__)
			TCNT1 = 0;
			OCR1A = (F_CPU / 1024) / 1;
			TCCR1B = (1 << WGM12) | (1 << CS12) | (1 << CS10);
		#elif defined(__AVR_ATmega64__)
			TCNT1 = 0;
			OCR1A = (F_CPU / 1024) / 1;
			TCCR1A = (1 << WGM12);
			TCCR1B = (1 << CS12) | (1 << CS10);
		#elif defined(__AVR_ATmega88__)
			TCNT1 = 0;
			OCR1A = (F_CPU / 1024) / 1;
			TCCR1B = (1 << WGM12) | (1 << CS12) | (1 << CS10);
		#elif defined(__AVR_ATmega88V__)
			TCNT1 = 0;
			OCR1A = (F_CPU / 1024) / 1;
			TCCR1B = (1 << WGM12) | (1 << CS12) | (1 << CS10);
		#elif defined(__AVR_ATmega128__)
			TCNT1 = 0;
			OCR1A = (F_CPU / 1024) / 1;
			TCCR1A = (1 << WGM12);
			TCCR1B = (1 << CS12) | (1 << CS10);
		#elif defined(__AVR_ATmega168__)
			TCNT1 = 0;
			OCR1A = (F_CPU / 1024) / 1;
			TCCR1B = (1 << WGM12) | (1 << CS12) | (1 << CS10);
		#elif defined(__AVR_ATmega168V__)
			TCNT1 = 0;
			OCR1A = (F_CPU / 1024) / 1;
			TCCR1B = (1 << WGM12) | (1 << CS12) | (1 << CS10);
		#elif defined(__AVR_ATmega169P__)
			TCCR0A = (1 << CS01) | (1 << CS00);
			TCNT0 = 0;
			OCR0A = (F_CPU / 1024) / 1;
		#elif defined(__AVR_ATmega169PV__)
			TCCR0A = (1 << CS01) | (1 << CS00);
			TCNT0 = 0;
			OCR0A = (F_CPU / 1024) / 1;
		#elif defined(__AVR_ATmega644__)
			TCNT1 = 0;
			OCR1A = (F_CPU / 1024) / 1;
			TCCR1B = (1 << WGM12) | (1 << CS12) | (1 << CS10);
		#elif defined(__AVR_AT90CAN32__)
			TCCR0A = (1 << CS01) | (1 << CS00);
			TCNT0 = 0;
			OCR0A = (F_CPU / 1024) / 1;
		#elif defined(__AVR_AT90CAN64__)
			TCCR0A = (1 << CS01) | (1 << CS00);
			TCNT0 = 0;
			OCR0A = (F_CPU / 1024) / 1;
		#elif defined(__AVR_AT90CAN128__)
			TCCR0A = (1 << CS01) | (1 << CS00);
			TCNT0 = 0;
			OCR0A = (F_CPU / 1024) / 1;
		#else
			#error "No definition for this MCU available."
		#endif

		for (;;) {

			wdt_reset();

			#if defined(__AVR_ATmega8__)
				if (bit_is_set(TIFR, OCF1A)) {
					TCCR1B = 0;
			#elif defined(__AVR_ATmega16__)
				if (bit_is_set(TIFR, OCF1A)) {
					TCCR1B = 0;
			#elif defined(__AVR_ATmega32__)
				if (bit_is_set(TIFR, OCF1A)) {
					TCCR1B = 0;
			#elif defined(__AVR_ATmega48__)
				if (bit_is_set(TIFR1, OCF1A)) {
					TCCR1B = 0;
			#elif defined(__AVR_ATmega48V__)
				if (bit_is_set(TIFR1, OCF1A)) {
					TCCR1B = 0;
			#elif defined(__AVR_ATmega64__)
				if (bit_is_set(TIFR, OCF1A)) {
					TCCR1B = 0;
			#elif defined(__AVR_ATmega88__)
				if (bit_is_set(TIFR1, OCF1A)) {
					TCCR1B = 0;
			#elif defined(__AVR_ATmega88V__)
				if (bit_is_set(TIFR1, OCF1A)) {
					TCCR1B = 0;
			#elif defined(__AVR_ATmega128__)
				if (bit_is_set(TIFR, OCF1A)) {
					TCCR1B = 0;
			#elif defined(__AVR_ATmega168__)
				if (bit_is_set(TIFR1, OCF1A)) {
					TCCR1B = 0;
			#elif defined(__AVR_ATmega168V__)
				if (bit_is_set(TIFR1, OCF1A)) {
					TCCR1B = 0;
			#elif defined(__AVR_ATmega169P__)
				if (bit_is_set(TIFR, OCF0)) {
					TCCR0 = 0;
			#elif defined(__AVR_ATmega169PV__)
				if (bit_is_set(TIFR, OCF0)) {
					TCCR0 = 0;
			#elif defined(__AVR_ATmega644__)
				if (bit_is_set(TIFR1, OCF1A)) {
					TCCR1B = 0;
			#elif defined(__AVR_AT90CAN32__)
				if (bit_is_set(TIFR, OCF0)) {
					TCCR0 = 0;
			#elif defined(__AVR_AT90CAN64__)
				if (bit_is_set(TIFR, OCF0)) {
					TCCR0 = 0;
			#elif defined(__AVR_AT90CAN128__)
				if (bit_is_set(TIFR, OCF0)) {
					TCCR0 = 0;
			#else
				#error "No definition for this MCU available."
			#endif
					if (Isb_Node_Operating_Mode >= ISB_NODE_OPERATING_MODE__FW_NORM) {
						JumpToFirmware();
					}
				}

			#if ISB_INF == USART0
				#if defined(__AVR_ATmega8__)
					if (UCSRA & (1 << RXC)) {
						tempByte = UDR;
					}
					else {
						continue;
					}
				#elif defined(__AVR_ATmega16__)
					if (UCSRA & (1 << RXC)) {
						tempByte = UDR;
					}
					else {
						continue;
					}
				#elif defined(__AVR_ATmega32__)
					if (UCSRA & (1 << RXC)) {
						tempByte = UDR;
					}
					else {
						continue;
					}
				#elif defined(__AVR_ATmega44__)
					if (UCSR0A & (1 << RXC0)) {
						tempByte = UDR0;
					}
					else {
						continue;
					}
				#elif defined(__AVR_ATmega44V__)
					if (UCSR0A & (1 << RXC0)) {
						tempByte = UDR0;
					}
					else {
						continue;
					}
				#elif defined(__AVR_ATmega64__)
					if (UCSR0A & (1 << RXC0)) {
						tempByte = UDR0;
					}
					else {
						continue;
					}
				#elif defined(__AVR_ATmega88__)
					if (UCSR0A & (1 << RXC0)) {
						tempByte = UDR0;
					}
					else {
						continue;
					}
				#elif defined(__AVR_ATmega88V__)
					if (UCSR0A & (1 << RXC0)) {
						tempByte = UDR0;
					}
					else {
						continue;
					}
				#elif defined(__AVR_ATmega128__)
					if (UCSR0A & (1 << RXC0)) {
						tempByte = UDR0;
					}
					else {
						continue;
					}
				#elif defined(__AVR_ATmega168__)
					if (UCSR0A & (1 << RXC0)) {
						tempByte = UDR0;
					}
					else {
						continue;
					}
				#elif defined(__AVR_ATmega168V__)
					if (UCSR0A & (1 << RXC0)) {
						tempByte = UDR0;
					}
					else {
						continue;
					}
				#elif defined(__AVR_ATmega169P__)
					if (UCSRA & (1 << RXC)) {
						tempByte = UDR;
					}
					else {
						continue;
					}
				#elif defined(__AVR_ATmega169PV__)
					if (UCSRA & (1 << RXC)) {
						tempByte = UDR;
					}
					else {
						continue;
					}
				#elif defined(__AVR_ATmega644__)
					if (UCSR0A & (1 << RXC0)) {
						tempByte = UDR0;
					}
					else {
						continue;
					}
				#elif defined(__AVR_AT90CAN32__)
					if (UCSR0A & (1 << RXC0)) {
						tempByte = UDR0;
					}
					else {
						continue;
					}
				#elif defined(__AVR_AT90CAN64__)
					if (UCSR0A & (1 << RXC0)) {
						tempByte = UDR0;
					}
					else {
						continue;
					}
				#elif defined(__AVR_AT90CAN128__)
					if (UCSR0A & (1 << RXC0)) {
						tempByte = UDR0;
					}
					else {
						continue;
					}
				#else
					#error "No definition for this MCU available."
				#endif
				if (relPos == 0 && tempByte == ISB_INF_USART0_STARTBYTE) {
					for(uint8_t i = 0; i < 8; i++) {
						Isb_Msg.Data[i] = 0x00;
					}
					relPos++;
					continue;
				}
				if (relPos == 1) {
					Isb_Msg.Flags = tempByte;
					Isb_Msg_Dlc = Isb_Msg.Flags & ISB_MSG_FLAGS_DLC_MASK;
					relPos++;
					continue;
				}
				if (relPos == 2) {
					Isb_Msg.DestId = tempByte;
					relPos++;
					continue;
				}
				if (relPos == 3) {
					Isb_Msg.DestId |= tempByte << 8;
					relPos++;
					continue;
				}
				if (relPos == 4) {
					Isb_Msg.SourceId = tempByte;
					relPos++;
					continue;
				}
				if (relPos == 5) {
					Isb_Msg.SourceId |= tempByte << 8;
					relPos++;
					continue;
				}
				if ((relPos > 5) && (relPos <= (Isb_Msg_Dlc + 5))) {
					Isb_Msg.Data[relPos - 6] = tempByte;
					relPos++;
					continue;
				}
				if (relPos == (Isb_Msg_Dlc + 6)) {
					relPos++;
					continue;
				}
				if (relPos == (Isb_Msg_Dlc + 7)) {
					if (tempByte == Lib_Crc_Calc8(&Isb_Msg, Isb_Msg_Dlc + 5)) {
						relPos++;
					}
					else {
						relPos = 0;
					}
					continue;
				}
				if (relPos == (Isb_Msg_Dlc + 8)) {
					relPos = 0;
					if (tempByte != ISB_INF_USART0_STOPBYTE) {
						continue;
					}
				}
			#endif /* ISB_INF == USART0 */

			#if ISB_INF == CAN0
				{
					uint8_t a,b,c;
					INF_CAN0_SS_LOW;
					Inf_Spi_WriteRead(LIB_MCP2515_RX_STATUS);
					uint8_t State = Inf_Spi_WriteRead(0xFF);
					INF_CAN0_SS_HIGH;
					if (bit_is_clear(State, LIB_MCP2515_RX_STATUS_INSTRUCTION_CANINTF_RX0IF)) {
						continue;
					}
					INF_CAN0_SS_LOW;
					Inf_Spi_WriteRead(LIB_MCP2515_READ_RX_BUFFER0);
					a = Inf_Spi_WriteRead(0x00);
					b = Inf_Spi_WriteRead(0x00) << 2;
					c = Inf_Spi_WriteRead(0x00);
					Isb_Msg.Flags = (a >> 2) & 0x30;
					Isb_Msg.DestId = a << 10 | (b & 0x0380) | ((b << 3) & 0x0060) | c >> 3;
					Isb_Msg.SourceId = ByteToShort(c & 0x07, Inf_Spi_WriteRead(0x00));
					Isb_Msg_Dlc = Inf_Spi_WriteRead(0x00) & 0x0F;
					Isb_Msg.Flags |= Isb_Msg_Dlc;
					for(uint8_t i = 0; i < Isb_Msg_Dlc; i++) {
						Isb_Msg.Data[i] = Inf_Spi_WriteRead(0x00);
					}
					INF_CAN0_SS_HIGH;
				}
			#endif /* ISB_INF == CAN0 */

			if ((Isb_Msg.Flags & ISB_MSG_FLAGS_TOF_MASK) != ISB_MSG_FLAGS_TOF_UNICAST) {
				continue;
			}

			if ((Isb_Msg.DestId & ISB_MSG_UNICAST_PORT_MASK) != ISB_MSG_UNICAST_PORT_CONFIG) {
				continue;
			}

			if ((Isb_Msg.DestId & ISB_MSG_UNICAST_NODEID_MASK) != Isb_Node_Id) {
				continue;
			}

			if (Isb_Msg.Data[0] == ISB_CONFIG_CMD_SETNODEID) {
				if (memcmp(Isb_Msg.Data + 1, Isb_Node_Serial_Number, 4)) {
					continue;
				}
				eep_write_byte((uint8_t *)EEP__ISB_NODE_ID_0, Isb_Msg.Data[5]);
				eep_write_byte((uint8_t *)EEP__ISB_NODE_ID_1, Isb_Msg.Data[6]);
				eep_write_byte((uint8_t *)EEP__ISB_NODE_OPERATING_RESETSOURCE, 0x80);
				while (1) ;
			}

			if (Isb_Node_Id == 0) {
				continue;
			}

			if (Isb_Msg.Data[0] == ISB_CONFIG_CMD_SETMODE) {
				eep_write_byte((uint8_t *)EEP__ISB_NODE_OPERATING_MODE, Isb_Msg.Data[1]);
				eep_write_byte((uint8_t *)EEP__ISB_NODE_OPERATING_RESETSOURCE, 0x80);
				while (1) ;
			}

			if (Isb_Node_Operating_Mode == ISB_NODE_OPERATING_MODE__BL_FLASH) {

				if (Isb_Msg.Data[0] == ISB_CONFIG_CMD_SETCRC) {
					eep_write_byte((uint8_t *)EEP__ISB_FIRMWARE_CRC_0, Isb_Msg.Data[1]);
					eep_write_byte((uint8_t *)EEP__ISB_FIRMWARE_CRC_1, Isb_Msg.Data[2]);
					goto ackit;
				}

				if (Isb_Msg.Data[0] == ISB_CONFIG_CMD_SETPAGE) {
					flashPage = ByteToShort(Isb_Msg.Data[2], Isb_Msg.Data[1]);
					if (flashPage > FLASHPAGES) {
						eep_write_byte((uint8_t *)EEP__ISB_NODE_OPERATING_RESETSOURCE, 0x80);
						while (1) ;
					}
					flashAddr = 0;
					goto ackit;
				}

				if (Isb_Msg.Data[0] == ISB_CONFIG_CMD_WRITEFLASH) {
					if (flashPage != 0xFFFF) {
						for (uint8_t i = 1; (i < Isb_Msg_Dlc) && (flashAddr < SPM_PAGESIZE); i++, flashAddr++) {
							if (flashAddr % 2) {
								boot_page_fill(flashPage * SPM_PAGESIZE + (flashAddr & ~1), ByteToShort(Isb_Msg.Data[i], flashWord));
							}
							else {
								flashWord = Isb_Msg.Data[i];
							}
						}
						if (flashAddr == SPM_PAGESIZE) {
							boot_page_write(flashPage * SPM_PAGESIZE);
							boot_spm_busy_wait();
							boot_rww_enable();
							flashPage = 0xFFFF;
						}
						goto ackit;
					}
				}

			}

			if (Isb_Msg.Data[0] == ISB_CONFIG_CMD_READEEPROMBLOCK) {
				uint8_t len = Isb_Msg.Flags & ISB_MSG_FLAGS_DLC_MASK;
				uint16_t addr = ByteToShort(Isb_Msg.Data[2], Isb_Msg.Data[1]);
				for (uint8_t i = 0; i < (len - 3); i++) {
					Isb_Msg.Data[3 + i] = eeprom_read_byte((uint8_t *)(addr + i));
				}
				goto ackit;
			}

			Isb_Msg.Data[0] |= ISB_CONFIG_ANSWER_NACK;

			if (0) ackit:Isb_Msg.Data[0] |= ISB_CONFIG_ANSWER_ACK;

			Isb_Msg.DestId = Isb_Msg.SourceId | ISB_MSG_UNICAST_PORT_CONFIG;
			Isb_Msg.SourceId = Isb_Node_Id;
			Send_Message(&Isb_Msg);

		}

	}



#endif /* ISB_BL_C_ */
