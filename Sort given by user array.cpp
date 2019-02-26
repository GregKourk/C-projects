#include<stdio.h>
#include <stdlib.h> /*Library to accept command system*/

#define N 4 /*Dimensions of initial 2-dimensiotal table/ 
#define M N*N /*Dimension of 1-dimensiotal table*/

void selection_sort(int Y[M]); /*Αλγόριθμος ταξινόμησης με επιλογή*/

int main()
{
	system("chcp 1253>nul"); /*Display greek characters*/
	int i,j,z=0,A[N][N],X[M];
	for (i=0; i<N; i++) /*Table data input*/
	{
		for (j=0; j<N; j++)
		{
			printf ("Give number of %d row and %d column:\n",i+1,j+1);
			scanf("%d",&A[i][j]);
		}
	}
	printf("\nInserted table is:\n");
	for (i=0; i<N; i++) /*Printing table by columns*/
	{
		for (j=0; j<N; j++)
			printf("%d\t",A[i][j]);
		printf("\n");			
	}
	for (i=0; i<N; i++) /*Creating new 1-dimensiotal table*/
	{
		for (j=0; j<N; j++)
		{
			X[z]=A[i][j];
			z++;
		}	
	}
	selection_sort(X); /*sorting function call*/
	printf("\nSorted table is:\n");
	for (z=0; z<M; z++) /*Printing sorted table*/
	{
		printf("%d\t",X[z]);		
		}	
	return 0;
}

void selection_sort(int Y[]) /*Sorting with selection algorithm*/
{
	int k,l,pos,swap;
	for (k=0; k<M; k++)
	{
		pos=k;
		for (l=k+1; l<M; l++)
		{
			if (Y[l]<Y[pos])
				pos=l;
		}
		if (pos!=k)
		{
			swap=Y[k];
			Y[k]=Y[pos];
			Y[pos]=swap;	
		}	
	}
}
