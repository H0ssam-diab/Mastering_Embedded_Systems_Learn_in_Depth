/*
 * LINKED_LIST.h
 *
 *  Created on: Oct 31, 2023
 *      Author: HOSSAM DIAB
 */

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"

#define DPRINTF(...)	{fflush(stdout); \
		fflush(stdin); \
		printf(__VA_ARGS__); \
		fflush(stdout); \
		fflush(stdin);}

/* Type Definitions */
typedef struct {
	unsigned int ID;
	char Name[50];
	float height;
}SData;

    /*Element structure of Linked list*/
struct Sstudent{
	SData student;
	struct Sstudent* PNextStudent;
};

struct Sstudent* pTempStudent;
/* APIs */
void AddStudent();
void Fill_the_Record(struct Sstudent* pStud);
int  DeleteStudent();
void DisplayAllStudent();
void DeleteAllStudent();
int Display_1_Student();
int Node_Number();
void DisplayStudent_Reversed();
int List_Length(struct Sstudent* pCurStudent);

#endif /* LINKED_LIST_H_ */
