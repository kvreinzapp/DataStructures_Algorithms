#include <stdio.h>
#include <stdlib.h>
#include "universal.h"

void reverse(int ar[], int from, int to);
void converse(int ar[], int n, int p);
int main(void)
{
    int array[5] = {1, 2, 3, 4, 5};
    print(array, 5);
    converse(array, 5, 3);
    print(array, 5);
}

void reverse(int ar[], int from, int to)
{
    int temp;
    for (size_t i = 0; i < (to - from + 1) / 2; i++)
    {
        temp = ar[from + i];
        ar[from + i] = ar[to - i];
        ar[to - i] = temp;
    }
}

void converse(int ar[], int n, int p)
{
    reverse(ar, 0, p - 1);
    reverse(ar, p, n - 1);
    reverse(ar, 0, n - 1);
}

// 1. how to write reverse is learnable
// 2. don't mess up about how to pass array
// 3. Time O(n), Space O(1),cause noo extra space
