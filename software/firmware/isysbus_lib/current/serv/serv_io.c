/*! @file  srv_avr-io.c
 * @brief  
 * @author Cosinus
 * @date   19.08.2006  
*/
#include <inttypes.h>
#include <isysbus_typedef.h>
#include <avr/io.h>

//defines Groß
#define SERV_IO_HWPORT  PORTD
#define SERV_IO_VALUE    0x00   //Initialisierungs-Zustand
#define SERV_IO_DDR     DDRD
#define SERV_IO_DD      0xFF  //Data-Direction

uint8_t serv_io_init( void )
{
  //hwport initialisieren
  SERV_IO_DDR = SERV_IO_DD;
  SERV_IO_HWPORT = SERV_IO_VALUE;

  return 1;  //Initialisierung erfolgreich
}

void serv_io_exec(uint8_t aktion, uint16_t index, uint8_t data ,data_t* response)
{
   
  if (aktion == 0x01)  //Pin Schreiben
  {
    if (index < 7)
    {
      if (data > 127) {
        SERV_IO_HWPORT |= _BV(index);
	} else {
	  SERV_IO_HWPORT &= ~(_BV(index));
	}
     // Bestätigung senden
     response->length=1;
     response->data[0] = 0x01; //OK zurücksenden
    }
  }
  if (aktion == 0x03)   // Pin Setzen
  {
    if (index < 7)
    {
      SERV_IO_HWPORT |= _BV(index);
     // Bestätigung senden
     response->length=1;
     response->data[0] = 0x01; //OK zurücksenden
    }
  }

  if (aktion == 0x04)   // Pin Löschen
  {
    if (index < 7)
    {
      SERV_IO_HWPORT &= ~(_BV(index));
     // Bestätigung senden 
     response->length=1;
     response->data[0] = 0x01; //OK zurücksenden
    }
  }

  if (aktion == 0x02)   // Pin Lesen
  {
    if (index < 7)
    {
      if (SERV_IO_HWPORT & _BV(index)) { response -> data[0] = 0xFF;} 
        else { response -> data[0] = 0x00;};
      response -> length = 1;
    }
  }

}

uint8_t serv_io_idle( void )
{
  // pinchange events
return 0;
}
	
