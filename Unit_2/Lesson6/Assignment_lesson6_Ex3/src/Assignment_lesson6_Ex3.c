/*
 ============================================================================
 Name        : Assignment_lesson6_Ex3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct Scomplex {
	float real;
	float img;
}num1,num2,sum;

void ADD (struct Scomplex X ,struct Scomplex Y);
int main(void) {

printf("\nEnter the first number in the form (real  imaginary) :  ");
fflush(stdout);fflush(stdin);
scanf("%f %f",&num1.real,&num1.img);

printf("\nEnter the second number in the form (real  imaginary) :  ");
fflush(stdout);fflush(stdin);
scanf("%f %f",&num2.real,&num2.img);

ADD(num1,num2);



return 0;
}
void ADD (struct Scomplex X ,struct Scomplex Y){
	sum.real = X.real+Y.real;
	sum.img = X.img+Y.img;
	printf("\nSum = %.2f + i%.2f",sum.real,sum.img);


}




















