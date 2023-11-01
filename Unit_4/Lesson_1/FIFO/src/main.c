/*
 * main.c
 *
 *  Created on: Oct 30, 2023
 *      Author: Hossam
 */


#include "FIFO.h"

element_type Buffer1[Buffer_Length];

int main(void) {
	element_type  i , temp ;
	FIFO_Buffer_t UART_FIFO , I2C_FIFO;

	/*STATIC ALLOCATION*/
	if(FIFO_INIT(&UART_FIFO,Buffer1 ,Buffer_Length)== FIFO_NO_ERROR){
		printf(".......... UART_FIFO initialization is Done .............\n");
	}

	/*DYNAMIC ALLOCATION*/
	element_type* Buffer2 =(element_type*) malloc(Buffer_Length * sizeof(element_type));
	if(FIFO_INIT(&I2C_FIFO,Buffer2,Buffer_Length)== FIFO_NO_ERROR){
		printf(".......... I2C_FIFO initialization is Done .............\n");
	}

	printf("\n............................../*STATIC Adding*/..........................................\n");
	for(i=0 ; i< 9 ; i++){
		if((FIFO_ENQUEUE(&UART_FIFO,i+1)) == FIFO_NO_ERROR){
			printf("\nUART FIFO ADD : %d" , i+1);
		}else{
			printf("\nUART FIFO ADD : %d FAILED ^^^^^^^^^^" , i+1);

		}
	}
	printf("\n................................/*STATIC Fetching*/........................................\n");

	for(i=0 ; i< 2 ; i++){
		if((FIFO_DEQUEUE(&UART_FIFO, &temp)) == FIFO_NO_ERROR){
			printf("\nUART FIFO POP : %d" , temp);
		}else{
			printf("\nUART FIFO Fetch : %d FAILED ^^^^^^^^^^" , i+1);
		}
	}
	FIFO_Display(&UART_FIFO);

		printf("\n............................../*DYNAMIC ALLOCATION*/..........................................\n");
		for(i=0 ; i< 5 ; i++){
			if((FIFO_ENQUEUE(&I2C_FIFO,i)) == FIFO_NO_ERROR){
				printf("\nI2C FIFO PUSH : %d" , i);
			}
		}

		printf("\n............................./*DYNAMIC Fetching*/...........................................\n");

		for(i=0 ; i< 1 ; i++){
			if(i==Buffer_Length){break;}
			if((FIFO_DEQUEUE(&I2C_FIFO, &temp)) == FIFO_NO_ERROR){
				printf("\nI2C FIFO POP : %d" , temp);
			}
		}
		FIFO_Display(&I2C_FIFO);


		free(Buffer2);
		return 0;



	}
