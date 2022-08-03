#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/******************Declaration*******************/
typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode;
typedef struct
{
    LNode *front, *rear;
} LinkQueue;
/******************Initialization*******************/
void InitQueue(LinkQueue &Q)
{
    Q.front = NULL;
    Q.rear = NULL;
}
bool Empty(LinkQueue Q)
{
    return (Q.front == NULL);
}
/******************In and Out*******************/
void EnQueue(LinkQueue &Q, int x)
{
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = x;
    s->next = NULL;

    if (Q.rear == NULL)
        Q.front = Q.rear = s;

    Q.rear->next = s;
    Q.rear = s;
}
bool DeQueue(LinkQueue &Q, int x)
{
    if (Q.front == NULL)
        return false;

    LNode *p = Q.front;
    x = p->data;
    Q.front = p->next;

    if (Q.rear == p)
        Q.front = Q.rear = NULL;

    free(p);
    return true;
}
