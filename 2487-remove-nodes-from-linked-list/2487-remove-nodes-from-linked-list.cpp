/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> st;
         
         while(head!=nullptr){
            st.push(head);
            head = head->next;
         }

        ListNode* curr = st.top();
        st.pop();

        int mx = curr->val;
        curr->next = nullptr;
        

        while(!st.empty()){
             ListNode* node = st.top();
             st.pop();
             if(node->val>=mx){
                mx=node->val;
                node->next = curr;
                curr = node;
             }
        }
        return curr;   
    }
};