/*
 ============================================================================
 Name        : Assignment_lesson5_Ex3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char sentence[]);

int main(void) {
	char sentence[100];
	printf("Enter your sentence :  ");
	fflush(stdout);fflush(stdin);
	gets(sentence);

	reverse(sentence);

	return 0;
}

void reverse(char sentence[]){
	int i=strlen(sentence)-1 ;
	printf("%c",sentence[i]);
	sentence[i]=0;
	if(i!=0){
	reverse(sentence);
	}
}
