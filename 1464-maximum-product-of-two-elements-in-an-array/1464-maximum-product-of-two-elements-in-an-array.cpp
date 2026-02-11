class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int>pq;
        for(int i = 0 ; i < nums.size(); i++){
            int a = nums[i]-1;
            pq.push(a);
        }
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        return first*second;
    }
};