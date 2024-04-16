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
#include <string.h>

/*******************************************************************************
 * List preprocessing directives - you may define your own.
*******************************************************************************/

#define MAX_TITLE_SIZE 100
#define MAX_AUTHOR_SIZE 50
#define MAX_ISBN_SIZE 20
#define MAX_GENRE_SIZE 30

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
    char title[MAX_TITLE_SIZE];
    char author[MAX_AUTHOR_SIZE];
    char isbn[MAX_ISBN_SIZE];
    struct publication_date bookDate;
    char genre[MAX_GENRE_SIZE];
};

/*******************************************************************************
 * Function prototypes - do NOT change the given prototypes. However you may
 * define your own functions if required.
*******************************************************************************/
void printMenu(void);

void addBook();
struct book getBookDetails();

void deleteLastBook(void);
void displayBookList(void);
void saveBookListDB(void);
void readBookListDB(void);
void exitProgram(void);

/*******************************************************************************
 * Program Variables
*******************************************************************************/   

	/*char dbFileName[] = "database";*/

	int userInput;

	struct book *booksLibrary = NULL;
	int book_count = 0;
	int book_capacity = 10;

/*******************************************************************************
 * Main
*******************************************************************************/
int main(void){

	/********  Main Menu  ********/
    printMenu();
	scanf("%d", &userInput);

	/********  Initialising Library  ********/
	booksLibrary = calloc(book_capacity, sizeof(struct book));
    if (!booksLibrary) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
	}

	/********  Function Control  ********/
	switch (userInput)
	{
	case 1:
		/* addBook */
		getBookDetails();
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
 * Get details of the book the user wants to add.
 * inputs:
 * - none
 * outputs:
 * - none
*******************************************************************************/
struct book getBookDetails(){
	printf("Function running: getBookDetails\r\n");

	struct book newBook;

	/* Clear any leftover data in stdin buffer */
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}

    printf("Enter book title: ");
    fgets(newBook.title, MAX_TITLE_SIZE, stdin);
    newBook.title[strcspn(newBook.title, "\n")] = 0;

    printf("Enter author's name: ");
    fgets(newBook.author, MAX_AUTHOR_SIZE, stdin);
    newBook.author[strcspn(newBook.author, "\n")] = 0;

    printf("Enter ISBN: ");
    fgets(newBook.isbn, MAX_ISBN_SIZE, stdin);
    newBook.isbn[strcspn(newBook.isbn, "\n")] = 0;

    printf("Enter publication month and year (e.g., 12 1999): ");
    scanf("%d %d", &newBook.bookDate.month, &newBook.bookDate.year);
    while ((c = getchar()) != '\n' && c != EOF) {} 		/* Clear input buffer from scanf */

    printf("Enter genre: ");
    fgets(newBook.genre, MAX_GENRE_SIZE, stdin);
    newBook.genre[strcspn(newBook.genre, "\n")] = 0;

    return newBook;
}

/*******************************************************************************
 * This function allows the user to add a new book to the library.
 * inputs:
 * - none
 * outputs:
 * - none
*******************************************************************************/
void addBook(){
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
