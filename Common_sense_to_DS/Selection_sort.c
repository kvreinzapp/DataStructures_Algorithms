#include <stdio.h>
void selectionSort(int *array, int n);
int main(void)
{
    int sth[] = {4, 2, 7, 1, 3};
    selectionSort(sth, 5);
    for (int i = 0; i < 5; i++)
        printf("%d", sth[i]);
}

void selectionSort(int *array, int n)
{
    int smallest_index = 0;
    for (int i = 0; i < n; i++)
    {
        int start_position = 0;
        for (int j = start_position; j < n; j++)
        {
            if (array[j] > array[j + 1])
            {
                smallest_index = j + 1;
            }
        }
        printf("now who: %d\n", smallest_index);
        int temp = array[i];
        array[i] = array[smallest_index];
        array[smallest_index] = temp;
        for (int i = 0; i < 5; i++)
            printf("%d", array[i]);
        printf("\n");
        start_position++;
    }
}