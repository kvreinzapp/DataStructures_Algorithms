if (head == NULL)
  return;
struct ListNode *fast = head;
struct ListNode *slow = head;
while (fast != NULL && fast->next != NULL) {
  fast = fast->next->next;
  slow = slow->next;
}
struct ListNode *first = NULL;
struct ListNode *second = slow->next;
slow->next = NULL;
struct ListNode *third;
while (second != NULL) {
  third = second->next;
  second->next = first;
  second = third;
  first = second;
}
struct ListNode *p = head;
struct ListNode *q = first;
struct ListNode *t1;
struct ListNode *t2;
while (q != NULL) {
  t1 = p->next;
  t2 = q->next;
  p->next = q;
  q->next = t1;
  p = t1;
  q = t2;
}
