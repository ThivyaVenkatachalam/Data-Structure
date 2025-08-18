#include <stdio.h>
#include<stdlib.h>
struct node{
    int d;
    struct node* next;
};

void push(struct node*head, int n)
{
   struct node *newnode = (struct node*)malloc(sizeof(struct node));
   newnode->d=n;
   newnode->next=head->next;
   head->next=newnode;
}
void pop(struct node* head)
{
    
    if(head->next!=NULL)
    {
      printf("\nthe deleted element %d",head->next->d);
      struct node* temp=head->next;  
      head->next= head->next->next;
      free(temp);
    }
    else
    {
        printf("list is empty");
    }
}
void peek(struct node* head)
{
    if(head->next!=NULL)
    {
        printf("\nthe peek value %d",head->next->d);
    }
}
void display(struct node*head)
{
    struct node*t=head->next;
    printf("the pushed values in stack are ");
    while(t!=NULL)
    {
        printf("%d\t",t->d);
        t=t->next;
    }
}
int main()
{
    struct node*head= (struct node*)malloc((sizeof(struct node)));
    head->next=NULL;
    for(int i=1;i<=5;i++)
    {
         push(head,i);
    }
    display(head);
    pop(head);
    pop(head);
    peek(head);
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
