#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;
bool InitList(LinkList &L)
{

    LNode *L = (LNode *)malloc(sizeof(LNode));
    if (L == NULL)
        return false;
    L->next = L;
    return true;
}
bool Empty(LinkList L)
{
    return (L->next == L);
}
bool isTail(LinkList L, LNode *p)
{
    return (p->next == L);
}