#include "STATE.h"
#include "Platform_Types.h"

#ifndef ALARM_H_
#define ALARM_H_

enum {
	ALARM_WAITING,
	ALARM_ON,
	ALARM_OFF
}ALARM_State_id;

/*States of Sensor*/
STATE_DEFINE(ALARM_init);
STATE_DEFINE(ALARM_WAITING);
STATE_DEFINE(ALARM_ON);
STATE_DEFINE(ALARM_OFF);

/*Pointer to states of Alarm takes nothing and return void */

void (*ALARM_state)();


#endif