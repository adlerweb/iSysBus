/*! @file  mos_spi.c
 * @brief  
 * @author Cosinus
 * @date   21.08.2006  
*/
#include <mod/mod_spi.h>

void mod_spi_init(void)
{
  //Pin Configuration
  DDRB|= _BV(MOD_SPI_SCK) | _BV(MOD_SPI_MOSI) | _BV(MOD_SPI_SS);
  DDRB&= ~_BV(MOD_SPI_MISO);

  //SPI Configurieren
  SPCR= _BV(SPE) | _BV(MSTR);   
  /*!todo SPI Geschwindigeit. Was ist erlaubt? was wird genommen*/
}

uint8_t mod_spi_readwrite(uint8_t data)
{
  SPDR = data;  
  //Warten bis Byte übertragen wurde
  loop_until_bit_is_set(SPSR, SPIF);
  return SPDR;  
}

