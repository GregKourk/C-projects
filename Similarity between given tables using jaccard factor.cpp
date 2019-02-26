#include <stdio.h>
#include <stdlib.h> /*Library to accept command system*/

#define M 5 /*ÁTable's colun number*/

void read_set_collection(int Set_Collection[][M], int size);
double jaccard_coefficient(int Set_Collection[][M], int size, int row1, int row2);
void set_clustering(int Set_Collection[][M],int size);

int main()
{
	system("chcp 1253>nul"); /*Display greek characters*/
	int size=4, array[size][M]; /*Defining numbers of sets and tables*/
	read_set_collection(array, size); /*Function call to put values into table*/
	set_clustering(array, size); /*Function call to merge*/
	return 0;
}

void read_set_collection(int Set_Collection[][M], int size)
{
	int i,j;
	for (i=0; i<size; i++)
	{
		printf("Give elements of set s%d\n",i);
		for (j=0; j<M; j++)
		{
			do /*Defensive programming for right table input values*/
			{
				printf("Does element %d belongs to the set s%d;(0 (NO) , 1 (YES)):",j,i);
				scanf("%d",&Set_Collection[i][j]);
			} 
			while (Set_Collection[i][j]!=0 && Set_Collection[i][j]!=1);
		}
	}
	printf("\nTable is:\n"); 
	for (i=0; i<size; i++) /*Printing inputed table*/
	{
		for (j=0; j<M; j++)
		{
			printf("%d\t",Set_Collection[i][j]);
		}
		printf("\n");
	}
}

void set_clustering(int Set_Collection[][M],int size)
{
	int i,l,z,w,j;
	double max,jaccard;
	printf("\nMerging results:");
	while (size>1) /*While table has size>1*/
	{
		max=0;
		for (i=0; i<size; i++)
		{
			for (l=i+1; l<size; l++)
			{	
				jaccard = jaccard_coefficient(Set_Collection,size,i,l); /*Function call for finding jaccard factor and saving it to jaccard variable*/
				if (jaccard>max) /*Finding max factor and rows than involves*/
				{
					max=jaccard;
					z=i;
					w=l;
				}
				if (jaccard==max) /*If jaccard factor same with max*/
				{
					if (i>z) /*Choose row pair with greater k*/
					{
						z=i;
						w=l;
					}
					else
					{
						if (l>w) /*Choosing row pair with same k and greater l*/
						{
							z=i;
							w=l;
						}
					}
				}
			}				
		}
		for (j=0; j<M; j++) /*Merge 2 sets with max factor*/
		{
			
			if (Set_Collection[z][j]==1||Set_Collection[w][j]==1)
			{
				Set_Collection[z][j]=1;
			}
		}
		for (l=w+1; l<size; l++) /*Moving rows 1 position up*/
		{	
			for (j=0; j<M; j++)
			{
				Set_Collection[l-1][j]=Set_Collection[l][j];
			}
		}
		printf("\nSet in rows %d êáé %d, with similarity value %f are merging and result is saving in row %d.\n",z,w,max,z);
		printf("Table is:\n");
		for (z=0; z<size-1; z++) /*Printing new table*/
		{
			for (j=0; j<M; j++)
			{
				printf("%d\t",Set_Collection[z][j]);
			}
			printf("\n");
		}
		size--; /*Decreasing table size by 1*/
	}
}

double jaccard_coefficient(int Set_Collection[][M], int size, int row1, int row2) /*Function calculating jaccard factor*/
{
	int j,t=0,e=0;
	double jac;
	for (j=0; j<M; j++)
		{
			if (Set_Collection[row1][j]==1&&Set_Collection[row2][j]==1) /*Finding element number of section*/
			{
				t++;
			}
			
			if (Set_Collection[row1][j]==1||Set_Collection[row2][j]==1) /*Finding element number of union*/
			{
				e++;
			}
				
		}
	if (e==0&&t==0)/*If both sets are empty*/
	{
		jac=1;
	}
	else
	{	
	jac = (double)t/e; /*Calculating jaccard factor*/
	}
	return jac;
}
