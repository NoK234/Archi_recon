/*******************************************************************************
* File Name: PWM_FRONT_PM.c
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

#include "PWM_FRONT.h"

static PWM_FRONT_backupStruct PWM_FRONT_backup;


/*******************************************************************************
* Function Name: PWM_FRONT_SaveConfig
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
*  PWM_FRONT_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void PWM_FRONT_SaveConfig(void) 
{

    #if(!PWM_FRONT_UsingFixedFunction)
        #if(!PWM_FRONT_PWMModeIsCenterAligned)
            PWM_FRONT_backup.PWMPeriod = PWM_FRONT_ReadPeriod();
        #endif /* (!PWM_FRONT_PWMModeIsCenterAligned) */
        PWM_FRONT_backup.PWMUdb = PWM_FRONT_ReadCounter();
        #if (PWM_FRONT_UseStatus)
            PWM_FRONT_backup.InterruptMaskValue = PWM_FRONT_STATUS_MASK;
        #endif /* (PWM_FRONT_UseStatus) */

        #if(PWM_FRONT_DeadBandMode == PWM_FRONT__B_PWM__DBM_256_CLOCKS || \
            PWM_FRONT_DeadBandMode == PWM_FRONT__B_PWM__DBM_2_4_CLOCKS)
            PWM_FRONT_backup.PWMdeadBandValue = PWM_FRONT_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(PWM_FRONT_KillModeMinTime)
             PWM_FRONT_backup.PWMKillCounterPeriod = PWM_FRONT_ReadKillTime();
        #endif /* (PWM_FRONT_KillModeMinTime) */

        #if(PWM_FRONT_UseControl)
            PWM_FRONT_backup.PWMControlRegister = PWM_FRONT_ReadControlRegister();
        #endif /* (PWM_FRONT_UseControl) */
    #endif  /* (!PWM_FRONT_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: PWM_FRONT_RestoreConfig
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
*  PWM_FRONT_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_FRONT_RestoreConfig(void) 
{
        #if(!PWM_FRONT_UsingFixedFunction)
            #if(!PWM_FRONT_PWMModeIsCenterAligned)
                PWM_FRONT_WritePeriod(PWM_FRONT_backup.PWMPeriod);
            #endif /* (!PWM_FRONT_PWMModeIsCenterAligned) */

            PWM_FRONT_WriteCounter(PWM_FRONT_backup.PWMUdb);

            #if (PWM_FRONT_UseStatus)
                PWM_FRONT_STATUS_MASK = PWM_FRONT_backup.InterruptMaskValue;
            #endif /* (PWM_FRONT_UseStatus) */

            #if(PWM_FRONT_DeadBandMode == PWM_FRONT__B_PWM__DBM_256_CLOCKS || \
                PWM_FRONT_DeadBandMode == PWM_FRONT__B_PWM__DBM_2_4_CLOCKS)
                PWM_FRONT_WriteDeadTime(PWM_FRONT_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(PWM_FRONT_KillModeMinTime)
                PWM_FRONT_WriteKillTime(PWM_FRONT_backup.PWMKillCounterPeriod);
            #endif /* (PWM_FRONT_KillModeMinTime) */

            #if(PWM_FRONT_UseControl)
                PWM_FRONT_WriteControlRegister(PWM_FRONT_backup.PWMControlRegister);
            #endif /* (PWM_FRONT_UseControl) */
        #endif  /* (!PWM_FRONT_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: PWM_FRONT_Sleep
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
*  PWM_FRONT_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void PWM_FRONT_Sleep(void) 
{
    #if(PWM_FRONT_UseControl)
        if(PWM_FRONT_CTRL_ENABLE == (PWM_FRONT_CONTROL & PWM_FRONT_CTRL_ENABLE))
        {
            /*Component is enabled */
            PWM_FRONT_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            PWM_FRONT_backup.PWMEnableState = 0u;
        }
    #endif /* (PWM_FRONT_UseControl) */

    /* Stop component */
    PWM_FRONT_Stop();

    /* Save registers configuration */
    PWM_FRONT_SaveConfig();
}


/*******************************************************************************
* Function Name: PWM_FRONT_Wakeup
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
*  PWM_FRONT_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_FRONT_Wakeup(void) 
{
     /* Restore registers values */
    PWM_FRONT_RestoreConfig();

    if(PWM_FRONT_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        PWM_FRONT_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
