#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct DNode
{
    int data;
    struct DNode *prior, *next;
} Dnode, *DLinklist;
bool InitDLinklist(DLinklist &L)
{

    Dnode *L = (Dnode *)malloc(sizeof(Dnode));
    if (L == NULL)
        return false;
    L->next = L;
    L->prior = L;
    return true;
}
bool Empty(DLinklist L)
{
    return (L->next == L);
}

bool isTail(DLinklist L, Dnode *p)
{
    return (p->next == L);
}
bool InsertNextNode(DLinklist &L, Dnode *p)
{
    Dnode *s = (Dnode *)malloc(sizeof(Dnode));
    s->next = p->next;
    p->next->prior = s;
    p->next = s;
    s->prior = p;
    return true;
}
bool DeleteNextNode(Dnode *p)
{
    Dnode *q = p->next;
    p->next = q->next;
    q->next->prior = p;
    return true;
    free(q);
}
