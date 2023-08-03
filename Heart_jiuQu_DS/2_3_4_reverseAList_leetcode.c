#include "00_linkedList.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

/* Node *reverseList_false(Node *L) { */
/*   Node *first = NULL; */
/*   Node *second = L; */
/*   Node *third = L->next; */
/*   Node *temp; */
/*   // second->next = first; */
/*   while (second != NULL) { */
/*     second->next = first; */
/*     temp = third->next; */
/*     third->next = second; */
/*     first = second; */
/*     second = third; */
/*     third = temp; */
/*   } */
/*   return first; */
/* } // Didn't work */

struct node *reverseList_versionOfBook(struct node *head) {
  struct node *first = NULL;
  struct node *second = head;
  struct node *third; // always a temp node to record the next.

  while (second != NULL) {
    third = second->next; // record the next;
    second->next = first; // change the link
    first = second;       // move
    second = third;       // move
  }
  return first;
}

void traverse_withoutHead(Node *L) {
  Node *p = L;
  while (p != NULL) {
    printf("%d ", p->data);
    p = p->next;
  }
  puts("");
}

int main() {
  Node *L = (Node *)malloc(sizeof(Node));
  L->data = 1;
  tail_insert(L, 2);
  tail_insert(L, 3);
  tail_insert(L, 4);
  tail_insert(L, 5);
  traverse_withoutHead(L);
  L = reverseList_versionOfBook(L);
  traverse_withoutHead(L);
}
