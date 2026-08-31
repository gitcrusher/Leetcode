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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* nxt = curr->next;
        int maxima = 0;
        int minima = 0;
        vector<int>ans;
        int count =2;
        while(curr->next!=nullptr){
            if((prev->val > curr->val && nxt->val > curr->val)||
            (prev->val < curr->val && nxt->val < curr->val)){
                ans.push_back(count);
            }
            prev = curr;
            curr = nxt;
            nxt = nxt->next;
            count++;
        }

        if(ans.size()<2)return {-1,-1};
        
        int mindist = INT_MAX;

        for(int i = 1; i < ans.size(); i++){
            mindist = min(mindist, ans[i]-ans[i-1]);
        }
        int maxdist = ans.back()-ans.front();

        return {mindist, maxdist};

    }
};