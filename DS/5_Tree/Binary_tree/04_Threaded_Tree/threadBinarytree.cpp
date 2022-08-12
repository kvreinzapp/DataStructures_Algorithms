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

/***************************************************Main-Topic******************************************************/
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

/*********************InOrder********************/
void InThread(ThreadTree T) // same as InOrder FindPre
{
    if (T != NULL)
    {
        InThread(T->lchild);
        visit(T);
        InThread(T->rchild);
    }
}

void createInthread(ThreadTree T)
{
    pre = NULL;
    if (T != NULL)
    {
        InThread(T);
        if (pre->rchild == NULL)
            pre->rtag = 1;
    }
}

/*********************PreOrder********************/
void PreThread(ThreadTree T) // same as InOrder FindPre
{
    if (T != NULL)
    {
        visit(T);

        // pretend frome cycle
        if (T->ltag == 0)
            InThread(T->lchild);

        InThread(T->rchild);
    }
}

void createInthread(ThreadTree T)
{
    pre = NULL;
    if (T != NULL)
    {
        InThread(T);
        if (pre->rchild == NULL)
            pre->rtag = 1;
    }
}
/***************************************************Enter-doSth******************************************************/

int main(void)
{
    ThreadTree root;
    addRange(root, 6);
    createInthread(root);
}