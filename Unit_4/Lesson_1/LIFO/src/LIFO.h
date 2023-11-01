/*
 * LIFO.h
 *
 *  Created on: Oct 30, 2023
 *      Author: Hossam
 */

#ifndef LIFO_H_
#define LIFO_H_
#include <stdio.h>
#include <stdlib.h>
#define Buffer_Length 5

/*Type Definitions*/

typedef struct {
	unsigned int length;
	unsigned int counter;
	unsigned int* base;
	unsigned int* head;
}LIFO_Buffer_t;

typedef enum{
	LIFO_NO_ERROR,
	LIFO_FULL,
	LIFO_EMPTY,
	LIFO_NULL
}BUFFER_STATUS;

/* APIs */
BUFFER_STATUS LIFO_PUSH(LIFO_Buffer_t* lifo_buffer ,unsigned int item);
BUFFER_STATUS LIFO_POP(LIFO_Buffer_t* lifo_buffer ,unsigned int* item);
BUFFER_STATUS LIFO_INIT(LIFO_Buffer_t* lifo_buffer ,unsigned int* buffer, unsigned int length);




#endif /* LIFO_H_ */
