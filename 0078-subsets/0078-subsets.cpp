class Solution {
public:
    void subset(vector<int> a,vector<int>nums,vector<vector<int>>& full,int idx){
        if(idx==nums.size()){
            full.push_back(a);
            return;
        }

        // nto take
        subset(a,nums,full,idx+1);

        a.push_back(nums[idx]);
        subset(a,nums,full,idx+1);
        
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> full;
        vector<int>a;
        subset(a,nums,full,0);
        return full;

    }
};