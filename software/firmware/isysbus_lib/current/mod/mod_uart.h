/**
 * @file 	uart.h
 *
 * @author 	Fabian Greif
 * @date	22.3.2005
 *
 * @brief	enth�t Funktionen zur Ansteuerung des UART
 *
 * 
 */

#ifndef _UART_H_
#define _UART_H_ 1

#include <avr/pgmspace.h>
#include "mod_uart_conf.h"
/**
 * @name	N�tzliche Makros
 */
 
/**
 * @brief	Erzeugt aus den Werten f�r die Taktfrequenz und Baudraten
 *			den entsprechnden Wert f�r das Register UBRR
 */
#if UART_BAUDRATE_DOUBLE_SPEED
#define UART_UBRR_BAUD (((float)(F_CPU))/(((float)(UART_BAUD))*8.0)-1.0+0.5)
#else
#define UART_UBRR_BAUD (((float)(F_CPU))/(((float)(UART_BAUD))*16.0)-1.0+0.5)
#endif
//#define UBRR_BAUD	((F_CPU/(16L*UART_BAUD))-1)


/**
 * @brief	Definiert die UART-Register des jeweiligen Controllers
 */
#if  defined(__AVR_ATmega8__)    || defined(__AVR_ATmega16__) || defined(__AVR_ATmega32__) \
  || defined(__AVR_ATmega8515__) || defined(__AVR_ATmega8535__) \
/* ATMega with one USART */
#define	UART_BAUD_RATE_LOW	     UBRRL
#define UART_BAUD_RATE_HIGH      UBRRH
#define	UART_CONTROL_REGA        UCSRA
#define	UART_CONTROL_REGB	     UCSRB
#define UART_CONTROL_REGC        UCSRC
#define	UART_ENABLE_TRANSMITTER	 TXEN
#define	UART_ENABLE_RECEIVER	 RXEN
#define	UART_TRANSMIT_COMPLETE	 TXC
#define	UART_RECEIVE_COMPLETE	 RXC
#define	UART_DATA_REG	         UDR
#define UART_TX_EMPTYINT         UDRIE
#define UART_DOUBLE_SPEED        U2X
#define UART_URSEL				 URSEL
#define UART_RX_INTERRUPT        RXCIE
#define UART_CHARSIZE_SELECT0    UCSZ0
#define UART_CHARSIZE_SELECT1    UCSZ1
#define UART_CHARSIZE_SELECT2    UCSZ2
#define UART_UDRE_INT            USART_UDRE_vect
#define UART_RXC_INT             USART_RXC_vect

#elif  defined(__AVR_ATmega64__) || defined(__AVR_ATmega128__) || defined(__AVR_ATmega162__)
/* ATMega with two USART */
#define	UART_BAUD_RATE_LOW	     UBRR0L
#define UART_BAUD_RATE_HIGH      UBRR0H
#define	UART_CONTROL_REGA        UCSR0A
#define	UART_CONTROL_REGB	     UCSR0B
#define UART_CONTROL_REGC        UCSR0C
#define	UART_ENABLE_TRANSMITTER	 TXEN0
#define	UART_ENABLE_RECEIVER	 RXEN0
#define	UART_TRANSMIT_COMPLETE	 TXC0
#define	UART_RECEIVE_COMPLETE	 RXC0
#define	UART_DATA_REG	         UDR0
#define UART_TX_EMPTYINT         UDRIE0
#define UART_DOUBLE_SPEED        U2X0
#define UART_RX_INTERRUPT        RXCIE0
#define UART_CHARSIZE_SELECT0    UCSZ00
#define UART_CHARSIZE_SELECT1    UCSZ01
#define UART_CHARSIZE_SELECT2    UCSZ02
#define UART_UDRE_INT            USART0_UDRE_vect
#define UART_RXC_INT             USART0_RXC_vect

#else
	#error "no UART definition for MCU available"
#endif


/*@}*/

/**
 * @brief	Macro um einen konstanten String automatisch im Programmspeicher abzulegen
 *
 * Beispiel:
 * \code
 * uart_puts_P( "Hallo Welt!");
 * \endcode
 *
 * @see		uart_puts_p
 */
#ifndef UART_NO_TX
#define uart_puts_P(__s)         uart_puts_p(PSTR(__s))
#endif

/**
 * @brief	Initialisiert den UART des AVRs
 *
 * Stellt die Baudrate ein, aktiviert den UART und initialisiert den Empfangspuffer
 */
extern void uart_init(void);

/**
 * @brief	Schiebt ein Zeichen in den Ringbuffer
 *
 * @param	data	Zeichen das gespeichert werden soll
 * @return	none
 *
 * Funktion stammt von Peter Fleury ( http://jump.to/fleury ) aus seiner UART Libary
 *
 * Die Zeichen im Ringbuffer werden per Interrupt automatisch ausgegeben.
 */
#ifndef UART_NO_TX
extern void uart_putc(uint8_t data);
#endif

/**
 * @brief	Sendet einen String aus dem Programmspeicher �ber die serielle Schnittstelle
 *
 * @param	progmem_s Pointer auf einen String im Flashspeicher
 * @return	none
 *
 * Funktion stammt von Peter Fleury ( http://jump.to/fleury ) aus seiner UART Libary
 *
 * @see		uart_puts_P
 */
#ifndef UART_NO_TX
extern void uart_puts_p(const char *progmem_s);
#endif

/**
 * @brief	Sendet einen String aus dem RAM �ber die serielle Schnittstelle
 *
 * @param	string Pointer auf einen String im RAM
 * @return	none
 */
#ifndef UART_NO_TX
extern void uart_puts(char *string);
#endif

/**
 * @brief 	Gibt einen Integer ( 0..65535 ) mit oder ohne f�hrende Nullen aus
 *
 * @param	wert	Zahl die ausgegeben werden soll
 * @param	anzahl	Anzahl der Zeichen die ausgegeben werden ( maximal 10 )
 * @param	fuell	F�llzeichen die am Anfang ausgegeben werden
 *
 * @return	none
 *
 * Beispiel :
 * \code
 * uart_put_dec(12345,6,'0')  ->  '012345'
 * uart_put_dec(12345,5,'')   ->  '12345'
 * uart_put_dec(12345,6,' ')  ->  ' 12345'
 * \endcode
 */
#ifndef UART_NO_TX
extern void uart_put_dec(uint16_t wert, uint8_t anzahl, uint8_t fuell);
#endif

/**
 * @brief	Gibt ein Byte Hexadezimal �ber den UART aus
 *
 * @param	wert	Zahl die ausgegeben werden soll
 * @return	none
 */
#ifndef UART_NO_TX
extern void uart_put_hex(uint8_t wert);
#endif

/**
 * @brief	Fragt ab, ob Daten im TX-Ringbuffer liegen
 *
 * @return	!=0 bei Daten, =0 bei keine Daten
 */
#ifndef UART_NO_TX
extern uint8_t uart_tx_pending(void);
#endif

/**
 * @brief	Fragt ab, ob Daten im RX-Ringbuffer liegen
 *
 * @return	!=0 bei Daten, =0 bei keine Daten
 */
#ifndef UART_NO_RX
extern uint8_t uart_rx_avail(void);
#endif

/**
 * @brief	Liest ein Zeichen aus dem RX-Ringbuffer
 *
 * @return	Zeichen, das gelesen wurde
 */
#ifndef UART_NO_RX
extern uint8_t uart_get_byte(void);
#endif


#endif 	// _UART_H
