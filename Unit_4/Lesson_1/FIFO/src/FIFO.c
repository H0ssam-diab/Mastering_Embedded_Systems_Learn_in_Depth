/*
 ============================================================================
 Name        : FIFO.c
 Author      : HOSSAM DIAB
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "FIFO.h"
BUFFER_STATUS FIFO_INIT(FIFO_Buffer_t* fifo_buffer ,element_type* buffer, element_type length){

	if(buffer == NULL){
		return FIFO_NULL;
	}

	fifo_buffer->base = buffer ;
	fifo_buffer->head = buffer ;
	fifo_buffer->tail = buffer ;
	fifo_buffer->counter = 0 ;
	fifo_buffer->length = length ;

	return FIFO_NO_ERROR;

}



BUFFER_STATUS FIFO_ENQUEUE(FIFO_Buffer_t* fifo_buffer ,element_type item){

	/*Validation Check*/
	if(!fifo_buffer->base || !fifo_buffer->head || !fifo_buffer->tail){return FIFO_NULL;}
	/*Full Check*/
	if(FIFO_IS_FULL(fifo_buffer)==FIFO_FULL){return FIFO_FULL;}

	*(fifo_buffer->head) = item;
	fifo_buffer->counter++;
	if(fifo_buffer->head == fifo_buffer->base +((fifo_buffer->length)*sizeof(element_type))){
		fifo_buffer->head = fifo_buffer->base;}
	else{
		fifo_buffer->head++;}


	return FIFO_NO_ERROR;

}


BUFFER_STATUS FIFO_DEQUEUE(FIFO_Buffer_t* fifo_buffer ,element_type* item){

	/*Validation Check*/
	if(!fifo_buffer->base || !fifo_buffer->head || !fifo_buffer->tail){return FIFO_NULL;}
	/*EMPTY Check*/
	if(fifo_buffer->counter == 0){return FIFO_EMPTY;}

	*item = *(fifo_buffer->tail);
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
void FIFO_Display(FIFO_Buffer_t* fifo_buffer){

	if(fifo_buffer->counter == 0){
		printf("FIFO IS EMPTY ^^^^\n");
	}else{
		element_type* temp;
		temp = fifo_buffer->tail;
		element_type i;
		printf("\n*********FIFO PRINT*********\n");
		for(i=0 ; i< fifo_buffer->counter ; i++ , temp++){
				printf("\t %d \n",*temp);
		}
	}



}

