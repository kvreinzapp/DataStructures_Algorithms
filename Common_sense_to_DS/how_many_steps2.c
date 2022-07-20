#include <stdio.h>
#include <stdbool.h>
bool hasDuplicateValue(int *array, int n);
int main(void)
{
    int sth[] = {1, 1, 3, 4, 5};
    int temp = hasDuplicateValue(sth, 5);
    printf("result is %d\n", temp);
}

bool hasDuplicateValue(int *array, int n)
{
    int exsitingNumber[10];
    int steps = 0;
    for (int i = 0; i < n; i++)
    {
        steps++;
        if (exsitingNumber[array[i]] == 1)
        {
            printf("Step is %d\n", steps);
            return true;
        }
        else
            exsitingNumber[array[i]] = 1;
    }
    printf("Step is %d\n", steps);
    return false;
}