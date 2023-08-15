#include "00_linkedList.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

bool hasCycle(struct node *head) {
  struct node *fast = head;
  struct node *slow = head;
  while (fast != NULL && fast->next != NULL) {
    fast = fast->next->next;
    slow = slow->next;

    if (fast == slow)
      return true;
  }

  return false;
}

int main() {
  Node *L = init();
  L->data = 1;
  tail_insert(L, 2);
  tail_insert(L, 3);
  tail_insert(L, 4);
  tail_insert(L, 5);
  tail_insert(L, 6);

  Node *p = getTail(L);
  p->next = L->next;
  printf("%s", hasCycle(L) ? "true" : "false");
}
