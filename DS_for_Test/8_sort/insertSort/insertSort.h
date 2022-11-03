#include <stdio.h>
void print(int *array, int num);
void insertSort_wangdao(int ar[], int count)
{
    for (size_t i = 1; i < count; i++)
    {
        int temp = ar[i];
        int j;
        if (ar[i - 1] > ar[i])
        {
            for (j = i - 1; j >= 0; j--)
            {
                if (ar[j] > temp)
                {
                    ar[j + 1] = ar[j];
                }
                else
                {
                    break;
                }
            }
            ar[j + 1] = temp;
        }
    }
}

void insertSort_wangdaoShaobing(int ar[], int n) // Some question
{
    int i, j;
    for (i = 2; i <= n; i++)
    {
        if (ar[i - 1] > ar[i])
        {
            ar[0] = ar[i];
            for (j = i - 1; ar[j] > ar[0]; --j)
            {
                ar[j + 1] = ar[j];
            }
            ar[j + 1] = ar[0];
        }
    }
}

void insertSort_commenSense(int ar[], int n)
{
    for (size_t i = 0; i < n; i++)
    {
        int temp = ar[i];
        int position = i - 1;
        while (position >= 0)
        {
            if (ar[position] > temp)
            {
                ar[position + 1] = ar[position];
                position--;
            }
            else
            {
                break;
            }
        }
        ar[position + 1] = temp;
    }
}

void insertSort_cainiaoResult(int ar[], int count)
{
    for (size_t i = 1; i < count; i++)
    {
        int temp = ar[i];
        int position = i - 1;
        while (position >= 0 && ar[position] > temp)
        {
            ar[position + 1] = ar[position];
            position--;
        }
        ar[position + 1] = temp;
    }
}

// Anoter view
void insertSort_juejingResult(int ar[], int n)
{
    int i, j, temp;
    for (i = 1; i < n; i++)
    {
        for (j = i - 1; j >= 0 && ar[j] > ar[j + 1]; j--)
        {
            temp = ar[j];
            ar[j] = ar[j + 1];
            ar[j + 1] = temp;
        }
    }
}

void print(int *array, int num)
{
    for (size_t i = 0; i < num; i++)
    {
        printf("%d ", array[i]);
    }
    puts("");
}