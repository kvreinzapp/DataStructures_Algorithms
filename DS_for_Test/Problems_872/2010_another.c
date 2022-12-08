#include <stdio.h>
#include <stdbool.h>
#define NUM 6

bool isOdds(int x)
{
    return x % 2 != 0;
}
void print(int ar[], int n)
{
    for (size_t i = 0; i < n; i++)
    {
        printf("%d ", ar[i]);
    }
    puts("");
}
void exchangeList(int array[], int n)
{
    int uneven = 1, even = 2;
    //设置两个游标，uneven遍历奇数位序元素，even偶数位序
    while (uneven <= n && even <= n)
    {
        //结束循环时奇数位序上是偶数，偶数位序上是奇数，或者下标越界
        while (isOdds(array[uneven]) && uneven <= n)
        {
            uneven += 2;
            while (!isOdds(array[even]) && even <= n)
            {
                even += 2;
                //如果是因为越界结束循环，说明奇数位上全奇数、偶数位上全偶数至少满足一个
                if (uneven > n | even > n)
                {
                    break;
                }
                else
                {
                    int temp = array[uneven];
                    array[uneven] = array[even];
                    array[even] = temp;
                }
            }
        }
    }
}

int main()
{
    int ar[NUM] = {1, 2, 3, 4, 5, 6};
    exchangeList(ar, NUM);
}