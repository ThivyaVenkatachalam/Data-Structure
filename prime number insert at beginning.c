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
 
void insertatbeg(struct node* head , int e)
{ 
    struct node* newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->d=e;
    newnode->next=head->next;
    head->next=newnode;
    
}

void display (struct node* head)
{
    struct node* temp=head->next;
    while(temp!=NULL)
    {
        printf("%d\n",temp->d);
        temp=temp->next;
    }
    
}

int main()
{
    int n,i,j,count;
    scanf("%d",&n);
    struct node* head=create();
    for(i=2;i<=n;i++)
    {
        count=1;
       for(j=2;j<=i-1;j++)
       {
           if(i%j==0)
           {
               count=0;
               break;
           }
       }
       if(count==1)
       {
        insertatbeg(head,i);
       }
    }
    
    display(head);
    return 0;
}








