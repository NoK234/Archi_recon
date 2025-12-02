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

volatile uint8_t key_event = 0;
volatile uint8_t pressed_key = 0;

CY_ISR(MyInter)
{   
    pressed_key = button_read();
    key_event = 1;                    
        
}

int main(void)
{
    
    CyGlobalIntEnable; /* Enable global interrupts. */
    PWM_BACK_Start();
    PWM_FRONT_Start();
    ADC_SAR_1_Start();
    ADC_SAR_1_StartConvert();
    uint8 adc_val;
    key_event = 0;
    pressed_key = 0;
    
    inter_uart_StartEx(MyInter);
    
     
   
    
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        if(key_event)
        {
            key_event = 0;
            adc_val = ADC_SAR_1_GetResult8();
            
            switch(in_uart)
            {
            case 'z':
            IN_A1_Write(0);
            IN_A2_Write(1);
            IN_B1_Write(1);
            IN_B2_Write(0);
            
            IN_A1_1_Write(1);
            IN_A2_1_Write(1);
            IN_B1_1_Write(0);
            IN_B2_1_Write(0);
            break;
            
            case 's':
            IN_A1_Write(1);
            IN_A2_Write(0);
            IN_B1_Write(0);
            IN_B2_Write(1);
            
            IN_A1_1_Write(0);
            IN_A2_1_Write(0);
            IN_B1_1_Write(1);
            IN_B2_1_Write(1);
            break;
            
            case 'q':
            IN_A1_Write(0);
            IN_A2_Write(1);
            IN_B1_Write(1);
            IN_B2_Write(0);
            
            IN_A1_1_Write(1);
            IN_A2_1_Write(1);
            IN_B1_1_Write(0);
            IN_B2_1_Write(0);
            break;
            
            case 'd':
            IN_A1_Write(1);
            IN_A2_Write(0);
            IN_B1_Write(0);
            IN_B2_Write(1);
            
            IN_A1_1_Write(0);
            IN_A2_1_Write(0);
            IN_B1_1_Write(1);
            IN_B2_1_Write(1);
            break;
            }
        }
                PWM_BACK_WriteCompare1(adc_val);
                PWM_BACK_WriteCompare2(adc_val);
                PWM_FRONT_WriteCompare1(adc_val);
                PWM_FRONT_WriteCompare2(adc_val);
           // }

        //}

        
        
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
