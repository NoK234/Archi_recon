/*******************************************************************************
* File Name: PWM1_AR_D.h  
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

#if !defined(CY_PINS_PWM1_AR_D_H) /* Pins PWM1_AR_D_H */
#define CY_PINS_PWM1_AR_D_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "PWM1_AR_D_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 PWM1_AR_D__PORT == 15 && ((PWM1_AR_D__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    PWM1_AR_D_Write(uint8 value);
void    PWM1_AR_D_SetDriveMode(uint8 mode);
uint8   PWM1_AR_D_ReadDataReg(void);
uint8   PWM1_AR_D_Read(void);
void    PWM1_AR_D_SetInterruptMode(uint16 position, uint16 mode);
uint8   PWM1_AR_D_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the PWM1_AR_D_SetDriveMode() function.
     *  @{
     */
        #define PWM1_AR_D_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define PWM1_AR_D_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define PWM1_AR_D_DM_RES_UP          PIN_DM_RES_UP
        #define PWM1_AR_D_DM_RES_DWN         PIN_DM_RES_DWN
        #define PWM1_AR_D_DM_OD_LO           PIN_DM_OD_LO
        #define PWM1_AR_D_DM_OD_HI           PIN_DM_OD_HI
        #define PWM1_AR_D_DM_STRONG          PIN_DM_STRONG
        #define PWM1_AR_D_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define PWM1_AR_D_MASK               PWM1_AR_D__MASK
#define PWM1_AR_D_SHIFT              PWM1_AR_D__SHIFT
#define PWM1_AR_D_WIDTH              1u

/* Interrupt constants */
#if defined(PWM1_AR_D__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in PWM1_AR_D_SetInterruptMode() function.
     *  @{
     */
        #define PWM1_AR_D_INTR_NONE      (uint16)(0x0000u)
        #define PWM1_AR_D_INTR_RISING    (uint16)(0x0001u)
        #define PWM1_AR_D_INTR_FALLING   (uint16)(0x0002u)
        #define PWM1_AR_D_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define PWM1_AR_D_INTR_MASK      (0x01u) 
#endif /* (PWM1_AR_D__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define PWM1_AR_D_PS                     (* (reg8 *) PWM1_AR_D__PS)
/* Data Register */
#define PWM1_AR_D_DR                     (* (reg8 *) PWM1_AR_D__DR)
/* Port Number */
#define PWM1_AR_D_PRT_NUM                (* (reg8 *) PWM1_AR_D__PRT) 
/* Connect to Analog Globals */                                                  
#define PWM1_AR_D_AG                     (* (reg8 *) PWM1_AR_D__AG)                       
/* Analog MUX bux enable */
#define PWM1_AR_D_AMUX                   (* (reg8 *) PWM1_AR_D__AMUX) 
/* Bidirectional Enable */                                                        
#define PWM1_AR_D_BIE                    (* (reg8 *) PWM1_AR_D__BIE)
/* Bit-mask for Aliased Register Access */
#define PWM1_AR_D_BIT_MASK               (* (reg8 *) PWM1_AR_D__BIT_MASK)
/* Bypass Enable */
#define PWM1_AR_D_BYP                    (* (reg8 *) PWM1_AR_D__BYP)
/* Port wide control signals */                                                   
#define PWM1_AR_D_CTL                    (* (reg8 *) PWM1_AR_D__CTL)
/* Drive Modes */
#define PWM1_AR_D_DM0                    (* (reg8 *) PWM1_AR_D__DM0) 
#define PWM1_AR_D_DM1                    (* (reg8 *) PWM1_AR_D__DM1)
#define PWM1_AR_D_DM2                    (* (reg8 *) PWM1_AR_D__DM2) 
/* Input Buffer Disable Override */
#define PWM1_AR_D_INP_DIS                (* (reg8 *) PWM1_AR_D__INP_DIS)
/* LCD Common or Segment Drive */
#define PWM1_AR_D_LCD_COM_SEG            (* (reg8 *) PWM1_AR_D__LCD_COM_SEG)
/* Enable Segment LCD */
#define PWM1_AR_D_LCD_EN                 (* (reg8 *) PWM1_AR_D__LCD_EN)
/* Slew Rate Control */
#define PWM1_AR_D_SLW                    (* (reg8 *) PWM1_AR_D__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define PWM1_AR_D_PRTDSI__CAPS_SEL       (* (reg8 *) PWM1_AR_D__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define PWM1_AR_D_PRTDSI__DBL_SYNC_IN    (* (reg8 *) PWM1_AR_D__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define PWM1_AR_D_PRTDSI__OE_SEL0        (* (reg8 *) PWM1_AR_D__PRTDSI__OE_SEL0) 
#define PWM1_AR_D_PRTDSI__OE_SEL1        (* (reg8 *) PWM1_AR_D__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define PWM1_AR_D_PRTDSI__OUT_SEL0       (* (reg8 *) PWM1_AR_D__PRTDSI__OUT_SEL0) 
#define PWM1_AR_D_PRTDSI__OUT_SEL1       (* (reg8 *) PWM1_AR_D__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define PWM1_AR_D_PRTDSI__SYNC_OUT       (* (reg8 *) PWM1_AR_D__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(PWM1_AR_D__SIO_CFG)
    #define PWM1_AR_D_SIO_HYST_EN        (* (reg8 *) PWM1_AR_D__SIO_HYST_EN)
    #define PWM1_AR_D_SIO_REG_HIFREQ     (* (reg8 *) PWM1_AR_D__SIO_REG_HIFREQ)
    #define PWM1_AR_D_SIO_CFG            (* (reg8 *) PWM1_AR_D__SIO_CFG)
    #define PWM1_AR_D_SIO_DIFF           (* (reg8 *) PWM1_AR_D__SIO_DIFF)
#endif /* (PWM1_AR_D__SIO_CFG) */

/* Interrupt Registers */
#if defined(PWM1_AR_D__INTSTAT)
    #define PWM1_AR_D_INTSTAT            (* (reg8 *) PWM1_AR_D__INTSTAT)
    #define PWM1_AR_D_SNAP               (* (reg8 *) PWM1_AR_D__SNAP)
    
	#define PWM1_AR_D_0_INTTYPE_REG 		(* (reg8 *) PWM1_AR_D__0__INTTYPE)
#endif /* (PWM1_AR_D__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_PWM1_AR_D_H */


/* [] END OF FILE */
