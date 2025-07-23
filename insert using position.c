#include<stdio.h>
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

void insertusingposition(struct node* head,int e,int pos)
{
    struct node* prev=head;
    int i=0;
    while(i<(pos-1) && prev!=NULL )
    {
        prev=prev->next;
        i++;
    }
    if(prev==NULL)
    {
        printf("size exceeded\n");
    }
    else
    {
        struct node* newnode;
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->d=e;
        newnode->next=prev->next;
        prev->next=newnode;
    }
}

void display(struct node* head)
{
    struct node* temp=head->next;
    while(temp!=NULL)
    {
        printf("%d\t",temp->d);
        temp=temp->next;
    }
}

int main()
{
    struct node* head = create();
    insertusingposition(head,1,1);
    insertusingposition(head,2,4);
    insertusingposition(head,3,2);
    insertusingposition(head,4,2);
    insertusingposition(head,5,4);
    insertusingposition(head,6,7);
    display(head);
    return 0;
}




