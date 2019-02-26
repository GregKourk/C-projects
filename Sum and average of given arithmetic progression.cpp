#include<stdio.h>
#include <stdlib.h> /*Library to accept command system*/

struct list {
   int value;
   struct list * next;
};
typedef struct list item;

int main()
{
   system("chcp 1253>nul"); /*Display greek characters*/
   item * cur, * head;
   int i,N,w,x,average, sum=0;
   head = NULL;
   do /*Defensive programming for right input of arithmetic progression's terms*/
   {
   		printf("Give arithmetic prograssion's terms'(more than 1):\n");
   		scanf("%d",&N);
   }
   while (N<1);
   do /*Defensive programming for right arithmetic progression's step input*/
   {
   		printf("Give step(more than 1):\n");
   		scanf("%d",&w);
   }
   while (w<1);
   x=(1+w)+(N-2)*w; /*Finding last element of arithmetic progression*/
   for(i=0;i<N;i++) /*Putting elements into the start of list */
    {
      cur = (item *)malloc(sizeof(item));
      cur->value = x;
      cur->next  = head;
      head = cur;
      x-=w;
   }
   cur = head;
   while(cur) /*Finding sum of arithmetic progression's elements*/
   {
      sum =sum+ cur->value;
      cur= cur->next;
   }
   average=(sum/N); /*Finding arithmetic progression's elements average*/
   printf("%d\n",average);
   return 0;
}
