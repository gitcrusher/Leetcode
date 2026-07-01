class Solution {
public:
    vector<vector<int>> result;
    void twoSum(vector<int>&nums, int target, int l, int r ){
        while(l<r){
            if(nums[l]+nums[r]>target)r--;
            else if(nums[l]+nums[r]<target)l++;
            else{
                //first we have to remove duplicates then
                while(l<r && nums[l]==nums[l+1])l++;
                while(l<r && nums[r]==nums[r-1])r--;
                result.push_back({-target,nums[l],nums[r]});
                l++;
                r--;
            }
        }
    }


    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if(n<3)return {};
        result.clear();

        //sort it
        sort(nums.begin(),nums.end());

        //fixing the one element.
        for(int i = 0 ; i <=n-3 ;i++ ){
            if(i>0 && nums[i]==nums[i-1])continue;
            int n1 = nums[i];
            int target = -n1;
            twoSum(nums,target,i+1,n-1);
        }
        return result;
    }
};