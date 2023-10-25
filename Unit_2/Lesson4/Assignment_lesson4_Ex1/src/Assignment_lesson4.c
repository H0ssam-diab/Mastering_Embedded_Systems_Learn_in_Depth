/*
 ============================================================================
 Name        : Assignment_lesson4.c
 Author      : Hossam Diab
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	int i, j ;
	float array_1 [2][2];
	float array_2 [2][2];

	printf("Enter the elements of first matrix \n");
	for(i= 0 ; i<2 ; i++){
		for(j=0 ; j<2 ; j++){

			printf("Enter the element [%d][%d] : " , i, j);
			fflush(stdin);fflush(stdout);
			scanf("%f", &array_1[i][j]);

		}
	}

	printf("\nEnter the elements of second matrix \n");
		for(i= 0 ; i<2 ; i++){
			for(j=0 ; j<2 ; j++){

				printf("Enter the element [%d][%d] : " , i, j);
				fflush(stdin);fflush(stdout);
				scanf("%f", &array_2[i][j]);

			}
		}

		printf("The sum of 2 Matrices : \n");
		for(i= 0 ; i<2 ; i++){
					for(j=0 ; j<2 ; j++){

						printf("%f \t",(array_1[i][j]+array_2[i][j]));
					}
					printf("\n");
				}

	return 0;
}
