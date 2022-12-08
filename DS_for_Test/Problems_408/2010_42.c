#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    void print(int *ar, int n);
    // 0:Init
    int n, p;
    puts("n is:");
    scanf("%d", &n);
    puts("p is:");
    scanf("%d", &p);
    if (p > n || p < 0)
    {
        return 0;
    }
    // 01:
    int *array = NULL;
    array = (int *)malloc(sizeof(int) * n);
    for (size_t i = 0; i < n; i++)
    {
        array[i] = i + 1;
    }
    print(array, n);

    // 1:Move
    // 10
    int *temp = NULL;
    temp = (int *)malloc(sizeof(int) * p);
    for (size_t i = 0; i < p; i++)
    {
        temp[i] = array[i];
    }
    // 11
    for (size_t i = p, j = 0; i < n, j < n - p; i++, j++)
    {
        array[j] = array[i];
    }
    // 12
    for (size_t i = 0, j = n - p; i < p, j < n; i++, j++)
    {
        array[j] = temp[i];
    }
    print(array, n);
}
void print(int *ar, int n)
{
    for (size_t i = 0; i < n; i++)
    {
        printf("%d ", ar[i]);
    }
    puts("");
}

// In this way O(n) and O(p)
// O(p) cause you allocate p, it's extra compared to n