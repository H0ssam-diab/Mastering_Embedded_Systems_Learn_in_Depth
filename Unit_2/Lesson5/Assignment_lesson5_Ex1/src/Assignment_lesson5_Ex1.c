/*
 ============================================================================
 Name        : Assignment_lesson5_Ex1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void primeFinder(int start, int end);

int main(void) {

	unsigned int start , end ;
	printf("\nEnter 2 numbers (Intervals) : ");
	fflush(stdout);fflush(stdin);
	scanf("%d%d",&start,&end);

	primeFinder(start,end);

	return 0;
}

void primeFinder(int start, int end){
	int i,k;
	int prime_flag;
	printf("\nPrime numbers between %d and %d are : ", start, end);
	for(i=start ; i<=end ;i++){
		prime_flag=0;
		if(i==0||i==1){
			continue;
		}
		else if(i==2){
			printf(" %d ",i);
			continue;
		}
		else{
			for(k=2;k<i;k++){
				if(i%k==0){
					prime_flag=1;
					break;
				}

			}
			if(prime_flag==0){
				printf(" %d ",i);
			}
		}
	}


}
