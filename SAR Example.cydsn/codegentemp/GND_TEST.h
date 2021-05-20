/*******************************************************************************
* File Name: GND_TEST.h  
* Version 2.10
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_GND_TEST_H) /* Pins GND_TEST_H */
#define CY_PINS_GND_TEST_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "GND_TEST_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 GND_TEST__PORT == 15 && ((GND_TEST__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    GND_TEST_Write(uint8 value) ;
void    GND_TEST_SetDriveMode(uint8 mode) ;
uint8   GND_TEST_ReadDataReg(void) ;
uint8   GND_TEST_Read(void) ;
uint8   GND_TEST_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define GND_TEST_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define GND_TEST_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define GND_TEST_DM_RES_UP          PIN_DM_RES_UP
#define GND_TEST_DM_RES_DWN         PIN_DM_RES_DWN
#define GND_TEST_DM_OD_LO           PIN_DM_OD_LO
#define GND_TEST_DM_OD_HI           PIN_DM_OD_HI
#define GND_TEST_DM_STRONG          PIN_DM_STRONG
#define GND_TEST_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define GND_TEST_MASK               GND_TEST__MASK
#define GND_TEST_SHIFT              GND_TEST__SHIFT
#define GND_TEST_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define GND_TEST_PS                     (* (reg8 *) GND_TEST__PS)
/* Data Register */
#define GND_TEST_DR                     (* (reg8 *) GND_TEST__DR)
/* Port Number */
#define GND_TEST_PRT_NUM                (* (reg8 *) GND_TEST__PRT) 
/* Connect to Analog Globals */                                                  
#define GND_TEST_AG                     (* (reg8 *) GND_TEST__AG)                       
/* Analog MUX bux enable */
#define GND_TEST_AMUX                   (* (reg8 *) GND_TEST__AMUX) 
/* Bidirectional Enable */                                                        
#define GND_TEST_BIE                    (* (reg8 *) GND_TEST__BIE)
/* Bit-mask for Aliased Register Access */
#define GND_TEST_BIT_MASK               (* (reg8 *) GND_TEST__BIT_MASK)
/* Bypass Enable */
#define GND_TEST_BYP                    (* (reg8 *) GND_TEST__BYP)
/* Port wide control signals */                                                   
#define GND_TEST_CTL                    (* (reg8 *) GND_TEST__CTL)
/* Drive Modes */
#define GND_TEST_DM0                    (* (reg8 *) GND_TEST__DM0) 
#define GND_TEST_DM1                    (* (reg8 *) GND_TEST__DM1)
#define GND_TEST_DM2                    (* (reg8 *) GND_TEST__DM2) 
/* Input Buffer Disable Override */
#define GND_TEST_INP_DIS                (* (reg8 *) GND_TEST__INP_DIS)
/* LCD Common or Segment Drive */
#define GND_TEST_LCD_COM_SEG            (* (reg8 *) GND_TEST__LCD_COM_SEG)
/* Enable Segment LCD */
#define GND_TEST_LCD_EN                 (* (reg8 *) GND_TEST__LCD_EN)
/* Slew Rate Control */
#define GND_TEST_SLW                    (* (reg8 *) GND_TEST__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define GND_TEST_PRTDSI__CAPS_SEL       (* (reg8 *) GND_TEST__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define GND_TEST_PRTDSI__DBL_SYNC_IN    (* (reg8 *) GND_TEST__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define GND_TEST_PRTDSI__OE_SEL0        (* (reg8 *) GND_TEST__PRTDSI__OE_SEL0) 
#define GND_TEST_PRTDSI__OE_SEL1        (* (reg8 *) GND_TEST__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define GND_TEST_PRTDSI__OUT_SEL0       (* (reg8 *) GND_TEST__PRTDSI__OUT_SEL0) 
#define GND_TEST_PRTDSI__OUT_SEL1       (* (reg8 *) GND_TEST__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define GND_TEST_PRTDSI__SYNC_OUT       (* (reg8 *) GND_TEST__PRTDSI__SYNC_OUT) 


#if defined(GND_TEST__INTSTAT)  /* Interrupt Registers */

    #define GND_TEST_INTSTAT                (* (reg8 *) GND_TEST__INTSTAT)
    #define GND_TEST_SNAP                   (* (reg8 *) GND_TEST__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_GND_TEST_H */


/* [] END OF FILE */
