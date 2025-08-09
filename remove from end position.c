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
 
void insertatend(struct node* head , int e)
{ 
    struct node* last=head;
    while(last->next!=NULL)
    {
        last=last->next;
    }
    struct node* newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->d=e;
    newnode->next=NULL;
    last->next=newnode;
}

void display (struct node* head)
{
    struct node* temp=head->next;
   
    while(temp!=NULL)
    {
        printf("%d\t",temp->d);
        temp=temp->next;
        
    }
    
}
int len (struct node* head)
{
    struct node* temp=head->next;
    int size=0;
    while(temp!=NULL)
    {
        
        temp=temp->next;
        size++;
        
    }
    return size;
    
}
void delete(struct node* head,int size,int pos)
{
    
    if(pos>size || pos<0)
    {
        printf("invalid");
        return;
    }
    struct node*prev=head;
    pos=size-pos+1;
    int i=0;
    while(i<(pos-1)&&prev->next!=NULL)
    {
        prev=prev->next;
        i++;
    }
    if(prev==NULL)
    {
        printf("empty");
    }
    else
    {
        struct node*t=prev->next;
        prev->next=prev->next->next;
        free(t);
    }
}
int main()
{
    int n,pos;
    scanf("%d",&n);
    struct node* head=create();
    for(int i=1;i<=n;i++)
    {
        insertatend(head,i);
    }
    int size=len(head);
    display(head);
    printf("Enter the pos to delete the element:");
    scanf("%d",&pos);
    delete(head,size,pos);
    display(head);
    return 0;
}
