#include<stdio.h>
int main()
{
    char a[50];
    scanf("%[^\n]",a);
    int stack[50];
    int top=-1;
    for(int i=0;a[i]!='\0';i++)
    {
        if(a[i]>='0'&& a[i]<='9')
        {
            stack[++top]=a[i]-'0';
        }
        else if(a[i]==' ')
        {
          continue;  
        }
        else
        {
            int s=stack[top--];
            int p=stack[top--];
            switch(a[i])
            {
                case'+':
                stack[++top]=s+p;
                break;
                case'-':
                stack[++top]=s-p;
                break;
                case'*':
                stack[++top]=s*p;
                break;
                case'/':
                stack[++top]=s/p;
                break;
            }
        }
    }
    printf("%d",stack[top]);
    return 0;
    
}
