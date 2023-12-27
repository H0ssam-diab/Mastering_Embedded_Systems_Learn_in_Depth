/*
 * STATE.h
 *
 *  Created on: Dec 22, 2023
 *      Author: Hossam Diab
 */

#include <stdio.h>
#include <stdlib.h>
#include "Platform_Types.h"
#ifndef STATE_H_
#define STATE_H_



#define STATE_DEFINE(_state_func_)     void ST_##_state_func_()
#define STATE(_state_func_) 	       ST_##_state_func_

/*
 * Connections between Pressure Sensor & Main  Modules
 */

int Get_PressureValue(int Pval);
int PS_Forward_Signal ;
/*
 * Connections between Pressure Alarm Actuator & Main  Modules
 */
int HighPressure_Alarm();
int Alarm_OFF();
int Alarm_Back_Signal ;

#endif /* STATE_H_ */
