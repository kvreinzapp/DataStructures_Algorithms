#include "threadTree.h"

int main() {
  ThreadTree head;
  ThreadTree T;

  create_thread_tree(&T);
  inorder_threading(&head, T);

  thread_inorder_noRecur(head);
}
