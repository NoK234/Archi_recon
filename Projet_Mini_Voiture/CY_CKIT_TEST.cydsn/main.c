/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"

 uint8_t key_event ;
 uint8_t pressed_key;

CY_ISR(MyInter)
{   
    pressed_key = UART_XBEE_GetChar();
    key_event = 1;                    
        
}

int main(void)
{
    
    CyGlobalIntEnable; /* Enable global interrupts. */
    PWM_BACK_Start();
    PWM_FRONT_Start();
    
    
    UART_XBEE_Start();
    
 
    key_event = 0;
    pressed_key = 0;
    uint8 vit_max_PWM = 255;
    uint8 vit_moy_PWM = 125;
    uint8 vit_min_PWM = 25;
    
    inter_uart_StartEx(MyInter);
    
     
   
    
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        if(key_event)
        {
            key_event = 0;
            
            switch(pressed_key)
            {
            case 'z':
            IN_A2_AR_G_Write(1);
            IN_B2_AR_G_Write(0);
            IN_A1_AR_D_Write(1);
            IN_B1_AR_D_Write(0);
            
            IN_A1_AV_G_Write(1);
            IN_B1_AV_G_Write(0);
            IN_A2_AV_D_Write(1);
            IN_B2_AV_D_Write(0);
            
            PWM_BACK_WriteCompare1(vit_max_PWM);
            PWM_BACK_WriteCompare2(vit_max_PWM);
            PWM_FRONT_WriteCompare1(vit_max_PWM);
            PWM_FRONT_WriteCompare2(vit_max_PWM);
            
            break;
            
            case 's':
            IN_A2_AR_G_Write(0);
            IN_B2_AR_G_Write(1);
            IN_A1_AR_D_Write(0);
            IN_B1_AR_D_Write(1);
            
            IN_A1_AV_G_Write(0);
            IN_B1_AV_G_Write(1);
            IN_A2_AV_D_Write(0);
            IN_B2_AV_D_Write(1);
            
            PWM_BACK_WriteCompare1(vit_max_PWM);
            PWM_BACK_WriteCompare2(vit_max_PWM);
            PWM_FRONT_WriteCompare1(vit_max_PWM);
            PWM_FRONT_WriteCompare2(vit_max_PWM);
            break;
            
            case 'q':
            IN_A2_AR_G_Write(1);
            IN_B2_AR_G_Write(0);
            IN_A1_AR_D_Write(1);
            IN_B1_AR_D_Write(0);
            
            IN_A1_AV_G_Write(1);
            IN_B1_AV_G_Write(0);
            IN_A2_AV_D_Write(1);
            IN_B2_AV_D_Write(0);
                        
            PWM_BACK_WriteCompare1(vit_max_PWM);
            PWM_BACK_WriteCompare2(vit_max_PWM);
            
            PWM_FRONT_WriteCompare1(vit_min_PWM);
            PWM_FRONT_WriteCompare2(vit_max_PWM);
            break;
            
            case 'd':
            IN_A2_AR_G_Write(1);
            IN_B2_AR_G_Write(0);
            IN_A1_AR_D_Write(1);
            IN_B1_AR_D_Write(0);
            
            IN_A1_AV_G_Write(1);
            IN_B1_AV_G_Write(0);
            IN_A2_AV_D_Write(1);
            IN_B2_AV_D_Write(0);
                         
            PWM_BACK_WriteCompare1(vit_max_PWM);
            PWM_BACK_WriteCompare2(vit_max_PWM);
            
            PWM_FRONT_WriteCompare1(vit_max_PWM);
            PWM_FRONT_WriteCompare2(vit_moy_PWM);
            break;
            
            case ' ':
            IN_A2_AR_G_Write(0);
            IN_B2_AR_G_Write(0);
            IN_A1_AR_D_Write(0);
            IN_B1_AR_D_Write(0);
            
            IN_A1_AV_G_Write(0);
            IN_B1_AV_G_Write(0);
            IN_A2_AV_D_Write(0);
            IN_B2_AV_D_Write(0);
                         
            PWM_BACK_WriteCompare1(0);
            PWM_BACK_WriteCompare2(0);
            PWM_FRONT_WriteCompare1(0);
            PWM_FRONT_WriteCompare2(0);
            break;
            
            
            }
            
        }
                
    }
}

/* [] END OF FILE */
