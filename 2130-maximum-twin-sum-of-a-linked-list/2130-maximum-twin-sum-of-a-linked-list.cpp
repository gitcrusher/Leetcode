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
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow;

        ListNode* prev = NULL;
        ListNode* nextNode = NULL;

        while(mid!=nullptr){
            nextNode = mid->next;
            mid->next = prev ;
            prev = mid;
            mid = nextNode;
        }

        int result = 0; 
        ListNode* curr = head;
        while(prev!=nullptr){
            result = max(result, curr->val+prev->val);
            curr = curr->next;
            prev = prev->next;
        }

        return result;

    }
};