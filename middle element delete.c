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
void middle(struct node* head,int size)
{
    struct node*prev=head;
    if(head->next!=NULL)
    {
       if(size%2==0)
       {
           size=size/2;
           struct node*prev=head;
           int i=0;
           while(i<size)
           {
               prev=prev->next;
               i++;
           }
           struct node*temp=prev->next;
           prev->next=prev->next->next;
           free(temp);
       }
       else
       {
           size=size/2;
           struct node*prev=head;
           int i=0;
           while(i<size)
           {
               prev=prev->next;
               i++;
           }
           struct node*temp=prev->next;
       prev->next=prev->next->next;
       free(temp);
       }
       
       
       
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
    display(head);
    int size=len(head);
    middle(head,size);
    display(head);
    return 0;
}
