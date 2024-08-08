#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  char data;
  char weight;
  struct node *left_child;
  struct node *right_child;
} TreeNode, *BiTree;

char *str = "GHD##A##IJKF##B##C##E##"; // pre order output

int weight[23] = {0, 42, 15, 0, 0, 27, 0, 0, 58, 28, 13, 5,
                  0, 0,  8,  0, 0, 15, 0, 0, 30, 0,  0};
int Index = 0;

void createTree(BiTree *T) {
  char ch = str[Index];
  char we = weight[Index];
  Index++;
  if ('#' == ch)
    *T = NULL;
  else {
    *T = (BiTree)malloc(sizeof(TreeNode));
    (*T)->data = ch;
    (*T)->weight = we;
    createTree(&(*T)->left_child);
    createTree(&(*T)->right_child);
  }
}

void preOrder(BiTree T) {
  if (T == NULL)
    return;
  printf("%c ", T->data);
  printf("%d ", T->weight);
  preOrder(T->left_child);
  preOrder(T->right_child);
}
void inOrder(BiTree T) {
  if (T == NULL)
    return;
  printf("(");
  inOrder(T->left_child);
  printf("%c", T->data);
  inOrder(T->right_child);
  printf(")");
}
void postOrder(BiTree T) {
  if (T == NULL) {
    return;
  }
  postOrder(T->left_child);
  postOrder(T->right_child);
  printf("%c", T->data);
}
