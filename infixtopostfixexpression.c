#include <stdio.h>
#include<ctype.h>
#include<string.h>
# define max 100
char stack[max];
int top=-1;
void push(char c)
{
    if(top==max-1)
    {
        printf("stack overflow");
    }
    else
    {
        stack[++top]=c;
    }
}
char pop()
{
    if(top==-1)
    {
        return -1;
    }
    else
    {
        return stack[top--];
    }
}
char peek()
{
    if(top==-1)
    {
        return -1;
    }
    else
    {
        return stack[top];
    }
}
int precedence(char c)
{
    if(c=='^')
    {
        return 3;
    }
    else if(c=='*'||c=='/')
    {
        return 2;
    }
    else if(c=='+'||c=='-')
    {
        return 2;
    }
    else
    {
        return -1;
    }
}
void infixtopostfix(char *infix)
{
    char postfix[max];
    int k=0;
    for(int i=0;infix[i]!='\0';i++)
    {
        char c=infix[i];
        if(isalnum(c))
        {
            postfix[k]=c;
            k++;
        }
        else if(c=='(')
        {
            push(c);
        }
        else if(c==')')
        {
        while(top!=-1||peek()!=')')
        {
            postfix[k++]=pop();
        }
        pop();
        }
        else
        {
            while(top!=-1&&precedence(peek())>=precedence(c))
            {
                postfix[k++]=pop();
            }
            push(c);
        }
    }
    while(top!=-1)
    {
        postfix[k++]=pop();
    }
    postfix[k]='\0';
    printf("%s",postfix);
}
int main()
{
    char infix[max];
    scanf("%s",infix);
    infixtopostfix(infix);
    return 0;
}
