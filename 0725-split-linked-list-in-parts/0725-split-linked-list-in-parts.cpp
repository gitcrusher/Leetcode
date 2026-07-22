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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* curr = head;
        int count = 0;
        while(curr!=nullptr){
            count++;
            curr = curr->next;
        }

        int ele = count/k;
        int rem = count%k;
        vector<ListNode*>res(k,NULL);
        curr=head;
        ListNode* prev = nullptr;
        for(int i = 0; i < k ;i++){
            res[i] = curr;
            for(int j = 1;j<=ele+(rem>0?1:0);j++){
                prev = curr;
                curr = curr->next;
            }
            if(prev!=nullptr)
                prev->next = nullptr;
            rem--;
        }
        return res;
    }
};