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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        unordered_map<int,int> freq;
        for(int i = 0 ; i < lists.size(); i++){
            ListNode* curr = lists[i];
            while(curr!=nullptr){
                freq[curr->val]++;
                curr = curr->next;
            }
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>>pq;

        for(auto& c:freq){
            pq.push({c.first,c.second}); 
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();

            int value = top.first;
            int count = top.second;

            while(count--){
                tail->next = new ListNode(value);
                tail = tail->next;
            }
        }
        return dummy.next;
    }
};