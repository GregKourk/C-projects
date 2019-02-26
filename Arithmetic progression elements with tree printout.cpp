#include <stdio.h>
#include <stdlib.h> /*Library to accept command system*/

int main()
{
	system("chcp 1253>nul"); /*Display greek characters*/
	int k,i,w,n,x=1;
	do /*Defensive programming for right sequence step input*/
	{
		printf("Give step:");
		scanf("%d",&w);
	}
	while (w<0);
	do /*Defensive programming for right number of rows input*/
	{
		printf("Give number of rows(1-10):");
		scanf("%d",&n);
	}
	while ((n<1||n>10));
	for (i=1; i<=n; i++) /*Print rows of sequences*/
	{
		for (k=1; k<=i; k++) /*Print elements of sequence in every line*/
		{
			printf("%d\t",x);
			x+=w;
		}
		printf("\n");
	}
	return 0;
}
