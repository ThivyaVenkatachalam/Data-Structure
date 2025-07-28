#include <stdio.h>
#include<stdlib.h>

struct node{
    int d;
    struct node* next;
};

struct node* create()
{
    struct node* head;
    head=(struct node*)malloc(sizeof(struct node));
    head->next=NULL;
    return head;
}
void insertatbeginning(struct node*head, int n)
{
   struct node *newnode = (struct node*)malloc(sizeof(struct node));
   newnode->d=n;
   newnode->next=head->next;
   head->next=newnode;
}
void display(struct node* head)
{
    struct node*temp=head->next;
    while(temp!=NULL)
    {
        printf("%d\n",temp->d);
        temp=temp->next;
    }
}
void deleteatbeginning(struct node* head)
{
    
    if(head->next!=NULL)
    {
      struct node* temp=head->next;  
      head->next= head->next->next;
      free(temp);
      printf("deleted");
    }
    else
    {
        printf("list is empty");
    }
}

int main()
{

    struct node* head=create();
    insertatbeginning(head,1);
    insertatbeginning(head,2);
    insertatbeginning(head,3);
    insertatbeginning(head,4);
    insertatbeginning(head,5);
    display(head);
    deleteatbeginning(head);
    
    return 0;
}
