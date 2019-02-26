#include <stdio.h>
#include <stdlib.h> /*Library to accept command system*/

int main()
{
	system("chcp 1253>nul"); /*Display greek characters*/
	char c,display[26];
	int i;
	for (i=0;i<26;i++) /*Initialization frequency letter display table*/
		display[i]=0;
	printf("Give character sequency:");
	c=getchar();
	while (c!='\n')	/*While no enter character*/
	{
	if (c>64&&c<91) /*If character is capital letter*/
	{
		i=c-65;
		display[i]++; /*Increase by 1 table position correspondive to the capital letter that reads*/ 
	}
	else 
	{
		if (c>96&&c<123) /*If character is non capital letter*/
		{
			i=c-97;
			display[i]++; /*Increase by 1 table position correspondive to the non capital letter that reads*/
		}	
	}
	c=getchar();
	}
	printf("\nDisplay frequency:\n");	
	for (i=0;i<26;i++)
	{
		if (display[i]!=0) /*If character related to this table position hasn't shown will not be displayed*/
		{
			printf("%c->%d\n",i+'a',display[i]); /*Character display*/
		}	
	}
	return 0;
}

