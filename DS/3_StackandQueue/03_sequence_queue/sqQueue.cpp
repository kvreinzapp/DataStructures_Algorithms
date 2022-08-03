#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/******************Declaration*******************/
#define MAXSIZE 10
typedef struct SqQueue
{
    int data[MAXSIZE];
    int front, rear;
} SqQueue;

/******************Initialization*******************/
void InitQueue(SqQueue &Q)
{
    Q.rear = Q.front = 0;
}

bool Empty(SqQueue Q)
{
    return (Q.rear == Q.front);
}
/******************In and Out*******************/
bool EnQueue(SqQueue &Q, int x)
{
    if ((Q.rear + 1) % MAXSIZE == Q.front)
        return false;
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MAXSIZE;
    return true;
}

bool DeQueue(SqQueue &Q, int x)
{
    if (Q.front == Q.rear)
        return false;
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MAXSIZE;
    return true;
}

/******************Read head*******************/
bool GetHead(SqQueue Q, int x)
{
    if (Q.front == Q.rear)
        return false;
    x = Q.data[Q.front];
    return true;
}

/******************Length*******************/
int Length(SqQueue Q)
{
    return ((Q.rear - Q.front + MAXSIZE) % MAXSIZE);
}