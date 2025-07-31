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

void insert(struct node* head,int pos,int e)
{
    struct node*prev=head;
    int i=0;
    while(i<(pos-1) && prev->next!=NULL)
    {
        prev=prev->next;
        i++;
    }
    if(prev==NULL)
    {
        printf("the size limit exceeds");
    }
    else
    {
       struct node* nn=(struct node*)malloc(sizeof(struct node));
       nn->d=e;
       nn->next=prev->next;
       nn->prev=prev;
       prev->next=nn;
       if(nn->next!=NULL)
        {
           nn->next->prev=nn;
        }
       
    }
    
}

void delete(struct node* head)
{
    if(head->next!=NULL)
    {
        struct node* t=head->next;
        head->next=head->next->next;
        head->next->prev=head;
        free(t);
    }
}

void display(struct node* head)
{
    struct node* temp=head->next;
    while(temp!=NULL)
    {
        printf("%d",temp->d);
        temp=temp->next;
    }
}
int main()
{
    struct node* head=create();
    insert(head,1,1);
    insert(head,1,2);
    insert(head,1,3);
    display(head);
    delete(head);
    display(head);

    return 0;
}
