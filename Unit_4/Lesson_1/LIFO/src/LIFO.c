/*
 ============================================================================
 Name        : LIFO.c
 Author      : Hossam Diab
 Version     :
 ============================================================================
 */
#include "LIFO.h"
BUFFER_STATUS LIFO_INIT(LIFO_Buffer_t* lifo_buffer ,unsigned int* buffer, unsigned int length){

	if(buffer == NULL){
		return LIFO_NULL;
	}


	lifo_buffer->base = buffer;
	lifo_buffer->head = buffer ;
	lifo_buffer->counter = 0 ;
	lifo_buffer->length = length;

	return LIFO_NO_ERROR;

}



BUFFER_STATUS LIFO_PUSH(LIFO_Buffer_t* lifo_buffer ,unsigned int item){

	/*Validation Check*/
	if(!lifo_buffer->base || !lifo_buffer->head){return LIFO_NULL;}
	/*Full Check*/
	if(lifo_buffer->counter == lifo_buffer->length){return LIFO_FULL;}

	*(lifo_buffer->head)= item;
	lifo_buffer->head++;
	lifo_buffer->counter++;
	return LIFO_NO_ERROR;

}


BUFFER_STATUS LIFO_POP(LIFO_Buffer_t* lifo_buffer ,unsigned int* item){

	/*Validation Check*/
	if(!lifo_buffer->base || !lifo_buffer->head){return LIFO_NULL;}
	/*Full Check*/
	if(lifo_buffer->counter == 0){return LIFO_EMPTY;}

	lifo_buffer->head--;
	*item = *(lifo_buffer->head);
	lifo_buffer->counter--;

	return LIFO_NO_ERROR;

}

