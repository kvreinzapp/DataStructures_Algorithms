#include <stdio.h>
#include "simpleSelectSort.h"
#define NUM 5
int main(void)
{
    int ar[NUM] = {15, 4, 17, 2, 16};
    print(ar, NUM);
    simpleSelectSort(ar, NUM);
    print(ar, NUM);
}