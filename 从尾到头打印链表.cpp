/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
vector<int> temp;
std::stack<int> node;
class Solution {
public:
    
    vector<int> printListFromTailToHead(ListNode* head) {
        temp.clear();
        while(head!=NULL){
            int tempt = head->val;
            node.push(tempt);
            head = head->next;
        }
        while(!node.empty()){
            temp.push_back(node.top());
            node.pop();
        }
        return temp;
    }

};
