
#include <mod/mod_uart.h>
//#include <avr/signal.h>
#include <avr/interrupt.h>


#define MESSAGE_BUF_MASK	(MESSAGE_BUF_SIZE - 1)
//#define RX_BUF_SIZE			(MESSAGE_BUF_SIZE * MAX_LAENGE)
#define RX_BUF_MASK			(RX_BUF_SIZE - 1)
#define TX_BUF_MASK			(TX_BUF_SIZE - 1)

/*
 * Variablen f�r den Senderingbuffer
 */
#ifndef UART_NO_TX
static volatile uint8_t tx_buf[TX_BUF_SIZE];
static volatile uint8_t tx_tail = 0;
static volatile uint8_t tx_head = 0;
#endif

/*
 * Variablen f�r den Empfangsringbuffer
 */
#ifndef UART_NO_RX
static volatile uint8_t rx_buf[RX_BUF_SIZE];
static volatile uint8_t rx_tail = 0;
static volatile uint8_t rx_head = 0;
#endif

// -------------------------------------------------------------------------
/*
 * Funktionsdefinitionen
 */
void uart_init(void);

#ifndef UART_NO_TX
uint8_t uart_tx_pending(void);
void uart_putc(uint8_t data);
void uart_puts_p(const char *progmem_s);
void uart_puts(char *string);
void uart_put_dec(uint16_t wert, uint8_t anzahl, uint8_t fuell);
void uart_put_hex(uint8_t wert);
#endif

#ifndef UART_NO_RX
uint8_t uart_rx_avail(void);
uint8_t uart_get_byte(void);
#endif



// -------------------------------------------------------------------------
/*
 * Initialisiert den UART des AVRs
 */
void uart_init(void)
{
#ifdef UART_BAUDRATE_DOUBLE_SPEED
	/* DoubleSpeed-Modus aktivieren */
	UART_CONTROL_REGA   |=  (1 <<UART_DOUBLE_SPEED);
#endif
	/* Baudrate einstellen */
	UART_BAUD_RATE_HIGH = (uint8_t)(UART_UBRR_BAUD) >> 8;
	UART_BAUD_RATE_LOW = (uint8_t)(UART_UBRR_BAUD) & 0x00FF;
	/* Receiver+Transmitter aktivieren */
	UART_CONTROL_REGB   = 0;
#ifndef UART_NO_RX
	UART_CONTROL_REGB  |= (1 << UART_ENABLE_RECEIVER) | (1 << UART_RX_INTERRUPT);
#endif
#ifndef UART_NO_TX
	UART_CONTROL_REGB  |= (1 << UART_ENABLE_TRANSMITTER);
    DDRD |= _BV(PD1);
#endif
#ifdef UART_URSEL
	UART_CONTROL_REGC   = (1 << UART_URSEL) | (1 << UART_CHARSIZE_SELECT1) | (1 << UART_CHARSIZE_SELECT0);
#else
	UART_CONTROL_REGC   = (1 << UART_CHARSIZE_SELECT1) | (1 << UART_CHARSIZE_SELECT0);
#endif  
//    DDRD = _BV(PD1);
}


// -------------------------------------------------------------------------
/*
 * Fragt ab, ob noch Bytes im Sendepuffer liegen.
 */
#ifndef UART_NO_TX
uint8_t uart_tx_pending(void)
{
	return !( (tx_head == tx_tail) && (UART_CONTROL_REGA & (1<<UART_TRANSMIT_COMPLETE) ) );
}
#endif

// -------------------------------------------------------------------------
/*
 * Schiebt ein Zeichen in den Ringbuffer
 */
#ifndef UART_NO_TX
void uart_putc(uint8_t data)
{        //sei();
	uint8_t tmphead;
	
	if (data == '\n')
		uart_putc('\r');

	tmphead  = (tx_head + 1) & TX_BUF_MASK;

	/* Warten bis Platz im Buffer ist */
	while ( tmphead == tx_tail ) {
		;
	}

	tx_buf[tmphead] = data;
	tx_head = tmphead;

	/* UDRE Interrupt aktivieren */
	UART_CONTROL_REGB |= (1<<UART_TX_EMPTYINT);
	//cli();
}
#endif

// -------------------------------------------------------------------------
/*
 * Sendet einen String aus dem Programmspeicher �ber die serielle Schnittstelle
 */
#ifndef UART_NO_TX
void uart_puts_p(const char *progmem_s)
{
	char c;

	while ( (c = pgm_read_byte(progmem_s++)) ) {
		uart_putc(c);
	}
}
#endif

