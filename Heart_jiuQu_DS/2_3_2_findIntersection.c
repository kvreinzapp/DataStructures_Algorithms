#include "00_linkedList.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

int findLength(Node *p) {
  int length = 0;
  while (p != NULL) {
    length++;
    p = p->next;
  }
  return length;
}

Node *getIntersectionNode(Node *headA, Node *headB) {
  if (headA == NULL || headB == NULL)
    return NULL;
  int length_a = findLength(headA);
  int length_b = findLength(headB);
  // int length=length_a>length_b?length_a:length_b;

  if (length_a >= length_b) {
    Node *longP = headA;
    for (int i = length_a - length_b; i > 0; i--)
      longP = longP->next;
    Node *shortQ = headB;
    while (longP != NULL) {
      longP = longP->next;
      shortQ = shortQ->next;
      if (longP->data == shortQ->data)
        return longP;
    }
  }

  if (length_a < length_b) {
    Node *longP = headB;
    for (int i = length_b - length_a; i > 0; i--)
      longP = longP->next;
    Node *shortQ = headA;
    while (longP != NULL) {
      longP = longP->next;
      shortQ = shortQ->next;
      if (longP->data == shortQ->data)
        return longP;
    }
  }
}

struct node *getIntersectionNodeVersionOfBook(struct node *headA,
                                              struct node *headB) {
  if (NULL == headA || NULL == headB)
    return NULL;

  struct node *p = headA;
  int len_a = 0;
  int len_b = 0;
  while (p != NULL) {
    p = p->next;
    len_a++;
  }
  p = headB;
  while (p != NULL) {
    p = p->next;
    len_b++;
  }

  struct node *m;
  struct node *n;
  int step;
  if (len_a > len_b) {
    step = len_a - len_b;
    m = headA;
    n = headB;
  } else {
    step = n - m;
    m = headB;
    n = headA;
  }

  for (int i = 0; i < step; i++)
    m = m->next;
  while (m != n) {
    m = m->next;
    n = n->next;
  }
  return m;
}

int main() {
  // Construct two list we need
  Node *L = init();
  head_insert_char(L, 'g');
  head_insert_char(L, 'n');
  head_insert_char(L, 'i');
  head_insert_char(L, 'd');
  head_insert_char(L, 'a');
  head_insert_char(L, 'o');
  head_insert_char(L, 'l');

  Node *T = init();
  head_insert_char(T, 'e');
  head_insert_char(T, 'b');

  Node *p = getPositionNode(L, 5);
  Node *q = getPositionNode(T, 2);
  q->next = p;

  // print two word
  traverse_char(L);
  traverse_char(T);

  Node *intersection = getIntersectionNodeVersionOfBook(L, T);
  printf("the intersection letter is: %c\n", intersection->data);
}
