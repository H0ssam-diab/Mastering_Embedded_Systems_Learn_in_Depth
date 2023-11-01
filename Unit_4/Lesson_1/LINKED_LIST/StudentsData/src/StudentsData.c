/*
 ============================================================================
 Name        : StudentsData.c
 Author      : HOSSAM DIAB
 Version     :
 Copyright   : 
 Description : Student data manipulation using linked list
 ============================================================================
 */

#include "LINKED_LIST.h"

extern struct Sstudent* gpFirstStudent ;

int main(void) {
	char answer[5];
	while(1){
		DPRINTF("\tSELECT YOUR OPTION\n");
		DPRINTF("1:Add New Student\n");
		DPRINTF("2:Delete Student\n");
		DPRINTF("3:Print All Student\n");
		DPRINTF("4:Delete All Student\n");
		DPRINTF("5:Print Student data using ID\n");
		DPRINTF("6:Print Student ID using Node Number\n");
		DPRINTF("7:Print Length of the List_Recersive\n");
		DPRINTF("8:Reverse the list and Display\n");
		DPRINTF("0:Exit the Program");
		DPRINTF("\n  Enter option number: ");
		gets(answer);
		DPRINTF("\n");
		switch(atoi(answer))
		{
		case 1:
			AddStudent();
			break;
		case 2:
			DeleteStudent();
			break;
		case 3:
			DisplayAllStudent();
			break;
		case 4:
			DeleteAllStudent();
			break;
		case 5:
			Display_1_Student();
			break;
		case 6:
			Node_Number();
			break;
		case 7:
			pTempStudent = gpFirstStudent;
			DPRINTF("\n^^^^^ %d Students ^^^^^\n",List_Length(pTempStudent)) ;
			break;
		case 8:
			DisplayStudent_Reversed();
			break;
		case 0:
			exit(0);
			break;
		default:
			DPRINTF("\t\"WRONG OPTION !! .. Try again \"\n");
			break;
		}
		DPRINTF(" ============================================\n");
	}
	return 0;
















	return 0;
}