// -------------------------------------------------------------------------
/*
 * Sendet einen String aus dem RAM �ber die serielle Schnittstelle
 */
#ifndef UART_NO_TX
void uart_puts(char *string)
{
	char c;
	
	while ( ( c = *string++ ) )
	{
		uart_putc(c);
	}
}
#endif

// -------------------------------------------------------------------------
/*
 * Gibt einen Integer ( 0..65535 ) mit oder ohne f�hrende Nullen aus
 */
#ifndef UART_NO_TX
void uart_put_dec(uint16_t wert, uint8_t anzahl, uint8_t fuell)
{
	uint8_t i, s[10];

	/* Zahl in String umwandeln */
	for (i = 0; i < anzahl; i++)
	{
		s[anzahl - i - 1] = '0' + (wert % 10);
		wert /= 10;
	}

	/* F�llbyte ersetzten */
	for (i=0; i<(anzahl - 1); i++)
	{
		if (s[i] == '0')
			s[i] = fuell;
		else
			break;
	}

	/* String ausgeben */
	for (i=0; i<anzahl; i++)
		uart_putc(s[i]);
}
#endif

// -------------------------------------------------------------------------
/*
 * Gibt einen Hex-Wert aus
 */
#ifndef UART_NO_TX
void uart_put_hex(uint8_t wert)
{
	uint8_t hi,low;

	/* Obere 4-bit */
	hi = wert & 0xf0;
	hi >>= 4;
	hi += '0';
	if ( hi > '9')
		hi += 7;				// A..F

	/* Untere 4-bit */
	low = ( wert & 0x0f ) + '0';
	if (low > '9')
		low += 7;				// A..F

	uart_putc(hi);
	uart_putc(low);
}
#endif



// -------------------------------------------------------------------------
/*
 * Fragt ab, ob Daten im RX-Ringbuffer liegen
 */
#ifndef UART_NO_RX
uint8_t uart_rx_avail(void)
{
	return !(rx_head == rx_tail);
}
#endif

// -------------------------------------------------------------------------
/*
 * Liest ein Zeichen aus dem RX-Ringbuffer
 */
#ifndef UART_NO_RX
uint8_t uart_get_byte(void)
{
	uint8_t tmptail;
	
	if ( rx_head != rx_tail )
	{
		tmptail = (rx_tail + 1) & RX_BUF_MASK;
		rx_tail = tmptail;
		return (rx_buf[tmptail]);
	}
	else // RX-Buffer leer
	{
		uart_puts_P("RX Buffer leer");
		return 0;
	}
}
#endif




// -------------------------------------------------------------------------
/*
 * Interrupt wird ausgel�st falls wieder ein Zeichen per UART verschickt
 * werden kann. Nächstes Zeichen wird aus dem Sendepuffer gelesen und verschickt.
 */
#ifndef UART_NO_TX
//SIGNAL(SIG_USART_DATA)
ISR(UART_UDRE_INT)
{
	uint8_t tmptail;

	if ( tx_head != tx_tail ) {
		/* neue Ringbufferposition berechnen */
		tmptail = (tx_tail + 1) & TX_BUF_MASK;
		tx_tail = tmptail;
		/* Byte aus dem Ringbuffer lesen und ausgeben */
		UART_DATA_REG = tx_buf[tmptail];  /* Starte �bertragung */
		UART_CONTROL_REGA |= (1<<UART_TRANSMIT_COMPLETE);
	}
	else {
		/* Sendebuffer ist leer, UDRE Interrupt deaktivieren */
		UART_CONTROL_REGB &= ~(1<<UART_TX_EMPTYINT);
	}
}
#endif

// -------------------------------------------------------------------------
/*
 * Interrupt wird ausgel�st wenn ein Zeichen per UART empfangen wurde.
 * Zeichen wird in den Empfangspuffer geschrieben.
 */
#ifndef UART_NO_RX
//SIGNAL(SIG_UART_RECV)
ISR(UART_RXC_INT)
{
	uint8_t tmphead;
	uint8_t data = UART_DATA_REG;
	tmphead = (rx_head + 1) & RX_BUF_MASK;
	if (tmphead != rx_tail)
	{
		rx_buf[tmphead] = data;
		rx_head = tmphead;
	}
	else //Ringbuffer ist voll
	{
		uart_puts_P("RX-Ringbuffer voll\n");
	}
}
#endif

