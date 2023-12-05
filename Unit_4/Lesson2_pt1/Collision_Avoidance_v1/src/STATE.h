/*
 * STATE.h
 *
 *  Created on: Dec 5, 2023
 *      Author: Hardware
 */

#ifndef STATE_H_
#define STATE_H_

#include <stdio.h>
#include <stdlib.h>

#define STATE_DEFINE(_state_func_)     void ST_##_state_func_()
#define STATE(_state_func_) 	       ST_##_state_func_

/*
 * Connections between Modules
 */

void US_distance_set(int distance);
void DC_MotorSpeed(int speed);

#endif /* STATE_H_ */
