class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // use set  
        int l=0;
        unordered_set<int> s;
        for(int r =0 ; r < nums.size();r++ ){
            if(abs(l-r)>k){
                s.erase(nums[l]);
                l++;
            }

            if(s.find(nums[r])!=s.end()){
                return true;
            }

            s.insert(nums[r]);
        }
        return false;
    }
};