class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0 ; 
        int high = nums.size()-1;
        int n = nums.size();

        while(low<=high){

            int mid = low + (high -low)/2;

            //for mid == minimum number then minimum 3 element should be present.
            // with mid cant be 0 as well that means there is only 1 element is present. 
            if (mid > 0 && mid < n-1 &&
                nums[mid-1] > nums[mid] &&
                nums[mid+1] > nums[mid]) {
                return nums[mid];
            }


            if(nums[mid]>nums[high]){
/*
here in above if(nums[mid]>nums[high]) this condition i was using if(nums[mid]>nums[mid+1])
-> it would fail at edge case where there woudl be only 1 element;

USAGE OF if(nums[mid]>nums[high]):
-> here we consider the left side of sorted array to be alwaysa sorted which means 
    if(nums[mid]>nums[low]) is alwys true;
-> thats why we use if(nums[mid]>nums[high]) to check for the right side only; 
*/
                low = mid+1;
            }else{
                high=mid-1;
            }
        }
        return nums[low];
    }
};