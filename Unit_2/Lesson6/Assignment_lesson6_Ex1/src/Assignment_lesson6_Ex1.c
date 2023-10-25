/*
 ============================================================================
 Name        : Assignment_lesson6_Ex1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct Sstudent_data
{
	char name[50];
	int roll_number;
	float marks;
} student;


int main(void) {
	printf("\nEnter the information of the student :\t");
	printf("\nEnter the name :\t");
	fflush(stdout);fflush(stdin);
	scanf("%s",student.name);
	printf("\nEnter the roll number :\t");
	fflush(stdout);fflush(stdin);
	scanf("%d",&student.roll_number);
	printf("\nEnter the marks :\t");
	fflush(stdout);fflush(stdin);
	scanf("%f",&student.marks);

	printf("Displaying information ..\n\rName :%s\n\rRoll number :%d\n\rMarks :%f\n\r",
			student.name,
			student.roll_number,
			student.marks
			);
	return 0;
}
