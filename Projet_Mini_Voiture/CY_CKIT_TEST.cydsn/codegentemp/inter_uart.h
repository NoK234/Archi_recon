/*******************************************************************************
* File Name: inter_uart.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_inter_uart_H)
#define CY_ISR_inter_uart_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void inter_uart_Start(void);
void inter_uart_StartEx(cyisraddress address);
void inter_uart_Stop(void);

CY_ISR_PROTO(inter_uart_Interrupt);

void inter_uart_SetVector(cyisraddress address);
cyisraddress inter_uart_GetVector(void);

void inter_uart_SetPriority(uint8 priority);
uint8 inter_uart_GetPriority(void);

void inter_uart_Enable(void);
uint8 inter_uart_GetState(void);
void inter_uart_Disable(void);

void inter_uart_SetPending(void);
void inter_uart_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the inter_uart ISR. */
#define inter_uart_INTC_VECTOR            ((reg32 *) inter_uart__INTC_VECT)

/* Address of the inter_uart ISR priority. */
#define inter_uart_INTC_PRIOR             ((reg8 *) inter_uart__INTC_PRIOR_REG)

/* Priority of the inter_uart interrupt. */
#define inter_uart_INTC_PRIOR_NUMBER      inter_uart__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable inter_uart interrupt. */
#define inter_uart_INTC_SET_EN            ((reg32 *) inter_uart__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the inter_uart interrupt. */
#define inter_uart_INTC_CLR_EN            ((reg32 *) inter_uart__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the inter_uart interrupt state to pending. */
#define inter_uart_INTC_SET_PD            ((reg32 *) inter_uart__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the inter_uart interrupt. */
#define inter_uart_INTC_CLR_PD            ((reg32 *) inter_uart__INTC_CLR_PD_REG)


#endif /* CY_ISR_inter_uart_H */


/* [] END OF FILE */
