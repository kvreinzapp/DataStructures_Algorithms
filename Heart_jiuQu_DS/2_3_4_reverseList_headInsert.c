// T(n) = O(n)
#include "00_linkedList.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

Node *reverse(Node *L) {
  Node *R = init();
  Node *p = L->next;

  while (p != NULL) {
    Node *e = (Node *)malloc(sizeof(Node));
    e->next = R->next;
    e->data = p->data;
    R->next = e;
    p = p->next;
  }

  return R;
}

int main() {
  Node *L = init();
  head_insert(L, 5);
  head_insert(L, 4);
  head_insert(L, 3);
  head_insert(L, 2);
  head_insert(L, 1);
  traverse(L);
  L = reverse(L);
  traverse(L);
}
