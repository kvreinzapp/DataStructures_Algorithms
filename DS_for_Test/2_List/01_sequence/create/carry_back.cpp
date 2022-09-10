#include <stdio.h>

void change(int &num);
int main(void)
{
    int number = 1;
    printf("number is %d\n", number);
    change(number);
    printf("Now number is %d\n", number);
}

void change(int &num)
{
    num = 1024;
    printf("In function, number is %d\n", num);
}