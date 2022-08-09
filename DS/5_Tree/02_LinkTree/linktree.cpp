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
    ElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

/************Operation******************/
/*******Init*****/

/*******Empty*****/
bool IsEmpty(BiTree *T)
{
    return (lchild == NULL && rchild == NULL);
}
/*******AddNode*****/
void AddandInit(BiTree &root)
{
    // NULL tree
    BiTree root = NULL;

    // add root
    root = (BiTree)malloc(sizeof(BiTNode));
    root->data = {1};
    root->lchild = NULL;
    root->rchild = NULL;

    // add new node
    BiTNode *sec = (BiTNode *)malloc(sizeof(BiTNode));
    sec->data = {2};
    sec->lchild = NULL;
    sec->rchild = NULL;
    root->lchild = sec;

    // add new node
    BiTNode *thir = (BiTNode *)malloc(sizeof(BiTNode));
    thir->data = {3};
    thir->lchild = NULL;
    thir->rchild = NULL;
    root->rchild = thir;

    // add new node
    BiTNode *four = (BiTNode *)malloc(sizeof(BiTNode));
    four->data = {4};
    four->lchild = NULL;
    four->rchild = NULL;
    sec->lchild = four;

    // add new node
    BiTNode *five = (BiTNode *)malloc(sizeof(BiTNode));
    five->data = {5};
    five->lchild = NULL;
    five->rchild = NULL;
    sec->rchild = five;
}

void PrintTree(BitTree T, int num)
{
    for (int i = 1; i < = num; i++)
    {
        printf("%d: %d", i, T->data)
    }
}
int main(void)
{
    BiTree root;
    AddandInit(root);
}