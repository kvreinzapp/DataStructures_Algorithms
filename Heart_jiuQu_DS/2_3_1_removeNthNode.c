#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int data;
  struct ListNode *next;
};

struct ListNode *removeNthFromEnd(struct ListNode *head, int n) {
  struct ListNode *p = (struct ListNode *)malloc(sizeof(struct ListNode));
  p->next = head;

  struct ListNode *fast = head;
  struct ListNode *slow = p;

  for (int i = 0; i < n; i++) {
    fast = fast->next;
  }

  while (fast != NULL) {
    fast = fast->next;
    slow = slow->next;
  }

  slow->next = slow->next->next;
  return p->next;
}
