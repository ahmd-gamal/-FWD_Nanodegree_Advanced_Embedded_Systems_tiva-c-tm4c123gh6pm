#include "LED.h"

int main(void)
{

	Led_int();
	LED_Init(1,2);
	
	
	while(1)
	{
		Buttom_pushed();
		Timer_0A_ISR();
	}
	return 0;
}
