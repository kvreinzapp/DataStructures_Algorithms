#include <stdio.h>
#include <stdlib.h>
typedef char ElemType;

typedef struct TreeNode {
  ElemType data;
  struct TreeNode *left_child;
  struct TreeNode *right_child;
} TreeNode;

typedef TreeNode *BiTree;
int Index = 0;
char *str = "ABDH#K###E##CFI###G#J##";

void create_tree(BiTree *T) {
  ElemType ch = str[Index++];
  if (ch == '#') {
    *T = NULL;
  } else {
    *T = (BiTree)malloc(sizeof(TreeNode));
    (*T)->data = ch;
    create_tree(&(*T)->left_child);
    create_tree(&(*T)->right_child);
  }
}

void pre_order(BiTree T) {
  if (NULL == T)
    return;
  else {
    printf("%c", T->data);
    pre_order(T->left_child);
    pre_order(T->right_child);
  }
}

void in_order(BiTree T) {
  if (NULL == T)
    return;
  else {
    in_order(T->left_child);
    printf("%c", T->data);
    in_order(T->right_child);
  }
}

void post_order(BiTree T) {
  if (NULL == T)
    return;
  else {
    post_order(T->left_child);
    post_order(T->right_child);
    printf("%c", T->data);
  }
}
