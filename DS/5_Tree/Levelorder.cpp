#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*************Declaration***************/
struct ElemType
{
    int value;
} typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

typedef struct LinkNode
{
    BiTNode *data;
    struct LinkNode *next;
} LinkNode;

typedef struct
{
    LinkNode *front, *rear;
} LinkQueue;

void visit(BiTNode *T)
{
    printf("The int here is %d\n", T.data);
}

void InitQueue(LinkQueue Q)
{
    Q.front = NULL;
    Q.rear = NULL;
}

void EnQueue(LinkQueue &Q, BiTNode *x)
{
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = x;
    s->next = NULL;

    if (Q.rear == NULL)
        Q.front = Q.rear = s;

    Q.rear->next = s;
    Q.rear = s;
}

bool Empty(LinkQueue Q)
{
    return (Q.front == NULL);
}

bool DeQueue(LinkQueue &Q, BiTNode *x)
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

/************Level order******************/
void LevelOrder(BitTree T)
{
    LinkQueue(Q);
    InitQueue(Q);
    BitTree p;
    EnQueue(Q, T);
    while (!Empty(Q))
    {
        DeQueue(Q, p);
        visit(p);
        if (p->lchild != NULL)
            EnQueue(Q, p->lchild);
        if (p->rchild != NULL)
            EnQueue(Q, p->rchild);
    }
}