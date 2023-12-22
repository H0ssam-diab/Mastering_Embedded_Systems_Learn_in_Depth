#include "STATE.h"
#include "sensor.h"
#include <stdlib.h>
#include <stdio.h>
#include "driver.h"
extern void Delay(int nCount);
extern int getPressureVal();
extern void Set_Alarm_actuator(int i);
extern void GPIO_INITIALIZATION ();


extern void (*PS_state)();
int Pval = 0 ;
int pull_time = 1000 ;



STATE_DEFINE(PS_WAITING)
{
	PS_State_id = PS_WAITING;
	Pval =  getPressureVal();
	Delay(pull_time); /*Pulling Delay*/
	/*Sending the value of Pressure  */

	if(Pval > 20){
		PS_Forward_Signal = 1 ;
		PS_state = STATE(PS_WAITING);
	}
	else{
		PS_Forward_Signal = 0 ;
		
		PS_state = STATE(PS_WAITING);
	}
	


}

STATE_DEFINE(PS_init)
{
	PS_state = STATE(PS_WAITING);

}




