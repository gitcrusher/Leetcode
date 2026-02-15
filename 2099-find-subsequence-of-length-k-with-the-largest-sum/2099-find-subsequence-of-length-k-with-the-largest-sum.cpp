class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        for(int i = 0; i <nums.size();i++){
            pq.push({nums[i],i});
        }
        int sum = 0 ;
        vector<int>a;
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>> 
        >r;
        while(k--){
            auto top = pq.top();
            pq.pop();
            r.push({top.second,top.first});
        }
        while(!r.empty()){
            auto top = r.top();
            r.pop();
            a.push_back(top.second);
        }
        return a;
    }
};