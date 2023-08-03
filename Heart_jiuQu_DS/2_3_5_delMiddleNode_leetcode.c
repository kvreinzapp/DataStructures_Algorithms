#include "00_linkedList.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

void delMidNode_myVersion(struct node *head) {
  /* struct node *p = (struct node *)malloc(sizeof(struct node)); */
  /* p->next = head; */
  /* p->data = 0; */
  /* head = p; */

  struct node *fast = head;
  struct node *slow = head;
  struct node *temp;

  while (fast != NULL && fast->next != NULL) {
    fast = fast->next->next;
    temp = slow;
    slow = slow->next;
  }
  temp->next = slow->next;
  free(slow);
}

struct node *deleteMiddle_brilliant(struct node *head) {
  struct node *p = (struct node *)malloc(sizeof(struct node));
  p->next = head;

  struct node *fast = head;
  struct node *slow = p;

  while (fast != NULL && fast->next != NULL) {
    fast = fast->next->next;
    slow = slow->next;
  }

  struct node *q = slow->next;
  slow->next = q->next;
  free(q);
  return p->next;
}

int main() {
  Node *L = (Node *)malloc(sizeof(Node));
  L->data = 1;
  tail_insert(L, 2);
  tail_insert(L, 3);
  tail_insert(L, 4);
  tail_insert(L, 5);
  tail_insert(L, 6);
  traverse_withoutHead(L);
  deleteMiddle_brilliant(L);
  traverse_withoutHead(L);
}
