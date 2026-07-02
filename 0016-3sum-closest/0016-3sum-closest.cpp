class Solution {
public:
    int ans ;
    
    void twoSum(vector<int>&nums, int target, int l , int r, int first, int& ans){
       
        while(l<r){
           int currsum = first + nums[l] + nums[r];
           if (abs(currsum - target) < abs(ans - target)) ans = currsum; 
           if (currsum > target) r--; 
           else if (currsum < target) l++; 
           else { 
            ans = currsum;
            return;
           }
        }
    }

    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        ans = nums[0] + nums[1] + nums[2];

        if(n<3)return 0; 
        for(int i = 0 ; i < n; i++){
            if(i>0 && nums[i]==nums[i-1])continue;
            int n1 = nums[i];
            twoSum(nums, target, i+1, n-1, n1, ans);
        }
        return ans;
    }
};