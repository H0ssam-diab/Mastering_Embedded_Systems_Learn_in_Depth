/*
 ============================================================================
 Name        : Assignment_lesson6_Ex5.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define pi 3.14
#define area(radius) (pi*radius*radius)


int main(void) {
		float r;
		printf("Enter the radius of circle :");
		fflush(stdout);fflush(stdin);
		scanf("%f", &r);
		printf("\nThe Area of the circle is :   %.2f ", area(r));


	return 0;
}
