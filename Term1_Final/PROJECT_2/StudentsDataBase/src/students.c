/*Master Embedded Systems "learn in depth"
 *Eng. Hossam Essam Diab
 *Unit 5/PROJECT_2:Student Data Base
 *File: students.c
 */
#include "students.h"
#include "FIFO.h"


/********************************************************************************************************************/

void add_student_from_txt(FIFO_Buffer_t* Queue){
	FILE *File;
	char Buffer[500];
	File = fopen("File.txt", "r");
	if (File == NULL) {
		DPRINTF("[ERROR] Unable to open file\n");
		return;
	}

	Sstudent_t New_Student;
	while (fgets(Buffer, sizeof(Buffer), File) != NULL) {
		New_Student.ROLL = atoi(Buffer);
		sscanf(Buffer,"%d %s %s %f %d %d %d %d %d",
				&New_Student.ROLL,
				New_Student.FIRST_NAME,
				New_Student.LAST_NAME,
				&New_Student.GPA,
				&New_Student.COURSE[0],
				&New_Student.COURSE[1],
				&New_Student.COURSE[2],
				&New_Student.COURSE[3],
				&New_Student.COURSE[4]);

		// Check if roll number already exist
		int Flag=0;
		Sstudent_t * Temp_Pointer = Queue->tail;
		for (int i = 0; i < Queue->counter; i++){
			if(Temp_Pointer->ROLL == New_Student.ROLL){
				DPRINTF("[ERROR] Roll Number %d Already Exist.\n",New_Student.ROLL);
				Flag=1;
			}
			Temp_Pointer++;
		}
		if(Flag == 0){
			FIFO_ENQUEUE(Queue, New_Student);
			DPRINTF("[INFO] Added Student With Roll Number %d Successfully.\n",New_Student.ROLL);
		}

	}
	total_num_of_students(Queue);
	fclose(File);


}
/********************************************************************************************************************/

void total_num_of_students(FIFO_Buffer_t *Queue){
	DPRINTF("[INFO] Number of Students In the Database: %d\n",Queue->counter);
	DPRINTF("[INFO] You Can Add Up To %d More Students.\n",55-Queue->counter);
}
/********************************************************************************************************************/

void add_student(FIFO_Buffer_t *Queue){

	char Temp[50];
	Sstudent_t New_Student;
	DPRINTF("Add the Student Details Manually\n");

	DPRINTF("Enter the Roll Number: ");
	gets(Temp);
	New_Student.ROLL = atoi(Temp);
	// Check if roll number already exist
	Sstudent_t * Temp_Pointer = Queue->tail;
	for (int i = 0; i < Queue->counter; i++){
		if(Temp_Pointer->ROLL == New_Student.ROLL){
			DPRINTF("[ERROR] Roll Number %d Already Exist.\n",New_Student.ROLL);
			return;
		}
		Temp_Pointer++;
	}
	DPRINTF("Enter the First Name of the Student:");
	gets(Temp);
	strcpy(New_Student.FIRST_NAME,Temp);

	DPRINTF("Enter the Last Name of the Student:");
	gets(Temp);
	strcpy(New_Student.LAST_NAME,Temp);

	DPRINTF("Enter the GPA:");
	gets(Temp);
	New_Student.GPA = atof(Temp);

	DPRINTF("Enter Course ID of Each Course\n");
	for (int i = 0; i < 5; i++){
		printf("Course %d ID:",i+1);
		gets(Temp);
		New_Student.COURSE[i] = atoi(Temp);
	}
	FIFO_ENQUEUE(Queue, New_Student);
	DPRINTF("[INFO] Student Details Added Successfully :)\n");
	total_num_of_students(Queue);

}
/********************************************************************************************************************/

void find_student_with_ROLL_id(FIFO_Buffer_t *Queue){
	char Temp[10];
	enum Flag {Not_Found, Found} Flag;
	Flag = Not_Found;
	DPRINTF("Enter the Roll Number of The Student: ");
	gets(Temp);
	Sstudent_t* Temp_Pointer = Queue->tail;
	for (int i = 0; i < Queue->counter; i++){
		if(Temp_Pointer->ROLL == atoi(Temp)){
			DPRINTF("[INFO] Found the Student With Roll Number: %d\n",atoi(Temp));
			Show_Student(Temp_Pointer);
			Flag = Found;
		}
		Temp_Pointer++;
	}
	if(Flag == Not_Found)
		DPRINTF("[ERROR] Roll Number %d Not Found.\n",atoi(Temp));

}
/********************************************************************************************************************/
void Show_Student(Sstudent_t *Student){
	DPRINTF("Student Details Are:\n\n");
	DPRINTF("\tThe First Name: %s\n",Student->FIRST_NAME);
	DPRINTF("\tThe Last Name: %s\n",Student->LAST_NAME);
	DPRINTF("\tThe Roll Number: %d\n",Student->ROLL);
	DPRINTF("\tThe GPA: %.2f\n",Student->GPA);
	for (int i = 0; i < 5; i++){
		DPRINTF("\tCourse %d ID: %d\n",i+1,Student->COURSE[i]);
	}
	DPRINTF("----------\n");
}
/********************************************************************************************************************/

void find_student_with_1stname(FIFO_Buffer_t *Queue){
	char Temp[10];
	enum Flag {Not_Found, Found} Flag;
	Flag = Not_Found;
	printf("Enter the First Name of The Student: ");
	gets(Temp);
	Sstudent_t * Temp_Pointer = Queue->tail;
	for (int i = 0; i < Queue->counter; i++){
		if( !strcmp(Temp_Pointer->FIRST_NAME,Temp) ){
			DPRINTF("[INFO] Found the Student With First Name: %s\n",Temp);
			Show_Student(Temp_Pointer);
			Flag = Found;
		}
		Temp_Pointer++;
	}
	if(Flag == Not_Found)
		DPRINTF("[ERROR] First Name %s Not Found.\n",Temp);

}
/********************************************************************************************************************/

