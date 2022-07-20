#include <stdio.h>
#include <stdbool.h>
#define MAXSIZE 10
typedef struct
{
    int data[MAXSIZE];
    int length;
} Sqlist;

void InitList(Sqlist &L)
{
    L.length = 0;
}

bool ListInsert(Sqlist &L, int i, int e)
{
    // Some additional
    // check i
    if (i < 1 || i > L.length + 1)
    {
        printf("Wrong value of i, must between 1 ~ %d", L.length + 1);
        return false;
    }
    // check full
    if (L.length >= MAXSIZE)
    {
        printf("Now it's full");
        return false;
    }

    // basic things for inserting
    for (int j = MAXSIZE; j >= i; j--)
    {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e; // PA it's [i-1]
    L.length++;
}

bool ListDelete(Sqlist &L, int i, int &e)
{
    // Some additional
    // check i
    if (i < 1 || i > L.length + 1)
    {
        printf("Wrong value of i, must between 1 ~ %d", L.length + 1);
        return false;
    }

    // basic things for deleting
    e = L.data[i - 1]; // take things back
    for (int j = i; j < L.length; j++)
    {
        L.data[j - 1] = L.data[j];
    }
    // L.data[L.length-1]=0; seems not need to do this
    L.length--;
}

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
