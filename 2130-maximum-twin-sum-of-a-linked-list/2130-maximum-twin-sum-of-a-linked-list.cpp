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
    int pairSum(ListNode* head) {
        int len = 0 ;
        ListNode* temp1 = head;
        while(temp1){
            len++;
            temp1= temp1->next;
        }


        ListNode* newhead = nullptr;
        ListNode* newtail = nullptr;
        ListNode* temp = head;

        while(temp){
            ListNode* newnode = new ListNode(temp->val);
            if(newhead==nullptr){
                newhead = newnode;
                newtail = newnode;
            }else{
                newtail->next = newnode;
                newtail = newnode;
            }
            temp=temp->next;
        }

        ListNode* prev = nullptr, *next = nullptr, *curr = newhead;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev= curr;
            curr = next;
        }
        //return prev 
        int maxi = INT_MIN;
        for(int i = 0 ; i < len/2; i++){
            int sum = head->val+prev->val;
            maxi = max(maxi,sum);
            head = head->next;
            prev = prev->next;
        }
        return maxi; 
    }
};