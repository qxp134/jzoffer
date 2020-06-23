#include <iostream>

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
 public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* fast_ptr = head;   // found the end node
    ListNode* slow_ptr = head;  // a node before will be deleted node
    while (n != 0) {
      --n;
      fast_ptr = fast_ptr->next;
    }
    if (!fast_ptr)
      head = head->next;
      delete(slow_ptr);
      return head;
    while (fast_ptr->next) {
      fast_ptr = fast_ptr->next;
      slow_ptr = slow_ptr->next;
    }
    ListNode* delete_ptr = slow_ptr->next;
    if (delete_ptr) {
      slow_ptr->next = delete_ptr->next;
      delete (delete_ptr);
    }
    return head;
  }
};