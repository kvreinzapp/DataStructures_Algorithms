#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXSIZE 10
typedef struct LinkNode
{
    int data;
    struct LinkNode *next;
} * LiStack;

void InitStack(LiStack &L)
{
    L = NULL;
}

bool Push(LiStack &L)
{
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    if (s == NULL)
        return false;
    s->next = L;
    L = s;
    return true;
}