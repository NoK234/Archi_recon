/*******************************************************************************
* File Name: PWM_BACK_PM.c
* Version 3.30
*
* Description:
*  This file provides the power management source code to API for the
*  PWM.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "PWM_BACK.h"

static PWM_BACK_backupStruct PWM_BACK_backup;


/*******************************************************************************
* Function Name: PWM_BACK_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_BACK_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void PWM_BACK_SaveConfig(void) 
{

    #if(!PWM_BACK_UsingFixedFunction)
        #if(!PWM_BACK_PWMModeIsCenterAligned)
            PWM_BACK_backup.PWMPeriod = PWM_BACK_ReadPeriod();
        #endif /* (!PWM_BACK_PWMModeIsCenterAligned) */
        PWM_BACK_backup.PWMUdb = PWM_BACK_ReadCounter();
        #if (PWM_BACK_UseStatus)
            PWM_BACK_backup.InterruptMaskValue = PWM_BACK_STATUS_MASK;
        #endif /* (PWM_BACK_UseStatus) */

        #if(PWM_BACK_DeadBandMode == PWM_BACK__B_PWM__DBM_256_CLOCKS || \
            PWM_BACK_DeadBandMode == PWM_BACK__B_PWM__DBM_2_4_CLOCKS)
            PWM_BACK_backup.PWMdeadBandValue = PWM_BACK_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(PWM_BACK_KillModeMinTime)
             PWM_BACK_backup.PWMKillCounterPeriod = PWM_BACK_ReadKillTime();
        #endif /* (PWM_BACK_KillModeMinTime) */

        #if(PWM_BACK_UseControl)
            PWM_BACK_backup.PWMControlRegister = PWM_BACK_ReadControlRegister();
        #endif /* (PWM_BACK_UseControl) */
    #endif  /* (!PWM_BACK_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: PWM_BACK_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_BACK_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_BACK_RestoreConfig(void) 
{
        #if(!PWM_BACK_UsingFixedFunction)
            #if(!PWM_BACK_PWMModeIsCenterAligned)
                PWM_BACK_WritePeriod(PWM_BACK_backup.PWMPeriod);
            #endif /* (!PWM_BACK_PWMModeIsCenterAligned) */

            PWM_BACK_WriteCounter(PWM_BACK_backup.PWMUdb);

            #if (PWM_BACK_UseStatus)
                PWM_BACK_STATUS_MASK = PWM_BACK_backup.InterruptMaskValue;
            #endif /* (PWM_BACK_UseStatus) */

            #if(PWM_BACK_DeadBandMode == PWM_BACK__B_PWM__DBM_256_CLOCKS || \
                PWM_BACK_DeadBandMode == PWM_BACK__B_PWM__DBM_2_4_CLOCKS)
                PWM_BACK_WriteDeadTime(PWM_BACK_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(PWM_BACK_KillModeMinTime)
                PWM_BACK_WriteKillTime(PWM_BACK_backup.PWMKillCounterPeriod);
            #endif /* (PWM_BACK_KillModeMinTime) */

            #if(PWM_BACK_UseControl)
                PWM_BACK_WriteControlRegister(PWM_BACK_backup.PWMControlRegister);
            #endif /* (PWM_BACK_UseControl) */
        #endif  /* (!PWM_BACK_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: PWM_BACK_Sleep
********************************************************************************
*
* Summary:
*  Disables block's operation and saves the user configuration. Should be called
*  just prior to entering sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_BACK_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void PWM_BACK_Sleep(void) 
{
    #if(PWM_BACK_UseControl)
        if(PWM_BACK_CTRL_ENABLE == (PWM_BACK_CONTROL & PWM_BACK_CTRL_ENABLE))
        {
            /*Component is enabled */
            PWM_BACK_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            PWM_BACK_backup.PWMEnableState = 0u;
        }
    #endif /* (PWM_BACK_UseControl) */

    /* Stop component */
    PWM_BACK_Stop();

    /* Save registers configuration */
    PWM_BACK_SaveConfig();
}


/*******************************************************************************
* Function Name: PWM_BACK_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration. Should be called just after
*  awaking from sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_BACK_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_BACK_Wakeup(void) 
{
     /* Restore registers values */
    PWM_BACK_RestoreConfig();

    if(PWM_BACK_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        PWM_BACK_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
