#include "00_linkedList.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

void reRange(struct node *head) {
  if (NULL == head)
    return;

  struct node *fast = head;
  struct node *slow = head;
  while (fast != NULL && fast->next != NULL) {
    fast = fast->next->next;
    slow = slow->next;
  }
  Node *temp = slow->next;

  struct node *first = NULL;
  struct node *second = slow->next; // break from middle node and its next node.
  slow->next = NULL; // make first half of list finally point to NULL
  struct node *third;
  while (second != NULL) {
    third = second->next;
    second->next = first;
    first = second;
    second = third;
  }

  struct node *p1 = head;
  struct node *q1 = first;
  struct node *p2, *q2;

  while (p1 != NULL && q1 != NULL) {
    p2 = p1->next;
    q2 = q1->next;

    p1->next = q1;
    q1->next = p2;

    p1 = p2;
    q1 = q2;
  }
}

int main(void) {
  Node *L = init();
  L->data = 1;
  tail_insert(L, 2);
  tail_insert(L, 3);
  tail_insert(L, 4);
  tail_insert(L, 5);
  tail_insert(L, 6);
  tail_insert(L, 7);
  traverse_withoutHead(L);
  reRange(L);
  traverse_withoutHead(L);
}
