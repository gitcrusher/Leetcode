class Solution {
public:
    vector<vector<int>>result;

    void twoSum(vector<int>& nums, long long target, int l, int r, int first, int second){
        while(l<r){
            if(nums[l]+nums[r]>target)r--;
            else if(nums[l]+nums[r]<target)l++;
            else{
                while(l<r && nums[l]==nums[l+1])l++;
                while(l<r && nums[r]==nums[r-1])r--;
                result.push_back({first,second, nums[l],nums[r]});
                l++;
                r--;
            }
        }
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        int n = nums.size();
        sort(nums.begin(), nums.end());
        if(n<4)return{};

        for(int i = 0 ; i < n ; i++ ){
            if(i>0 && nums[i]==nums[i-1])continue;
            for(int j = i+1 ; j < n ; j++){
                if(j>i+1 && nums[j]==nums[j-1])continue;
                long long need = (long long)target-nums[i]-nums[j];
                twoSum(nums, need,j+1,n-1,nums[i], nums[j]);
            }
        }
    return result;
    }
};