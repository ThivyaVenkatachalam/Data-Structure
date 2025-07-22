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
        printf("%d\n",temp->d);
        temp=temp->next;
    }
    
}

void sum(struct node* head)
{
    struct node*temp=head->next;
    int sum1=0,sum2=0;
    while(temp!=NULL)
    {
        if(temp->d%2==0)
        {
            sum1=sum1+temp->d;
        }
        else
        {
            sum2=sum2+temp->d;
        }
        temp=temp->next;
    }
    printf("the sum of even is %d\n",sum1);
    printf("the sum of odd is %d",sum2);
}

int main()
{
    int n;
    scanf("%d",&n);
    struct node* head=create();
    for(int i=1;i<=n;i++)
    {
        insertatend(head,i);
    }
    display(head);
    sum(head);
    return 0;
}








