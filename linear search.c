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
void insert(struct node*head,int pos,int n)
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
        struct node *newnode = (struct node*)malloc(sizeof(struct node));
        newnode->d=n;
        newnode->next=prev->next;
        prev->next=newnode;
    }
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
void search(struct node* head,int n)
{
    
    if(head->next==NULL)
    {
        printf("list is empty");
    }
    else{
        struct node*temp=head->next;
        int i=0;
        while(temp->next!=NULL&&temp->d!=n)
        {
            temp=temp->next;
            i++;
        }
        if(temp->next==NULL)
        {
            printf("NOT FOUND");
            
           
        }
        else
        {
            printf("ELEMENT FOUND AT %d",i+1);
        }
        
    }
}

int main()
{

    struct node* head=create();
    insert(head,1,1);
    insert(head,2,2);
    insert(head,3,3);
    insert(head,4,4);
    insert(head,5,5);
    display(head);
    search(head,3);
   
    
    return 0;
}
