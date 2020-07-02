#include <functional>
#include <iostream>
#include <queue>
#include <vector>

struct ListNode {
  int val;
  ListNode* next;
  explicit ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
 public:
  ListNode* mergeTwo(ListNode* list_one, ListNode* list_two) {
    ListNode* head = new ListNode(-1);
    ListNode* work = head;
    while (list_one && list_two) {
      if (list_one->val < list_two->val) {
        work->next = list_one;
        list_one = list_one->next;
      } else {
        work->next = list_two;
        list_two = list_two->next;
      }
      work = work->next;
    }
    if (list_one == nullptr) {
      work->next = list_two;
    } else {
      work->next = list_one;
    }
    work = head;
    head = head->next;
    delete work;
    return head;
  }
  ListNode* mergeKLists(std::vector<ListNode*>& lists) {  // NOLINT
    if (lists.size() == 0)
      return nullptr;  // fastest and space complexity O(1) defeat 100% user
    while (lists.size() != 1) {
      int length = lists.size();
      for (int i = 0; i < length / 2; ++i) {
        lists[i] = mergeTwo(lists[i], lists[length - 1 - i]);
        lists.pop_back();
      }
    }
    return lists[0];
  }
};
