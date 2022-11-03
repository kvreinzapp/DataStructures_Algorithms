#include <stdio.h>
#include "shellSort.h"
int main(void)
{
    int ar[] = {23, 434, 21, 43, 75, 71, 12, 121, 2, 34};
    int size = sizeof ar / sizeof ar[0];
    print(ar, size);
    shellSort(ar, size);
    print(ar, size);
}