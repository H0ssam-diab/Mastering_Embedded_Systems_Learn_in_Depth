/*
 ============================================================================
 Name        : FIFO.c
 Author      : HOSSAM DIAB
 ============================================================================
 */

#include "FIFO.h"


BUFFER_STATUS FIFO_INIT(FIFO_Buffer_t* fifo_buffer ,element_type* list, int length){

	if(list == NULL){
		return FIFO_NULL;
	}

	fifo_buffer->base = list ;
	fifo_buffer->head = list ;
	fifo_buffer->tail = list ;
	fifo_buffer->counter = 0 ;
	fifo_buffer->length = length ;

	return FIFO_NO_ERROR;

}



BUFFER_STATUS FIFO_ENQUEUE(FIFO_Buffer_t* fifo_buffer ,element_type data){

	/*Validation Check*/
	if(!fifo_buffer->base || !fifo_buffer->head || !fifo_buffer->tail){return FIFO_NULL;}
	/*Full Check*/
	if(FIFO_IS_FULL(fifo_buffer)==FIFO_FULL){return FIFO_FULL;}

	*(fifo_buffer->head) = data;
	fifo_buffer->counter++;

	if(fifo_buffer->head == fifo_buffer->base +((fifo_buffer->length)*sizeof(element_type))){
		fifo_buffer->head = fifo_buffer->base;
	return FIFO_FULL;
	}
	else{
		fifo_buffer->head++;
		return FIFO_NO_ERROR;
	}




}


BUFFER_STATUS FIFO_DEQUEUE(FIFO_Buffer_t* fifo_buffer ){

	/*Validation Check*/
	if(!fifo_buffer->base || !fifo_buffer->head || !fifo_buffer->tail){return FIFO_NULL;}
	/*EMPTY Check*/
	if(fifo_buffer->counter == 0){return FIFO_EMPTY;}

	fifo_buffer->counter--;
	if(fifo_buffer->tail == fifo_buffer->base +((fifo_buffer->length)*sizeof(element_type))){
		fifo_buffer->tail = fifo_buffer->base;}
	else{
		fifo_buffer->tail++;}


	return FIFO_NO_ERROR;

}

BUFFER_STATUS FIFO_IS_FULL(FIFO_Buffer_t* fifo_buffer){
	if(!fifo_buffer->base || !fifo_buffer->head || !fifo_buffer->tail){return FIFO_NULL;}
	if (fifo_buffer->counter == fifo_buffer->length){
		return FIFO_FULL;
	}else{
		return FIFO_NO_ERROR;}
}


