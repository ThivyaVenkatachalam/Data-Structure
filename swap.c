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
struct node* swap(struct node* head,int size,int pos)
{
    int pos1=size-pos+1;
    if(pos>size || pos<0)
    {
        printf("invalid");
        return head;
    }
    if(pos==pos1)
    {
        return head;
    }
    if(pos>pos1)
    {
        int temp=pos;
        pos=pos1;
        pos1=temp;
    }
    struct node*prev1=head;
    struct node* prev2=head;
    struct node* nn1;
    struct node* nn2;
    for(int i=0;i<pos;i++)
    {
        prev1=prev1->next;
        nn1=prev1->next;
    }
    for(int i=0;i<pos1;i++)
    {
        prev2=prev2->next;
        nn2=prev2->next;
    }
    nn1->next=prev2->next;
    nn2->next=prev1->next;
    struct node* t=nn1->next;
    nn1->next=nn2->next;
    nn2->next=t;
    return head;
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
    struct node* l=swap(head,size,pos);
    display(l);
    return 0;
}
