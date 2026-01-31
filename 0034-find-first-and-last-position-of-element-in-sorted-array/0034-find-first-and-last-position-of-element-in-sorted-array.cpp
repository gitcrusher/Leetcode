class Solution {
public:
    int first(vector <int>& nums, int target){
        int low = 0 , result = -1;
        int high = nums.size()-1;
        while(low <=high){
            int mid = low + (high-low)/2;
            if(nums[mid] == target){
                result = mid; 
                high =  mid -1;
            }else if (nums[mid]<target){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return result;
    }

    int last(vector <int>& nums, int target){
        int low = 0 , result = -1;
        int high = nums.size()-1;
        while(low <=high){
            int mid = low + (high-low)/2;
            if(nums[mid] == target){
                result = mid; 
                low = mid+1;
            }else if (nums[mid]<target){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return result;
    }

    
    vector<int> searchRange(vector<int>& nums, int target) {
        return{first(nums,target),last(nums, target)};
    }
};