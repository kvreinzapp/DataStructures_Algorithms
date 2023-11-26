#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  char data;
  struct node *left_child;
  struct node *right_child;
} TreeNode, *BiTree;

char *str = "ABDH#K###E##CFI###G#J##"; // pre order output
int Index = 0;

void createTree(BiTree *T) {
  char ch = str[Index++];
  if ('#' == ch)
    *T = NULL;
  else {
    *T = (BiTree)malloc(sizeof(TreeNode));
    (*T)->data = ch;
    createTree(&(*T)->left_child);
    createTree(&(*T)->right_child);
  }
}

void preOrder(BiTree T) {
  if (T == NULL)
    return;
  printf("%c", T->data);
  preOrder(T->left_child);
  preOrder(T->right_child);
}
void inOrder(BiTree T) {
  if (T == NULL)
    return;
  inOrder(T->left_child);
  printf("%c", T->data);
  inOrder(T->right_child);
}
void postOrder(BiTree T) {
  if (T == NULL) {
    return;
  }
  postOrder(T->left_child);
  postOrder(T->right_child);
  printf("%c", T->data);
}
