#include <stdio.h>
#include <stdlib.h> /*Library to accept command system*/
#include <string.h>

#define n 5 /*Structure elements count*/

struct tickets{
	char name[20];
	float price;
};	

int main()
{
	system("chcp 1253>nul"); /*Display greek characters*/
	int choice,number,amount,ikerma,i;
	float kerma,change,value,antitimo,ypoloipo;
	struct tickets ticket[n]; /*initializing structure's values*/
 	strcpy(ticket[0].name, "Full");
 	ticket[0].price=1.40;
 	strcpy(ticket[1].name, "Reduced");
 	ticket[1].price=0.60;
 	strcpy(ticket[2].name, "Daily");
 	ticket[2].price=4.50;
 	strcpy(ticket[3].name, "Weekly");
 	ticket[3].price=9.00;
 	strcpy(ticket[4].name, "Airport");
 	ticket[4].price=10.00;
 	
   	do  /*Defensive programming for right ticket selection from user and option printing*/
   	{
		printf("Please choose one of the following:\n\n");
		for (i=0; i<n; i++)
		{
			printf("%d. %s %2.2f ευρώ\n",i,ticket[i].name,ticket[i].price);
		}
       	printf(" \nPlease put your choice: "); 
       	scanf("%d", &choice);
    }
   	while ( choice < 1 || choice > 5);
   	do /*Defensive programming for ticket number selection*/
   	{
   		printf("\nNumber of tickets:");
   		scanf("%d",&number);	
	}
	while (number<1); 
    switch (choice) /* Matching user selection's with price */
    {
    	case 1:
    		antitimo = 140;
     	break;
       	case 2:
   			antitimo = 60;
       	break;
       	case 3:
   			antitimo = 450;
       	break;
       	case 4:
   			antitimo = 900;
       	break;
       	case 5:
   			antitimo = 1000;
       	break;
	}
	value=antitimo*number; /*Calculating total ticket's cost*/
    amount = 0;
	while (amount < value) /*While user has not entered more money than required*/
    {
   		 do /*Defensive programming for acceptable ammount input from user*/
		{
       		ypoloipo=value-amount;
        	printf("\n\nYou must enter %3.2f euro totally\n", (ypoloipo)/100);
        	printf("\nHow much do you enter; ");
        	scanf("%f", &kerma);
        	ikerma = kerma * 100;
        	if (ikerma!=5&&ikerma != 10 && ikerma != 20 && ikerma != 50 &&	ikerma != 100 && ikerma != 200 && ikerma != 500 && ikerma != 1000&&ikerma!=2000&&ikerma!=5000)
       		{
            	printf("\nInsert an acceptable value: 0.05 / 0.1 / 0.2 / 0.5 / 1 / 2 / 5 / 10 / 20 / 50 ");
            }
   		}
   		while (ikerma!=5&&ikerma != 10 && ikerma != 20 && ikerma != 50 && ikerma != 100 && ikerma != 200 && ikerma != 500 && ikerma != 1000&&ikerma!=2000&&ikerma!=5000);
		amount += ikerma;
	}
	change = amount - value; /* calculating change */
	printf("\nPlease take change %3.2f euro\n", change/100);

	return 0;
}
