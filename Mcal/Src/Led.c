/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  SysCrtl.c
 *        \brief  System Clock Controller Driver
 *
 *      \details  The Driver Configure System Clock
 *                Enable CLock Gate for External Peripherals
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "LED.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
Gpt_ConfigType Timer00={ID_0,PERIODIC,GPT_PREDEF_TIMER_1US_32BIT};
Port_ConfigType LED={Pin1,GPIOF,GPIO,LOW,OUTPUT,OPEN_DRAIN,Current_4mA};
Port_ConfigType b1={Pin4,GPIOF,GPIO,LOW,INPUT,OPEN_DRAIN,Current_4mA};
Port_ConfigType b2={Pin0,GPIOF,GPIO,LOW,INPUT,OPEN_DRAIN,Current_4mA};

 uint32 ontime , offtime;
 uint32 b2_statas=0;
 uint32 on_count=0;
uint32 off_count=0;

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


void Led_int(void)
{
	//SysCrtl_Init();
	Port_Clk_Init();
	Port_Init (&LED);
	Port_Init (&b1);
	Port_Init (&b2);
	Gpt_Init(&Timer00);
	
}

void LED_Init(uint16 onTime, uint16 offTime)
{
    ontime = offTime;
    offtime = onTime;
}

void Buttom_pushed()
{
	if(Dio_ReadChannel(PF0)==HIGH)
	{
		
		if(b2_statas == 2)
		{
			b2_statas=0;
			ontime=on_count;
			offtime=off_count;
		}
		else{
			b2_statas++;
		}
	
	}
	else{}
		
	if((b2_statas==1) && (Dio_ReadChannel(PF4)==PinHIGH))
	{
		on_count++;
	}
	else if((b2_statas==2) && (Dio_ReadChannel(PF4)==PinHIGH))
	{
		off_count++;
	}
}
void Timer_0A_ISR()
{
	
	GPT_ClearFlag(Timer00.GPT_ChannelID);
	
	if(ontime>0)
	{
		Dio_WriteChannel(PF0,PinHIGH);
		ontime--;
		offtime=off_count;
	}
	else if(offtime>0)
	{
		offtime--;
	}
	if((ontime==0)&&(offtime==0))
	{
		ontime=on_count;
		offtime=off_count;
	}
	Gpt_StartTimer(Timer00.GPT_ChannelID,1000000);
	while (GPT_FinishedInterrupt(Timer00.GPT_ChannelID)==0)
    {
    }
	Gpt_StopTimer(Timer00.GPT_ChannelID);
	GPT_ClearFlag(Timer00.GPT_ChannelID);
	
	
}



/**********************************************************************************************************************
 *  END OF FILE: SysCrtl.c
 *********************************************************************************************************************/







  





