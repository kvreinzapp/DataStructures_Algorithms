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
    if (i < L.length)  // If not the last position
    {
        for (int k = i; k < L.length; k++)
        {
            L.data[k - 1] = L.data[k];
        }
    }
    L.length--;
    return true;
}

/* 初始条件：顺序线性表L已存在 */
/* 操作结果：依次对L的每个数据元素输出 */
bool ListTraverse(SqList L)
{
    int i;
    for (i = 0; i < L.length; i++)
        visit(L.data[i]);
    printf("\n");
    return true;
}

/*将所有的在线性表Lb中但不在La中的数据元素插入到La中*/
void unionL(SqList &La, SqList Lb)
{
    int La_len, Lb_len, i;
    ElemType e;              /*声明与La和Lb相同的数据元素e*/
    La_len = ListLength(La); /*求线性表的长度 */
    Lb_len = ListLength(Lb);
    for (i = 1; i <= Lb_len; i++)
    {
        GetElem(Lb, i, e);               /*取Lb中第i个数据元素赋给e*/
        if (!LocateElem(La, e))          /*La中不存在和e相同数据元素*/
            ListInsert(La, ++La_len, e); /*插入*/
    }
}

int main(void)
{
    SqList L;
    InitList(L);

    return 0;
}
