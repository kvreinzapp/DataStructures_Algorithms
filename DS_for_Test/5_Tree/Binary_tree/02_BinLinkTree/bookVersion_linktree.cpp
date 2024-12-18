#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*************Declaration***************/
struct ElemType
{
    int value;
};

typedef struct BiTNode
{
    char data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

/************Operation******************/
/*******Init*****/

/*******Empty*****/
bool IsEmpty(BiTNode *T)
{
    return (T->lchild == NULL && T->rchild == NULL);
}
/*******AddNode*****/
void AddandInit(BiTree &root)
{
    // NULL tree
    root = NULL;

    // add root
    root = (BiTree)malloc(sizeof(BiTNode));
    root->data = {'A'};
    root->lchild = NULL;
    root->rchild = NULL;

    // add new node
    BiTNode *sec = (BiTNode *)malloc(sizeof(BiTNode));
    sec->data = {'B'};
    sec->lchild = NULL;
    sec->rchild = NULL;
    root->lchild = sec;

    // add new node
    BiTNode *thir = (BiTNode *)malloc(sizeof(BiTNode));
    thir->data = {'C'};
    thir->lchild = NULL;
    thir->rchild = NULL;
    root->rchild = thir;

    // add new node
    BiTNode *four = (BiTNode *)malloc(sizeof(BiTNode));
    four->data = {'D'};
    four->lchild = NULL;
    four->rchild = NULL;
    sec->lchild = four;

    // add new node
    BiTNode *five = (BiTNode *)malloc(sizeof(BiTNode));
    five->data = {'E'};
    five->lchild = NULL;
    five->rchild = NULL;
    sec->rchild = five;

    // add new node
    BiTNode *six = (BiTNode *)malloc(sizeof(BiTNode));
    six->data = {'F'};
    six->lchild = NULL;
    six->rchild = NULL;
    thir->rchild = six;

    // add new node
    BiTNode *seven = (BiTNode *)malloc(sizeof(BiTNode));
    seven->data = {'G'};
    seven->lchild = NULL;
    seven->rchild = NULL;
    four->rchild = seven;
}

void newNode(BiTNode *parent, char ch)
{
    BiTNode *seven = (BiTNode *)malloc(sizeof(BiTNode));
    seven->data = {ch};
    seven->lchild = NULL;
    seven->rchild = NULL;
    parent = seven;
}
void visit(BiTNode *T)
{
    printf("%c\n", T->data);
}
void InOrder(BiTree T)
{
    if (T != NULL)
    {
        InOrder(T->lchild);
        visit(T);
        InOrder(T->rchild);
    }
}
int main(void)
{
    BiTree root;
    AddandInit(root);
    InOrder(root);
}