/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  GPT.c
 *        \brief  General Perpose timer
 *
 *      \details  
 *              
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "GPT.h"
#include "MCU_HW.h"
#include "GPT_Types.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	
#define TIMER_A_ENABLE  0
/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
uint32 Set_Counter=0;
static GPT_REGS *GPT_Option_ARR[12] = {GPT00_REGS, GPT01_REGS, GPT02_REGS, GPT03_REGS, GPT04_REGS, GPT05_REGS,
                                GPT06_REGS, GPT07_REGS, GPT08_REGS, GPT09_REGS, GPT10_REGS, GPT11_REGS};
/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void Gpt_Init(const Gpt_ConfigType* ConfigPtr)                                      
* \Description     : 
*                                                       
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Gpt_Init(const Gpt_ConfigType* ConfigPtr)
{
	CLR_BIT(GPT_Option_ARR[ConfigPtr->GPT_ChannelID]->GPTMCTL ,TIMER_A_ENABLE);
	GPT_Option_ARR[ConfigPtr->GPT_ChannelID]->GPTMCFG = ConfigPtr->GPT_Predef_Timer;
  GPT_Option_ARR[ConfigPtr->GPT_ChannelID]->GPTMTAMR[0] |= ConfigPtr->GPT_Channel_Mode;
}

/******************************************************************************
* \Syntax          : void Gpt_DisableNotification(Gpt_ChannelType Channel)                                     
* \Description     :  
*                                                      
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Gpt_DisableNotification(Gpt_ChannelType Channel)
{
	  CLR_BIT(GPT_Option_ARR[Channel]->GPTMIMR , 0);
}
/******************************************************************************
* \Syntax          :  void Gpt_EnableNotification(Gpt_ChannelType Channel )                                      
* \Description     :  
*                                                      
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Gpt_EnableNotification(Gpt_ChannelType Channel )
{
    /*Enable Interrupt Mask Register*/
	SET_BIT(GPT_Option_ARR[Channel]->GPTMIMR,0);
}

/******************************************************************************
* \Syntax          : Gpt_startTimer( Gpt_ChannelType Channel,Gpt_ValueType Value)                                  
* \Description     :  
*                                                      
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Gpt_StartTimer( Gpt_ChannelType Channel,Gpt_ValueType Value)
{
	GPT_Option_ARR[Channel]->GPTMTAILR[0] = Value;
    Set_Counter = Value;
	SET_BIT(GPT_Option_ARR[Channel]->GPTMCTL,TIMER_A_ENABLE);
}
/******************************************************************************
* \Syntax          : Gpt_startTimer( Gpt_ChannelType Channel)                                  
* \Description     :  
*                                                      
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Gpt_StopTimer( Gpt_ChannelType Channel)
{
	CLR_BIT(GPT_Option_ARR[Channel]->GPTMCTL,TIMER_A_ENABLE);
  Set_Counter = 0;
}
/******************************************************************************
* \Syntax          : Gpt_startTimer( Gpt_ChannelType Channel)                                  
* \Description     :  
*                                                      
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
Gpt_ValueType Gpt_GetTimeEapsed(Gpt_ChannelType Channel)
{
	return (Set_Counter - GPT_Option_ARR[Channel]->GPTMTAV[0]);
}


/**********************************************************************************************************************
 *  END OF FILE: GPT.c
 *********************************************************************************************************************/

/******************************************************************************
* \Syntax          : Gpt_ValueType Gpt_GetTimeRemaining(Gpt_ChannelType Channel)                                 
* \Description     :  
*                                                      
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
Gpt_ValueType Gpt_GetTimeRemaining(Gpt_ChannelType Channel)
{
	return (Set_Counter - (Set_Counter - GPT_Option_ARR[Channel]->GPTMTAV[0]));
}
/******************************************************************************
* \Syntax          : GPT_ClearFlag(Gpt_ChannelType Channel)                                 
* \Description     :  
*                                                      
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void GPT_ClearFlag(Gpt_ChannelType Channel)
{
    
    SET_BIT( GPT_Option_ARR[Channel]->GPTMICR, 0);
}
/******************************************************************************
* \Syntax          : Gpt_ValueType GPT_FinishedInterrupt(Gpt_ChannelType Channel)                               
* \Description     :  
*                                                      
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/

Gpt_ValueType GPT_FinishedInterrupt(Gpt_ChannelType Channel)
{
    /*Return Raw Interrupt Status Value to Check if Interrupt has finished*/
    return (GET_BIT(GPT_Option_ARR[Channel]->GPTMRIS, 0));
}






  





