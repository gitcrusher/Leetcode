class Solution {
public:
    int first(vector<int>& nums , int x){
        int low = 0 ; int  high = nums.size()-1;
        int res=-1;
        while(low<=high){
            int mid = low +(high-low)/2;
            if(nums[mid]==x){
                res = mid;
                high=mid-1;
            }else if (nums[mid]<x){
                low=mid+1;
            }else{
                high = mid-1;
            }
        }
        return res;
    }

    int last(vector<int>& nums , int x){
        int low = 0 ; int  high = nums.size()-1;
        int res=-1;
        while(low<=high){
            int mid = low +(high-low)/2;
            if(nums[mid]==x){
                res = mid;
                low=mid+1;
            }else if (nums[mid]<x){
                low=mid+1;
            }else{
                high = mid-1;
            }
        }
        return res;
    }

    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int f = first(nums,target);
        if(f==-1)return{};
        int l = last(nums,target);
        vector<int> ans;
        for (int i = f; i <= l; i++) {
        ans.push_back(i);
        }
    return ans;
    }
};