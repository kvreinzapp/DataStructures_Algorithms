#include <stdio.h>
#include <stdbool.h>
bool hasDuplicateValue(int *array, int n);
int main(void)
{
    int sth[] = {1, 2, 3, 4, 5};
    int temp = hasDuplicateValue(sth, 5);
    printf("result is %d\n", temp);
}

bool hasDuplicateValue(int *array, int n)
{
    int steps = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            steps++;
            if (i != j && array[i] == array[j])
            {
                return true;
            }
        }
    }
    printf("Step is %d\n", steps);
    return false;
}