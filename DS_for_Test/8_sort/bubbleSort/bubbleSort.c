#include <stdio.h>
#include "bubbleSort.h"
#define NUM 5
int main(void)
{
    int array[NUM] = {5, 4, 3, 2, 1};
    print(array, NUM);
    bubbleSort(array, NUM);
    print(array, NUM);
}