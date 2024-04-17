/*******************************************************************************
 * 48430 Fundamentals of C Programming - Assignment 2
 * Name:
 * Student ID:              Elena Justo
 * Date of submission:      
 * A brief statement on what you could achieve (less than 50 words):
 * 10/15 test cases
 * 
 * A brief statement on what you could NOT achieve (less than 50 words):
 * 
 * 
*******************************************************************************/

/*******************************************************************************
 * Header files 
*******************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*******************************************************************************
 * Preprocessing directives 
*******************************************************************************/

#define MAX_TITLE_SIZE 25
#define MAX_AUTHOR_SIZE 50
#define MAX_ISBN_SIZE 13
#define MAX_GENRE_SIZE 30

/*******************************************************************************
 * Structs
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
 * Function prototypes
*******************************************************************************/
void printMenu(void);

void addBook(struct book);
struct book getBookDetails();

int deleteLastBook(void);

void displayBookList(struct book *books);
void printFunction(struct book bookInput);
void printPublicationDate(struct publication_date date);
void trimLeadingWhitespace(char *str);

void saveBookListDB(void);
void readBookListDB(void);
void exitProgram(void);

void resizeLibrary();
void freeLibrary();

/*******************************************************************************
 * Program Variables
*******************************************************************************/   

	/*char dbFileName[] = "database";*/

	int userInput;

	struct book *booksLibrary = NULL;
	int book_count = 0;
	int book_capacity = 10;

