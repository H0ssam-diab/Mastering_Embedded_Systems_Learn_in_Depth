/*
 ============================================================================
 Name        : Assignment_lesson6_Ex4.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct SData {

	char name[50];
	int mark;


};

struct SData students[10];

int main(void) {
	int i ;
	printf("\nEnter the information of the students .. ");
	for(i=0; i< sizeof(students)/sizeof(students[0]);i++){
		printf("\nFor Roll no.%d ..\t",i+1);

		printf("\nEnter the name :\t");
			fflush(stdout);fflush(stdin);
			scanf("%s",students[i].name);

			printf("\nEnter the marks :\t");
			fflush(stdout);fflush(stdin);
			scanf("%d",&students[i].mark);

	}

	printf("\nDisplaying the data of students..");

	for(i=0; i< sizeof(students)/sizeof(students[0]);i++){


			printf("\nRoll number :\t%d",i);
			printf("\nName :\t%s",students[i].name);
			printf("\nMarks :\t%d",students[i].mark);
				}





	return EXIT_SUCCESS;
}
