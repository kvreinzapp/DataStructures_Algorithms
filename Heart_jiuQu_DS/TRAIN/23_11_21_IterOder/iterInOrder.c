#include "0_stack.h"

void iterInOrder(TreeNode *T, Stack *S) {
  while (!(T == NULL && is_empty(S) == 1)) {
    while (T != NULL) {
      push(S, T);
      T = T->left_child;
    }
    pop(S, &T);
    printf("%c", T->data);
    T = T->right_child;
  }
}

int main() {
  TreeNode *T;
  Stack S;
  initStack(&S);
  createTree(&T);

  inOrder(T);
  iterInOrder(T, &S);
}
