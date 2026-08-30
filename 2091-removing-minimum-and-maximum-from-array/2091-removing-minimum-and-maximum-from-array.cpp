class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if(n<=1)return n;
        int maxi = *max_element(begin(nums),end(nums));
        int mini = *min_element(begin(nums),end(nums));
        int mid = nums.size()/2 ;
        int count = 0;
        int maxidx = 0;
        int minidx = 0;
        for(int i = 0 ; i < nums.size(); i++){
            if(nums[i]== maxi) maxidx = i;
            if(nums[i]== mini) minidx = i;
        }
        
        int front = max(maxidx, minidx) + 1; 
        int back = n - min(maxidx, minidx); 
        int mixed1 = maxidx + 1 + n - minidx; 
        int mixed2 = minidx + 1 + n - maxidx; 
        return min({front, back, mixed1, mixed2});
    }
};