void find_course_students(FIFO_Buffer_t *Queue){
	char Temp[50];
	printf("Enter the ID of The Course: ");
	enum Flag {Not_Found, Found} Flag;
	Flag = Not_Found;
	gets(Temp);
	Sstudent_t * Temp_Pointer = Queue->tail;
	for (int i = 0; i < Queue->counter; i++){
		for (int j = 0; j < 5; j++){
			if( Temp_Pointer->COURSE[j] == atoi(Temp) ){
				Show_Student(Temp_Pointer);
				Flag = Found;
			}
		}
		Temp_Pointer++;
	}
	if(Flag == Not_Found)
		DPRINTF("[ERROR] Course ID %d Not Found.\n",atoi(Temp));
}

/********************************************************************************************************************/

void delete_student_with_ROLL_id(FIFO_Buffer_t *Queue){
	char Temp[10];
	DPRINTF("Enter the Roll Number To Delete: ");
	gets(Temp);
	Sstudent_t * Temp_Pointer = Queue->tail;
	for (int i = 0; i < Queue->counter; i++){
		if(Temp_Pointer->ROLL == atoi(Temp)){
			DPRINTF("[INFO] Found the Student With Roll Number: %d\n",atoi(Temp));
			// Copy First Element To Dequeue in This Element
			Temp_Pointer->ROLL=Queue->tail->ROLL;
			for (int i = 0; i < 5; i++)
				Temp_Pointer->COURSE[i]	= Queue->tail->COURSE[i];
			Temp_Pointer->GPA = Queue->tail->GPA;
			strcpy(Temp_Pointer->FIRST_NAME,Queue->tail->FIRST_NAME);
			strcpy(Temp_Pointer->LAST_NAME,Queue->tail->LAST_NAME);
			FIFO_DEQUEUE(Queue);
			return;
		}
		Temp_Pointer++;
	}
	DPRINTF("[ERROR] Roll Number %d Not Found.\n",atoi(Temp));

}
/********************************************************************************************************************/

void update_student_with_ROLL_id(FIFO_Buffer_t *Queue){

	char Temp[10];
	enum Flag {Not_Found, Found} Flag;
	Flag = Not_Found;
	DPRINTF("Enter the Roll Number To Update: ");
	gets(Temp);
	Sstudent_t * Temp_Pointer = Queue->tail;
	for (int i = 0; i < Queue->counter; i++){
		if(Temp_Pointer->ROLL == atoi(Temp)){
			DPRINTF("[INFO] Found the Student With Roll Number: %d\n",atoi(Temp));
			DPRINTF("What Do You Want To Update?:\n");
			DPRINTF("1. First Name\n2. Last Name\n3. Roll Number\n4. GPA\n5. Courses\n");
			gets(Temp);
			switch(atoi(Temp)){
			case 1:
				DPRINTF("Enter a New First Name: ");
				gets(Temp);
				strcpy(Temp_Pointer->FIRST_NAME,Temp);
				DPRINTF("[INFO ]First Name Updated!\n");
				break;
			case 2:
				DPRINTF("Enter a New Last Name: ");
				gets(Temp);
				strcpy(Temp_Pointer->LAST_NAME,Temp);
				DPRINTF("[INFO ]Last Name Updated!\n");
				break;
			case 3:
				DPRINTF("Enter the New Roll Number: ");
				gets(Temp);
				Temp_Pointer->ROLL = atoi(Temp);
				DPRINTF("[INFO ]Roll Number Updated!\n");
				break;
			case 4:
				DPRINTF("Enter the New GPA: ");
				gets(Temp);
				Temp_Pointer->GPA = atof(Temp);
				DPRINTF("[INFO ]GPA Updated!\n");
				break;
			case 5:
				for (int i = 0; i < 5; i++){
					DPRINTF("Enter the Course %d New ID:",i+1);
					gets(Temp);
					Temp_Pointer->COURSE[i] = atoi(Temp);
				}
				DPRINTF("[INFO ]Courses IDs Updated!\n");
				break;
			default:
				DPRINTF("[ERROR] Wrong choice, Try Again.\n");
			}
			Show_Student(Temp_Pointer);
			Flag = Found;
		}
		Temp_Pointer++;
	}
	if(Flag == Not_Found)
		DPRINTF("[ERROR] Roll Number %d Not Found.\n",atoi(Temp));
}
/********************************************************************************************************************/

void show_all_students(FIFO_Buffer_t *Queue){
	if(Queue->counter==0){
		DPRINTF("[ERROR] Empty Database\n");
		return;
	}
	Sstudent_t * Temp_Pointer = Queue->tail;
	DPRINTF("Student Details Are:\n");
	for (int i = 0; i < Queue->counter; i++){
		DPRINTF("The First Name: %s\n",Temp_Pointer->FIRST_NAME);
		DPRINTF("The Last Name: %s\n",Temp_Pointer->LAST_NAME);
		DPRINTF("The Roll Number: %d\n",Temp_Pointer->ROLL);
		DPRINTF("The GPA: %.2f\n",Temp_Pointer->GPA);
		for (int i = 0; i < 5; i++)
			DPRINTF("Course %d ID: %d\n",i+1,Temp_Pointer->COURSE[i]);
		DPRINTF("----------\n");
		Temp_Pointer++;
	}
}
