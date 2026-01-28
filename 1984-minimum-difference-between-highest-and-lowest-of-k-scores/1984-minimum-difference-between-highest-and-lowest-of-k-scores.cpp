class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int l = 0, currdif = 0;
        int r = k-1;
        int mindif = INT_MAX;
        if(k==1) return 0; 

        while (r < nums.size()) {
            int currdif = nums[r] - nums[l];
            mindif = min(mindif, currdif);
            l++;
            r++;
        }
        return mindif;
    }
};