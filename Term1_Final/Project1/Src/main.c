#include <stdint.h>
#include <stdio.h>
#include "STATE.h"
#include "driver.h"
#include "sensor.h"
#include "alarm.h"
#include "Platform_Types.h"

/*extern int Alarm_Back_Signal;*/
/*extern int PS_Forward_Signal;*/
extern void GPIO_INITIALIZATION ();

extern int Get_PressureValue(int Pval);
extern int HighPressure_Alarm();
extern int Alarm_OFF();

void setup()
{
	/* Init all drivers
	 *Init Interrupts
	 *Init HAL  US and DC_Driver
	 *Init Block
	 */
	GPIO_INITIALIZATION();
	STATE(PS_init)();
	STATE(ALARM_init)();

}
int main (){
	setup();
	while (1)
	{	
		PS_state();
		
		ALARM_state();

		 
	}

}
