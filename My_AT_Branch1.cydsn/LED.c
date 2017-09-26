#include "led.h"

void LED_ON(int16_t color)
{
   
    switch (color)
  {
    case(G):
      LED_1_Write(0);
      break;
    case(B):
      LED_2_Write(0);
      break;
    case(R):
      LED_3_Write(0);
      break;
    default:
      break;
  }
}
void LED_OFF(int16_t color)
{
    switch (color)
  {
    case(G):
      LED_1_Write(1);
      break;
    case(B):
      LED_2_Write(1);
      break;
    case(R):
      LED_3_Write(1);
      break;
    default:
      break;
  }
}
void LED(int16_t color,int8_t power)
{
    switch (color)
  {
    case(G):
     if(power==ON)
      LED_1_Write(0);
      else
      LED_1_Write(1);
      break;
    case(B):
    if(power==ON)
      LED_2_Write(0);
     else  
      LED_2_Write(1);
      break;
    case(R):
    if(power==ON)
      LED_3_Write(0);
    else
       LED_3_Write(1);
      break;
    
    default:
      break;
  }
}