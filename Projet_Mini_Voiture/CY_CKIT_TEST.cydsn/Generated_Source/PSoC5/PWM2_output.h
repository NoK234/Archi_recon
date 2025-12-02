/*******************************************************************************
* File Name: PWM2_output.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_PWM2_output_H) /* Pins PWM2_output_H */
#define CY_PINS_PWM2_output_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "PWM2_output_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 PWM2_output__PORT == 15 && ((PWM2_output__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    PWM2_output_Write(uint8 value);
void    PWM2_output_SetDriveMode(uint8 mode);
uint8   PWM2_output_ReadDataReg(void);
uint8   PWM2_output_Read(void);
void    PWM2_output_SetInterruptMode(uint16 position, uint16 mode);
uint8   PWM2_output_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the PWM2_output_SetDriveMode() function.
     *  @{
     */
        #define PWM2_output_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define PWM2_output_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define PWM2_output_DM_RES_UP          PIN_DM_RES_UP
        #define PWM2_output_DM_RES_DWN         PIN_DM_RES_DWN
        #define PWM2_output_DM_OD_LO           PIN_DM_OD_LO
        #define PWM2_output_DM_OD_HI           PIN_DM_OD_HI
        #define PWM2_output_DM_STRONG          PIN_DM_STRONG
        #define PWM2_output_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define PWM2_output_MASK               PWM2_output__MASK
#define PWM2_output_SHIFT              PWM2_output__SHIFT
#define PWM2_output_WIDTH              1u

/* Interrupt constants */
#if defined(PWM2_output__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in PWM2_output_SetInterruptMode() function.
     *  @{
     */
        #define PWM2_output_INTR_NONE      (uint16)(0x0000u)
        #define PWM2_output_INTR_RISING    (uint16)(0x0001u)
        #define PWM2_output_INTR_FALLING   (uint16)(0x0002u)
        #define PWM2_output_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define PWM2_output_INTR_MASK      (0x01u) 
#endif /* (PWM2_output__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define PWM2_output_PS                     (* (reg8 *) PWM2_output__PS)
/* Data Register */
#define PWM2_output_DR                     (* (reg8 *) PWM2_output__DR)
/* Port Number */
#define PWM2_output_PRT_NUM                (* (reg8 *) PWM2_output__PRT) 
/* Connect to Analog Globals */                                                  
#define PWM2_output_AG                     (* (reg8 *) PWM2_output__AG)                       
/* Analog MUX bux enable */
#define PWM2_output_AMUX                   (* (reg8 *) PWM2_output__AMUX) 
/* Bidirectional Enable */                                                        
#define PWM2_output_BIE                    (* (reg8 *) PWM2_output__BIE)
/* Bit-mask for Aliased Register Access */
#define PWM2_output_BIT_MASK               (* (reg8 *) PWM2_output__BIT_MASK)
/* Bypass Enable */
#define PWM2_output_BYP                    (* (reg8 *) PWM2_output__BYP)
/* Port wide control signals */                                                   
#define PWM2_output_CTL                    (* (reg8 *) PWM2_output__CTL)
/* Drive Modes */
#define PWM2_output_DM0                    (* (reg8 *) PWM2_output__DM0) 
#define PWM2_output_DM1                    (* (reg8 *) PWM2_output__DM1)
#define PWM2_output_DM2                    (* (reg8 *) PWM2_output__DM2) 
/* Input Buffer Disable Override */
#define PWM2_output_INP_DIS                (* (reg8 *) PWM2_output__INP_DIS)
/* LCD Common or Segment Drive */
#define PWM2_output_LCD_COM_SEG            (* (reg8 *) PWM2_output__LCD_COM_SEG)
/* Enable Segment LCD */
#define PWM2_output_LCD_EN                 (* (reg8 *) PWM2_output__LCD_EN)
/* Slew Rate Control */
#define PWM2_output_SLW                    (* (reg8 *) PWM2_output__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define PWM2_output_PRTDSI__CAPS_SEL       (* (reg8 *) PWM2_output__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define PWM2_output_PRTDSI__DBL_SYNC_IN    (* (reg8 *) PWM2_output__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define PWM2_output_PRTDSI__OE_SEL0        (* (reg8 *) PWM2_output__PRTDSI__OE_SEL0) 
#define PWM2_output_PRTDSI__OE_SEL1        (* (reg8 *) PWM2_output__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define PWM2_output_PRTDSI__OUT_SEL0       (* (reg8 *) PWM2_output__PRTDSI__OUT_SEL0) 
#define PWM2_output_PRTDSI__OUT_SEL1       (* (reg8 *) PWM2_output__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define PWM2_output_PRTDSI__SYNC_OUT       (* (reg8 *) PWM2_output__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(PWM2_output__SIO_CFG)
    #define PWM2_output_SIO_HYST_EN        (* (reg8 *) PWM2_output__SIO_HYST_EN)
    #define PWM2_output_SIO_REG_HIFREQ     (* (reg8 *) PWM2_output__SIO_REG_HIFREQ)
    #define PWM2_output_SIO_CFG            (* (reg8 *) PWM2_output__SIO_CFG)
    #define PWM2_output_SIO_DIFF           (* (reg8 *) PWM2_output__SIO_DIFF)
#endif /* (PWM2_output__SIO_CFG) */

/* Interrupt Registers */
#if defined(PWM2_output__INTSTAT)
    #define PWM2_output_INTSTAT            (* (reg8 *) PWM2_output__INTSTAT)
    #define PWM2_output_SNAP               (* (reg8 *) PWM2_output__SNAP)
    
	#define PWM2_output_0_INTTYPE_REG 		(* (reg8 *) PWM2_output__0__INTTYPE)
#endif /* (PWM2_output__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_PWM2_output_H */


/* [] END OF FILE */
