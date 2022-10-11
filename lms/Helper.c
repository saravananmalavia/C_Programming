// function to get the input from the console

char* readSting()
{
	 char temp;
	 char *stringInput  = malloc(30);

	 scanf("%c",&temp); 
     scanf("%[^\n]",stringInput);

     return stringInput;
}


int readInteger(){
	  int intValue;
	  scanf("%d", &intValue);

	  return intValue;
}