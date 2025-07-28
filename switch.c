#include <stdio.h>
#include<stdlib.h>
struct node{
    int d;
    struct node* next;
};

void insertatbeginning(struct node*head, int n)
{
   struct node *newnode = (struct node*)malloc(sizeof(struct node));
   newnode->d=n;
   newnode->next=head->next;
   head->next=newnode;
}
void insertatend(struct node*head, int n)
{
   struct node*last=head;
   while(last->next!=NULL)
   {
       last=last->next;
   }
   struct node *newnode = (struct node*)malloc(sizeof(struct node));
   newnode->d=n;
   newnode->next=NULL;
   last->next=newnode;
}
void insertatposition(struct node*head,int pos,int n)
{
    struct node*prev=head;
    int i=0;
    while(i<(pos-1)&&prev!=NULL)
    {
        prev=prev->next;
        i++;
    }
    if(prev==NULL)
    {
       printf("exceeds limit");
    }
    else
    {
        struct node *newnode = (struct node*)malloc((sizeof(struct node));
        newnode->d=n;
        newnode->next=prev->next;
        prev->next=newnode;
    }
}
void deleteatbeginning(struct node* head)
{
    
    if(head->next!=NULL)
    {
      struct node* temp=head->next;  
      head->next= head->next->next;
      free(temp);
    }
    else
    {
        printf("list is empty");
    }
}
int main()
{
    int e,pos,n;
    struct node*head= (struct node*)malloc((sizeof(struct node));
    head->next=NULL;
    while(1)
    {
        printf("1");
        printf("2");
        printf("3");
        printf("4");
        printf("5");
        printf("6");
        printf("7");
        printf("8");
        scanf("%d",&);
         switch(n)
         {
             case 1:
             
         }
    }
}
