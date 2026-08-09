class Solution {
public:
    int minPairSum(vector<int>& nums) {
     sort(begin(nums),end(nums));
        int l = 0 , r = nums.size()-1;
        int res = 0;
        while(l<=r){
            int n = nums[l]+nums[r];
            res = max(res,n);
            l++;
            r--;
        }
        return res;   
    }
};