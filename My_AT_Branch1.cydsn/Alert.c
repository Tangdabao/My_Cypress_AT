/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

#include <project.h>
#include "Alert.h"

/* IAS alert level value */
uint8 alertLevel = 0;

void IasEventHandler(uint32 event, void *eventParam)
{
  
    if(event == CYBLE_EVT_IASS_WRITE_CHAR_CMD)
    {
        CyBle_IassGetCharacteristicValue(CYBLE_IAS_ALERT_LEVEL, 
            sizeof(alertLevel), &alertLevel);
    }
}


/* [] END OF FILE */
