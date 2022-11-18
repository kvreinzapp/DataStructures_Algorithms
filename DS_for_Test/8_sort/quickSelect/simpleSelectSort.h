#include <stdio.h>
#include "universe.h"

void simpleSelectSort(int ar[], int n)
{
    for (size_t i = 0; i < n - 1; i++)
    {
        int min = i;
        for (size_t j = i; j < n; j++)
        {
            if (ar[j] < ar[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            swap(&ar[i], &ar[min]);
        }
    }
}