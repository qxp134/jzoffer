class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(pListHead ==NULL)return NULL;
        ListNode *frist = pListHead;
        ListNode *secend = pListHead;
        while(k != 0){
            if(frist!=NULL){
                frist = frist->next;
            }
            else return NULL;
            k--;
        }
        while(frist != NULL){
            frist = frist->next;
            secend = secend -> next;
        }
        return secend;
    }
};
