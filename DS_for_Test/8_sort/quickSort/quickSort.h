#include <stdio.h>
#include "universe.h"

int partation(int A[], int low, int high)
{
    int pivot = A[low];
    while (low < high)
    {
        while (low < high && A[high] > pivot)
        {
            high--;
        }
        while (low < high && A[low] < pivot)
        {
            low++;
        }
        if (low != high)
        {
            swap(&A[low], &A[high]);
        }
        else if (low >= high)
        {
            break;
        }
    }
    return low;
}

void quickSort(int A[], int low, int high)
{
    if (low < high)
    {
        int pivot = partation(A, low, high);
        quickSort(A, low, pivot - 1);
        quickSort(A, pivot + 1, high);
    }
    else
        return;
}
