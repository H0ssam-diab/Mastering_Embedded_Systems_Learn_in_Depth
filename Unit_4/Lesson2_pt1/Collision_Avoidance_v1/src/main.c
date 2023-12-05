/*
 ============================================================================
 Name        : Collision_Avoidance_v1.c
 Author      : HOSSAM DIAB
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "STATE.h"
#include "US.h"
#include "DC_Motor.h"
#include "CA.h"



void setup()
{
	/* Init all drivers
	 *Init Interrupts
	 *Init HAL  US and DC_Driver
	 *Init Block
	 */

	ST_US_init();
	STATE(DC_Motor_init)();
	/* Set states pointers for each block*/
	US_state = STATE(US_BUSY);
	CA_state = STATE(CA_waiting);
	DC_state = STATE(DC_Motor_IDLE);

}

int main(void) {

	setup();
	while(1){

		/* Call state for each block*/
		US_state();
		CA_state();
		DC_state();
		/*
		 *  Doesn't this make an overload (Overflow) ?
		 *Stack of waiting --> stack of driving --> ..
		 * Overflow won't happen, why ?
		 * When we put the address of the function inside the pointer, it doesn't mean calling it
		 * It will run and after it prints, its stack will be deleted

		 */
	}








	return 0;
}
