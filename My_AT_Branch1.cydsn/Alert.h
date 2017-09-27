#ifndef _ALERT_H_
#define _ALERT_H_

#include <project.h>
 
#define NO_ALERT           (0u)
#define MILD_ALERT         (1u)
#define HIGH_ALERT         (2u)

extern uint8 alertLevel;

/***************************************
*       Function Prototypes
***************************************/
void IasEventHandler(uint32 event, void* eventParam);

#endif
