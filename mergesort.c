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

struct node* merge(struct node* l1,struct node* l2)
{
   struct node dummy;
   struct node* tail=&dummy;
   dummy.next=NULL;
   l1=l1->next;
   while(l1!=NULL && l2!=NULL)
   {
       if(l1->d<=l2->d)
       {
           tail->next=l1;
           l1=l1->next;
       }
       else
       {
           tail->next=l2;
           l2=l2->next;
       }
       tail=tail->next;
       
   }
   if(l1!=NULL)
   {
       tail->next=l1;
   }
   else
{
       tail->next=l2;
}
return dummy.next;
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
     for(int i=6;i<=10;i++)
    {
        insertatend(l2,i);
    }
    
    display(l1);
    display(l2);
    struct node*m=merge(l1,l2);
    display(m);
    return 0;
}
