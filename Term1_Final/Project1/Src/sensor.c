#include "STATE.h"
#include "sensor.h"
#include <stdlib.h>
#include <stdio.h>
#include "driver.h"
extern void Delay(int nCount);
extern int getPressureVal();
extern void Set_Alarm_actuator(int i);
extern void GPIO_INITIALIZATION ();

static int counter =0;

extern void (*PS_state)();
int Pval = 0 ;
int pull_time = 10000 ;

int PS_Get_Pressure_random();

STATE_DEFINE(PS_WAITING)
{
	PS_State_id = PS_WAITING;
	Pval =  PS_Get_Pressure_random();
	Delay(pull_time); /*Pulling Delay*/
	counter += 2;
	/*Sending the value of Pressure  */

	if(Pval > 20){
		PS_Forward_Signal = Get_PressureValue(Pval);
		getPressureVal();       /*driver*/
		PS_state = STATE(PS_WAITING);
	}
	else{
		PS_Forward_Signal = Get_PressureValue(Pval);
		getPressureVal();
		PS_state = STATE(PS_WAITING);
	}
	


}

STATE_DEFINE(PS_init)
{
	PS_state = STATE(PS_WAITING);

}

int Get_PressureValue(int Pval){
	if(Pval > 20 ){
			return 1;
	}
	else{
		return 0;
	}
}



int PS_Get_Pressure_random()
{
	if (counter >30)
		counter=0;
	return counter;

}
