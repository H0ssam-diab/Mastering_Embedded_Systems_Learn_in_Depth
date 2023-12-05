/*
 * DC_Motor.h
 *
 *  Created on: Dec 5, 2023
 *      Author: Hossam
 */


#include "STATE.h"

#ifndef DC_Motor_H_
#define DC_Motor_H_

enum {
	DC_Motor_BUSY,
	DC_Motor_IDLE
}DC_State_id;

/*States of Dc motor*/
STATE_DEFINE(DC_Motor_init);
STATE_DEFINE(DC_Motor_BUSY);
STATE_DEFINE(DC_Motor_IDLE);

/*Pointer to states of Motor takes nothing and return void */

void (*DC_state)();

#endif
