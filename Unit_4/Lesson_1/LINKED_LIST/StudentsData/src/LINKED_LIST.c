/*
 * LINKED_LIST.c
 *
 *  Created on: Oct 31, 2023
 *      Author: HOSSAM DIAB
 */

#include "LINKED_LIST.h"

struct Sstudent* gpFirstStudent =(struct Sstudent*) NULL;


void AddStudent(){
	struct Sstudent* pNewStudent ;
	struct Sstudent* pLastStudent ;

	/*Check Empty list*/
	if(gpFirstStudent == NULL){
		pNewStudent = (struct Sstudent*) malloc (sizeof(struct Sstudent));
		gpFirstStudent = pNewStudent;

	}else{
		pLastStudent = gpFirstStudent ;
		while(pLastStudent->PNextStudent){
			pLastStudent = pLastStudent->PNextStudent;
		}
		pNewStudent = (struct Sstudent*) malloc (sizeof(struct Sstudent));
		pLastStudent->PNextStudent = pNewStudent;

	}
	/*fill record of new student*/
	Fill_the_Record(pNewStudent);
	/*Assign last student next pointer to null*/
	pNewStudent->PNextStudent = NULL;

}

void Fill_the_Record(struct Sstudent* pStud){
	char text[50];
	DPRINTF("Creating New Student into the List\n");

	DPRINTF("\nEnter the ID : ");
	gets(text);
	pStud->student.ID= atoi(text);

	DPRINTF("\nEnter the Name : ");
	gets(pStud->student.Name);

	DPRINTF("\nEnter the Height : ");
	gets(text);
	pStud->student.height = atof(text);

}

int DeleteStudent(){
	struct Sstudent* pPreviosStudent = NULL ;
	struct Sstudent* pSelectedStudent = gpFirstStudent ;
	if(gpFirstStudent == NULL){
		DPRINTF("\nEMPTY LIST , TRY TO INSERT ELEMENT FIRST\n");
		return 0;
	}else{
		char temp[10];

		DPRINTF("\nEnter the ID of student to be removed :   ");
		gets(temp);

		while(pSelectedStudent){
			if(pSelectedStudent->student.ID == atoi(temp)){
				if(pPreviosStudent){

					pPreviosStudent->PNextStudent= pSelectedStudent->PNextStudent;

				}else{

					gpFirstStudent = pSelectedStudent->PNextStudent;
				}
				free(pSelectedStudent);
				return 1;


			}

			pPreviosStudent = pSelectedStudent;
			pSelectedStudent = pSelectedStudent->PNextStudent;

		}
	}


	DPRINTF("The ID is not existing in the list ");
	return 0;


}

void DisplayAllStudent(){

	int counter = 0 ;
	struct Sstudent* pCurrentStudent = gpFirstStudent;

	if(gpFirstStudent == NULL){
		DPRINTF("\nEMPTY LIST , TRY TO INSERT ELEMENT FIRST\n");}

	while(pCurrentStudent){
		DPRINTF("\n\t<<<Record Number %d >>>", ++counter);
		DPRINTF("\n\tID : %d",pCurrentStudent->student.ID);
		DPRINTF("\n\tName : %s",pCurrentStudent->student.Name);
		DPRINTF("\n\tHeight : %.2f", pCurrentStudent->student.height);
		DPRINTF("\n*******************************");
		pCurrentStudent = pCurrentStudent->PNextStudent;
	}


}


void DeleteAllStudent(){


	if(gpFirstStudent == NULL){
		DPRINTF("\nEMPTY LIST , TRY TO INSERT ELEMENT FIRST\n");}
	else{
		struct Sstudent* pCurrentStudent = gpFirstStudent;
		while(pCurrentStudent){
			struct Sstudent* pPreviosStudent ;
			pPreviosStudent = pCurrentStudent;
			pCurrentStudent = pCurrentStudent->PNextStudent;
			free(pPreviosStudent);
		}
		gpFirstStudent = NULL;
		DPRINTF("\n!!!!!!!!!!!!All STUDENTS DATA DELETED SUCCESSFULLY!!!!!!!!!!!!")



	}


}


int Display_1_Student(){
	struct Sstudent* pSelectedStudent = gpFirstStudent ;


	if(gpFirstStudent == NULL){
		DPRINTF("\nEMPTY LIST , TRY TO INSERT ELEMENT FIRST\n");
		return 0;
	}
	else{
		char temp[10];
		unsigned int counter = 0 ;

		DPRINTF("\nEnter the ID of student to be Previewed :   ");
		gets(temp);

		while(pSelectedStudent){
			if(pSelectedStudent->student.ID == atoi(temp)){

				DPRINTF("\n\t<<<Record Number %d >>>", counter);
				DPRINTF("\n\tID : %d",pSelectedStudent->student.ID);
				DPRINTF("\n\tName : %s",pSelectedStudent->student.Name);
				DPRINTF("\n\tHeight : %f.2", pSelectedStudent->student.height);
				DPRINTF("\n*******************************");


				return 1;
			}
			pSelectedStudent = pSelectedStudent->PNextStudent;
			counter++;
		}

	}

	DPRINTF("\nThe ID does not exist !!!! .. Try Again ");
	return 0;
}


int Node_Number(){


	struct Sstudent* pSelectedStudent = gpFirstStudent ;


	if(gpFirstStudent == NULL){
		DPRINTF("\nEMPTY LIST , TRY TO INSERT ELEMENT FIRST\n");
		return 0;
	}
	else{
		char temp[10];
		unsigned int counter = 0 ;

		DPRINTF("\nEnter the Index of student to Preview its ID :   ");
		gets(temp);

		while(pSelectedStudent){
			if( atoi(temp) == (counter+1) ){

				DPRINTF("\n\t<<<ID of chosen index is  %d >>>", pSelectedStudent->student.ID);
				DPRINTF("\n*******************************");


				return 1;
			}
			pSelectedStudent = pSelectedStudent->PNextStudent;
			counter++;
		}

	}

	DPRINTF("\nThe Index does not exist in this list !!!! .. Try Again ");
	return 0;

}


int List_Length(struct Sstudent* pCurStudent){


	if(pCurStudent == NULL){
		return 0 ;}
	else{
		return (1+List_Length(pCurStudent->PNextStudent)) ;
	}


}




void DisplayStudent_Reversed(){

	struct Sstudent* current = gpFirstStudent ;
	struct Sstudent* previos = NULL ;
	struct Sstudent* next = current->PNextStudent ;
	if(gpFirstStudent == NULL){
		DPRINTF("\nEMPTY LIST , TRY TO INSERT ELEMENT FIRST\n");
	}
	else{
		while(current){

			if(!previos){
				current->PNextStudent = NULL;
				previos = current;
				current = next;
				next = next->PNextStudent;
				current->PNextStudent = previos;
			}
			else if(!next) {
				current->PNextStudent = previos;
				gpFirstStudent = current;
				break;

			}
			else{
				current->PNextStudent = previos;
				previos = current;
				current = next;
				next = next->PNextStudent;

			}


		}


	}



}












