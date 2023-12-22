#include <stdint.h>
#include <stdio.h>
#include "alarm.h"
#include "driver.h"
#include "STATE.h"



extern void Delay(int nCount);
extern int getPressureVal();
extern void Set_Alarm_actuator(int i);
extern void GPIO_INITIALIZATION ();

extern int PS_Forward_Signal;
extern void (*ALARM_state)();
int Alarm_Back_Signal;
int alarmTimer = 100000; /*60 sec assumption*/

STATE_DEFINE(ALARM_init){
ALARM_State_id = ALARM_WAITING;
ALARM_state = STATE(ALARM_WAITING);



}
STATE_DEFINE(ALARM_WAITING){
	if(HighPressure_Alarm())
	{
	ALARM_State_id = ALARM_ON;
	ALARM_state = STATE(ALARM_ON);
	ALARM_state();
	}
	else{
	ALARM_State_id = ALARM_OFF;
    ALARM_state = STATE(ALARM_OFF);
    Alarm_Back_Signal = Alarm_OFF();
    ALARM_state();
	}


}
STATE_DEFINE(ALARM_ON){

    Set_Alarm_actuator(1);
	Delay(alarmTimer);
	Set_Alarm_actuator(0);
	
	ALARM_state = STATE(ALARM_WAITING);
	
}

STATE_DEFINE(ALARM_OFF){
	ALARM_State_id = ALARM_OFF;
	if (Alarm_Back_Signal == Alarm_OFF()){
		Set_Alarm_actuator(0);}
	

	ALARM_state = STATE(ALARM_WAITING);
	

}

int Alarm_OFF(){
	if(ALARM_State_id == ALARM_OFF || ALARM_State_id == ALARM_WAITING ){
		return 1;
	}
	else
	 return 0;
}

int HighPressure_Alarm(){
	if(PS_Forward_Signal)
		return 1;
	else
		return 0;


}