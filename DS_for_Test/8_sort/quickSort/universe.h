#include <stdio.h>

void print(int A[], int n)
{
    for (size_t i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    puts("");
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}