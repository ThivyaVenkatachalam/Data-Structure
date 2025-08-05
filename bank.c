#include <stdio.h>
#include<stdlib.h>
struct bank
{
    int acc;
    char name[20];
    int balance;
};
struct bank* insert(struct bank*sp,int*size,int*capacity)
{
    if(*size==*capacity)
    {
        *capacity=(*capacity)*2;
        sp=(struct bank*)realloc(sp,sizeof(struct bank)*(*capacity));
    }
    printf("Enter the acc no,name:");
    scanf("%d %s",&sp[*size].acc,sp[*size].name);
    (*size)++;
    return sp;
}
void deposit(struct bank*sp,int*size)
{
   int b,e;
   printf("Enter acc no:");
   scanf("%d",&b);
   printf("Enter the amount:");
   scanf("%d",&e);
   for(int i=0;i<*size;i++)
   {
       if(sp[i].acc==b)
       {
           sp[i].balance+=e;
           printf("AMOUNT ADDED\n");
       }
   }
}
void search(struct bank*sp,int*size)
{
   int e;
   printf("Enter acc no:");
   scanf("%d",&e);
   for(int i=0;i<*size;i++)
   {
       if(sp[i].acc==e)
       {
           printf("NAME:%s ACC NO:%d BALANCE:%d\n",sp[i].name,sp[i].acc,sp[i].balance);
       }
   }
}
void withdraw(struct bank* sp, int *size)
{
   int b, e;
   printf("Enter acc no:");
   scanf("%d",&b);
   printf("Enter the amount:");
   scanf("%d",&e);
   for(int i=0;i<*size;i++)
   {
       if(sp[i].acc==b)
       {
          if(sp[i].balance>=e)
          {
            sp[i].balance=sp[i].balance-e;
           printf("AMOUNT WITHDRAWED\n");  
          }
          else
          {
              printf("bBALANCE IS GREATER THAN WITHDRAWL AMOUNT\n");
          }
          
       }
   }
    
}
void displaythreshold(struct bank* sp,int*size)
{
    for(int i=0;i<*size;i++)
    {
        if(sp[i].balance<1500)
        {
            printf("The account with below threshold balance Acc no:%d Name:%s Balance:%d\n",sp[i].acc,sp[i].name,sp[i].balance);
        }
    }
    
}

int main()
{
    int size=0,capacity=2,o;
    struct bank* sp=(struct bank*)malloc(sizeof(int)*capacity);
    while(1)
    {
        printf("enter an option:");
        scanf("%d",&o);
        switch(o)
        {
            case 1:
            sp=insert(sp,&size,&capacity);
            break;
            case 2:
            deposit(sp,&size);
            break;
            case 3:
            search(sp,&size);
            break;
            case 4:
            withdraw(sp,&size);
            break;
            case 5:
            displaythreshold(sp,&size);
            break;
        }
    }

    return 0;
}
