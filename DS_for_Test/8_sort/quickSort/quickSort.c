#include <stdio.h>
#include "quickSort.h"
#define NUM 6
int main(void)
{
    int ar[NUM] = {18, 5, 20, 3, 2, 19};
    print(ar, NUM);
    // partation(ar, 0, NUM - 1);
    // print(ar, NUM);
    quickSort(ar, 0, NUM - 1);
    print(ar, NUM);
}