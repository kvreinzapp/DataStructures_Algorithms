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
    L = NULL; // why? because maybe a pointer must be initialize
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

    // this is the only different part
    if (i == 1)
    {
        LNode *s = (LNode *)malloc(sizeof(LNode)); // you must create a new node at the first
        s->data = e;
        s->next = L;
        L = s; // Let head pointer point to new node
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
bool ListDelete(LinkList &L, int i, int e)
{
    if (i < 1)
        return false;
    if (i == 1)
    {
        LNode *p = L;
        L = p->next;
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
int main(void)
{
    // Let L point to a list
    LinkList L;
    InitList(L); // PA:Now we don't create a node anymore, just a pointer point to node, and the pointer is NULL
}