#include "00_linkedList.h"
#include <stdbool.h>
#include <stdio.h>

int main(void) {
  Node *L = init();
  head_insert(L, 3);
  head_insert(L, 2);
  head_insert(L, 1);
  traverse(L);
  printf("NULL->next:%p\n", NULL->next);
}
