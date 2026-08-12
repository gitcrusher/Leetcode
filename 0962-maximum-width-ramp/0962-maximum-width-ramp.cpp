class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<int> rightmax(n,0);
        rightmax[n-1] = nums[n-1];
        // creating the max value...
        for(int i = n-2; i >=0 ; i--){
            rightmax[i]= max(rightmax[i+1],nums[i]);
        }
        int maxi = 0;
        int i = 0 ; 
        int j = 0;
        while(j<n){
            if(i<j && nums[i]>rightmax[j]){
                i++;
            }
                maxi = max(maxi, j-i);
                j++; 
        }
        return maxi;
    }
};