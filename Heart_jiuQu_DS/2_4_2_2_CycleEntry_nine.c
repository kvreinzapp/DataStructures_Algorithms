#include "00_listNode.h"

struct ListNode *detectCycle(struct ListNode *head) {
  struct ListNode *fast = head;
  struct ListNode *slow = head;

  while (fast && fast->next) {
    fast = fast->next->next;
    slow = slow->next;
    if (fast == slow) {
      struct ListNode *p = fast;
      int count = 1;
      while (p->next != slow) {
        p = p->next;
        count++;
      }

      fast = head;
      slow = head;
      for (int i = 0; i < count; i++)
        fast = fast->next;
      while (fast != slow) {
        fast = fast->next;
        slow = slow->next;
      }
      return slow;
    }
  }
  return NULL;
}
