class Solution {
public:
    void subset(vector<int>b, vector<vector<int>>& ans,vector<int>&candidates,  int target, int idx){
        if(target ==0){
            ans.push_back(b);
            return;
        }
        if(idx == candidates.size()|| target <0) return ;

        //take
        b.push_back(candidates[idx]); 
        subset(b,ans,candidates,target-candidates[idx],idx);
        b.pop_back();

        //not take
        subset(b,ans,candidates,target,idx+1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>b;
        subset(b,  ans, candidates,target,0);
        return ans;
    }
};