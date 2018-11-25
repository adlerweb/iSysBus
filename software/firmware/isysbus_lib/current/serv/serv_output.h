#ifndef SERV_OUTPUT_H_
#define SERV_OUTPUT_H_

#include <isysbus_typedef.h>
#include "serv_output_config.h"



/*! Initialisiert die Ausgänge */
void serv_output_init(void);

/*! Ein Datenpaket für das Mudul wurde empfangen
 *  @param msg Empfangenes Datenpaket */
void avr_io_do(pmessage_t message);

/*! Wird regelmäßig Aufgerufen. In der Regel beim Durchlaufen der Hauptschleife */
void avr_io_update(void);


#endif /*SERV_OUTPUT_H_*/
