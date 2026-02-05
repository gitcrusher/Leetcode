class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefix(n+1,0); //n+1 ka isi liye kyunki prefix sum ka pehla index hi hota hai 
        for(int i = 0 ; i < n; i++){
            prefix[i+1] = prefix[i]+nums[i];
        }
        int res = INT_MAX;
        for(int i  =0 ; i < n; i++){
            long long need = prefix[i]+target;

            int low = i+1;
            int high = n;
            int ans = -1;

            while(low<=high){
                int mid = low+(high-low)/2;
                if(prefix[mid]>=need){
                    ans = mid;
                    high = mid-1;
                }else{
                    low = mid+1;
                }
            }
            if(ans!=-1){
                res=min(res,ans-i);
            }
        }
        return res ==INT_MAX?0:res;
    }
};