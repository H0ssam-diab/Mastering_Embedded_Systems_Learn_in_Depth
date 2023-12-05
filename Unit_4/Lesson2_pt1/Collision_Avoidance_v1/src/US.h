/*
 * US.c
 *
 *  Created on: Dec 5, 2023
 *      Author: Hossam Diab
 */


#include "STATE.h"


#ifndef US_H_
#define US_H_

enum {
	US_BUSY
}US_State_id;

/*States of Sensor*/
STATE_DEFINE(US_init);
STATE_DEFINE(US_BUSY);

/*Pointer to states of sensor takes nothing and return void */

void (*US_state)();

#endif
