#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
typedef struct TreeNode {
  ElemType data;
  struct TreeNode *left_child;
  struct TreeNode *right_child;
} TreeNode;

typedef TreeNode *BiTree;

void pre_order(BiTree T) {
  if (NULL == T)
    return;
  printf("%c", T->data);
  pre_order(T->left_child);
  pre_order(T->right_child);
}

void in_order(BiTree T) {
  if (NULL == T)
    return;
  in_order(T->left_child);
  printf("%c", T->data);
  in_order(T->right_child);
}

void post_order(BiTree T) {
  if (NULL == T)
    return;
  post_order(T->left_child);
  post_order(T->right_child);
  printf("%c", T->data);
}
