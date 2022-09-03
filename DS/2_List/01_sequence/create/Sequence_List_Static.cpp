// Sequence list -- Static
#include <stdio.h>

#include <stdbool.h>

#define MAXSIZE 10
typedef int ElemType;
typedef struct
{
    ElemType data[MAXSIZE];
    int length;
} SqList;

bool visit(ElemType e)
{
    printf("d ", e);
    return true;
}

// Initialization
bool InitList(SqList &L)
{
    L.length = 0;
    return true;
}

// PRE:L exsist. RES:If list is empty, return true
bool ListEmpty(SqList L)
{
    if (0 == L.length)
        return true;
    else
        return false;
}

// PRE: L exsist. RES: Clear the list
bool ClearList(SqList &L)
{
    L.length = 0;
    return true;
}

// PRE: L exsist. RES: return the length
int ListLength(SqList L)
{
    return L.length;
}

// Pre: L exsist
// RES: change e, return true
// PA: i is the real num, not index num
bool GetElem(SqList L, int i, ElemType &e)
{
    if (0 == L.length || i < 1 || i > L.length)
        return false;
    e = L.data[i - 1]; // e is fine, not like C, needed *e
    return true;
}

// Pre: L exsist
// RES: Find the first elem matched with e, return it real num
// PA: not return position; not return status
ElemType LocateElem(SqList L, ElemType e)
{
    int i;
    if (0 == L.length)
        return false;
    for (i = 0; i < L.length; i++)
    {
        if (e == L.data[i])
            // return i + 1;
            break;
    }
    if (i >= L.length)
    {
        return false;
    }
    return i + 1;
}

// Pre: L exsist
// RES: add e before real num i, length of L + 1
bool ListInsert(SqList &L, int i, int e)
{
    // check full
    if (L.length >= MAXSIZE)
    {
        printf("Now it's full");
        return false;
    }
    // check real num i
    if (MAXSIZE == L.length || i < 1 || i > L.length + 1)
    {
        printf("Wrong value of i, must between 1 ~ %d", L.length + 1);
        return false;
    }
    // basic things for inserting
    if (i <= L.length)
    {
        for (int k = L.length - 1; k >= i - 1; k--)
        {
            L.data[k + 1] = L.data[k];
        }
    }
    L.data[i - 1] = e; // PA it's [i-1]
    L.length++;
    return true;
}

// RES: delete real num's elem, assign to e, return status
bool ListDelete(SqList &L, int i, ElemType &e)
{
    // check empty
    if (ListEmpty(L))
        return false;
    // check i
    if (i < 1 || i > L.length)
    {
        printf("Wrong value of i, must between 1 ~ %d", L.length);
        return false;
    }

    // basic things for deleting
    e = L.data[i - 1]; // take things back
    if (i < L.length) /* 如果删除不是最后位置 */
    {
        for (int k = i; k < L.length; k++)
        {
            L.data[k - 1] = L.data[k];
        }
    }
    L.length--;
    return true;
}

int main(void)
{
    SqList L;
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
