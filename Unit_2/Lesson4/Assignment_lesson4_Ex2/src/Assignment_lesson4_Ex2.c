/*
 ============================================================================
 Name        : Assignment_lesson4_Ex2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


int main(void) {
	int i;
	int n = 0 ;
	printf("Enter the number of elements :  ");
	fflush(stdin);fflush(stdout);
	scanf("%d", &n );
	float Average = 0;
	float array[n];

	for(i=0; i<n ;i++){
		printf("\nEnter Element #%d :  ", i );
		fflush(stdin);fflush(stdout);
		scanf("%f",&array[i]);
		Average += (array[i]/n);
	}

	printf("\nTHE AVERAGE OF THE ARRAY IS \t%f", Average);

	return 0;
}
