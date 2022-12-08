#include <stdio.h>
#include <stdbool.h>
#define NUM 6
bool isOdds(int n)
{
    return n % 2;
}
void exchange(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void print(int ar[], int n)
{
    for (size_t i = 0; i < n; i++)
    {
        printf("%d ", ar[i]);
    }
    puts("");
}

void reRange(int ar[], int n)
{
    for (size_t i = 0; i < n; i++)
    {
        int even = 0;
        int odds = 1;
        while (even < n && !isOdds(ar[even]))
            even += 2;
        if (even >= n)
        {
            puts("Finish");
            puts("Even is ordered");
            break;
        }
        else
        {
            while (odds < n && isOdds(ar[odds]))
                odds += 2;
            if (odds >= n)
            {
                puts("Finish Again");
                puts("Odds is ordered");
                break;
            }
            else
            {
                puts("oops, need to exchange");
                exchange(&ar[odds], &ar[even]);
            }
        }
    }
}

int main()
{
    int ar[NUM] = {1, 2, 3, 4, 5, 6};
    print(ar, NUM);
    reRange(ar, NUM);
    print(ar, NUM);
}