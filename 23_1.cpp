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
  int id;
  int value;
  IdWithValue(int id, int value) : id(id), value(value) {}
  // bool operator>(IdWithValue other) const {
  // return value_ > other.value_;
  //}
};

inline bool operator<(const IdWithValue& lhs, const IdWithValue& rhs) {
  return lhs.value > rhs.value;
}

class Solution {
 public:
  ListNode* mergeKLists(std::vector<ListNode*>& lists) {  // NOLINT
    std::priority_queue<IdWithValue> heap;
    ListNode* head = nullptr;
    ListNode* work;
    bool is_frist = true;
    int length = lists.size();
    for (int i = 0; i < length; ++i) {
      if (lists[i]) {
        heap.emplace(i, lists[i]->val);
        lists[i] = lists[i]->next;
      }
    }
    while (!heap.empty()) {
      IdWithValue pop_value = heap.top();
      heap.pop();
      ListNode* flag_node = new ListNode(pop_value.value);
      if (is_frist) {
        is_frist = false;
        head = flag_node;
        work = head;
      } else {
        work->next = flag_node;
        work = flag_node;
      }
      int index = pop_value.id;
      if (lists[index]) {
        heap.emplace(index, lists[index]->val);
        lists[index] = lists[index]->next;
      }
    }
    return head;
  }
};
