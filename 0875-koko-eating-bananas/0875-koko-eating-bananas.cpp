class Solution {
public:

    bool isValid(vector<int>& nums, int mid ,int h){
        long long sum = 0 ;
        for(int i = 0; i<nums.size();i++ ){
            sum+=(nums[i]+mid-1)/mid;
        }
        if(sum<=h)return true;
        else return false;

    }


    int minEatingSpeed(vector<int>& piles, int h) {
        //sort(piles.begin(),piles.end());
        int n = piles.size();
        // int low = 0 ; low 0 nahi ho sakta kyunki yahan pr speed zero nahi hai.
        int low =1;
        int high = *max_element(piles.begin(),piles.end());
        int ans = 0;

        while(low<=high){
            int mid = low+(high - low)/2;
            if(isValid(piles,mid, h)==true){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};