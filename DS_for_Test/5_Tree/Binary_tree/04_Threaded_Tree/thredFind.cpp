#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/***************************************************Declaration******************************************************/
struct ElemType // kind of useless
{
    int value;
};

typedef struct ThreadNode
{
    char data;
    struct ThreadNode *lchild, *rchild;
    int ltag, rtag;
} ThreadNode, *ThreadTree;

ThreadNode *pre = NULL; // Just for this file

/***************************************************Basic-Functions******************************************************/
/*******************AddNode***********************/
ThreadNode *newNode(ThreadNode *&parent, char ch)
{
    ThreadNode *theNode = (ThreadNode *)malloc(sizeof(ThreadNode));
    theNode->data = {ch};
    theNode->lchild = NULL;
    theNode->rchild = NULL;
    theNode->ltag = 0;
    theNode->rtag = 0;
    parent = theNode;
    return theNode;
}

void addRange(ThreadTree &root, int range)
{
    ThreadNode *p[20];
    p[1] = NULL;
    for (int i = 1; i <= range; i++)
    {
        if (i == 1)
            p[1] = newNode(p[1], 'A');
        else
        {
            if (i % 2 == 0)
                p[i] = newNode(p[i / 2]->lchild, 64 + i);
            else
                p[i] = newNode(p[i / 2]->rchild, 64 + i);
        }
    }
    root = p[1];
}

/****************Visit*********************/
void visit(ThreadNode *q)
{
    if (q->lchild == NULL)
    {
        q->lchild = pre;
        q->ltag = 1;
    }
    if (pre != NULL && pre->rchild == NULL)
    {
        pre->rchild = q;
        pre->rtag = 1;
    }
    pre = q;
    printf("%c\n", q->data);
}

/***************************************************Main-Topic******************************************************/
/*******************InOder**********************/
/***findnext****/
ThreadNode *firstNode(ThreadNode *p)
{
    while (p->ltag == 0)
        p = p->lchild;
    return p;
}

ThreadNode *nextNode(ThreadNode *p)
{
    if (p->rtag == 0)
        return firstNode(p->rchild);
    else
        return p->rchild;
}
/* Another way to InOrder*/
void InOrder(ThreadNode *T)
{
    for (ThreadNode *p = firstNode(T); p != NULL; p = nextNode(p))
        visit(p);
}

/***find_pre****/
ThreadNode *lastNode(ThreadNode *p)
{
    while (p->rtag == 0)
        p = p->rchild;
    return p;
}

ThreadNode *preNode(ThreadNode *p)
{
    if (p->ltag == 0)
        return lastNode(p->lchild);
    else
        return p->lchild;
}
/* Reverse InOrder*/
void revInorder(ThreadNode *T)
{
    for (ThreadNode *p = lastNode(T); p != NULL; p = preNode(p))
        visit(p);
}

/*******************PreOrder**********************/

/***************************************************Enter-doSth******************************************************/

int main(void)
{
    ThreadTree root;
    addRange(root, 6);
    createInthread(root);
}