#include <stdio.h>
#include <stdlib.h> /*Library to accept command system*/

int main()
{
	system("chcp 1253>nul"); /*Display greek characters*/
	int A,B,C,x,y;
	do /*Defensive programming for right input of A,B,C*/
	{
		printf("Give numbers for inouts A,B,C of logic circuit(only 0 or 1 allowed):\n");
		scanf("%d %d %d", &A, &B, &C);	
	}
	while ((A!=0&&A!=1)||(B!=0&&B!=1)||(C!=0&&C!=1));
	printf("\n Output is: %d",(A^B)^C);
	return 0;
}
