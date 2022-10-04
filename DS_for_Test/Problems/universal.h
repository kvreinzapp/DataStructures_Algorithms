#include <stdio.h>
#include <stdlib.h>

void print(int *ar, int n)
{
    for (size_t i = 0; i < n; i++)
    {
        printf("%d ", ar[i]);
    }
    puts("");
}