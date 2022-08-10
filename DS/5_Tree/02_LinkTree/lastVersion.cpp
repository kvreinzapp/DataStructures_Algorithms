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
} BiTNode, *BitTree;

/************Operation******************/
/*******Init*****/

/*******Empty*****/
bool IsEmpty(BiTNode *T)
{
    return (T->lchild == NULL && T->rchild == NULL);
}
/*******AddNode*****/
BiTNode *newNode(BiTNode *&parent, char ch)
{
    BiTNode *seven = (BiTNode *)malloc(sizeof(BiTNode));
    seven->data = {ch};
    seven->lchild = NULL;
    seven->rchild = NULL;
    parent = seven;
    return seven;
}

void addRange(BitTree &root, int range)
{
    // NULL tree
    root = NULL;

    // add root
    root = (BitTree)malloc(sizeof(BiTNode));
    root->data = {'A'};
    root->lchild = NULL;
    root->rchild = NULL;

    BiTNode *p[20];
    p[1] = root;
    for (int i = 2; i <= range; i++)
    {
        if (i % 2 == 0)
            p[i] = newNode(p[i / 2]->lchild, 64 + i);
        else
            p[i] = newNode(p[i / 2]->rchild, 64 + i);
    }
}

void visit(BiTNode *T)
{
    printf("%c\n", T->data);
}
void InOrder(BitTree T)
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
    BitTree root;
    addRange(root, 5);
    InOrder(root);
}