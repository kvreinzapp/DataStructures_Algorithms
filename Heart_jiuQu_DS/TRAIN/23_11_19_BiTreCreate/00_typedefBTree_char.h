// REVIEWED in 2023.11.19
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  char data;
  struct node *left_child;
  struct node *right_child;
} TreeNode, *BiTree;

/******** ORDER with RECURSION *******/
// Preorder by recursion
void pre_order(TreeNode *T) {
  if (T == NULL)
    return;
  printf("%c", T->data);
  pre_order(T->left_child);
  pre_order(T->right_child);
}
// Inorder by recursion
void in_order(TreeNode *T) {
  if (T == NULL)
    return;
  in_order(T->left_child);
  printf("%c", T->data);
  in_order(T->right_child);
}
// postorder by recursion
void post_order(TreeNode *T) {
  if (T == NULL)
    return;
  post_order(T->left_child);
  post_order(T->right_child);
  printf("%c", T->data);
}
