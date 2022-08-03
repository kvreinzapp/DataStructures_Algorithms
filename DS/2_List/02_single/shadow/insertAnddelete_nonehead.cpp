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
    L = NULL;
    return true;
}

bool Empty(LinkList L)
{
    return (L == NULL);
}

bool ListInsert(LinkList &L, int i, int e)
{
    if (i < 1)
        return false;

    if (i == 1)
    {
        LNode *s = (LNode *)malloc(sizeof(LNode));
        s->data = e;
        s->next = L;
        L = s;
        return true;
    }

    LNode *p;
    p = L;
    int j = 1; // PA:    p point to the 1st node, not zero
    while (p != NULL && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (p == NULL)
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}
bool InsertNextNode(LNode *p, int e);  // same as head
bool InsertPriorNode(LNode *p, int e); // same as head

bool ListDelete(LinkList &L, int i, int e)
{
    if (i < 1)
        return false;
    if (i == 1)
    {
        LNode *p = L;
        e = p->data;
        L = p->next;
        free(p);
        return true;
    }

    // I guess that we can still use p here?
    LNode *p;
    p = L;
    int j = 1;
    while (p != NULL && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (p == NULL)
        return false;

    LNode *q = p->next;
    e = q->data;
    p->next = q->next;
    free(q);
    return false;
}
bool DeleteNode(LNode *p); // same as head

int main(void)
{
}