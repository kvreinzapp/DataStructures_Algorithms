#include <stdio.h>
#define LEN 6
void print_arr(const int *ar);

int main(void)
{
    int A[LEN] = {5, 2, 4, 6, 1, 3};

    // Begain to sort the array
    for (int j = 2; j <= LEN; j++)
    {
        int key = A[j - 1]; // int key=A[j]; because index start from 0, j should be j-1
        int i = j - 2;      // int i=j-1 -1
        while (i >= 0 && A[i] > key)
        {
            A[i + 1] = A[i];
            i = i - 1;
        }
        A[i + 1] = key;
    }
    // Print the array
    print_arr(A);
    return 0;
}

void print_arr(const int *ar)
{
    for (int i = 0; i < LEN; i++)
    {
        printf("%d ", ar[i]);
    }
}