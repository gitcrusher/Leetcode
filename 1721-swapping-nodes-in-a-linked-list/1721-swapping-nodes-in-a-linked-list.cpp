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
    ListNode* swapNodes(ListNode* head, int first) {
        ListNode* curr = head;
        int count = 0;
        ListNode* front;
        ListNode* back;
        while (curr!=nullptr){
            count++;
            curr= curr->next;
        }
        curr = head;
        int last = count - first+1;
        for (int i = 1 ; i < first; i ++){
            curr= curr->next;
        }
        front = curr;
        curr = head;
        for(int i = 1 ; i<last; i++){
            curr=curr->next;
        }
        back = curr;
        curr = head;
        int temp = front->val;
        front->val = back->val;
        back->val = temp;

        return head;
    }
};