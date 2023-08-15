#include "00_listNode.h"

struct ListNode *detectCycle(struct ListNode *head) {
  struct ListNode *slow = head, *fast = head;
  while (fast != NULL) {
    slow = slow->next;
    if (fast->next == NULL) {
      return NULL;
    }
    fast = fast->next->next;
    if (fast == slow) {
      struct ListNode *ptr = head;
      while (ptr != slow) {
        ptr = ptr->next;
        slow = slow->next;
      }
      return ptr;
    }
  }
  return NULL;
}
