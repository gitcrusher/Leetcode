class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        // 3,5,6,7 t =9
        // 
        //
        //
        //


        sort(begin(nums), end(nums));
        int n = nums.size();
        int M = 1e9+7;
        int l = 0 ; 
        int r = n-1;
        int result = 0;
        // now we have to use recomputation here as pow(if failing and increasing the complexity)
        vector<int>power(n);
        power[0] =1;
        for(int i = 1 ; i < n ; i++){
            power[i] = (power[i-1]*2) % M;
        }

        while(l<=r){
            if(nums[l]+nums[r]<=target){
                result= (result%M + power[r-l])%M;
                l++;
            }
            else r--;
        }
        return result; 
    }
};