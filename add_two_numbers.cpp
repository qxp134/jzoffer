/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int over_flow = 0;
        ListNode* ans = new ListNode(0);;
        ListNode* work = ans;
        while(l1 != NULL || l2 != NULL){
            if(l1 == NULL){
                l1 = new ListNode(0);
            }
            if(l2 == NULL){
                l2 = new ListNode(0);
            }
            int temp_val = l1->val + l2->val + over_flow;
            ListNode* temp = new ListNode(0);
            work->next = temp;
            if(temp_val > 9){
                temp->val = temp_val - 10;
                over_flow = 1;
            }
            else{
                temp->val = temp_val;
                over_flow = 0;
            }
            l1 = l1->next;
            l2 = l2->next;
            work = work->next;
        }
        if(over_flow == 1){
            ListNode* temp = new ListNode(1);
            work->next = temp;
        }
        return ans->next;
    }
};
