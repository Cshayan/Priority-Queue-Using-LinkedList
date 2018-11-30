#include <stdio.h>
#include <stdlib.h>

struct node{

 int data;
 int priority;
 struct node *next;
}*start=NULL;

void push(int item, int pri)
{
    struct node *temp, *curr;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data= item;
    temp->priority= pri;
    temp->next=NULL;

    if(start==NULL)
    {
        start=temp;
        printf("\nInserted\n");
        return;
    }

    if(start->priority < pri)
    {
        temp->next=start;
        start=temp;
    }
    else
    {
        curr=start;
        while(curr->next!=NULL && curr->next->priority > pri)
        {
            curr=curr->next;
        }
        temp->next=curr->next;
        curr->next=temp;
    }
    printf("\nInserted\n");
}
int pop()
{
    if(start==NULL)
    {
        printf("\nEmpty queue\n");
        return -1;
    }
    struct node *temp;
    int val;

    temp=start;
    start=start->next;
    val=temp->data;
    free(temp);
    return val;
}
void display()
{
    if(start==NULL)
    {
        printf("\nEmpty queue\n");
        return;
    }
    struct node *curr;
    curr=start;
    printf("\nThe priority queue is:- \n");
    while(curr!=NULL)
    {
        printf("%d\t",curr->data);
        curr=curr->next;
    }
    printf("\n\n");
}
int main()
{
    int item, pri, ch, val;
    while(1)
    {
        printf("\n1.Push");
        printf("\n2.Pop");
        printf("\n3.Display");
        printf("\n4.Exit");
        printf("\nEnter the choice:- ");
        scanf("%d",&ch);
           switch(ch)
           {
               case 1:
                     printf("\nEnter the item and it's priority:- ");
                     scanf("%d%d",&item,&pri);
                     push(item, pri);
                     break;
               case 2:
                      val=pop();
                     if(val!=-1)
                     {
                         printf("\nPopped value is:- %d\n", val);
                     }
                     break;
               case 3:
                     display();
                     break;
               case 4:
                     exit(1);
           }
    }
    return 0;

}
