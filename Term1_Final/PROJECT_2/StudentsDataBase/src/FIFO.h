/*
 * FIFO.h
 *
 *  Created on: Dec 24, 2023
 *      Author: Hossam Diab
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#ifndef FIFO_H_
#define FIFO_H_

typedef struct
{
    char FIRST_NAME[50];
    char LAST_NAME[50];
    int ROLL;
    float GPA;
    int COURSE[5];
} Sstudent_t;



#define element_type Sstudent_t
/*Type Definitions*/

typedef struct {
	unsigned int length;
	unsigned int counter;
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
BUFFER_STATUS FIFO_DEQUEUE(FIFO_Buffer_t* fifo_buffer);
BUFFER_STATUS FIFO_INIT(FIFO_Buffer_t* fifo_buffer ,element_type* buffer, int length);
BUFFER_STATUS FIFO_IS_FULL(FIFO_Buffer_t* fifo_buffer);



#endif /* FIFO_H_ */
