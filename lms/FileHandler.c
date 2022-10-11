
int writeBook(book *bookObj)
{
	FILE *fp = NULL;
	fp = fopen(lmsBookData, "ab+");

	if (fp == NULL)
	{
		return 0;
	}
	else{

		fwrite(bookObj, sizeof(book), 1, fp);
		fclose(fp);
		return 1;
	}

}

int updateBook(book *updateBookObj)
{
    
    FILE *fp = NULL;
    FILE *fu = NULL;

    fp = fopen(lmsBookData, "rb");
    fu = fopen(lmsTempData, "wb");

    if (fp == NULL || fu == NULL )
    {
            return 0;
    }
    else{

        rewind(fp);

        book *no_change__book = (book*)malloc(sizeof(book));
        
        while (fread(no_change__book, sizeof(book), 1, fp) == 1)
        {
            if (updateBookObj->book_id != no_change__book->book_id)
            {
                fwrite(no_change__book, sizeof(book), 1, fu);
            }else
            {
                fwrite(updateBookObj, sizeof(book), 1, fu);
            }

        }
        fclose(fp);
        fclose(fu);
        free(no_change__book);

        remove(lmsBookData);
        rename(lmsTempData,lmsBookData);

        return 1;
     
    }

}

int deleteBook(book *discardBookObj)
{
    
    FILE *fp = NULL;
    FILE *fu = NULL;

    fp = fopen(lmsBookData, "rb");
    fu = fopen(lmsTempData, "wb");

    if (fp == NULL || fu == NULL )
    {
            return 0;
    }
    else{

        rewind(fp);

        book *keep_book = (book*)malloc(sizeof(book));
        
        while (fread(keep_book, sizeof(book), 1, fp) == 1)
        {
            if (discardBookObj->book_id != keep_book->book_id)
            {
                fwrite(keep_book, sizeof(book), 1, fu);
            }

        }
        fclose(fp);
        fclose(fu);
        free(keep_book);

        remove(lmsBookData);
        rename(lmsTempData,lmsBookData);

        return 1;
     
    }

}


book* getBook(int id)
{
    
    FILE *fp = NULL;
    fp = fopen(lmsBookData,"rb");
    book *book_to_find = NULL;
    if(fp == NULL)
    {
       return book_to_find;
    }
    else{
    
        book_to_find = (book*) malloc(sizeof(book));

        while(fread(book_to_find,sizeof(book),1,fp))
        {
            if(book_to_find->book_id == id)
            {
                fclose(fp);
                return book_to_find;
            }
        }
        
        fclose(fp);
        return book_to_find;
    }
}



//book* getAllBooks()
void getAllBooks(int totalBookcount)
{
    FILE *fp = NULL;
    fp = fopen(lmsBookData,"rb");
    book *book_to_find = NULL;
    
     //book *books = malloc(sizeof(book) * totalBookcount);
     book *books[totalBookcount];
    
     if(fp != NULL)
     {
     
       book_to_find = (book*) malloc(sizeof(book));

       printf("\n\t\t\t\t\tBook Details \t\t\t\t\n");
       printf("\n***********************************************************************************\n");

       for(int i=0;i<totalBookcount;i++)

        //while(fread(book_to_find,sizeof(book),1,fp))
        {       fread(book_to_find,sizeof(book),1,fp);
                books[i] = book_to_find;
                 printf("\nBook_Id : %d\t\tBook_name : %s\t\tBook_Author: %s",books[i]->book_id,books[i]->book_name,books[i]->author_name);
                 
        }
        printf("\n***********************************************************************************\n");

   
        fclose(fp);
        //return books;
    }
}




