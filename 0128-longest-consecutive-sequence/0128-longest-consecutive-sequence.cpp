class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n<1)return n;
        sort(begin(nums),end(nums));
        int count = 1;
        int ans = 1;
        for(int i = 1 ; i < nums.size(); i++){
            if(nums[i] == nums[i-1])
                continue;
            if(nums[i]-nums[i-1]==1)count++;
            else count =1;
            ans = max(ans, count);
        }
        return ans;
    }
};