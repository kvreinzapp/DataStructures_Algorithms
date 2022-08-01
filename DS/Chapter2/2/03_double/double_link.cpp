#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Dnode
{
    int data;
    struct Dnode *prior, *next;
} Dnode, *DLinklist;

bool InitDLinklist(DLinklist &L)
{

    Dnode *L = (Dnode *)malloc(sizeof(Dnode));
    if (L == NULL)
        return false;
    L->next = NULL;
    L->prior = NULL;
    return true;
}

bool Empty(DLinklist L)
{
    return (L->next == NULL);
}

bool InsertNextNode(Dnode *p, Dnode *s) // In double link list, this function is the basiced func
{
    if (p == NULL || s == NULL)
        return false;
    s->next = p->next;
    if (p->next != NULL) // in case of p is the last node
        p->next->prior = s;
    p->next = s;
    s->prior = p;
}
bool DeleteNextNode(Dnode *p)
{
    if (p == NULL)
        return false;
    Dnode *q = p->next;
    if (q == NULL)
        return false;
    p->next = q->next;
    if (q->next != NULL)
        q->next->prior = p;
    free(q);
    return true;
}

void DestroyList(DLinklist &L)
{
    while (L->next != NULL)
        DeleteNextNode(L);
    free(L);
    L = NULL;
}

void PrintList(DLinklist L) // can't be implement, just here illustrate sth
{
    Dnode *p = L;
    while (p != NULL)
    {
        printf("%d", p->data);
        p = p->next;
    }
    while (p != NULL)
    {
        printf("%d", p->data);
        p = p->prior;
    }
    while (p->prior != NULL) // you can skip the data of headnode in this way
    {
        printf("%d", p->data);
        p = p->prior;
    }
    while (p->next != NULL) // But can't in print back, it will ignore the last data
    {
        printf("%d", p->data);
        p = p->next;
    }
}