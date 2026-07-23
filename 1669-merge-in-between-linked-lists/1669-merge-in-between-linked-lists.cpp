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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* curr = list1;
        ListNode* prev = nullptr;
        ListNode* after= nullptr;
        int count = 0;
        while(curr!=nullptr){
            if(count ==a-1){
                prev = curr;
            }
            if(count ==b+1) after = curr;
            count++;
            curr= curr->next;
        }
        ListNode* temp = list2;
        while(temp->next!=nullptr){
            temp = temp->next;
        }
        prev->next = list2;
        temp->next = after;
        return list1;
    }
};