#include "00_queueWithTree.h"

void level_order(BiTree T, Queue *Q) {
  if (NULL == T)
    return;
  enqueue(Q, T);
  while (1) {
    BiTree curr = dequeue(Q);
    if (curr != NULL) {
      printf("%c", curr->data);
      if (curr->left_child != NULL)
        enqueue(Q, curr->left_child);
      if (curr->right_child != NULL)
        enqueue(Q, curr->right_child);
    } else
      break;
  }
  puts("");
}

int main() {
  BiTree T;
  Queue Q;
  init_queue(&Q);
  create_tree(&T);

  level_order(T, &Q);
}
