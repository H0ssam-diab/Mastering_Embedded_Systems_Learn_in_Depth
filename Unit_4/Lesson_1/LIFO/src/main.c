/*
 * main.c
 *
 *  Created on: Oct 30, 2023
 *      Author: Hossam
 */



#include "LIFO.h"

unsigned int Buffer1[Buffer_Length];

int main(void) {
	unsigned int  i , temp ;
	LIFO_Buffer_t UART_lifo , I2C_lifo;

	/*STATIC ALLOCATION*/
	LIFO_INIT(&UART_lifo,Buffer1 ,Buffer_Length);

	/*DYNAMIC ALLOCATION*/
	unsigned int* Buffer2 =(unsigned int*) malloc(Buffer_Length * sizeof(unsigned int));
	LIFO_INIT(&I2C_lifo,Buffer2,Buffer_Length);
	printf("\n............................../*STATIC ALLOCATION*/..........................................\n");
	for(i=0 ; i< Buffer_Length ; i++){
		if((LIFO_PUSH(&UART_lifo,i+1)) == LIFO_NO_ERROR){
			printf("\nUART LIFO ADD : %d" , i+1);
		}
	}
	printf("\n............................../*DYNAMIC ALLOCATION*/..........................................\n");
	for(i=0 ; i< Buffer_Length ; i++){
		if((LIFO_PUSH(&I2C_lifo,i)) == LIFO_NO_ERROR){
			printf("\nI2C LIFO PUSH : %d" , i);
		}
	}
	printf("\n................................/*STATIC ALLOCATION*/........................................\n");

	for(i=0 ; i< Buffer_Length ; i++){
		if((LIFO_POP(&UART_lifo, &temp)) == LIFO_NO_ERROR){
			printf("\nUART LIFO GOT : %d" , temp);
		}
	}
	printf("\n............................./*DYNAMIC ALLOCATION*/...........................................\n");

	for(i=0 ; i< Buffer_Length ; i++){
		if((LIFO_POP(&I2C_lifo, &temp)) == LIFO_NO_ERROR){
			printf("\nI2C LIFO POP : %d" , temp);
		}
	}

	free(Buffer2);
	return 0;
}
