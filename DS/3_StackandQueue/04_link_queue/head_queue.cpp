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
    Q.front = Q.rear = (LNode *)malloc(sizeof(LNode));
    Q.front->next = NULL;
}
bool Empty(LinkQueue Q)
{
    return (Q.front == Q.rear);
}
/******************In and Out*******************/
void EnQueue(LinkQueue &Q, int x)
{
    LNode *s = (LNode *)malloc(sizeof(LNode));

    s->data = x;
    s->next = NULL;

    Q.rear->next = s;
    Q.rear = s;
}
bool DeQueue(LinkQueue &Q, int x)
{
    if (Q.rear == Q.front)
        return false;
    LNode *q = Q.front->next;
    x = q->data;
    Q.front->next = q->next;
    if (Q.rear = q)
        Q.rear = Q.front;
    free(q);
    return true;
}