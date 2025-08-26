#include <stdio.h>
#include<stdlib.h>
struct node{
    int d;
    struct node* next;
};
struct node* create ()
{
    struct node* head;
    head=(struct node*)malloc(sizeof(struct node));
    head->next=NULL;
    return head;
}
void enqueue (struct node* head,int e)
{
    struct node* last=head;
    while(last->next!=NULL)
    {
        last=last->next;
    }
    struct node* nn=(struct node*)malloc(sizeof(struct node));
    nn->d=e;
    nn->next=NULL;
    last->next=nn;
}
void dequeue (struct node* head)
{
    if(head->next!=NULL)
    {
        printf("%d",head->next->d);
        struct node*t=head->next;
        head->next=head->next->next;
        free(t);
    }
    else
    {
        printf("list is empty");
    }
}
void display(struct node* head)
{
    struct node*t=head->next;
    if(t==NULL)
    {
        printf("there are no students in the queue");
    }
    while(t!=NULL)
    {
        printf("%d\t",t->d);
        t=t->next;
    }
    
}
void peek(struct node* head)
{
    if(head->next!=NULL)
    {
        printf("\nthe student next to be boarded : %d\t",head->next->d);
    }
    else
    {
        printf("\nthere are no students");
    }
    
}
void length(struct node* head)
{
    struct node*t=head->next;
    int i=0;
    while(t!=NULL)
    {
        i++;
        t=t->next;
    }
    printf("\nlength of the queue: %d",i);
}
void isempty(struct node*head)
{
    if(head->next!=NULL)
    {
        printf("\nSome has yet to be boarded");
    }
    else
    {
        printf("\nAll the students boarded successfully");
    }
}
int main()
{
    struct node*head=create();
    int j,a;
    printf("\n1.Enqueue students");
        printf("\n2.Display students in the queue");
        printf("\n3.Students boarded");
        printf("\n4.Student next in the queue");
        printf("\n5.Length of the queue");
        printf("\n6.Queue is empty or not");
        printf("\n7.Exit");

    
    while(1)
    {
        printf("\nEnter your choice:");
        scanf("%d",&a);
        switch(a)
        {
            case 1:
            int j;
            printf("Enter student id: ");
            scanf("%d",&j);
            enqueue(head,j);
            break;
            
            case 2:
            printf("Students waiting in the queue: ");
            display(head);
            break;
            
            case 3:
            printf("\nThe students boarded:\n");
            dequeue(head);
            break;
            
            case 4:
            peek(head);
            break;
            
            case 5:
            length(head);
            break;
            
            case 6:
            isempty(head);
            break;
            
            case 7:
            return 0;
        }
    }
   
    return 0;
}
