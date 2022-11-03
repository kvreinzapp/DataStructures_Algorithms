#include <stdio.h>
#include <stdlib.h>

#define InitSize 10
typedef struct
{
    int *data;
    int MaxSize;
    int length;

} Seqlist;

void InitList(Seqlist &L)
{
    L.data = (int *)malloc(InitSize * sizeof(int));
    L.length = 0;
    L.MaxSize = InitSize;
}

void IncreaseSize(Seqlist &L, int len)
{
    int *p = L.data;
    L.data = (int *)malloc((L.MaxSize + len) * sizeof(int));
    for (int i = 0; i < L.length; i++)
    {
        L.data[i] = p[i];
    }
    L.MaxSize = L.length + len;
    free(*p);
}

void PrintList(Seqlist &L)
{
    for (int i = 0; i < L.length; i++)
    {
        printf("data[%d]=%d", i, L.data[i]);
    }
}

int LocateElem(Seqlist &L, int e)
{
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] == e)
        {
            return i + 1;
        }
        else
            return 0;
    }
}

int main(void)
{
    Seqlist L;
    InitList(L);
}