#include "00_listNode.h"

struct ListNode *detectCycle(struct ListNode *head) {
  struct ListNode *fast = head;
  struct ListNode *slow = head;
  int count = 0;

  while (fast && fast->next) {
    fast = fast->next->next;
    slow = slow->next;
    count++;
    if (fast == slow)
      break;
  }

  if (!(fast && fast->next))
    return NULL;

  fast = head;
  slow = head;
  while (count--) {
    fast = fast->next;
  }

  while (fast != slow) {
    slow = slow->next;
    fast = fast->next;
  }

  return slow;
}
