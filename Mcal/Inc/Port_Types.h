/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Port_Types.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef PORT_TYPES_H
#define PORT_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define EN_MAIN_OSCILLATOR      0u
#define DIS_MAIN_OSCILLATOR     1u 

#define MAIN_OSCILLATOR                      0u
#define PRECISION_INTERNAL_OSCILLATOR        1u
#define PRECISION_INTERNAL_OSCILLATOR_4      2u
#define LOW_FREQUANCY_INTERNAL_OSCILLATOR    3u

#define CLOCK_VALIDATION_DIS    0u
#define CLOCK_VALIDATION_EN     1u

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum 
{
	GPIO=0U,
	ALTFUN
}Port_PinModeType;

typedef enum 
{
	LOW = 0u ,
	HIGH
}Port_PinLevelType;

typedef enum
{
	INPUT = 0u ,
	OUTPUT
}Port_PinDirection_Type;

typedef enum 
{
	OPEN_DRAIN =0u,
	PULL_UP ,
	PULL_DOWN ,
	SLEW_Rate,
}Port_PinInternalAttachType;

typedef enum
{
	Current_2mA= 0u  ,
	Current_4mA= 4u  ,
	Current_8mA= 8u  ,
	
}Port_PinOutputCurrentType;


 typedef enum 
{
	Disable=0u,
	Enable  
}Operation_Type;

typedef enum 
{
	Pin0 = 0u,
	Pin1     ,
	Pin2     ,
	Pin3     ,
	Pin4     ,
	Pin5     ,
	Pin6     ,
	Pin7
}Port_PinType;


typedef enum 
{
	GPIOA = 0u,
	GPIOB     ,
	GPIOC     ,
	GPIOD     ,
	GPIOE     ,
	GPIOF 
}Port_Type;

 typedef struct
{
	Port_PinType				PinNumber                 ;
	Port_Type                   PortNumber                ;
	Port_PinModeType            PortPinMode               ;  /* output or input */
	Port_PinLevelType           PortPinLevelValue         ;  /* set pin low or high */
	Port_PinDirection_Type      PortPinDirection          ;  /* output or input */
	Port_PinInternalAttachType  PortPinInternalAttach     ;  /* Pull up or down  */
	Port_PinOutputCurrentType   PortPinOutputCurrent      ;  /* set output current */
}Port_ConfigType;

#endif  /* PORT_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: Port_Types.h
 *********************************************************************************************************************/
