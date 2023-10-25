/*
 ============================================================================
 Name        : Assignment_less4_Ex4.c
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
	int i,inserted_number,location ;
	int array[n];

	printf("Enter the number of elements :  ");
	fflush(stdout);fflush(stdin);
		scanf("%d",&n);


		for(i=0 ; i<n ; i++){
			array[i]=i+1;
		}

		for(i=0 ; i<n ; i++){
			printf(" %d ", array[i]);
		}

		printf("\nEnter the number to be inserted :  ");
		fflush(stdout);fflush(stdin);
		scanf("%d",&inserted_number);

		printf("Enter the location :  ");
		fflush(stdout);fflush(stdin);
		scanf("%d",&location);

			location--;

		for(i=0; i<=n; i++ ){
			if(i==location){
				printf(" %d ", inserted_number);
				for(i=location+1;i<=n;i++){
					printf(" %d ", array[i-1]);
					if(i==n){break;}
				}
			}
			else{
				printf(" %d ", array[i]);
			}
		}


	return EXIT_SUCCESS;
}
