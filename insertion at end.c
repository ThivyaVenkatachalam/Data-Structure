#include <stdio.h>
#include<stdlib.h>

 struct node {
     int d;
     struct node *next;
 }; 
 
  struct node * create()
  {
      struct node *head;
      head=(struct node*)malloc(sizeof(struct node));
      head->next=NULL;
      return head;
  }
  
  
  void insert(struct node *head, int e)
  {
    struct node * last=head;
    while(last->next!=NULL)
    {
        last=last->next;
    }
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->d=e;
    newnode->next=NULL;
    last->next=newnode;
  }
  
  
  void display(struct node *head)
  {
      struct node * temp=head->next;
      while(temp!=NULL)
      {
          if(temp->d%5==0)
          {
              printf("%d \n" , temp->d);
          }
          temp=temp->next;
      }
  }
  
  int main()
  {
      struct node *head= create();
      for(int i=1;i<=100;i++)
      {
          insert(head,i);
      }
      display(head);
      return 0;
  }
  
