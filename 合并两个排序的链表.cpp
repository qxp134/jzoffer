class Solution {
 public:
  ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
    ListNode* work = new ListNode(0);
    ListNode* res = work;
    while (pHead1 != NULL && pHead2 != NULL) {
      if (pHead1->val < pHead2->val) {
        ListNode* temp = new ListNode(pHead1->val);
        work->next = temp;
        work = work->next;
        pHead1 = pHead1->next;
      } else {
        ListNode* temp = new ListNode(pHead2->val);
        work->next = temp;
        work = work->next;
        pHead2 = pHead2->next;
      }
    }
    if (pHead1 != NULL)
      work->next = pHead1;
    if (pHead2 != NULL)
      work->next = pHead2;
    if (res->next != NULL)
      return res->next;
    else
      return NULL;
  }
};
