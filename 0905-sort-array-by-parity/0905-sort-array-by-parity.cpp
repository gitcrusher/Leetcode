class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int l=0;
        int r=0;
        while(r<nums.size()){
            if(nums[l]%2==0 && nums[r]%2==0){
                l++;
                r++;
            }else if(nums[l]%2!=0 && nums[r]%2!=0){
                r++;
            }else swap(nums[l++],nums[r++]);

        }
        return nums;
    }
};