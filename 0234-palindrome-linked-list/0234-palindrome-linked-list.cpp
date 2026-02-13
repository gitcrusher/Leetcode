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
    ListNode* clone(ListNode* head) {
        if (!head) return nullptr;
        ListNode* node = new ListNode(head->val);
        node->next = clone(head->next);
        return node;
    }

    bool compare(ListNode* a, ListNode* b) {
        while (a && b) {
            if (a->val != b->val) return false;
            a = a->next;
            b = b->next;
        }
        return true;
    }


    ListNode* Reverse(ListNode* head){
        if(head==nullptr || head->next == nullptr){
            return head;
        }

        ListNode* rest = Reverse(head->next);

        head->next->next = head;
        head->next = nullptr;
        return rest;
    }


    bool isPalindrome(ListNode* head) {

        ListNode* copy = clone(head);   
        ListNode* newnode = Reverse(copy);
        return compare(head, newnode);
    }
};