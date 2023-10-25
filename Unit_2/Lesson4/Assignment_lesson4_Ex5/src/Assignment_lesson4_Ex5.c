/*
 ============================================================================
 Name        : Assignment_lesson4_Ex5.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int n = 45;
		int i,search_number,location ;
		int array[n];

		printf("\nEnter the number of elements :  ");
		fflush(stdout);fflush(stdin);
			scanf("%d",&n);


			for(i=0 ; i<n ; i++){
				array[i]=(i+1)*11;
			}

			for(i=0 ; i<n ; i++){
				printf(" %d ", array[i]);
			}

			printf("\nEnter the element you want to be searched :  ");
			fflush(stdout);fflush(stdin);
			scanf("%d",&search_number);


			for(i=0 ; i < n; i++){
				if(search_number==array[i]){
					location = i+1;
					printf("\nNumber has been found at location :  %d",location);
					break;
				}
				else{
					continue;
				}
			}
			if(i==n){
				printf("SORRY , The number you are searching for isn't in the the list");
			}



	return 0;
}
