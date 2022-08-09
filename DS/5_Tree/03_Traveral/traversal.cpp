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

/************Traversal******************/
void visit(BiTNode *T)
{
    printf("The int here is %d\n", T.data);
}

/*********pre******/
void PreOrder(BiTree T)
{
    if (T != NULL)
    {
        visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

/*********In******/
void InOrder(BiTree T)
{
    if (T != NULL)
    {
        InOrder(T->lchild);
        visit(T);
        InOrder(T->rchild);
    }
}

/*********post******/
void PostOrder(BiTree T)
{
    if (T != NULL)
    {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        visit(T);
    }
}