/*******************************************************************************
* File Name: Sensor_Pin_23.c  
* Version 2.10
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "Sensor_Pin_23.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 Sensor_Pin_23__PORT == 15 && ((Sensor_Pin_23__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: Sensor_Pin_23_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None
*  
*******************************************************************************/
void Sensor_Pin_23_Write(uint8 value) 
{
    uint8 staticBits = (Sensor_Pin_23_DR & (uint8)(~Sensor_Pin_23_MASK));
    Sensor_Pin_23_DR = staticBits | ((uint8)(value << Sensor_Pin_23_SHIFT) & Sensor_Pin_23_MASK);
}


/*******************************************************************************
* Function Name: Sensor_Pin_23_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  Sensor_Pin_23_DM_STRONG     Strong Drive 
*  Sensor_Pin_23_DM_OD_HI      Open Drain, Drives High 
*  Sensor_Pin_23_DM_OD_LO      Open Drain, Drives Low 
*  Sensor_Pin_23_DM_RES_UP     Resistive Pull Up 
*  Sensor_Pin_23_DM_RES_DWN    Resistive Pull Down 
*  Sensor_Pin_23_DM_RES_UPDWN  Resistive Pull Up/Down 
*  Sensor_Pin_23_DM_DIG_HIZ    High Impedance Digital 
*  Sensor_Pin_23_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void Sensor_Pin_23_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(Sensor_Pin_23_0, mode);
}


/*******************************************************************************
* Function Name: Sensor_Pin_23_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro Sensor_Pin_23_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Sensor_Pin_23_Read(void) 
{
    return (Sensor_Pin_23_PS & Sensor_Pin_23_MASK) >> Sensor_Pin_23_SHIFT;
}


/*******************************************************************************
* Function Name: Sensor_Pin_23_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 Sensor_Pin_23_ReadDataReg(void) 
{
    return (Sensor_Pin_23_DR & Sensor_Pin_23_MASK) >> Sensor_Pin_23_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Sensor_Pin_23_INTSTAT) 

    /*******************************************************************************
    * Function Name: Sensor_Pin_23_ClearInterrupt
    ********************************************************************************
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 Sensor_Pin_23_ClearInterrupt(void) 
    {
        return (Sensor_Pin_23_INTSTAT & Sensor_Pin_23_MASK) >> Sensor_Pin_23_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
