/*Master Embedded Systems "learn in depth"
*Eng. Hossam Essam Diab
*Unit 5/PROJECT_2:Student Data Base
*File: students.h
*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"
#include "FIFO.h"
#ifndef STUDENTS_H_
#define STUDENTS_H_



#define DPRINTF(...)	{fflush(stdout); \
		fflush(stdin); \
		printf(__VA_ARGS__); \
		fflush(stdout); \
		fflush(stdin);}


/*STRUCTURES*/
enum {
	ZERO,
	ADD_STUDENTS_FROM_TXT,
	ADD_STUDENT_MANUALY,
	FIND_STUDENT_FROM_ID,
	FIND_STUDENT_FROM_1stNAME,
	FIND_COURSE_STUDENTS,
	STUDENTS_NUMBER,
	DELET_BY_ROLL_NUM,
	UPDATE_STUDENT,
	VIEW_ALL,
	EXIT
}menu;






/*APIs*/
void add_student_from_txt(FIFO_Buffer_t* Queue);
void add_student(FIFO_Buffer_t *Queue);
void find_student_with_ROLL_id(FIFO_Buffer_t *Queue);
void find_student_with_1stname(FIFO_Buffer_t *Queue);
void find_course_students(FIFO_Buffer_t *Queue);
void total_num_of_students(FIFO_Buffer_t *Queue);
void delete_student_with_ROLL_id(FIFO_Buffer_t *Queue);
void update_student_with_ROLL_id(FIFO_Buffer_t *Queue);
void show_all_students(FIFO_Buffer_t *Queue);
void Show_Student(Sstudent_t *Student);




#endif /* STUDENTS_H_ */
