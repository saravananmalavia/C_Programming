
int getTotalBookCount();
int getLastBookId();

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

book* getAllBooks()
{
    FILE *fp = NULL;
    fp = fopen(lmsBookData,"rb");
    book *book_to_find = NULL;

    int totalBookcount = getTotalBookCount();
    
    book *books = (book*) malloc(sizeof(book) * totalBookcount);
     
    if(fp != NULL)
    {
     
       book_to_find = (book*) malloc(sizeof(book));

       for(int i=0;i<totalBookcount;i++)
       {      
                fread(book_to_find,sizeof(book),1,fp);

                books[i].book_id = book_to_find->book_id;
                strcpy(books[i].book_name, book_to_find->book_name);
                strcpy(books[i].author_name, book_to_find->author_name);
 
        }
    
    fclose(fp);
        
    }

    return books;
}



// To get total no of books in the library

int getTotalBookCount()
{
    int count = 0;
    FILE *fp = NULL;
    fp = fopen(lmsBookData,"rb");
    book *book_to_find = NULL;
    if(fp != NULL)
    {
     
       book_to_find = (book*) malloc(sizeof(book));

        while(fread(book_to_find,sizeof(book),1,fp))
        {
                count ++;
        }

         fclose(fp);
       }

       return count;

}


int getLastBookId()
{
    int lastBookId = 0;
    FILE *fp = NULL;
    fp = fopen(lmsBookData,"rb");
    book *book_to_find = NULL;
    if(fp != NULL)
    {
     
       book_to_find = (book*) malloc(sizeof(book));

        while(fread(book_to_find,sizeof(book),1,fp))
        {
                lastBookId = book_to_find->book_id;
        }

         fclose(fp);
       }

       return lastBookId;

}





