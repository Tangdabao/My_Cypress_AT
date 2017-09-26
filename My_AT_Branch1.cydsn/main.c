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
#include "led.h"

void AT_init(void);

int main()
{
     AT_init();
     CyGlobalIntEnable; 
    for(;;)
    {

      
    }
}

void AT_init(void)
{
    UART_AT_Start();
    UART_AT_SCB_IRQ_Start();
    UART_AT_UartPutString("Test for AT");
  #if 0
    LED(R,OFF);
    LED(G,OFF);
    LED(B,OFF);
  #else 
    LED_OFF(R);
    LED_OFF(G);
    LED_OFF(B);
   #endif
    //CyDelay(1000u);
  }



////////////////Interrupt///////////////////////////
/*******************************************************************************
* Function Name: UART_AT_SCB_IRQ_Interrupt
********************************************************************************
*
* Summary:
*
* Parameters:  
*   None
*
* Return:
*   None
*
*******************************************************************************/
CY_ISR(UART_AT_SCB_IRQ_Interrupt)
{
    #ifdef UART_AT_SCB_IRQ_INTERRUPT_INTERRUPT_CALLBACK
        UART_AT_SCB_IRQ_Interrupt_InterruptCallback();
    #endif /* UART_AT_SCB_IRQ_INTERRUPT_INTERRUPT_CALLBACK */ 

    /*  Place your Interrupt code here. */
    /* `#START UART_AT_SCB_IRQ_Interrupt` */ 
    UART_AT_ClearRxInterruptSource(UART_AT_INTR_RX_NOT_EMPTY);
    if(UART_AT_GetRxInterruptSourceMasked()&UART_AT_INTR_RX_NOT_EMPTY)
    {
        uint32 ReceviceData=0;
        ReceviceData=UART_AT_SpiUartReadRxData();
        LED_ON(ReceviceData);
        UART_AT_UartPutChar((uint8_t)ReceviceData);
    }
    UART_AT_SpiUartClearRxBuffer();  
    /* `#END` */
}
  


