#ifndef ISYSBUS_TYPEDEF_H_
#define ISYSBUS_TYPEDEF_H_

/*! @file  isysbus_typedef.h
 * @brief  Typendefinitionen speziell für das OSHB Projekt
 * @author Cosinus
 * @date   20.08.2006  
*/

#include <inttypes.h>
#include <avr/io.h>
#include <avr/eeprom.h>

#ifndef EEMEM
// alle Textstellen EEMEM im Quellcode durch __attribute__ ... ersetzen
#define EEMEM  __attribute__ ((section (".eeprom")))
#endif

/*!@name Message Flags 
 * @brief bitnummern, keine Maske!
 * */
#define MSG_RES         0

/*! Romete Transmit Requequest */
#define MSG_RTR         1  
  /*@}*/


/*!
 *iSysBus-Message Typ
 */ 
typedef struct  {
  uint16_t source, destination;  /*!< Zieladresse inklusive broadcastbit*/ 
  uint8_t port;/**< Port*/ 
  uint8_t length;
  uint8_t data[8];
  /*! @see Message Flags*/
  uint8_t flags;                          
} message_t;

typedef message_t* pmessage_t;

typedef struct  {
  uint8_t length;
  uint8_t data[8];                     
} data_t;

typedef data_t* pdata_t;

#endif /*ISYSBUS_TYPEDEF_H_*/
