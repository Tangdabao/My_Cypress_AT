#ifndef _LED_H_
#define _LED_H_
#include <project.h>
   
#define R 0x52
#define G 0x47
#define B 0x42 
 
#define ON  0
#define OFF 1
    
void LED_ON(int16_t color);
void LED_OFF(int16_t color);
void LED(int16_t color,int8_t power);

#endif
