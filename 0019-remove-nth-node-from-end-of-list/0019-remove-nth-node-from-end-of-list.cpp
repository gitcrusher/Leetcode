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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        int count  = 0 ;
        if(curr == nullptr){
            return nullptr;
        }
        while (curr!=nullptr){
            count++;
            curr = curr->next;
        }
        curr = head;
        int pos = count -n;
        if(pos ==0){
            ListNode* newhead = head->next;
            delete head;
            return newhead;
        }
        for(int a = 1 ; a!=pos; a++ ){
            curr = curr->next;
        }
        
            curr->next = curr->next->next;
            return head;
    }
};