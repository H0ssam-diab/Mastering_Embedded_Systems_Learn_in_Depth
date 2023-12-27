#include "STATE.h"
#include "Platform_Types.h"

#ifndef SENSOR_H_
#define SENSOR_H_



enum {
	PS_WAITING
}PS_State_id;

/*States of Sensor*/
STATE_DEFINE(PS_init);
STATE_DEFINE(PS_WAITING);

/*Pointer to states of sensor takes nothing and return void */

void (*PS_state)();




#endif