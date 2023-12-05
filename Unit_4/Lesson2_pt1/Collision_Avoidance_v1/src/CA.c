/*
 * CA.c
 *
 *  Created on: Dec 5, 2023
 *      Author: Hardware
 */
#include "CA.h"
#include <stdlib.h>
#include <stdio.h>


extern void (*CA_state)();
int CA_threshold = 50;
int CA_distance = 0;
int CA_speed =0;

void US_distance_set(int distance){
	CA_distance = distance ;

	CA_state= (CA_distance>CA_threshold)? STATE(CA_driving): STATE(CA_waiting);
	printf("\n\nUS ------ Distance = %d ----->CA\n",CA_distance);

}


STATE_DEFINE(CA_waiting){
	CA_State_id = CA_waiting;
	CA_speed = 0 ;

	printf("\nState : CA_waiting   ,   Distance = %d   , Speed = %d" , CA_distance ,CA_speed );
	DC_MotorSpeed(CA_speed);
	printf("\n\nCA ------ SPEED = %d ----->DC_Motor\n",CA_speed);

}

STATE_DEFINE(CA_driving){

	CA_State_id = CA_driving;
	CA_speed = 30 ;

	printf("\nState : CA_driving   ,   Distance = %d   , Speed = %d" , CA_distance ,CA_speed );
	DC_MotorSpeed(CA_speed);
	printf("\n\nCA ------ SPEED = %d ----->DC_Motor\n",CA_speed);

}


