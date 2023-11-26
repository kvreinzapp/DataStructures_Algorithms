#include "0_stack.h"

void iterPreOrder(TreeNode *T, Stack *S) {
  while (!(T == NULL && is_empty(S) == 1)) {
    while (T != NULL) {
      printf("%c", T->data);
      push(S, T);
      T = T->left_child;
    }
    pop(S, &T);
    T = T->right_child;
  }
}

int main() {
  TreeNode *T;
  Stack S;
  initStack(&S);
  createTree(&T);

  puts("\nPreOrder:");
  preOrder(T);
  puts("\nIterPreOrder:");
  iterPreOrder(T, &S);
}
