class Solution {
public:
    void subset(vector<int>b,vector<int>&nums, vector<vector<int>>&a, int indx){
        if(indx==nums.size()){
            a.push_back(b);
            return;
        }
        subset(b,nums,a,indx+1);

        b.push_back(nums[indx]);
        subset(b,nums,a,indx+1);
    }

    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>>a;
        vector<int>  b;
        subset(b,nums,a,0);
        int sum = 0 ;
        for(auto v: a){
            int x = 0 ; 
            for(auto ele:v){
                x^=ele;
            }
            sum+=x;
        }
        return sum;
    }
};