#include "0_queue.h"

int *levelMax(TreeNode *T, int *depth) {
  if (T == NULL)
    return 0;
  Queue Q;
  initQueue(&Q);
  int *level_max;
  int i = 0;

  enqueue(&Q, T);
  while (!emptyQueue(&Q)) {
    int count = sizeQueue(&Q);
    level_max[i] = 0x80000000;
    while (count > 0) {
      dequeue(&Q, &T);
      if (level_max[i] < (int)T->data)
        level_max[i] = (int)T->data;
      if (T->left_child != NULL)
        enqueue(&Q, T->left_child);
      if (T->right_child != NULL)
        enqueue(&Q, T->right_child);
      count--;
    }
    i++;
  }
  *depth = i;
  return level_max;
}

int main() {
  TreeNode *T;
  createTree(&T);
  int depth;
  int *val_max = levelMax(T, &depth);
  for (int i = 0; i < depth; i++)
    printf("%c\n", val_max[i]);
}
