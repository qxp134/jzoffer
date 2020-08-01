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
  bool operator<(IdWithValue other) const {
    return value_ < other.value_;
  }
};

class Solution {
 public:
  void heapify(int index) {
    IdWithValue temp_value = heap[index];
    int left_child = index * 2 + 1;
    for (; left_child < heap.size(); left_child = left_child * 2 + 1) {
      int right_child = left_child + 1;
      if (right_child < heap.size() && heap[right_child] < heap[left_child]) {
        ++left_child;
      }
      if (heap[left_child] < temp_value) {
        heap[index] = heap[left_child];
        index = left_child;
      } else {
        break;
      }
    }
    heap[index] = temp_value;
  }
  ListNode* mergeKLists(std::vector<ListNode*>& lists) {  // NOLINT
    heap.clear();
    ListNode* head = nullptr;
    ListNode* work;
    bool is_frist = true;
    int length = lists.size();
    for (int i = 0; i < length; ++i) {
      if (lists[i] != nullptr) {
        IdWithValue temp(i, lists[i]->val);
        lists[i] = lists[i]->next;
        heap.push_back(temp);
      }
    }
    for (int i = heap.size() / 2 - 1; i > -1; --i) {
      heapify(i);
    }
    while (!heap.empty()) {
      IdWithValue pop_value = heap[0];
      // heap[0] = *heap.rbegin();
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
        heap[0] = push_value;
        heapify(0);
        lists[index] = lists[index]->next;
      } else {
        heap[0] = *heap.rbegin();
        heap.pop_back();
      }
    }
    return head;
  }
  std::vector<IdWithValue> heap;
};
