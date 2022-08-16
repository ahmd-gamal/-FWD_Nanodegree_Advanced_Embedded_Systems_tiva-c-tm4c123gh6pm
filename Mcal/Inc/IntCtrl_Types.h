/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl_Types.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef INTCTRL_TYPES_H
#define INTCTRL_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
 
 typedef enum{
    S_GROUPPRIORITY_8_SUBPRIORITY_1 = 0x0                     ,
    S_GROUPPRIORITY_4_SUBPRIORITY_2 = 0x5                     ,
    S_GROUPPRIORITY_2_SUBPRIORITY_4 = 0x6                     ,
    S_GROUPPRIORITY_1_SUBPRIORITY_8 = 0x7
}PRIORYTY_TYPE_t;
typedef enum
{
   /*GROUP PRIORITY 8 SUBPRIORITY 1*/
    GROUPPRIORITY_0_SUBPRIORITY_0_XXX = 0u                    ,
    GROUPPRIORITY_1_SUBPRIORITY_0_XXX                         ,
    GROUPPRIORITY_2_SUBPRIORITY_0_XXX                         ,
    GROUPPRIORITY_3_SUBPRIORITY_0_XXX                         ,
    GROUPPRIORITY_4_SUBPRIORITY_0_XXX                         ,
    GROUPPRIORITY_5_SUBPRIORITY_0_XXX                         ,
    GROUPPRIORITY_6_SUBPRIORITY_0_XXX                         ,
    GROUPPRIORITY_7_SUBPRIORITY_0_XXX                         ,

    /*GROUP PRIORITY 4 SUBPRIORITY 2*/
    GROUPPRIORITY_0_SUBPRIORITY_0_XXY=0b000                   ,	
    GROUPPRIORITY_1_SUBPRIORITY_0_XXY=0b010                   ,
    GROUPPRIORITY_2_SUBPRIORITY_0_XXY=0b100                   ,
    GROUPPRIORITY_3_SUBPRIORITY_0_XXY=0b110                   ,
	GROUPPRIORITY_0_SUBPRIORITY_1_XXY=0b001                   ,
    GROUPPRIORITY_1_SUBPRIORITY_1_XXY=0b011                   ,
    GROUPPRIORITY_2_SUBPRIORITY_1_XXY=0b101                   ,
    GROUPPRIORITY_3_SUBPRIORITY_1_XXY=0b111                   ,

    /*GROUP PRIORITY 2 SUBPRIORITY 4*/
    GROUPPRIORITY_0_SUBPRIORITY_0_XYY=0b000                   ,
    GROUPPRIORITY_0_SUBPRIORITY_1_XYY=0b001                   ,
    GROUPPRIORITY_0_SUBPRIORITY_2_XYY=0b010                   ,
    GROUPPRIORITY_0_SUBPRIORITY_3_XYY=0b011                   ,
    GROUPPRIORITY_1_SUBPRIORITY_0_XYY=0b100                   ,
    GROUPPRIORITY_1_SUBPRIORITY_1_XYY=0b101                   ,
    GROUPPRIORITY_1_SUBPRIORITY_2_XYY=0b110                   ,
    GROUPPRIORITY_1_SUBPRIORITY_3_XYY=0b111                   ,
    
    /*GROUP_PRIORITY_1_SUBPRIORITY_8*/
	GROUPPRIORITY_0_SUBPRIORITY_0_YYY=0                       ,
    GROUPPRIORITY_0_SUBPRIORITY_1_YYY                         ,
    GROUPPRIORITY_0_SUBPRIORITY_2_YYY                         ,
    GROUPPRIORITY_0_SUBPRIORITY_3_YYY                         ,
    GROUPPRIORITY_0_SUBPRIORITY_4_YYY                         ,
    GROUPPRIORITY_0_SUBPRIORITY_5_YYY                         ,
    GROUPPRIORITY_0_SUBPRIORITY_6_YYY                         ,
    GROUPPRIORITY_0_SUBPRIORITY_7_YYY

}PRIORITY_LEVEL_t;

