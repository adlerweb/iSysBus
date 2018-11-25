#ifndef SRV_AVRIO_H_
#define SRV_AVRIO_H_
/*! @file  srv_avr-io.h
 * @brief AVR-IO Modul 
 * @author Cosinus
 * @date   18.08.2006  
*/

#include <isysbus_typedef.h>
#include "serv_output_config.h"



/*! Initialisiert das IO Modul */
void avr_io_init(void);

/*! Ein Datenpaket für das Mudul wurde empfangen
 *   */
void serv_output_exec(uint8_t aktion, uint16_t index, uint8_t data ,data_t* response);

/*! Wird regelmäßig Aufgerufen. In der Regel beim Durchlaufen der Hauptschleife */
void serv_output_update(void);


#endif /*SRV_AVRIO_H_*/
