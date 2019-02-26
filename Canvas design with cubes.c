#include <stdio.h>
#include <string.h>
#define MAXX 20
#define MAXY 20

int canvas[MAXX][MAXY];            /*Canvas*/

/*Function used to read commands from user*/
char *process_input(char *buffer, int size);
/*Function used to define 1 square*/
int define_rect(char *t, int *rect);


/*Printing canvas: prints number of cubes in every cell*/
void print_canvas()
{	
	int i,j;
	for (i=0; i<MAXX; i++)
	{
		for (j=0; j<MAXY; j++)
			printf("%d",canvas[i][j]);
		printf("\n");
	}
}


/*Function thats adds 1 cube in every cell of area defined*/
void add_layer(int x1, int y1, int x2, int y2)
{
	int i,j;
	for (i=MAXY-y2; i<=MAXY-y1; i++)
	{
		for (j=x1-1; j<=x2-1; j++)
			canvas[i][j]++;
	}
		
}


/*Function that returns 0 when there is at least 1 cell with no cube. Else returns 1*/
int pop_layer(int x1, int y1, int x2, int y2)
{
	int i,j,pop,s=0,t=0; /*Counter s counts amount of cells that defines given area and is compared with counter t 
that counts amount of cells that contains cube in given area*/
	for (i=MAXY-y2; i<=MAXY-y1; i++)
	{
		for (j=x1-1; j<=x2-1; j++)
		{
			s++;
			if (canvas[i][j]>0)
			{
				t++;
			}	
		}	
	}
	if (s!=t)
	{
		pop=0;
	}
	else
	{
	 	for (i=MAXY-y2; i<=MAXY-y1; i++)
		{
			for (j=x1-1; j<=x2-1; j++)
				canvas[i][j]--;
		}
		pop=1;	
	}		
	return pop;
}


/*Returns amount of cubes in given area*/
int query_canvas(int x1, int y1, int x2, int y2)
{
	int i,j,number=0;
	for (i=MAXY-y2; i<=MAXY-y1; i++)
	{
		for (j=x1-1; j<=x2-1; j++)
			number=number + canvas[i][j];
	}
	return number;		
}


int main(void)
{
	char text[50] = {0};
	int  rect[4] = {0};                   /* Coordinates for rectangular*/
	int  ncubes, allow_pop;

	while (*text != '0') {
		puts("Give command (\"0\" for exit): ");
		if (process_input(text, sizeof(text)) != NULL) {
		    /*User gave known command, read square*/
			if (define_rect(text, rect)  != 0) {
				switch (text[0]) {
					case 'q':        /*Command 'q' */
						ncubes = query_canvas(rect[0], rect[1], rect[2], rect[3]);
						printf(">>>Arithmos kybwn sthn perioxh: %d\n", ncubes);
						break;
					case '+' :       /* Command '+' */
						add_layer(rect[0], rect[1], rect[2], rect[3]);
						break;
					case '-' :       /*Command '-' */
						allow_pop = pop_layer(rect[0], rect[1], rect[2], rect[3]);
						if (!allow_pop)
							printf(">>>Lathos: adynati i afairesh kybwn apo tin perioxi\n");
						break;
					case '0' :       /*Command 0 */
						break;
					default:
						printf(">>>Wrong command, give '+' to add, '-' to remove, 'q' to question\n");
				}
			}
		}
		print_canvas();        /*Printing cubes*/
	}
	return 0;
}


/*Function to read commands of user*/
char *process_input(char *buffer, int size)
{
	if (buffer != NULL) {
		if (fgets(buffer, size, stdin) != NULL) {
			char *newline = strchr(buffer, '\n');
			if (newline != NULL)   /*less than 'size' - 1 characters */
				*newline = '\0';
			else {   /*inserted more than 'size' -1 characters*/
				for (;;) {
					int ch = getchar();
					if (ch == EOF)
						return NULL;
					if (ch == '\n')
						break;
				}
			}
		}
	}
	return buffer;
}


/*Function to define rectangular area*/
int define_rect(char *t, int *rect)
{
	int i = 0;
	char *pch;

	pch = strtok(t, " ");
	while (pch != NULL) {
		if (i > 4)
			break;
		else {
			if (i != 0)
				rect[i - 1] = atoi(pch);
			i++;
		}
		pch = strtok(NULL, " ");
	}
	if (i != 5){
		printf(">>>Wrong number of coordinates\n");
		return 0;
	}
	if (rect[0] > MAXX || rect[2] > MAXX || rect[1] > MAXY || rect[3] > MAXY) {
		printf(">>>Wrong, rectangular out of bounds\n");
		return 0;
	}
	if (rect[0] > rect[2] || rect[1] > rect[3]) {
		printf(">>>Wrong, values doesn't define rectangular\n");
		return 0;
	}
	return 1;
}
