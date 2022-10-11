#include "LmsStructures.c"
#include "LmsConfig.c"
#include "FileHandler.c"
#include "Helper.c"

int getTotalBookCount();
int getLastBookId();
book* searchBook();


//To add the book into the library


int addBook()
{
        char bookName[30], authorName[30];
       
        
        printf("\nBook Name: ");
        strcpy(bookName,readSting());
       
        printf("Author Name: ");
        strcpy(authorName,readSting());
       
		book *newBook = NULL;
		newBook = malloc(sizeof(book));

         bookIdGenerator = getLastBookId();

		newBook->book_id = ++bookIdGenerator ;
		strcpy(newBook->book_name, bookName);
		strcpy(newBook->author_name, authorName);
		
        int result = writeBook(newBook);

        int response = (result == 1) ? bookIdGenerator : 0;
		free(newBook);

		return response;

}

// To search the details of a particular book in the library

book* searchBook()
{
   int id;
   printf("\nEnter Book Id:");
   scanf("%d",&id);
   book *response = getBook(id);
   
   return response;
    
}

// To view the details of  particular all the book in the library

void viewAllBooks()
{
    book *books;
    books = getAllBooks();
    int totalBookcount = getTotalBookCount();


    printf("\n\t\t\t\t\tBook Details \t\t\t\t\n");
    printf("\n***********************************************************************************\n");
    for(int i=0;i<totalBookcount;i++){
         printf("\nBook_Id : %d\t\tBook_name : %s\t\tBook_Author: %s",books[i].book_id, books[i].book_name, books[i].author_name);
    }
    printf("\n***********************************************************************************\n");

    
}

// to update the Book details of a particular book

int editBook()
{
        char bookName[30], authorName[30];
        int result = 0;

        book *book_to_edit = searchBook();
        if(book_to_edit != NULL)
        { 
            printf("Old Book Details \n");
            printf("~~~~~~~~~~~~~~~~ \n");

            printf("\nBook_Id: %d\nBook_name: %s\nBook_Author: %s", book_to_edit->book_id, book_to_edit->book_name, book_to_edit->author_name);

            printf("\nEnter the new Book Details \n");
            printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~ \n");

            printf("\nBook Name: ");
            strcpy(bookName,readSting());
           
            printf("Author Name: ");
            strcpy(authorName,readSting());
           
            book *newBook = NULL;
            newBook = malloc(sizeof(book));

            newBook->book_id = book_to_edit->book_id;
            strcpy(newBook->book_name, bookName);
            strcpy(newBook->author_name, authorName);
        
            result = updateBook(newBook);

            free(book_to_edit);
     
        }
              
        return result;

}


int removeBook()
{
        char bookName[30], authorName[30];
        int result = 0;

        book *book_to_delete = searchBook();
        if(book_to_delete != NULL)
        { 
            printf("Deleted Book Details \n");
            printf("~~~~~~~~~~~~~~~~ \n");

            printf("\nBook_Id: %d\nBook_name: %s\nBook_Author: %s", book_to_delete->book_id, book_to_delete->book_name, book_to_delete->author_name);
        
            result = deleteBook(book_to_delete);

            free(book_to_delete);
     
        }
        
              
        return result;

}




