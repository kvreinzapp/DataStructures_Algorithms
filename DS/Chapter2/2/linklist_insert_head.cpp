#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
// define a LNode
// LNode *ptr   and   LinkList ptr is same way to define a ptr pionted to node
typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;

bool InitList(LinkList &L)
{
    L = (LNode *)malloc(sizeof(LNode));
    if (L == NULL)
        return false; // means that malloc is false, we don't have enough memory
    L->next = NULL;
    return true;
}

bool ListInsert(LinkList &L, int i, int e)
{
    // i can't less than 1
    if (i < 1)
        return false;
    // create a ptr point to head
    LNode *p;
    p = L;
    // j  and  while are there to let p point to last node(i-1) of position i
    int j = 0;
    while (p != NULL && j < i - 1)
    {
        p = L->next;
        j++;
    }
    // now j must equal to i-1  and  p point to it
    // because it is a linklist, so we have to use a loop to point i-1 one node by one node

    // the oif here is for the bigger i, if i is so big, p will point to NULL, because the LinkList's end is point to NULL
    if (p == NULL)
        return false;

    // now we add a new node
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    // must save the information in new place(the new node) before we change the last node's next
    s->next = p->next;
    p->next = s;
}

int main(void)
{
}