/*******************************************************************************
* File Name: Sensor_Pin_18.h  
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

#if !defined(CY_PINS_Sensor_Pin_18_H) /* Pins Sensor_Pin_18_H */
#define CY_PINS_Sensor_Pin_18_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Sensor_Pin_18_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Sensor_Pin_18__PORT == 15 && ((Sensor_Pin_18__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Sensor_Pin_18_Write(uint8 value) ;
void    Sensor_Pin_18_SetDriveMode(uint8 mode) ;
uint8   Sensor_Pin_18_ReadDataReg(void) ;
uint8   Sensor_Pin_18_Read(void) ;
uint8   Sensor_Pin_18_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Sensor_Pin_18_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Sensor_Pin_18_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Sensor_Pin_18_DM_RES_UP          PIN_DM_RES_UP
#define Sensor_Pin_18_DM_RES_DWN         PIN_DM_RES_DWN
#define Sensor_Pin_18_DM_OD_LO           PIN_DM_OD_LO
#define Sensor_Pin_18_DM_OD_HI           PIN_DM_OD_HI
#define Sensor_Pin_18_DM_STRONG          PIN_DM_STRONG
#define Sensor_Pin_18_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Sensor_Pin_18_MASK               Sensor_Pin_18__MASK
#define Sensor_Pin_18_SHIFT              Sensor_Pin_18__SHIFT
#define Sensor_Pin_18_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Sensor_Pin_18_PS                     (* (reg8 *) Sensor_Pin_18__PS)
/* Data Register */
#define Sensor_Pin_18_DR                     (* (reg8 *) Sensor_Pin_18__DR)
/* Port Number */
#define Sensor_Pin_18_PRT_NUM                (* (reg8 *) Sensor_Pin_18__PRT) 
/* Connect to Analog Globals */                                                  
#define Sensor_Pin_18_AG                     (* (reg8 *) Sensor_Pin_18__AG)                       
/* Analog MUX bux enable */
#define Sensor_Pin_18_AMUX                   (* (reg8 *) Sensor_Pin_18__AMUX) 
/* Bidirectional Enable */                                                        
#define Sensor_Pin_18_BIE                    (* (reg8 *) Sensor_Pin_18__BIE)
/* Bit-mask for Aliased Register Access */
#define Sensor_Pin_18_BIT_MASK               (* (reg8 *) Sensor_Pin_18__BIT_MASK)
/* Bypass Enable */
#define Sensor_Pin_18_BYP                    (* (reg8 *) Sensor_Pin_18__BYP)
/* Port wide control signals */                                                   
#define Sensor_Pin_18_CTL                    (* (reg8 *) Sensor_Pin_18__CTL)
/* Drive Modes */
#define Sensor_Pin_18_DM0                    (* (reg8 *) Sensor_Pin_18__DM0) 
#define Sensor_Pin_18_DM1                    (* (reg8 *) Sensor_Pin_18__DM1)
#define Sensor_Pin_18_DM2                    (* (reg8 *) Sensor_Pin_18__DM2) 
/* Input Buffer Disable Override */
#define Sensor_Pin_18_INP_DIS                (* (reg8 *) Sensor_Pin_18__INP_DIS)
/* LCD Common or Segment Drive */
#define Sensor_Pin_18_LCD_COM_SEG            (* (reg8 *) Sensor_Pin_18__LCD_COM_SEG)
/* Enable Segment LCD */
#define Sensor_Pin_18_LCD_EN                 (* (reg8 *) Sensor_Pin_18__LCD_EN)
/* Slew Rate Control */
#define Sensor_Pin_18_SLW                    (* (reg8 *) Sensor_Pin_18__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Sensor_Pin_18_PRTDSI__CAPS_SEL       (* (reg8 *) Sensor_Pin_18__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Sensor_Pin_18_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Sensor_Pin_18__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Sensor_Pin_18_PRTDSI__OE_SEL0        (* (reg8 *) Sensor_Pin_18__PRTDSI__OE_SEL0) 
#define Sensor_Pin_18_PRTDSI__OE_SEL1        (* (reg8 *) Sensor_Pin_18__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Sensor_Pin_18_PRTDSI__OUT_SEL0       (* (reg8 *) Sensor_Pin_18__PRTDSI__OUT_SEL0) 
#define Sensor_Pin_18_PRTDSI__OUT_SEL1       (* (reg8 *) Sensor_Pin_18__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Sensor_Pin_18_PRTDSI__SYNC_OUT       (* (reg8 *) Sensor_Pin_18__PRTDSI__SYNC_OUT) 


#if defined(Sensor_Pin_18__INTSTAT)  /* Interrupt Registers */

    #define Sensor_Pin_18_INTSTAT                (* (reg8 *) Sensor_Pin_18__INTSTAT)
    #define Sensor_Pin_18_SNAP                   (* (reg8 *) Sensor_Pin_18__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Sensor_Pin_18_H */


/* [] END OF FILE */
