/*
 ============================================================================
 Name        : Assaignment_lesson4_Ex8.c
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

	    int i;
		char sentence[1000];
		char rev_sentence[1000];

		printf("\n\nEnter a string : ");
		fflush(stdout);fflush(stdin);
		scanf("%s", &sentence);

		for(i=0;i<strlen(sentence);i++){
			rev_sentence[strlen(sentence)-1-i] = sentence[i];

		}


		printf("The reversed String  : %s ", rev_sentence);


	return 0;
}