/*******************************************************************************
 * Main Program
*******************************************************************************/
int main(void){

	/* Initialise Library */
	booksLibrary = calloc(book_capacity, sizeof(struct book));
	if (!booksLibrary) {
		fprintf(stderr, "Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}

	/*******************************************************************************
 	* Main Program Loop
	*******************************************************************************/
	while(1){

		/* Main Menu  */
		printMenu();
		scanf("%d", &userInput);

		/*  Function Control */
		switch (userInput)
		{
		case 1:
			/* addBook */
			addBook(getBookDetails());
			break;
		case 2:
			/* deleteLastBook */
			if (!deleteLastBook()) {
        		printf("List is empty\n");
   			}
			break;
		case 3:
			/* displayBookList */
			if (book_count > 0){
				printf("Title          Author         ISBN       Pub. Date Genre\n");
				printf("----------     ----------     ---------- --------- --------\n");
				displayBookList(booksLibrary);
			} else {
				printf("List is empty\n");
			}
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
			/* Invalid user inputs */
			printf("Invalid choice.\n");
			break;
		}
	}

	/* Free memory when program terminates */
	freeLibrary();
    return 0;
}

/*******************************************************************************
 * This function prints the initial menu with all instructions on how to use
 * this program.
*******************************************************************************/
void printMenu(void){
    printf("\nLibrary Management System \n"
    	"1. Add book\n"
    	"2. Delete last book\n"
    	"3. Display book list\n"
    	"4. Save the book list to the database\n"
    	"5. Read the book list from the database\n"
    	"6. Exit the program\n");
	printf("Enter your choice>\n");
}

/*******************************************************************************
 * Get details of the book the user wants to add.
 * Input: Done in console
 * Output: Instance of type Book with user defined parameters
*******************************************************************************/
struct book getBookDetails(){

	struct book newBook;

	/* Clear any leftover data in stdin buffer */
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}

	/* Title input */
    printf("Title: >");
    fgets(newBook.title, MAX_TITLE_SIZE, stdin);
	trimLeadingWhitespace(newBook.title);
    newBook.title[strcspn(newBook.title, "\n")] = 0;

	/* Author input */
    printf("Author: >");
    fgets(newBook.author, MAX_AUTHOR_SIZE, stdin);
	trimLeadingWhitespace(newBook.author);
    newBook.author[strcspn(newBook.author, "\n")] = 0;

	/* ISBN input */
    printf("ISBN: >");
    fgets(newBook.isbn, MAX_ISBN_SIZE, stdin);
	trimLeadingWhitespace(newBook.isbn);
    newBook.isbn[strcspn(newBook.isbn, "\n")] = 0;
	if (*newBook.isbn < 0){
		printf("Invalid ISBN.\n");
	}

	/* Publication month input */
    printf("Publication_date(month): >");
    scanf("%d", &newBook.bookDate.month);
    while ((c = getchar()) != '\n' && c != EOF) {} 		/* Clear input buffer from scanf */

	/* Publication year input */
	printf("Publication_date(year): >");
    scanf("%d", &newBook.bookDate.year);
    while ((c = getchar()) != '\n' && c != EOF) {} 		/* Clear input buffer from scanf */
	if (newBook.bookDate.year < 0){
		printf("Invalid year.\n");
	}
	
	/* Genre input */
    printf("Genre: >");
    fgets(newBook.genre, MAX_GENRE_SIZE, stdin);
	trimLeadingWhitespace(newBook.genre);
    newBook.genre[strcspn(newBook.genre, "\n")] = 0;

	/* New line character */
	printf("\n");

	/* Program output */
    return newBook;
}

/*******************************************************************************
 * This function allows the user to add a new book to the library.
 * Input: Instance type book
 * Output: None - Function appends input element to library array instance
*******************************************************************************/
void addBook(struct book bookToAdd){

	/* Allocates more memory if capacity has been reached */
	if (book_count == book_capacity) {
        resizeLibrary();
    }

	/* Add new book to latest point in library */
    booksLibrary[book_count] = bookToAdd;

	/* Increment book count */
    book_count++;
}

/*******************************************************************************
 * This function deletes the last book added by the user from the library.
*******************************************************************************/
int deleteLastBook(void){

	/* Logic ensures there is at least one item to be removed. */
    if (book_count > 0) {
        book_count--; 
        return 1;  
    }
    return 0; 
}

/*******************************************************************************
 * This function displays all the books currently stored in the library.
 * Input: Array of book instances (i.e., a library)
 * Output: None (Prints to console)
*******************************************************************************/
void displayBookList(struct book *books){
	
	/* Iterate through all book instances in the library */
	int i = 0;
	while (i < book_count){
		printFunction(books[i]);
		i++;
	}
}

/*******************************************************************************
 * Print function for items in the library
 * Input: Book instance from library
 * Output: None (Prints to console)
*******************************************************************************/
void printFunction(struct book bookInput){
	printf("%-14s %-14s %-10s %02d-%d   %s\n",
           bookInput.title, bookInput.author, bookInput.isbn,
           bookInput.bookDate.month, bookInput.bookDate.year, bookInput.genre);
}

/*******************************************************************************
 * This function saves the library into a database file so that future 
 * instances of the program can load the contents of the current library.
*******************************************************************************/
void saveBookListDB(void){
	FILE *fileDB;

	/* Open a file for writing */ 
    fileDB = fopen("library.db", "w");
    if (fileDB == NULL) {
        fprintf(stderr, "Failed to open file for writing\n");
        return;
    }

    /* Write each book to the file */
	int i = 0;
	
    while (i < book_count) {
        fprintf(fileDB, "%s,%s,%s,%d,%d,%s\n",
                booksLibrary[i].title,
                booksLibrary[i].author,
                booksLibrary[i].isbn,
                booksLibrary[i].bookDate.month,
                booksLibrary[i].bookDate.year,
                booksLibrary[i].genre);
		i++;
    }
	fclose(fileDB);
}

/*******************************************************************************
 * This function checks if a DB file from a previous instance of the program
 * is present in the executable's directory and reads its contents into memory
 * for the current program instance.
*******************************************************************************/
void readBookListDB(void){
    FILE *fileDB;
    char buffer[1024];

    /* Open the file for reading */
    fileDB = fopen("library.db", "r");

    if (fileDB == NULL) {
        printf("Read error: file not found\n");
        return;
    }

    /* Read each line from the file */
    while (fgets(buffer, sizeof(buffer), fileDB) != NULL) {
        struct book newBook;
        sscanf(buffer, "%[^,],%[^,],%[^,],%d,%d,%[^,\n]",
               newBook.title,
               newBook.author,
               newBook.isbn,
               &newBook.bookDate.month,
               &newBook.bookDate.year,
               newBook.genre);
        addBook(newBook); 
    }

    /* Close the file */
    fclose(fileDB);
}

/*******************************************************************************
 * This function exits the program.
*******************************************************************************/
void exitProgram(void){
	/* Frees up memory prior to exiting */
	freeLibrary();

	/* Exit function */
	exit(EXIT_SUCCESS);
}

/*******************************************************************************
 * This function dynamically reallocates the memory assigned to the library array.
*******************************************************************************/
void resizeLibrary(){
    int new_capacity = book_capacity * 2;

	/* Create additional memory for library based on current size times 2 */
    struct book *new_library = realloc(booksLibrary, new_capacity * sizeof(struct book));
    
	if (!new_library) {
        perror("Failed to reallocate library");
        exit(1);
    }

	/* Update variables keeping track of library in memory */
    book_capacity = new_capacity;
    booksLibrary = new_library;
}

/*******************************************************************************
 * This function clears the allocated memory for the library array.
*******************************************************************************/
void freeLibrary(){
	free(booksLibrary);
}

/*******************************************************************************
 * Helper function for trimming leading whitespace characters in strings.
 * Input: String with leading whitespace characters.
 * Output: String without leading whitespace characters.
*******************************************************************************/
void trimLeadingWhitespace(char *str) {
    int index, i;
    index = 0;

    /* Find index of first nonwhitespace character */
    while (str[index] == ' ' || str[index] == '\t' || str[index] == '\n') {
        index++;
    }

    /* Shift all characters to the left */
    if (index != 0) {
        i = 0;
        while (str[i + index] != '\0') {
            str[i] = str[i + index];
            i++;
        }
        str[i] = '\0'; /* Sentinel string char */
    }
}
 