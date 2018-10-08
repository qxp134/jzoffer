class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead == NULL || pHead->next == NULL)return pHead;
        ListNode* pre = NULL;
        ListNode* work = pHead;
        ListNode* head = NULL;
        while(work != NULL){
            ListNode* next = work->next;
            if(next == NULL)head = work;
            work->next = pre;
            pre = work;
            work = next;
        }
        return head;
    }
};
