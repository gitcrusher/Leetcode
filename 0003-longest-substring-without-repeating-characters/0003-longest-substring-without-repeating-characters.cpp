class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0 ; 
        int r = 0 ; 
        int maxi = 0;
        unordered_map<char, int>mp;
        while(r<s.size()){
            mp[s[r]]++;
            int window = r-l+1;
            while((r-l+1)>mp.size()){
                mp[s[l]]--;
                if(mp[s[l]]==0) mp.erase(s[l]);
                l++;
            }
            maxi = max(maxi,r-l+1);
            r++;
        }
        return maxi;
    }
};