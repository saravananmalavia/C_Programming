
#include "BookHandler.c"

int main()
{
	int id, choice, success;
	int indefinite = 1;

	char name[20], authorName[20];
	system("clear");  
	do{

			printf("\n\t\t\t\t\t\t*************** MAIN MENU ***************\n");
			printf("\n\t\t\t\t\t\t1. Add Book");
			printf("\n\t\t\t\t\t\t2. Remove Book");
			printf("\n\t\t\t\t\t\t3. Edit Book");
			printf("\n\t\t\t\t\t\t4. View All Books");
			printf("\n\t\t\t\t\t\t5. Search Book");
			printf("\n\t\t\t\t\t\t6. Close Application");
			printf("\n\t\t\t\t\t\t******************************************\n");
			printf("\n\t\t\t\t\t\tEnter your choice: ");
			scanf("%d", &choice);
			switch (choice)
			{
			case 1:
				
					success = addBook();
					if(success > 0 ) { 
						printf("\nBook added successfully with book id : %d \n", success);
					}else{
						printf("\nPlease try again later...\n");
					}
					break;

			case 2:
					success = removeBook();

					if(success > 0 ) { 
						printf("\nBook deleted successfully  \n");
					}else{
						printf("\nNo Book details found ...\n");
					}
					break;
				
			case 3:
					success = editBook();

					if(success > 0 ) { 
						printf("\nBook updated successfully \n");
					}else{
						printf("\nNo Book details found ...\n");
					}
					break;
				
			case 4:

					viewAllBooks();

				break;

			case 5:
					printf("\n");
					book *book_to_find = searchBook();
					if(book_to_find != NULL)
						{ 
							  printf("\nBook_Id: %d\nBook_name: %s\nBook_Author: %s", book_to_find->book_id, book_to_find->book_name, book_to_find->author_name);
							  free(book_to_find);
						}else{
							  printf("\nNo Book details found ...\n");
						}	
					break;

			case 6:
					printf("\n\n\n");
					exit(1);
			default:
					printf("\n\t\t\t\t\t\tInvalid input");
					break;
			}
	
	}while(indefinite > 0);

	return 0;
}
