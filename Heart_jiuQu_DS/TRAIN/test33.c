if (NULL == head)
  return;

struct ListNode *fast = head;
struct ListNode *slow = head;
while (fast != NULL && fast->next != NULL) {
  fast = fast->next->next;
  slow = slow->next;
}

struct ListNode *first = NULL;
struct ListNode *second =
    slow->next;    // break from middle node and its next node.
slow->next = NULL; // make first half of list finally point to NULL
struct ListNode *third;
while (second != NULL) {
  third = second->next;
  second->next = first;
  first = second;
  second = third;
}

struct ListNode *p1 = head;
struct ListNode *q1 = first;
struct ListNode *p2, *q2;
while (p1 != NULL && q1 != NULL) {
  p2 = p1->next;
  q2 = q1->next;

  p1->next = q1;
  q1->next = p2;

  p1 = p2;
  q1 = q2;
}
