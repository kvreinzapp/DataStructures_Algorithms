#include <stdio.h>
#include <stdlib.h>

struct Node {
  int val;
  struct Node *next;
};

struct Node *createCycledList(int a, int b, int c) {
  struct Node *A = (struct Node *)malloc(sizeof(struct Node));
  A->val = a;
  struct Node *B = (struct Node *)malloc(sizeof(struct Node));
  B->val = b;
  struct Node *C = (struct Node *)malloc(sizeof(struct Node));
  C->val = c;
  A->next = B;
  B->next = C;
  C->next = A;
  return A;
}

void printList(struct Node *head) {
  struct Node *p = head;
  while (1) {
    printf("%d ", p->val);
    p = p->next;
    if (p == head)
      break;
  }
  puts("");
}

struct Node *insert(struct Node *head, int insertVal) {
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  node->val = insertVal;
  node->next = NULL;
  if (head == NULL) {
    node->next = node;
    return node;
  }
  if (head->next == head) {
    head->next = node;
    node->next = head;
    return head;
  }
  struct Node *curr = head, *next = head->next;
  while (next != head) {
    if (insertVal >= curr->val && insertVal <= next->val) {
      break;
    }
    if (curr->val > next->val) {
      if (insertVal > curr->val || insertVal < next->val) {
        break;
      }
    }
    curr = curr->next;
    next = next->next;
  }
  curr->next = node;
  node->next = next;
  return head;
}

int main() {
  int a = 3, b = 4, c = 1;
  struct Node *L = createCycledList(a, b, c);
  printList(L);
  insert(L, 2);
  printList(L);
}
