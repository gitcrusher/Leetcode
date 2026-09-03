class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int countodd = 0;
        int counteve = 0;
        int minodd = INT_MAX;
        int mineve = INT_MAX;
        int n = nums1.size();

        for(int i = 0; i < n; i++) {
            if(nums1[i] % 2 != 0) {
                countodd++;
                minodd = min(minodd, nums1[i]);
            }
            else {
                counteve++;
                mineve = min(mineve, nums1[i]);
            }
        }

        // Already uniform
        if(countodd == 0 || counteve == 0)
            return true;

        // Make every even number odd
        //smallest odd can be subtracted from every even number will give us odd only no change 
        if(minodd < mineve)
            return true;

        return false;
    }
};