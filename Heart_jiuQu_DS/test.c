#include "00_linkedList.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

int main(void) {
  Node *L = init();
  head_insert(L, 5);
  head_insert(L, 4);
  head_insert(L, 3);
  head_insert(L, 2);
  head_insert(L, 1);
  traverse_withoutHead(L);
}
