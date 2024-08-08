#include "0_create2017Tree.h"

void getExpression(TreeNode *T, int depth) {
  if (T == NULL)
    return;
  else if (T->left_child == NULL && T->right_child == NULL)
    printf("%c", T->data);
  else {
    if (depth > 1)
      printf("(");
    getExpression(T->left_child, depth + 1);
    printf("%c", T->data);
    getExpression(T->right_child, depth + 1);
    if (depth > 1)
      printf(")");
  }
}

int main() {
  TreeNode *T;
  createTree(&T);
  int depth = 1;
  getExpression(T, depth);
}
