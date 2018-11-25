/*! @file  serv_output.c
 * @brief  
 * @author Cosinus
 * @date   11.11.2006  
*/

#include "serv_output.h"
#include <inttypes.h>
#include <isysbus_typedef.h>

#define toggelpin(port,pin) if(port & _BV(pin) ) {port &= ~_BV(pin);}  else {port |= _BV(pin);};

/*! Initialisiert das IO Modul */
void serv_output_init(void)
{
//Data Direction Register Setzen
#if SERV_OUTPUT_COUNT  >= 1
SERV_OUTPUT_OUT0_DDR |= _BV(SERV_OUTPUT_OUT0_PIN);
#endif

#if SERV_OUTPUT_COUNT  >= 2
SERV_OUTPUT_OUT1_DDR |= _BV(SERV_OUTPUT_OUT1_PIN);
#endif

    
}



/*! Ein Datenpaket f¸r das Mudul wurde empfangen
 *   */
void serv_output_exec(uint8_t aktion, uint16_t index, uint8_t data ,data_t* response)
{
#if SERV_OUTPUT_COUNT  >= 1
SERV_OUTPUT_OUT0_DDR |= _BV(SERV_OUTPUT_OUT0_PIN);
#endif 
    
if ( index >= SERV_OUTPUT_COUNT) { return;};

   
   
 if (aktion == 0x01)  //Pin Schreiben
  {
    if (index == 0)
    {
      if (data > 127) {
        aktion = 0x03; //Setzen
      } else {
        aktion = 0x04; //Lˆschen
      }
    }
  response->length=1;
  response->data[0] = 0x01; //OK zur¸cksenden
  }
  
  if (aktion == 0x03)   // Pin Setzen
  {
    if (index == 0)
    {
      SERV_OUTPUT_OUT0_PORT |= _BV(SERV_OUTPUT_OUT0_PIN);
    }
    if (index == 1)
    {
      SERV_OUTPUT_OUT1_PORT |= _BV(SERV_OUTPUT_OUT1_PIN);
    }
      
     // Best‰tigung senden
     response->length=1;
     response->data[0] = 0x01; //OK zur¸cksenden
  }

  if (aktion == 0x04)   // Pin Lˆschen
  {
    if (index == 0)
    {
      SERV_OUTPUT_OUT0_PORT &= ~_BV(SERV_OUTPUT_OUT0_PIN);
    }
    if (index == 1)
    {
      SERV_OUTPUT_OUT1_PORT &= ~_BV(SERV_OUTPUT_OUT1_PIN);
    }
     // Best‰tigung senden 
     response->length=1;
     response->data[0] = 0x01; //OK zur¸cksenden
  }
  
  if (aktion == 0x05)
  {
     if (index == 0)
    {
      toggelpin(SERV_OUTPUT_OUT0_PORT,SERV_OUTPUT_OUT0_PIN);
    }
    if (index == 1)
    {
      SERV_OUTPUT_OUT1_PORT &= ~_BV(SERV_OUTPUT_OUT1_PIN);
    }
     // Best‰tigung senden 
     response->length=1;
     response->data[0] = 0x01; //OK zur¸cksenden   
    
  }

  if (aktion == 0x02)   // Pin Lesen
  {
    response -> data[0] = 0x00;
    response -> length = 1;
    if (index  == 0)
    { 
      if (SERV_OUTPUT_OUT0_PORT & _BV(SERV_OUTPUT_OUT0_PIN)) { response -> data[0] = 0xFF;} 
    }
    if (index  == 1)
    { 
      if (SERV_OUTPUT_OUT0_PORT & _BV(SERV_OUTPUT_OUT0_PIN)) { response -> data[0] = 0xFF;} 
    }
  }
    


}


/*! Wird regelm‰ﬂig Aufgerufen. In der Regel beim Durchlaufen der Hauptschleife */
void serv_output_update(void);
