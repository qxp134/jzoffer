#include <iostream>

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
 public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* frist_ptr = head;   // found the end node
    ListNode* second_ptr = head;  // a node before will be deleted node
    while (n != 0) {
      --n;
      frist_ptr = frist_ptr->next;
    }
    if (frist_ptr == NULL)
      return head->next;
    while (frist_ptr->next != NULL) {
      frist_ptr = frist_ptr->next;
      second_ptr = second_ptr->next;
    }
    ListNode* delete_ptr = second_ptr->next;
    if (delete_ptr != NULL) {
      second_ptr->next = delete_ptr->next;
      delete (delete_ptr);
    }
    return head;
  }
};