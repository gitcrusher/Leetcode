class Solution {
public:
    void helper(vector<int>&nums, vector<int>&ans, vector<vector<int>>&fullans, int &k, int idx){
        //agar k element aa gaye to fir return krna hai 
        if(ans.size()==k){
            fullans.push_back(ans);
            return;
        }
        // agar numbers hi khatam ho jaye 
        if(idx==nums.size()){
            return;
        }

        //take
        ans.push_back(nums[idx]);
        helper(nums,ans,fullans,k,idx+1);
        ans.pop_back();


        //not take
        helper(nums,ans,fullans,k, idx+1);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>fullans;
        vector<int >nums;
        vector<int>ans;
        for(int i = 1 ; i <= n ; i++){
            nums.push_back(i);
        }
        helper(nums, ans, fullans, k, 0);
        return fullans;

    }
};