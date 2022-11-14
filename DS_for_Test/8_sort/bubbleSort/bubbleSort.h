#include <stdio.h>
void print(int *ar, int n)
{
    for (size_t i = 0; i < n; i++)
    {
        printf("%d ", ar[i]);
    }
    puts("");
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int *ar, int n)
{
    int flag = 0;
    for (size_t i = 0; i < n - 1; i++)
    {
        for (size_t j = 1; j < n - i; j++)
        {
            if (ar[j - 1] > ar[j])
            {
                swap(&ar[j - 1], &ar[j]);
                flag = 1;
            }
        }
        if (0 == flag)
        {
            break;
        }
    }
}
