/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Port.c
 *        \brief  Digital Input Output Driver init
 *
 *      \details  The Driver Configure Pins 
 *                Enable CLock Gate for External Peripherals
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Mcu_Hw.h"
#include "Port_Types.h"
#include "Port.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
static GPIO_REGS_t *GPIO_PORT[6]={MGPIOA,MGPIOB,MGPIOC,MGPIOD,MGPIOE,MGPIOF};
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
* \Syntax          : void Port_Clk_Init(void)                                     
* \Description     : initialize peripheral clock
*                                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Port_Clk_Init(void)
{
	SYSCTRL_RCGCGPIO->B.GPIOA=Enable;
	SYSCTRL_RCGCGPIO->B.GPIOB=Enable;
	SYSCTRL_RCGCGPIO->B.GPIOC=Enable;
	SYSCTRL_RCGCGPIO->B.GPIOD=Enable;
	SYSCTRL_RCGCGPIO->B.GPIOE=Enable;
	SYSCTRL_RCGCGPIO->B.GPIOF=Enable;
}

/******************************************************************************
* \Syntax          : void Port_Init (const Port_ConfigType* ConfigPtr)                                     
* \Description     : configurtion of GPIO Ports
*                                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/

void Port_Init (const Port_ConfigType* ConfigPtr)
{
	/*set Pin Mode Dio - Alternat Fun */
	GPIO_PORT[ConfigPtr->PortNumber] -> GPIOAFSEL |= (uint32)(ConfigPtr->PortPinMode << (ConfigPtr->PinNumber)) ;
	/*set Pin direction Input - Output*/
	GPIO_PORT[ConfigPtr->PortNumber] -> GPIODIR |= (uint32)(ConfigPtr->PortPinDirection << (ConfigPtr->PinNumber)) ;
	/*set Pin level init value  */
	if((ConfigPtr->PortPinDirection ==OUTPUT))
	{
		GPIO_PORT[ConfigPtr->PortNumber]->GPIODATA[1<< (ConfigPtr->PinNumber)] = (uint32)(ConfigPtr->PortPinLevelValue << (ConfigPtr->PinNumber));
	}
	else{}
	/*set Pin opendrain - pullup - pulldown - slewrate internal type*/
	GPIO_PORT[ConfigPtr->PortNumber] -> GPIOODR[0]|= (uint32)(0 << (ConfigPtr->PinNumber)) ;
	GPIO_PORT[ConfigPtr->PortNumber] -> GPIOODR[1]|= (uint32)(0 << (ConfigPtr->PinNumber)) ;
	GPIO_PORT[ConfigPtr->PortNumber] -> GPIOODR[2]|= (uint32)(0 << (ConfigPtr->PinNumber)) ;
	GPIO_PORT[ConfigPtr->PortNumber] -> GPIOODR[3]|= (uint32)(0 << (ConfigPtr->PinNumber)) ;
	GPIO_PORT[ConfigPtr->PortNumber] -> GPIOODR[ConfigPtr->PortPinInternalAttach]|= (1 << (ConfigPtr->PinNumber)) ;
	/*set Pin output current ( 2mA - 4mA - 8 mA ) */
	GPIO_PORT[ConfigPtr->PortNumber] -> GPIODR2R[0]|= (0 << (ConfigPtr->PinNumber)) ;
	GPIO_PORT[ConfigPtr->PortNumber] -> GPIODR2R[2]|= (0 << (ConfigPtr->PinNumber)) ;
	GPIO_PORT[ConfigPtr->PortNumber] -> GPIODR2R[0]|= (0 << (ConfigPtr->PinNumber)) ;
	GPIO_PORT[ConfigPtr->PortNumber] -> GPIODR2R[(ConfigPtr->PortPinOutputCurrent)]|= (1 << (ConfigPtr->PinNumber)) ;
}
/**********************************************************************************************************************
 *  END OF FILE: Port.c
 *********************************************************************************************************************/







  





