/*
 ============================================================================
 Name        : Assignment_lesson5_Ex4.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int power(int base , unsigned int p);

int main(void) {

	int base;
	unsigned int p;
	printf("\nEnter the base number : ");
	fflush(stdout);fflush(stdin);
	scanf("%d",&base);

	printf("\nEnter the power : ");
	fflush(stdout);fflush(stdin);
	scanf("%u",&p);

	printf("\n%d ^ %d = %d" , base, p, power(base ,p));


	return 0;
}

int power(int base , unsigned int p){

	if(p>1){
		return base*power(base,--p);
	}
	else if(p==1){
		return base;
	}
	else{
		if(p==0){printf("%d",1);}

		}

	}


