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
    ListNode* reverseKGroup(ListNode* head, int k) {
      ListNode* curr = head;
      int count = 0 ; 
      while (curr!=nullptr&& count<k){ // to check the count of element 
        curr=curr->next; 
        count++;
      }  

      if(count<k) return head; // if count is less than k then head would be return no reversal to be done.

    // reversal methods
      ListNode* prev = nullptr;
      curr=head;
      for(int i = 0 ;i<k ; i++){
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
      }
      head->next = reverseKGroup(curr,k);// recursevely we gonna do iterations
      return prev;
    }
};