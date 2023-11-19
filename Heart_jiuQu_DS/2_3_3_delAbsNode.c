#include "00_typedefNode.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

int getAbs(int num) {
  if (num < 0)
    num = -num;
  return num;
}

/* bool delTheNode(Node *L, int pos) { */
/*   Node *p = L; */
/*   for (int i = 0; i < pos - 1; i++) { */
/*     p = p->next; */
/*     if (p == NULL) { */
/*       puts("You can't delete the NULL"); */
/*       return false; */
/*     } */
/*   } */
/*   Node *q = p->next; */
/*   p->next = q->next; */
/*   free(q); */
/*   return true; */
/* } */

bool delTheNode(Node *L, int pos) {
  for (int i = 0; i < pos - 1; i++) {
    L = L->next;
    if (L == NULL) {
      puts("You can't delete the NULL");
      return false;
    }
  }
  Node *q = L->next;
  L->next = q->next;
  free(q);
  return true;
}

void removeAbsNode(Node *L) {
  Node *p = L->next;

  int checkAr[30];
  int position = 1;             // initialization for first node.
  checkAr[getAbs(p->data)] = 1; // initialization for first node.
  p = p->next;                  // start check from 2nd node.

  while (p != NULL) {
    position++;                          // add the position for next node
    if (1 == checkAr[getAbs(p->data)]) { // if the p's array position now is 1,
                                         // for the 1st node, definitely.
      Node *q = p->next; // record the next node, cause we gonna delete p which
                         // lose the next information.
      delTheNode(L, position);
      position--; // The position of L is changed. We delete L according to the
                  // position.
      p = q;      // update p, p now to the next node.
    } else {
      checkAr[getAbs(p->data)] = 1; // if not, we must assign it in array.
      p = p->next; // update the p to next node, no need to position--.
    }
  }
}

void remove_node_versionOfBook(Node *L, int n) {
  Node *p = L;
  int index;
  int *q = (int *)malloc(sizeof(int) *
                         (n + 1)); // create n+1 space, stores from 0 to n+1. If
                                   // you create n, max just to n-1, not enough.
  for (int i = 0; i < n + 1; i++)
    *(q + i) = 0;
  while (p->next != NULL) {
    if (p->next->data > 0)
      index = p->next->data;
    else
      index = -(p->next->data);

    if (*(q + index) == 0) {
      *(q + index) = 1;
      p = p->next;
    } else {
      Node *temp = p->next;
      p->next = temp->next;
      free(temp);
    }
  }
  free(q);
}

int main() {
  Node *L = init();
  head_insert(L, 4);
  head_insert(L, 11);
  head_insert(L, 3);
  head_insert(L, -4);
  head_insert(L, -3);
  head_insert(L, 4);
  head_insert(L, -22);
  head_insert(L, 22);
  traverse(L);
  remove_node_versionOfBook(L, 22); // create 23 location, store from 0 to 22
  traverse(L);
}
