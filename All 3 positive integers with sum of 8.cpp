#include <stdio.h>
#include <stdlib.h> /*Library to accept command system*/

int main()
{
	system("chcp 1253>nul"); /*Display greek characters*/
	int a=0,b=0,c=0;
	printf("Triads of possitive integers with sum of 8 are:\n");
	for (a=1; a<=8; a++)
	{
		for (b=1; b<=8; b++)
		{
			for (c=1; c<=8; c++)
			{
				if ((a+b+c)==8)
					printf("%d %d %d\n",a,b,c);
			}
				
		}
			
	}
	return 0;	
}
