#include <iostream>
struct ListNode {
  int val;
  ListNode* next;
  explicit ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
 public:
  ListNode* swapPairs(ListNode* head) {
    ListNode tmp(0);
    ListNode* work = &tmp;
    work->next = head;
    head = work;
    ListNode* swap = nullptr;
    ListNode* swap_next = nullptr;
    while (work) {
      if (work->next && work->next->next) {
        // assignment
        swap = work->next;
        swap_next = swap->next;
        // change 3 link
        work->next = swap_next;
        swap->next = swap_next->next;
        swap_next->next = swap;
        // renew work ptr
        work = swap;
      } else {
        break;
      }
    }
    work = head;
    head = head->next;
    delete work;
    return head;
  }
};
