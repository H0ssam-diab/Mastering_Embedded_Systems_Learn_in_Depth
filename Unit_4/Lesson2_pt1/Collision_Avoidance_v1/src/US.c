/*
 * US.c
 *
 *  Created on: Dec 5, 2023
 *      Author: Hossam Diab
 */


#include <stdlib.h>
#include <stdio.h>
#include "US.h"

int US_Get_distance_random(int l , int r , int count);
extern void (*US_state)();
int distance = 0 ;

STATE_DEFINE(US_BUSY)
{

	US_State_id = US_BUSY;
	distance = US_Get_distance_random(45,55,1);

	US_distance_set(distance);

	US_state = STATE(US_BUSY);
	printf("\nState : US_Busy   ,   Distance = %d" , distance );


}

void ST_US_init(){

	printf("\nUltraSonic_initialization \n");

	}


int US_Get_distance_random(int l , int r , int count)
{
	int i,rand_distance=0;
	for(i=0;i<count;i++)
	{
		rand_distance = (rand() % (r - l + 1)) + l;
		return rand_distance;
	}
	return rand_distance;
}


