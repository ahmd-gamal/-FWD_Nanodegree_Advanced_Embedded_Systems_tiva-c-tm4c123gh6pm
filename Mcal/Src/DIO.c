/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Dio.c
 *        \brief  Digital Input Output Driver
 *
 *      \details  The Driver Configure Pins 
 *                Enable CLock Gate for External Peripherals
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "MCU_HW.h"
#include "Dio_Types .h"
#include "Dio.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

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
* \Syntax          : Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)                                     
* \Description     : Read register pin
*                                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/

Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
	boolean ReadPin;
 	if( GET_BIT(GPIO_PORT[ChannelId/8]->GPIODATA[1<<(ChannelId%8)],(ChannelId%8))==PinHIGH)
	{
		ReadPin=PinHIGH;
	}
	else
	{
		ReadPin=PinLOW;
	}
	return ReadPin;
}

/******************************************************************************
* \Syntax          : void Dio_WriteChannel(Dio_ChannelType ChannelId,Dio_LevelType Level)                                    
* \Description     : write register pin
*                                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/

void Dio_WriteChannel(Dio_ChannelType ChannelId,Dio_LevelType Level)
{
	GPIO_PORT[ChannelId/8]->GPIODATA[1<<(ChannelId%8)]=(Level<<(ChannelId%8));
}

/******************************************************************************
* \Syntax          : Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)                                    
* \Description     : read register port
*                                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)
{
	return (uint8)(GPIO_PORT[PortId]->GPIODATA[255]);
}

/******************************************************************************
* \Syntax          : void Dio_WritePort(Dio_PortType PortId,Dio_PortLevelType Level)                                   
* \Description     : write register port
*                                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Dio_WritePort(Dio_PortType PortId,Dio_PortLevelType Level)
{
	GPIO_PORT[PortId]->GPIODATA[255]=Level;
}

/******************************************************************************
* \Syntax          : Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId)                                  
* \Description     : toggle pin
*                                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId)
{
	GPIO_PORT[ChannelId/8]->GPIODATA[1<<(ChannelId%8)]^=1<<(ChannelId%8);
	boolean ReadPin;
 	if( GET_BIT(GPIO_PORT[ChannelId/8]->GPIODATA[1<<(ChannelId%8)],(ChannelId%8))==PinHIGH)
	{
		ReadPin=PinHIGH;
	}
	else
	{
		ReadPin=PinLOW;
	}
	return ReadPin;
}
/**********************************************************************************************************************
 *  END OF FILE: Dio.c
 *********************************************************************************************************************/







  





