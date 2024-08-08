#include "0_queue.h"

int getWPL(TreeNode *T) {
  if (T == NULL)
    return 0;
  Queue Q;
  initQueue(&Q);
  enqueue(&Q, T);
  int depth = 0;
  int weight = 0;
  while (!emptyQueue(&Q)) {
    int count = sizeQueue(&Q);
    while (count > 0) {
      dequeue(&Q, &T);
      if (T->left_child == NULL && T->right_child == NULL)
        weight += T->weight * depth;
      if (T->left_child != NULL)
        enqueue(&Q, T->left_child);
      if (T->right_child != NULL)
        enqueue(&Q, T->right_child);
      count--;
    }
    depth++;
  }
  return weight;
}

int main() {
  TreeNode *T;
  createTree(&T);
  printf("The WPL of this tree is %d.\n", getWPL(T));
}
