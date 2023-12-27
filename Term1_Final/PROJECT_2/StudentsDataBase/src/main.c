/*
Master Embedded Systems "learn in depth"
Eng. Hossam Essam Diab
Unit 5/PROJECT_2:Student Data Base
File:main.c
*/

#include "students.h"
#include "FIFO.h"

int main()
{
	Sstudent_t Student_list[55] ;
	FIFO_Buffer_t Queue;
	FIFO_INIT(&Queue ,Student_list, 55);

    int choice;

    while(1){
    	DPRINTF("\n\t\t\tMenu\n");
    	DPRINTF("1- Add students details from text file.\n");
    	DPRINTF("2- Add student details manually..\n");
    	DPRINTF("3- Find student by a given roll number.\n");
    	DPRINTF("4- Find students by a given first name.\n");
    	DPRINTF("5- Find students registered in specific course.\n");
    	DPRINTF("6- Number of students registered.\n");
    	DPRINTF("7- Delete student by Roll number.\n");
    	DPRINTF("8- Update student information.\n");
    	DPRINTF("9- Show all\n");
    	DPRINTF("10- Exit\n");
    	DPRINTF("\n");

    	DPRINTF("Enter your choice: ");
		scanf("%d", &choice);

		switch (choice) {
			case ADD_STUDENTS_FROM_TXT:
				DPRINTF("You chose to add a student from a text file..\n");
				add_student_from_txt(&Queue);
				break;
			case ADD_STUDENT_MANUALY:
				DPRINTF("You chose to add a student manually\n");
				add_student(&Queue);
				break;
			case FIND_STUDENT_FROM_ID:
				DPRINTF("You chose to Find student by a given roll number.\n");
				find_student_with_ROLL_id(&Queue);
				break;
			case FIND_STUDENT_FROM_1stNAME:
				DPRINTF("You chose to Find students by a given first name.\n");
				find_student_with_1stname(&Queue);
				break;
			case FIND_COURSE_STUDENTS:
				DPRINTF("You chose to Find the number of students registered in specific course.\n");
				find_course_students(&Queue);
				break;
			case STUDENTS_NUMBER:
				DPRINTF("You chose to Find the total number of students registered.\n");
				total_num_of_students(&Queue);
				break;
			case DELET_BY_ROLL_NUM:
				DPRINTF("You chose to Delete student by Roll number.\n");
				delete_student_with_ROLL_id(&Queue);
				break;
			case UPDATE_STUDENT:
				DPRINTF("You chose to Update student information.\n");
				update_student_with_ROLL_id(&Queue);
				break;
			case VIEW_ALL:
				DPRINTF("You chose to show all students.\n");
				show_all_students(&Queue);
				break;
			case EXIT:
				DPRINTF("EXIT the program .\n");
				exit(0);
			default:
				DPRINTF("Invalid choice.\n");
				break;
		}
    }
	return 0;
}
