class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        set<int> s;
        vector<int> ans;

        for(int x : nums)
            s.insert(x);

        vector<int> v(s.begin(), s.end());

        // Missing numbers before first element
        if(v[0] != 1) {
            for(int i = 1; i < v[0]; i++) {
                ans.push_back(i);
            }
        }

        // Missing numbers between elements
        for(int i = 0; i < v.size() - 1; i++) {
            if(v[i + 1] - v[i] > 1) {
                for(int j = v[i] + 1; j < v[i + 1]; j++) {
                    ans.push_back(j);
                }
            }
        }

        // Missing numbers after last element
        if(v.back() != nums.size()) {
            for(int i = v.back() + 1; i <= nums.size(); i++) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};