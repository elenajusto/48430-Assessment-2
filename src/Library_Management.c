/*******************************************************************************
 * 48430 Fundamentals of C Programming - Assignment 2
 * Name:
 * Student ID:              Elena Justo
 * Date of submission:      
 * A brief statement on what you could achieve (less than 50 words):
 * 
 * 
 * A brief statement on what you could NOT achieve (less than 50 words):
 * 
 * 
*******************************************************************************/

/*******************************************************************************
 * List header files - do NOT use any other header files. Note that stdlib.h is
 * included in case you want to use any of the functions in there. However the
 * task can be achieved with stdio.h and string.h only.
*******************************************************************************/

#include <stdlib.h>
#include <stdio.h>

/*******************************************************************************
 * List preprocessing directives - you may define your own.
*******************************************************************************/

#define MAX_COMPANY_SIZE 20
#define MAX_NAME_SIZE 15

/*******************************************************************************
 * List structs - you may define struct date_time and struct flight only. Each
 * struct definition should have only the fields mentioned in the assignment
 * description.
*******************************************************************************/
struct publication_date {
	int month;
	int year;
};

struct book {
	char title;
	char author;
	char isbn;
	struct publication_date bookDate;
	char genre;
};

/*******************************************************************************
 * Function prototypes - do NOT change the given prototypes. However you may
 * define your own functions if required.
*******************************************************************************/
void printMenu(void);

void addBook(void);
void deleteLastBook(void);
void displayBookList(void);
void saveBookListDB(void);
void readBookListDB(void);
void exitProgram(void);

/*******************************************************************************
 * Main
*******************************************************************************/
int main(void){

    printMenu();
    /* char dbFileName[] = "database"; */

	int userInput;
	scanf("%d", &userInput);

	switch (userInput)
	{
	case 1:
		/* addBook */
		addBook();
		break;
	case 2:
		/* deleteLastBook */
		deleteLastBook();
		break;
	case 3:
		/* displayBookList */
		displayBookList();
		break;
	case 4:
		/* saveBookListDB */
		saveBookListDB();
		break;
	case 5:
		/* readBookListDB */
		readBookListDB();
		break;
	case 6:
		/* exitProgram */
		exitProgram();
		break;
	default:
		printf("Invalid input\r\n");
		break;
	}

    return 0;
}

/*******************************************************************************
 * This function prints the initial menu with all instructions on how to use
 * this program.
 * inputs:
 * - none
 * outputs:
 * - none
*******************************************************************************/
void printMenu(void){
    printf("\nLibrary Management System \n"
    	"1. Add a book\n"
    	"2. Delete last book\n"
    	"3. Display book list\n"
    	"4. Save the book list to the database\n"
    	"5. Read the book list from the database\n"
    	"6. Exit the program\n");
}

/*******************************************************************************
 * This function allows the user to add a new book to the library.
 * inputs:
 * - none
 * outputs:
 * - none
*******************************************************************************/
void addBook(void){
	printf("Function running: addBook\r\n");
}

/*******************************************************************************
 * This function deletes the last book added by the user from the library.
 * inputs:
 * - none
 * outputs:
 * - none
*******************************************************************************/
void deleteLastBook(void){
	printf("Function running: deleteLastBook\r\n");
}

/*******************************************************************************
 * This function displays all the books currently stored in the library.
 * inputs:
 * - none
 * outputs:
 * - none
*******************************************************************************/
void displayBookList(void){
	printf("Function running: displayBookList\r\n");
}

/*******************************************************************************
 * This function saves the current library into a DB file.
 * inputs:
 * - none
 * outputs:
 * - none
*******************************************************************************/
void saveBookListDB(void){
	printf("Function running: saveBookListDB\r\n");
}

/*******************************************************************************
 * This function checks for a DB file and reads its book library if a DB file is found.
 * inputs:
 * - none
 * outputs:
 * - none
*******************************************************************************/
void readBookListDB(void){
	printf("Function running: readBookListDB\r\n");
}

/*******************************************************************************
 * This function exits the program.
 * inputs:
 * - none
 * outputs:
 * - none
*******************************************************************************/
void exitProgram(void){
	printf("Function running: exitProgram\r\n");
}
