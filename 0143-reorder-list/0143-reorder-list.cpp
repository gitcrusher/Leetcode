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
    void reorderList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return;

        stack<ListNode*> st;
        ListNode* curr = head;
        int n = 0;

        // push all nodes into stack
        while(curr){
            st.push(curr);
            curr = curr->next;
            n++;
        }

        // IMPORTANT: reset curr
        curr = head;

        // reorder
        for(int i = 0; i < n/2; i++){
            ListNode* top = st.top();
            st.pop();

            ListNode* next = curr->next;
            curr->next = top;
            top->next = next;

            curr = next;
        }

        // terminate list to avoid cycle
        curr->next = nullptr;
    }
};
