#include <stdio.h>
#include <stdlib.h>

/*Data type for list nodes*/
typedef struct node {
	int digit;
	struct node *next;
} listnode_t;

listnode_t *create_list(int numdigits);							/*list creation*/
void print_number(listnode_t *head); 							/*print number of list head*/
listnode_t *int_to_list(int num);								/*integer conversiot to list*/
listnode_t *add_lists(listnode_t *head1, listnode_t *head2);	/*adding numbers that are represented by lists*/


int main(int argc, char** argv) 
{
	system("chcp 1253>nul"); /*Greek characters*/
	listnode_t *number1, *number2, *result;

	printf("Give first positive integer number by digit\n");
	number1 = create_list(3);
	printf("Give second positive integer number by digit\n");
	number2 = create_list(5);
	
	/*Adding numbers with lists*/
	result = add_lists(number1,number2);


	/*Printing numbers*/
	printf("First number is: ");
	print_number(number1);
	printf("\n");
	
	printf("Second number is: ");
	print_number(number2);
	printf("\n");
	
	/*Printing sum of numbers*/
	printf("Sum of numbers is: ");
	print_number(result);
	printf("\n\n");
	
	/*Converting integers into lists and print numbers*/
	number1 = int_to_list(100);
	print_number(number1);
	printf("\n");
	
	number1 = int_to_list(1024);
	print_number(number1);
	printf("\n");
	
	number1 = int_to_list(9812545);
	print_number(number1);
	printf("\n");
	
	return 0;
}


/*Function gets input a positive integer that represents length of number in digits. 
 *Function asks from user to insert number by-digit. Returns pointer to the first node of list.*/
listnode_t *create_list(int numdigits) 
{
    int x=0,y; /*Counter x is used to execute as many repeats as digits of number*/
    listnode_t * cur, * header; /*Pointer header is used to know head of list and cur is list's node */
    header = NULL;
    while (x < numdigits)
    {
    	do /* Defensive programming for right values input*/
    	{
    		scanf("%d", &y);
    		if (y<0 || y>9)
    		{ 
				printf("Number must be between 0 and 9\n");
			}
		}
    	while (y<0 || y>9);
    	x++;
    	cur = (listnode_t *)malloc(sizeof(listnode_t)); /*Creating reverse list*/
    	if (cur==NULL) /*Defensive programming*/
   			{
   				printf("Unefficient memory!!\n");
   				exit(-1);
   			}
      	cur->digit = y;
      	cur->next  = header; 
      	header = cur;
	}
	return (header); /*Return list header*/
}


/*Function that prints number that is saved into list. starting from MSB to LSB*/
void print_number(listnode_t *head) 
{
    listnode_t * cur, *prev, *next;
    cur = head;
    prev=NULL;
    while (cur!=NULL) /*Reversing list*/
    {
    	next=cur->next;
    	cur->next = prev;
    	prev = cur;
    	cur = next;
	}
	head=prev;
    if (head==NULL) /*If list is null print message*/
    	printf("List is empty.");
    while (head!=NULL) /* Printing list*/
    {
    	printf("%d ",head->digit);
    	head = head->next;
	}
}


/*Function that gets a positive integer and tranformes it into list representation. Returns pointer of list header. */
listnode_t *int_to_list(int num) 
{	
	int x;
	listnode_t * cur, * header, *temp; /*Pointer header is used to know list's head, temp is pointer to move through list and cur is list's node*/
	header = NULL;
    while (num>0) /*While number> 0 */
    {
    	x=num%10; /* Finding LSB, which is the rest of number*/
    	if (header==NULL) /*If list is null create list's header*/
    	{
    		cur = (listnode_t *)malloc(sizeof(listnode_t)); 
    		if (cur==NULL) /*Defensive programming*/
   			{
   				printf("Unefficient memory!!\n");
   				exit(-1);
   			}
    		cur->digit = x;
   			cur->next  = NULL; 
    		header = cur;
    		temp = cur;	
		}
		else /* If list in not null, create rest of the list */
		{
			cur = (listnode_t *)malloc(sizeof(listnode_t));
			if (cur==NULL) /*Defensive programming*/
   			{
   				printf("Unefficient memory!!\n");
   				exit(-1);
   			}
      		cur->digit = x;
			cur->next = NULL;
			temp->next = cur;
			temp = cur;	
		}
		num=num/10; /*Divine with 10 in order to decrease digits of number by 1 by LSB */
	}
	return (header); /*Return list's header*/
}


/*Function gets 2 pointers in the first nodes of 2 lists,adds numbers by-digit kai stores result into new list. 
  Returns pointer of first node from new list.*/
listnode_t *add_lists(listnode_t *head1, listnode_t *head2) 
{	
    int sum=0, carry=0, x, y; 
    listnode_t *cur, *header, *temp; /*Pointer header is used to know start of list, temp is pointer to go through list and cur is list's node*/
    header=NULL;
    while (head1!= NULL || head2!= NULL) /*While there is at least 1 list*/
    {
    	x=0;
    	y=0;
		if (head2!=NULL)
		{
			y = head2->digit;
		}
		if (head1!=NULL)
		{
			x = head1->digit;
		}
		sum = x + y + carry;
		if (sum>=10) /*If sum>10 we have carry for next addition and we decrease addition by 1 digit*/
		{
			carry = 1;
			sum=sum%10;
		}
		else
		{
			carry = 0;
		}
		if (header==NULL) /*If list is null create list header*/
    	{
    		cur = (listnode_t *)malloc(sizeof(listnode_t));
			if (cur==NULL) /*Defensive programming*/
   			{
   				printf("Unefficient memory!!\n");
   				exit(-1);
   			}
    		cur->digit = sum;
   			cur->next  = NULL; 
    		header=cur;
    		temp=cur;	
		}
		else /*If list is not null vreate rest of nodes*/
		{
			cur = (listnode_t *)malloc(sizeof(listnode_t));
			if (cur==NULL) /*Defensive programming*/
   			{
   				printf("Unefficient memory!!\n");
   				exit(-1);
   			}
      		cur->digit = sum;
			cur->next = NULL;
			temp->next = cur;
			temp = cur;
		}
		if(head1!=NULL) /*If there is node we move on to the next*/
			head1 = head1->next;
		if(head2!=NULL) /*If there is node we move on to the next*/
			head2 = head2->next;
	}
	if (carry>0) /*If carry after last additionis >1 we create node that has value last carry */
	{
		cur = (listnode_t *)malloc(sizeof(listnode_t));
		if (cur==NULL) /*Defensive programming*/
   		{
   			printf("Unefficient memory!!\n");
   			exit(-1);
   		}
   		cur->digit = carry;
		cur->next = NULL;
		temp->next = cur;
		temp = cur;
	}
	return (header); /*Return list header*/	
}
