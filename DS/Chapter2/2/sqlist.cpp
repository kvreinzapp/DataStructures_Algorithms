#include <stdio.h>
#define MAXSIZE 10
typedef struct
{
    int data[MAXSIZE];
    int length;
} Sqlist;

void InitList(Sqlist &L);

int main(void)
{
    Sqlist L;
    InitList(L);

    // //The for loop down bellow here is wrong

    // for (int i = 0; i < MAXSIZE; i++)
    // {
    //     printf("data[%d]:%d\n", i, L.data[i]);
    // }

    // Right one: use L.length intead of MAXSIZE
    // Of course function is a better way
    for (int i = 0; i < L.length; i++)
    {
        printf("data[%d]:%d\n", i, L.data[i]);
    }
    return 0;
}

void InitList(Sqlist &L)
{
    L.length = 0;
}