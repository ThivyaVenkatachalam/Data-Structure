#include <stdio.h>
#include<stdlib.h>

struct node
{
    int d;
    struct node* next;
};

struct node* create()
{
    struct node* head= (struct node*)malloc(sizeof(struct node));
    head->next=NULL;
    return head;
}

void insertatbeg(struct node* head , int e)
{
    struct node* nn=(struct node*)malloc(sizeof(struct node));
    nn->d=e;
    nn->next=head->next;
    head->next=nn;
    
}

void insertatend(struct node* head,int e)
{
    struct node*last=head;
    while(last->next!=NULL)
    {
        last=last->next;
    }
    struct node* nn=(struct node*)malloc(sizeof(struct node));
    nn->d=e;
    nn->next=NULL;
    last->next=nn;
}

void insertatposition(struct node*head,int e, int pos)
{
    struct node* prev=head;
    int i=0;
    while(i<pos-1&&prev!=NULL)
    {
        prev=prev->next;
        i++;
    }
    if(prev==NULL)
    {
        printf("The Size Exceeds");
    }
    else
    {
        struct node* nn=(struct node*)malloc(sizeof(struct node));
        nn->d=e;
        nn->next=prev->next;
        prev->next=nn;
    }
}

void deleteatbeginning(struct node* head)
{
    if(head->next!=NULL)
    {
        struct node* t=head->next;
        head->next=head->next->next;
        free(t);
    }
    else
    {
        printf("List is Empty");
    }
}

void deleteatend(struct node* head)
{
    if(head->next!=NULL)
    {
        struct node* t=head;
        while(t->next->next!=NULL)
        {
            t=t->next;
        }
        struct node*temp=t->next;
        temp->next=NULL;
        free(temp);
    }
    else
    {
        printf("List is Empty");
    }
}

void deleteusingpos(struct node* head,int pos)
{
    if(head->next!=NULL)
    {
       struct node* prev=head;
    int i=0;
    while(i<pos-1&&prev->next!=NULL)
    {
        prev=prev->next;
        i++;
    }
    if(prev->next==NULL)
    {
        printf("The Size Exceeds");
    }
    else
    {
        struct node* t=prev->next;
        prev->next=prev->next->next;
        free(t);
    } 
    }
    else{
        printf("List is empty");
    }
}

void deleteusingelement(struct node* head,int e)
{
    if(head->next!=NULL)
    {
        struct node* prev=head;
    while(prev->next!=NULL&&prev->next->d!=e)
    {
        prev=prev->next;
    }
    if(prev->next==NULL)
    {
        printf("The element not found");
    }
    else
    {
        struct node* t=prev->next;
        prev->next=prev->next->next;
        free(t);
    }
    }
    else{
        printf("The list is empty");
    }
}

void display(struct node*head)
{
    struct node* temp=head->next;
    while(temp!=NULL)
    {
        printf("%d",temp->d);
        temp=temp->next;
    }
}

void length(struct node*head)
{
    struct node* t=head->next;
    int i=1;
    while(t!=NULL)
    {
        t=t->next;
        i++;
    }
    printf("The size is %d",i);
}

int main()
{
    struct node* head=create();
    while(1)
    {
        printf("1.insert at begining\n");
        printf("2.insert at end\n");
        printf("3.insert at position\n");
        printf("4.delete at beginning\n");
        printf("5.delete at end\n");
        printf("6.delete using position\n");
        printf("7.delete using element\n");
        printf("8.Size\n");
        printf("9.display");
        int n;
        scanf("%d",&n);
        switch(n)
        {
            case 1:
            for(int i=0;i<5;i++)
            insertatbeg(head,i);
            printf("elements inserted");
            break;
            
            case 2:
            for(int i=0;i<5;i++)
            insertatend(head,i);
            printf("elements inserted");
            break;
            
            case 3:
            for(int i=0;i<5;i++)
            insertatposition(head,i,i);
            printf("elements inserted");
            break;
            
            case 4:
            deleteatbeginning(head);
            printf("\nelements deleted");
            break;
            
            case 5:
            deleteatend(head);
            printf("\nelements deleted");
            break;
            
            case 6:
            deleteusingpos(head,1);
            printf("\nelements deleted");
            break;
            
            case 7:
            deleteusingelement(head,5);
            printf("\nelements deleted");
            break;
            
            case 8:
            length(head);
            break;
            
            case 9:
            display(head);
            break;
        }
    }
    return 0;
}













