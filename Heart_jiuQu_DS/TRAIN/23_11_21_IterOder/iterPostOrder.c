#include "0_stack.h"

void iterPostOrder(BiTree T, Stack *S) {
  TreeNode *prev = NULL;
  while (!(T == NULL && is_empty(S) == 1)) {
    while (T != NULL) {
      push(S, T);
      T = T->left_child;
    }
    getTop(S, &T);
    if (T->right_child != NULL && T->right_child != prev) {
      T = T->right_child;
    } else {
      pop(S, &T);
      printf("%c", T->data);
      prev = T;
      T = NULL;
    }
  }
}

int main() {
  TreeNode *T;
  Stack S;
  initStack(&S);
  createTree(&T);

  postOrder(T);
  iterPostOrder(T, &S);
}
