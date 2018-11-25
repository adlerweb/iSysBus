#ifndef MOD_SPI_H_
#define MOD_SPI_H_
/*! @file  mod_spi.h
 * @brief Hardware Spi Interface 
 * @author Cosinus
 * @date   21.08.2006  */
 
#define MOD_SPI
 
#include <isysbus_typedef.h>


#if defined(__AVR_AT90S4433__ ) || defined(__AVR_ATmega8__) 
//#define MOD_SPI_PORT PORTB
#define MOD_SPI_SCK  PB5
#define MOD_SPI_MISO PB4
#define MOD_SPI_MOSI PB3
#define MOD_SPI_SS   PB2
#endif

#if defined(__AVR_ATmega16__ ) || defined(__AVR_ATmega32__) 
//#define MOD_SPI_PORT PORTB
#define MOD_SPI_SCK  PB7
#define MOD_SPI_MISO PB6
#define MOD_SPI_MOSI PB5
#define MOD_SPI_SS   PB4
#endif

#if defined(__AVR_ATmega128__ )  
//#define MOD_SPI_PORT PORTB
#define MOD_SPI_SCK  PB1
#define MOD_SPI_MISO PB3
#define MOD_SPI_MOSI PB2
#define MOD_SPI_SS   PB0
#endif

#define MOD_SPI_READ 0x00

#define SS_LOW() PORTB&=~(_BV(MOD_SPI_SS))
#define SS_HIGH() PORTB|=_BV(MOD_SPI_SS)

/*! Initalisiert das Spi-Interface. */
void mod_spi_init(void);

uint8_t mod_spi_readwrite(uint8_t data);

//uint8_t mod_spi_read(uint8_t data);




#endif /*MOD_SPI_H_*/
