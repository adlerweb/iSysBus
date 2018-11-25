#ifndef SPI_H_
#define SPI_H_

void spiInit (void);
//uint8_t spiRead (void);
//void spiWrite (const uint8_t aData);
uint8_t spiReadWrite (const uint8_t aData);

#endif /*SPI_H_*/
