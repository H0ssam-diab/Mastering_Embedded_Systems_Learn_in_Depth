/*
 * DC_Motor.c
 *
 *  Created on: Dec 5, 2023
 *      Author: Hossam Diab
 */

#include <stdlib.h>
#include <stdio.h>
#include "DC_Motor.h"

int DC_speed =0;
extern void (*DC_state)();

STATE_DEFINE(DC_Motor_init)
{

	printf("\nDC MOTOR Initialization\n");
}

void DC_MotorSpeed(int speed){


DC_State_id = DC_Motor_IDLE;

printf("\nState : DC_Motor_IDLE ,    Speed = %d", DC_speed);
DC_speed = speed ;
DC_state = STATE(DC_Motor_BUSY);

}


STATE_DEFINE(DC_Motor_BUSY){

	DC_State_id = DC_Motor_BUSY;

	printf("\nState : DC_Motor_BUSY ,    Speed = %d", DC_speed);

	DC_state = STATE(DC_Motor_IDLE);

}

STATE_DEFINE(DC_Motor_IDLE){

	DC_State_id = DC_Motor_IDLE;

	printf("\nState : DC_Motor_IDLE ,    Speed = %d", DC_speed);

}










