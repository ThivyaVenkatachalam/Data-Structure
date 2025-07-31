#include <stdio.h>
#include<stdlib.h>
 
struct node{
    int d;
    struct node* prev;
    struct node* next;
};
 
struct node* create()
{
    struct node* head=(struct node*)malloc(sizeof(struct node));
    head->next=NULL;
    head->prev=NULL;
    return head;
}

void insert(struct node* head,int e)
{
    struct node* nn=(struct node*)malloc(sizeof(struct node));
    nn->d=e;
    nn->next=head->next;
    nn->prev=head;
    head->next=nn;
    if(nn->next!=NULL)
    {
        nn->next->prev=nn;
    }
}

void display(struct node* head)
{
    struct node* temp=head->next;
    while(temp->next!=NULL)
    {
        printf("%d",temp->d);
        temp=temp->next;
    }
}
int main()
{
    struct node* head=create();
    insert(head,3);
    insert(head,4);
    insert(head,5);
    display(head);

    return 0;
}
