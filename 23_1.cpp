#include <functional>
#include <iostream>
#include <queue>
#include <vector>

struct ListNode {
  int val;
  ListNode* next;
  explicit ListNode(int x) : val(x), next(nullptr) {}
};

struct IdWithValue {
  int id_;
  int value_;
  IdWithValue(int id, int value) : id_(id), value_(value) {}
  bool operator>(IdWithValue other) const {
    return value_ > other.value_;
  }
};

class Solution {
 public:
  ListNode* mergeKLists(std::vector<ListNode*>& lists) {  // NOLINT
    std::priority_queue<
        IdWithValue, std::vector<IdWithValue>, std::greater<IdWithValue> >
        heap;
    ListNode* head = nullptr;
    ListNode* work;
    bool is_frist = true;
    int length = lists.size();
    for (int i = 0; i < length; ++i) {
      if (lists[i] != nullptr) {
        IdWithValue temp(i, lists[i]->val);
        lists[i] = lists[i]->next;
        heap.push(temp);
      }
    }
    while (!heap.empty()) {
      IdWithValue pop_value = heap.top();
      heap.pop();
      ListNode* flag_node = new ListNode(pop_value.value_);
      if (is_frist) {
        is_frist = false;
        head = flag_node;
        work = head;
      } else {
        work->next = flag_node;
        work = flag_node;
      }
      int index = pop_value.id_;
      if (lists[index] != nullptr) {
        IdWithValue push_value(index, lists[index]->val);
        heap.push(push_value);
        lists[index] = lists[index]->next;
      }
    }
    return head;
  }
};
