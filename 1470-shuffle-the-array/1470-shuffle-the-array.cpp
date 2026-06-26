class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int>ans;
        int l= 0 ;
        int r = (nums.size()/2);
        for(int i = 0 ; i < nums.size(); i++){
            if(i%2==0){
                ans.push_back(nums[l]);
                l++;
            }      
            else {
                ans.push_back(nums[r]);
                r++;
            }
        }
        return ans;
    }
};