#include "00_linkedList.h"
#include <stddef.h>
#include <stdio.h>

int findNode(Node *L, int k) {
  Node *slow = L;
  Node *fast = L;
  for (size_t i = 0; i < k; i++) {
    fast = fast->next;
    if (fast == NULL)
      return 0;
  }
  while (fast != NULL) {
    slow = slow->next;
    fast = fast->next;
  }
  printf("The k node: %d\n", slow->data);
  return 1;
}

// in leetcoode, we don't create head in init function
int removeNthFromEnd(Node *L, int k) {
  Node *head = (Node *)malloc(sizeof(Node)); // create a head nod
  head->next = L;                            // append a head node
  Node *slow = head;
  Node *fast = head;
  for (size_t i = 0; i < k; i++)
    fast = fast->next;
  while (fast->next != NULL) {
    fast = fast->next;
    slow = slow->next;
  }
  slow->next = slow->next->next;
  return 1;
}

int main() {
  Node *L = init();
  head_insert(L, 1);
  /* head_insert(L, 2); */
  /* head_insert(L, 3); */
  /* head_insert(L, 4); */
  /* head_insert(L, 5); */
  /* head_insert(L, 6); */
  /* head_insert(L, 7); */
  /* head_insert(L, 8); */
  traverse(L);
  // findNode(L, 3);
  removeNthFromEnd(L, 1);
  traverse(L);
  free_list(L);
}
