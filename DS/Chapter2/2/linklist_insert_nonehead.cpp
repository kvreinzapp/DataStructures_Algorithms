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

int main(void)
{
    // Let L point to a list
    LinkList L;
    InitList(L); // PA:Now we don't create a node anymore, just a pointer point to node, and the pointer is NULL
}