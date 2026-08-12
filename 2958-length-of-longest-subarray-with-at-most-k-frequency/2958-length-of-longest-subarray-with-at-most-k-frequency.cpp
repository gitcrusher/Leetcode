class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int , int>mp;
        int r = 0 ; 
        int l  = 0;
        int maxi = 0;
        int n = nums.size();
        if(n<=1&&k<=1)return n;
        while(r<nums.size()){
            if(mp.find(nums[r])!=mp.end()){
                if(mp[nums[r]]<k){
                    mp[nums[r]]++;
                    r++;
                    
                }else{
                    while(mp[nums[r]]>=k){
                        mp[nums[l]]--;
                        l++;
                    }
                }
            }
            else{
                mp[nums[r]]++;
                r++;
            }
            maxi = max(maxi, r-l);
        }
        return maxi;
    }
};