/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *headInsert(struct ListNode *head, int value) {
  struct ListNode *e = (struct ListNode *)malloc(sizeof(struct ListNode));
  e->val = value;
  e->next = head;
  head = e;
  return head;
}
struct ListNode *reverseList(struct ListNode *head) {
  if (head == NULL)
    return NULL;
  struct ListNode *new = (struct ListNode *)malloc(sizeof(struct ListNode));
  while (head != NULL) {
    new = headInsert(new, head->val);
    head = head->next;
  }
  return new;
}