typedef enum
{
    GPIO_PortA                                                ,
    GPIO_PortB                                                ,
    GPIO_PortC                                                ,
    GPIO_PortD                                                ,
    GPIO_PortE                                                ,
    UART0                                                     ,
    UART1                                                     ,
    SSI0                                                      ,
    I2C0                                                      ,
    PWM0_Fault                                                ,
    PWM0_Generator0                                           ,
    PWM0_Generator1                                           ,
    PWM0_Generator2                                           ,
    QEI0                                                      ,
    ADC0_Sequence0                                            ,
    ADC0_Sequence1                                            ,
    ADC0_Sequence2                                            ,
    ADC0_Sequence3                                            ,
    Watchdog_Timers0_and1                                     ,
    Timer_16_32Bit_0A                                         ,
    Timer_16_32Bit_0B                                         ,
    Timer_16_32Bit_1A                                         ,
    Timer_16_32Bit_1B                                         ,
    Timer_16_32Bit_2A                                         ,
    Timer_16_32Bit_2B                                         ,
    Analog_Comparator0                                        ,
    Analog_Comparator1                                        ,

    /* number 27 Reserved */

    System_Control = 28                                       ,
    Flash_Memory_Control_And_EEPROM_Control                   ,
    GPIO_PortF                                                ,

    /* number 31-32 Reserved */

    UART2 = 33                                                ,
    SSI1                                                      ,
    Bit_Timer_3A                                              ,
    Bit_Timer_3B                                              ,
    I2C1                                                      ,
    QEI1                                                      ,
    CAN0                                                      ,
    CAN1                                                      ,

    /* number 41-42 Reserved */

    Hibernation_Module = 43                                   ,
    USB                                                       ,
    PWM_Generator3                                            ,
    DMA_Software                                             ,
    DMA_Error                                                ,
    ADC1_Sequence0                                            ,
    ADC1_Sequence1                                            ,
    ADC1_Sequence2                                            ,
    ADC1_Sequence3                                            ,

    /*number  52-56 Reserved */

    SSI2 = 57                                                 ,
    SSI3                                                      ,
    UART3                                                     ,
    UART4                                                     ,
    UART5                                                     ,
    UART6                                                     ,
    UART7                                                     ,

    /*number 64-67 Reserved */

    I2C2 = 68                                                 ,
    I2C3                                                      ,
    Timer_16_32Bit_4A                                         ,
    Timer_16_32Bit_4B                                         ,

    /* number72-91 Reserved */

    Timer_16_32Bit_5A = 92                                    ,
    Timer_16_32Bit_5B                                         ,
    Timer_32_64Bit_0A                                         ,
    Timer_32_64Bit_0B                                         ,
    Timer_32_64Bit_1A                                         ,
    Timer_32_64Bit_1B                                         ,
    Timer_32_64Bit_2A                                         ,
    Timer_32_64Bit_2B                                         ,
    Timer_32_64Bit_3A                                         ,
    Timer_32_64Bit_3B                                         ,
    Timer_32_64Bit_4A                                         ,
    Timer_32_64Bit_4B                                         ,
    Timer_32_64Bit_5A                                         ,
    Timer_32_64Bit_5B                                         ,
    System_Exception                                          ,

    /* number107-133 Reserved */

    PWM1_Generator0 = 134                                     ,
    PWM1_Generator1                                           ,
    PWM1_Generator2                                           ,
    PWM1_Generator3                                           ,
    PWM1_Fault                                                


}IntCtrl_InterruptType_t;

typedef enum
{
	DISABLE_INTR=0,
	ENABLE_INTR,
	
}INTERRUPT_GROUPING_STATUS_t;


 
#endif  /* INTCTRL_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Types.h
 *********************************************************************************************************************/
