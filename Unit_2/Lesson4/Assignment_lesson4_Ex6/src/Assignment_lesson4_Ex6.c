/*
 ============================================================================
 Name        : Assignment_lesson4_Ex6.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {


	int i, freq =0;
	char target;
	char Sentence[1000];
	printf("\nEnter a string  :   ");
	fflush(stdout);fflush(stdin);
	gets(Sentence);

	printf("\n\nEnter a Character to find frequency of it :    ");
	fflush(stdout);fflush(stdin);
	scanf("%c",&target);

	for(i=0 ; i< strlen(Sentence) ; i++ ){
		if(target==Sentence[i]){
			freq++ ;
		}
		else{continue;}

	}

	printf("\n\nTHE FREQUENCY OF THE CHAR YOU CHOOSE IS  :  %d ", freq);





	return 0;
}
