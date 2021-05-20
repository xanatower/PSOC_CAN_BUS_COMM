/*******************************************************************************
* File Name: Sensor_Pin_28.h  
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

#if !defined(CY_PINS_Sensor_Pin_28_H) /* Pins Sensor_Pin_28_H */
#define CY_PINS_Sensor_Pin_28_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Sensor_Pin_28_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Sensor_Pin_28__PORT == 15 && ((Sensor_Pin_28__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Sensor_Pin_28_Write(uint8 value) ;
void    Sensor_Pin_28_SetDriveMode(uint8 mode) ;
uint8   Sensor_Pin_28_ReadDataReg(void) ;
uint8   Sensor_Pin_28_Read(void) ;
uint8   Sensor_Pin_28_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Sensor_Pin_28_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Sensor_Pin_28_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Sensor_Pin_28_DM_RES_UP          PIN_DM_RES_UP
#define Sensor_Pin_28_DM_RES_DWN         PIN_DM_RES_DWN
#define Sensor_Pin_28_DM_OD_LO           PIN_DM_OD_LO
#define Sensor_Pin_28_DM_OD_HI           PIN_DM_OD_HI
#define Sensor_Pin_28_DM_STRONG          PIN_DM_STRONG
#define Sensor_Pin_28_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Sensor_Pin_28_MASK               Sensor_Pin_28__MASK
#define Sensor_Pin_28_SHIFT              Sensor_Pin_28__SHIFT
#define Sensor_Pin_28_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Sensor_Pin_28_PS                     (* (reg8 *) Sensor_Pin_28__PS)
/* Data Register */
#define Sensor_Pin_28_DR                     (* (reg8 *) Sensor_Pin_28__DR)
/* Port Number */
#define Sensor_Pin_28_PRT_NUM                (* (reg8 *) Sensor_Pin_28__PRT) 
/* Connect to Analog Globals */                                                  
#define Sensor_Pin_28_AG                     (* (reg8 *) Sensor_Pin_28__AG)                       
/* Analog MUX bux enable */
#define Sensor_Pin_28_AMUX                   (* (reg8 *) Sensor_Pin_28__AMUX) 
/* Bidirectional Enable */                                                        
#define Sensor_Pin_28_BIE                    (* (reg8 *) Sensor_Pin_28__BIE)
/* Bit-mask for Aliased Register Access */
#define Sensor_Pin_28_BIT_MASK               (* (reg8 *) Sensor_Pin_28__BIT_MASK)
/* Bypass Enable */
#define Sensor_Pin_28_BYP                    (* (reg8 *) Sensor_Pin_28__BYP)
/* Port wide control signals */                                                   
#define Sensor_Pin_28_CTL                    (* (reg8 *) Sensor_Pin_28__CTL)
/* Drive Modes */
#define Sensor_Pin_28_DM0                    (* (reg8 *) Sensor_Pin_28__DM0) 
#define Sensor_Pin_28_DM1                    (* (reg8 *) Sensor_Pin_28__DM1)
#define Sensor_Pin_28_DM2                    (* (reg8 *) Sensor_Pin_28__DM2) 
/* Input Buffer Disable Override */
#define Sensor_Pin_28_INP_DIS                (* (reg8 *) Sensor_Pin_28__INP_DIS)
/* LCD Common or Segment Drive */
#define Sensor_Pin_28_LCD_COM_SEG            (* (reg8 *) Sensor_Pin_28__LCD_COM_SEG)
/* Enable Segment LCD */
#define Sensor_Pin_28_LCD_EN                 (* (reg8 *) Sensor_Pin_28__LCD_EN)
/* Slew Rate Control */
#define Sensor_Pin_28_SLW                    (* (reg8 *) Sensor_Pin_28__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Sensor_Pin_28_PRTDSI__CAPS_SEL       (* (reg8 *) Sensor_Pin_28__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Sensor_Pin_28_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Sensor_Pin_28__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Sensor_Pin_28_PRTDSI__OE_SEL0        (* (reg8 *) Sensor_Pin_28__PRTDSI__OE_SEL0) 
#define Sensor_Pin_28_PRTDSI__OE_SEL1        (* (reg8 *) Sensor_Pin_28__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Sensor_Pin_28_PRTDSI__OUT_SEL0       (* (reg8 *) Sensor_Pin_28__PRTDSI__OUT_SEL0) 
#define Sensor_Pin_28_PRTDSI__OUT_SEL1       (* (reg8 *) Sensor_Pin_28__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Sensor_Pin_28_PRTDSI__SYNC_OUT       (* (reg8 *) Sensor_Pin_28__PRTDSI__SYNC_OUT) 


#if defined(Sensor_Pin_28__INTSTAT)  /* Interrupt Registers */

    #define Sensor_Pin_28_INTSTAT                (* (reg8 *) Sensor_Pin_28__INTSTAT)
    #define Sensor_Pin_28_SNAP                   (* (reg8 *) Sensor_Pin_28__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Sensor_Pin_28_H */


/* [] END OF FILE */
