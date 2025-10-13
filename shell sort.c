#include <stdio.h>
void shellsort(int a[], int n)
{
    int gap = n / 2;
    while (gap >= 1) 
    {
        for (int i = gap; i < n; i++)
        {
            int temp = a[i];
            int j = i;
            while (j >= gap && a[j - gap] > temp)
            {
                a[j] = a[j - gap];
                j = j - gap;
            }
            a[j] = temp;
        }
        gap = gap / 2;
    }
}

int main()
{
    int a[8] = {1, 27, 98, 3, 65, 9, 20, 2};
    int n = 8;

    shellsort(a, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}
