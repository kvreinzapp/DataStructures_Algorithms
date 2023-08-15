#include "00_listNode.h"
struct ListNode *detectCycle(struct ListNode *head) {
  struct ListNode *slow = head, *fast = head;
  while (true) {
    if (!(fast && fast->next))
      return NULL;
    slow = slow->next;
    fast = fast->next->next;
    if (fast == slow)
      break;
  }
  fast = head;
  while (fast != slow) {
    head = head->next;
    slow = slow->next;
  }
  return slow;
}
