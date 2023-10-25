/*
 ============================================================================
 Name        : Assignment_lesson6_Ex2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct Sdistance
{
	int feet;
	float inch;

}dis_1,dis_2,sum;

int main(void) {
	printf("Enter the first distance \n");
	printf("\n\rEnter Feet : ");
	fflush(stdout);fflush(stdin);
	scanf("%d",&dis_1.feet);
	printf("\n\rEnter Inches : ");
	fflush(stdout);fflush(stdin);
	scanf("%f",&dis_1.inch);

	printf("Enter the second distance \n");
		printf("\n\rEnter Feet : ");
		fflush(stdout);fflush(stdin);
		scanf("%d",&dis_2.feet);
		printf("\n\rEnter Inches : ");
		fflush(stdout);fflush(stdin);
		scanf("%f",&dis_2.inch);

		 sum.feet = dis_1.feet+dis_2.feet;
		 sum.inch= dis_1.inch+ dis_2.inch;

		if(sum.inch>=12){
			sum.inch -= 12;
			sum.feet += 1;
		}

		printf("Sum of Distances is : %d'-%.1f'",sum.feet,sum.inch);




	return 0;
}
