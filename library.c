//Library management
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define MAX_BOOKS 100
struct Book
{
	int bookID ;
	char title[100];
	char author[100];
	int year;
	int quantity;
};
struct Library
{
	struct Book books[MAX_BOOKS];
	int count;
};
void addBook(struct Library*library){
	if (library -> count >= MAX_BOOKS){
		printf("Maximum number of books reached.\n");
		return;
	}
	struct Book newBook;
	printf("Enter  book ID :");
	scanf("%d",&newBook.bookID);
	printf("Enter  book title :");
	scanf("%s",newBook.title);
	printf("Enter the book author :");
	scanf("%s",newBook.author);
	printf("Enter publication year :");
	scanf("%d",&newBook .year);
	printf("Enter quantity:");
	scanf("%d",&newBook.quantity);
	
	
	library->books[library->count] = newBook;
	library -> count++;
	printf("Book added sucessfully.\n");
}
void Displaybooks(const struct Library *library) {
	printf("ID\tTitle\t\tAuthor\t\tYear\tQuantity\n");
	for (int i = 0; i < library->count; i++) {
		printf("%d\t%s\t\t%s\t\t%d\t%d\n",
		       library->books[i].bookID,
		       library->books[i].title,
		       library->books[i].author,
		       library->books[i].year,
		       library->books[i].quantity);
	}
}
int searchBook(const struct Library *library,int bookID)
{
	for (int i = 0 ; i<library-> count ; i++){
		if (library ->books[i].bookID == bookID){
			return i;
		}
	}
	return -1;
}
void borrowBook (struct Library * library){
	int bookID;
	printf("Enter book ID to borrow:");
	scanf("%d",&bookID);
	
	int bookIndex = searchBook(library , bookID);
	if (bookIndex == -1){
		printf("Book not found .\n");
		return;
	}
	if (library -> books[bookIndex].quantity <= 0){
		printf("Book is out of stock.\n");
		return;
	}
	library ->books[bookIndex].quantity--;
	printf("Book borrowed successfully.\n");
}
void returnBook(struct Library * library){
	int bookID;
	printf("Enter book ID to return :");
	scanf("%d",&bookID);
	int bookIndex = searchBook (library,bookID);
	if (bookIndex == -1){
		printf(" Book not found.\n");
		return;
	}
	library -> books[bookIndex].quantity ++ ;
	printf(" Book returned successfully.\n");
}

int main() {
	struct Library library;
	library.count = 0;
	int choice;

	do {
		printf("\n---- Library Management System ----\n");
		printf("1. Add a book\n");
		printf("2. Display books\n");
		printf("3.Borrow a book \n");
		printf("4.Return a book\n");
		printf("0. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
				addBook(&library);
				break;
			case 2:
				Displaybooks(&library);
				break;
				case 3 :
					borrowBook(&library);
					break;
					case 4:
						returnBook(&library);
						break ;
			case 0:
				printf("Exiting program.\n");
				break;
			default:
				printf("Invalid choice. Try again.\n");
				break;
		}
	} while (choice != 0);
	return 0;
}
