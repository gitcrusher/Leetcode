class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;
        for(int i =0; i< nums.size(); i++){
            pq.push({nums[i],i});   
        }


        while(k--){
            auto top = pq.top();
            pq.pop();
            int idx=top.second;
            int val = top.first;
            val=val*multiplier; 
            nums[idx]=val;
            pq.push({val,idx});  
        }
        return nums;
    }
};