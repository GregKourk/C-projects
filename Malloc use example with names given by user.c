#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ROWCOUNT 10         /* Initial/additional number of rows*/


int main()
{
	int i;
	char **names;      /*2-dimensiotal table of pointers to character pointers*/
	char tempname[50]; /*Table for temporary save of names. We register initial names to find their length 
						  and then register them into names[] */
	int name_length;   /*Lenth of every name that corresponds into size of 2nd dimension*/
	int number_of_names=0; /*Number of names counter of current 10*/
	int total_number_of_names=0; /*Total amount of names that will be stored. When amount overcrosses the number that can fit into table names, 
	                                space will be held for additional RowCount names*/

	system("chcp 1253>nul");    /*Greek characters*/


   names = (char**)malloc(ROWCOUNT*sizeof(char*));
   if (names==NULL) /*Defensive programming*/
   {
   	printf("Unefficient memory!!\n");
   	exit(-1);
   }
   int x=1; /*Counter that increases every time we want to bind more space*/
   i=0;
    printf("Παρακαλώ δώστε το πρώτο όνομα για εισαγωγή στον πίνακα \n");
	while (scanf("%s",tempname)>0)   /*While sentence exists (ends with CTRL-Z) */
	{		
		total_number_of_names++;
		number_of_names++;
		if (number_of_names > ROWCOUNT) /*Must increase 1st dimenion*/
		{  
			number_of_names = 1;
			x++; 
			names = (char**)realloc(names, (x*ROWCOUNT)*sizeof(char*)); /*Additional space binding for next 10 names into table names*/
			if (names==NULL) /*Defensive programming*/
			{
				printf("Unefficient memory!!\n");
				exit(-1);
			}
		}
			int len=strlen(tempname); /*Finding name length*/
			names[i] = (char*)malloc((len+1)*sizeof(char)); /*Binding as much space as needed for each name that is inserted included with null character*/
			if (names[i]==NULL) /*Defensive programming*/
			{
				printf("Unefficient memory!!\n");
				exit(-1);
			}
			strcpy(names[i], tempname); /*Name insertion*/
			i++;		
		printf("Give next name or press Ctrl-Z to end \n");     
	}
	names = (char**)realloc(names, total_number_of_names*sizeof(char*)); /*Bind as much space as total names that have been inserted*/
	printf("Τα ονόματα που δόθηκαν είναι:  \n"); /*Given names displayed*/
	for (i=0; i<total_number_of_names; i++)
	{
		printf("%s\n",names[i]);
	}
	system("pause");
	return(0);  
}
