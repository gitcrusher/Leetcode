class Solution {
public:
int M = 1e9+7;

    int numberOfGoodPartitions(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>last_idx;
        for(int i = 0 ; i < n ;i++){
            last_idx[nums[i]] = i;
        }
        int i = 0;
        int j = 0;
        j = max(j , last_idx[nums[0]]);
        int result = 1;
        while(i<n){
            if(i>j){//we got partition
                result = (result*2)%M;
            }
            j = max(j, last_idx[nums[i]]);
            i++;
        }
        return result;
    }
};