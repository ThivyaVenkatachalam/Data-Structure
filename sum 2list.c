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

void sum(struct node* l1,struct node* l2)
{
   int carry=0;
   struct node*temp1=l1->next;
   struct node*temp2=l2->next;
   
   while(temp1!=NULL || temp2!=NULL || carry!=0)
   {
     if(temp1!=NULL)
     {
        carry=carry+temp1->d; 
        temp1=temp1->next;
     }
     if(temp2!=NULL)
     {
         carry=carry+temp2->d;
         temp2=temp2->next;
     }
     printf("%d\t",carry%10);
     carry=carry/10;
       
   }
}

int main()
{
    int n;
    scanf("%d",&n);
    struct node* l1=create();
    struct node* l2=create();
    
    for(int i=1;i<=n;i++)
    {
        insertatend(l1,i);
    }
     for(int i=1;i<=n;i++)
    {
        insertatend(l2,i);
    }
    
    display(l1);
    display(l2);
    sum(l1,l2);
    return 0;
}
