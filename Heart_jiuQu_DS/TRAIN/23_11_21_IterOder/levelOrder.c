#include "0_queue.h"

void levelOrder(TreeNode *T, Queue *Q) {
  if (T == NULL)
    return;
  ;
  enqueue(Q, T);
  while (1) {
    dequeue(Q, &T);
    if (T != NULL) {
      printf("%c", T->data);
      if (T->left_child != NULL)
        enqueue(Q, T->left_child);
      if (T->right_child != NULL)
        enqueue(Q, T->right_child);
    } else
      break;
  }
}

int main() {
  TreeNode *T;
  createTree(&T);
  Queue Q;
  initQueue(&Q);

  levelOrder(T, &Q);
}
