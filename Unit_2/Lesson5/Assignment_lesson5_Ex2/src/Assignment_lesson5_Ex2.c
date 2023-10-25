/*
 ============================================================================
 Name        : Assignment_lesson5_Ex2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int factorial(unsigned int x);

int main(void) {
	unsigned int x,y ;
	printf("\nEnter a positive number: ");
	fflush(stdout);fflush(stdin);
	scanf("%d",&x);
	y= factorial(x);
	printf("\nThe Factorial for %d is %d ",x,y);
	return 0;
}

int factorial(unsigned int x){

	if(x==0||x==1){
		return 1;
	}
	else{
		x = x * factorial(x-1);
		return x;
	}

}
