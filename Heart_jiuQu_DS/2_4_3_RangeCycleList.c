#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

struct Node *createCycledList(int a, int b, int c) {
  struct Node *A = (struct Node *)malloc(sizeof(struct Node));
  A->data = a;
  struct Node *B = (struct Node *)malloc(sizeof(struct Node));
  B->data = b;
  struct Node *C = (struct Node *)malloc(sizeof(struct Node));
  C->data = c;
  A->next = B;
  B->next = C;
  C->next = A;
  return A;
}

void printList(struct Node *head) {
  struct Node *p = head;
  while (1) {
    printf("%d ", p->data);
    p = p->next;
    if (p == head)
      break;
  }
  puts("");
}

struct Node *insert(struct Node *head, int insertval) {
  struct Node *node = malloc(sizeof(struct Node));
  node->data = insertval;

  if (NULL == head) {
    head = node;
    head->next = head;
  } else if (head->next == head) {
    head->next = node;
    node->next = head;
  } else {
    struct Node *first = head;
    struct Node *second = head->next;
    struct Node *biggest = head;

    while (!(first->data <= node->data && second->data >= node->data) &&
           second != head) {
      first = first->next;
      second = second->next;
      if (first->data >= biggest->data) {
        biggest = first;
      }
    }

    if (first->data <= node->data && second->data >= node->data) {
      node->next = second;
      first->next = node;
    } else {
      node->next = biggest->next;
      biggest->next = node;
    }
  }
  return head;
}

int main() {
  int a = 3, b = 4, c = 1;
  struct Node *L = createCycledList(a, b, c);
  printList(L);
  insert(L, 2);
  printList(L);
}
