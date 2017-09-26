/***************************************************************************//**
* \file .h
* \version 3.20
*
* \brief
*  This private file provides constants and parameter values for the
*  SCB Component.
*  Please do not use this file or its content in your project.
*
* Note:
*
********************************************************************************
* \copyright
* Copyright 2013-2016, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SCB_PVT_UART_AT_H)
#define CY_SCB_PVT_UART_AT_H

#include "UART_AT.h"


/***************************************
*     Private Function Prototypes
***************************************/

/* APIs to service INTR_I2C_EC register */
#define UART_AT_SetI2CExtClkInterruptMode(interruptMask) UART_AT_WRITE_INTR_I2C_EC_MASK(interruptMask)
#define UART_AT_ClearI2CExtClkInterruptSource(interruptMask) UART_AT_CLEAR_INTR_I2C_EC(interruptMask)
#define UART_AT_GetI2CExtClkInterruptSource()                (UART_AT_INTR_I2C_EC_REG)
#define UART_AT_GetI2CExtClkInterruptMode()                  (UART_AT_INTR_I2C_EC_MASK_REG)
#define UART_AT_GetI2CExtClkInterruptSourceMasked()          (UART_AT_INTR_I2C_EC_MASKED_REG)

#if (!UART_AT_CY_SCBIP_V1)
    /* APIs to service INTR_SPI_EC register */
    #define UART_AT_SetSpiExtClkInterruptMode(interruptMask) \
                                                                UART_AT_WRITE_INTR_SPI_EC_MASK(interruptMask)
    #define UART_AT_ClearSpiExtClkInterruptSource(interruptMask) \
                                                                UART_AT_CLEAR_INTR_SPI_EC(interruptMask)
    #define UART_AT_GetExtSpiClkInterruptSource()                 (UART_AT_INTR_SPI_EC_REG)
    #define UART_AT_GetExtSpiClkInterruptMode()                   (UART_AT_INTR_SPI_EC_MASK_REG)
    #define UART_AT_GetExtSpiClkInterruptSourceMasked()           (UART_AT_INTR_SPI_EC_MASKED_REG)
#endif /* (!UART_AT_CY_SCBIP_V1) */

#if(UART_AT_SCB_MODE_UNCONFIG_CONST_CFG)
    extern void UART_AT_SetPins(uint32 mode, uint32 subMode, uint32 uartEnableMask);
#endif /* (UART_AT_SCB_MODE_UNCONFIG_CONST_CFG) */


/***************************************
*     Vars with External Linkage
***************************************/

#if (UART_AT_SCB_IRQ_INTERNAL)
#if !defined (CY_REMOVE_UART_AT_CUSTOM_INTR_HANDLER)
    extern cyisraddress UART_AT_customIntrHandler;
#endif /* !defined (CY_REMOVE_UART_AT_CUSTOM_INTR_HANDLER) */
#endif /* (UART_AT_SCB_IRQ_INTERNAL) */

extern UART_AT_BACKUP_STRUCT UART_AT_backup;

#if(UART_AT_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Common configuration variables */
    extern uint8 UART_AT_scbMode;
    extern uint8 UART_AT_scbEnableWake;
    extern uint8 UART_AT_scbEnableIntr;

    /* I2C configuration variables */
    extern uint8 UART_AT_mode;
    extern uint8 UART_AT_acceptAddr;

    /* SPI/UART configuration variables */
    extern volatile uint8 * UART_AT_rxBuffer;
    extern uint8   UART_AT_rxDataBits;
    extern uint32  UART_AT_rxBufferSize;

    extern volatile uint8 * UART_AT_txBuffer;
    extern uint8   UART_AT_txDataBits;
    extern uint32  UART_AT_txBufferSize;

    /* EZI2C configuration variables */
    extern uint8 UART_AT_numberOfAddr;
    extern uint8 UART_AT_subAddrSize;
#endif /* (UART_AT_SCB_MODE_UNCONFIG_CONST_CFG) */

#if (! (UART_AT_SCB_MODE_I2C_CONST_CFG || \
        UART_AT_SCB_MODE_EZI2C_CONST_CFG))
    extern uint16 UART_AT_IntrTxMask;
#endif /* (! (UART_AT_SCB_MODE_I2C_CONST_CFG || \
              UART_AT_SCB_MODE_EZI2C_CONST_CFG)) */


/***************************************
*        Conditional Macro
****************************************/

#if(UART_AT_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Defines run time operation mode */
    #define UART_AT_SCB_MODE_I2C_RUNTM_CFG     (UART_AT_SCB_MODE_I2C      == UART_AT_scbMode)
    #define UART_AT_SCB_MODE_SPI_RUNTM_CFG     (UART_AT_SCB_MODE_SPI      == UART_AT_scbMode)
    #define UART_AT_SCB_MODE_UART_RUNTM_CFG    (UART_AT_SCB_MODE_UART     == UART_AT_scbMode)
    #define UART_AT_SCB_MODE_EZI2C_RUNTM_CFG   (UART_AT_SCB_MODE_EZI2C    == UART_AT_scbMode)
    #define UART_AT_SCB_MODE_UNCONFIG_RUNTM_CFG \
                                                        (UART_AT_SCB_MODE_UNCONFIG == UART_AT_scbMode)

    /* Defines wakeup enable */
    #define UART_AT_SCB_WAKE_ENABLE_CHECK       (0u != UART_AT_scbEnableWake)
#endif /* (UART_AT_SCB_MODE_UNCONFIG_CONST_CFG) */

/* Defines maximum number of SCB pins */
#if (!UART_AT_CY_SCBIP_V1)
    #define UART_AT_SCB_PINS_NUMBER    (7u)
#else
    #define UART_AT_SCB_PINS_NUMBER    (2u)
#endif /* (!UART_AT_CY_SCBIP_V1) */

#endif /* (CY_SCB_PVT_UART_AT_H) */


/* [] END OF FILE */
