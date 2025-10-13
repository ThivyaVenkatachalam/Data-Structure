#include <stdio.h>
void insertionsort(int a[],int n)
{
    int i,j,key;
    for(int i= 1;i<n;i++)
    {
        key=a[i];
        for(int j=i-1;i>=0;j--)
        {
            if(a[j]>key)
            {
                a[j+1]=a[j];
            }
            else
            {
                break;
            }
        }
        a[j+1]=key;
    }
}
int main()  
{
   int a[50];
   a={1,27,98,3,65,9,20,2};
   insertionsort(a,8);
    return 0;
}
