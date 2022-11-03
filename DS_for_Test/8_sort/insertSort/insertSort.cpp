#include <stdio.h>
#include "insertSort.h"
int main(void)
{
    int ar[5] = {4, 2, 7, 1, 3};
    insertSort_juejingResult(ar, 5);
    print(ar, 5);
}