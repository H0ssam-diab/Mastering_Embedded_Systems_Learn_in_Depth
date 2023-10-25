/*
 ============================================================================
 Name        : Assignment_lesson4_Ex7.c
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
	int counter =0;
	char sentence[1000];

	printf("\n\nEnter a string ");
	fflush(stdout);fflush(stdin);
	scanf("%s", &sentence);

	for(i=0;i<sizeof(sentence);i++){
		if(sentence[i]==0){
			break;
		}
		else{
			counter++;
		}
	}

	printf("\n\nThe length of the string :  %d", counter);











	return 0;
}
