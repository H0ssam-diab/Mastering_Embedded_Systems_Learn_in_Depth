/*
 * CA.h
 *
 *  Created on: Dec 5, 2023
 *      Author: Hossam Diab
 */



#include "STATE.h"

#ifndef CA_H_
#define CA_H_

enum {
	CA_waiting,
	CA_driving
}CA_State_id;

/*States of Sensor*/
extern STATE_DEFINE(CA_waiting);
extern STATE_DEFINE(CA_driving);

/*Pointer to states of sensor takes nothing and return void */

void (*CA_state)();

#endif
