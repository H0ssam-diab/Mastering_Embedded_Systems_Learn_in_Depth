/*
 * FIFO.h
 *
 *  Created on: Oct 30, 2023
 *      Author: Hardware
 */

#ifndef FIFO_H_
#define FIFO_H_
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define Buffer_Length 7
#define element_type uint32_t
/*Type Definitions*/

typedef struct {
	element_type length;
	element_type counter;
	element_type* base;
	element_type* head;
	element_type* tail;
}FIFO_Buffer_t;

typedef enum{
	FIFO_NO_ERROR,
	FIFO_FULL,
	FIFO_EMPTY,
	FIFO_NULL
}BUFFER_STATUS;

/* APIs */
BUFFER_STATUS FIFO_ENQUEUE(FIFO_Buffer_t* fifo_buffer ,element_type item);
BUFFER_STATUS FIFO_DEQUEUE(FIFO_Buffer_t* fifo_buffer ,element_type* item);
BUFFER_STATUS FIFO_INIT(FIFO_Buffer_t* fifo_buffer ,element_type* buffer, element_type length);
BUFFER_STATUS FIFO_IS_FULL(FIFO_Buffer_t* fifo_buffer);
void FIFO_Display(FIFO_Buffer_t* fifo_buffer);





#endif /* FIFO_H_ */
