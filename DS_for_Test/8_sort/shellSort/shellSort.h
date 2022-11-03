#include <stdio.h>
#include <stdlib.h>
void print(int ar[], int count)
{
    for (size_t i = 0; i < count; i++)
    {
        printf("%d ", ar[i]);
    }
    puts("");
}

void shellSort(int ar[], int n)
{
    int i, j, gap, temp;

    for (gap = n / 2; gap > 0; gap /= 2)
    {
        for (i = gap; i < n; i++)
        {
            for (j = i - gap; j >= 0 && ar[j] > ar[j + gap]; j -= gap)
            {
                temp = ar[j];
                ar[j] = ar[j + gap];
                ar[j + gap] = temp;
            }
        }
    }
}
