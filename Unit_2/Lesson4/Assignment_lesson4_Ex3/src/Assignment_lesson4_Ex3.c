/*
 ============================================================================
 Name        : Assignment_lesson4_Ex3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int i ,j;
	int n=10,m=10;
	int array[n][m];
	int array_t [m][n];

	printf("\nEnter the number of rows :   ");
	fflush(stdout);fflush(stdin);
	scanf("%d",&n);
	printf("\nEnter the number of columns :   ");
	fflush(stdout );fflush(stdin);
	scanf("%d",&m);
	printf("\nEnter the elements of  matrix \n");
		for(i= 0 ; i<n ; i++){
			for(j=0 ; j<m ; j++){

				printf("Enter the element [%d][%d] : " , i, j);
				fflush(stdout);fflush(stdin);
				scanf("%d", &array[i][j]);

			}
		}
			printf("\nEntered Matrix is : \n");

		for(i= 0 ; i<n ; i++){
			for(j=0 ; j<m ; j++){

						printf("%d  " , array[i][j]);
						array_t[j][i]=array[i][j];
					}
					printf("\n");
				}


		printf("\nTransposed Matrix is : \n");
			for(i=0 ;i<m ; i++){
				for(j=0;j<n;j++){
					printf("%d  " , array_t[i][j]);
				}
				printf("\n");
			}

	return 0;
}
