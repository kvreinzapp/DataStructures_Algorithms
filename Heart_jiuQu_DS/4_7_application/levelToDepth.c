#include "0_queue.h"

int getBTreeDepth(TreeNode *T) {
  if (T == NULL) {
    return 0;
  }
  int depth = 0;
  Queue Q;
  initQueue(&Q);
  enqueue(&Q, T);
  while (!emptyQueue(&Q)) {
    int count = sizeQueue(&Q);
    while (count > 0) {
      dequeue(&Q, &T);
      if (T->left_child != NULL)
        enqueue(&Q, T->left_child);
      if (T->right_child != NULL)
        enqueue(&Q, T->right_child);
      count--;
    }
    depth++;
  }
  return depth;
}

int main() {
  TreeNode *T;
  createTree(&T);
  printf("The depth of this tree is %d\n", getBTreeDepth(T));
}
