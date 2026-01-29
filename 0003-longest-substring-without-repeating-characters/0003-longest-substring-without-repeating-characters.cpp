class Solution {
public:
    int lengthOfLongestSubstring(string s) {
     int l = 0,r=0;
     int maxi = 0;
     unordered_map<char,int>map;
     while(r<s.length()){
        map[s[r]]++;
        if (map.size()==r-l+1){
            maxi = max(maxi,r-l+1);
            r++;
        }else if(map.size()<r-l+1){
            while(map.size()<r-l+1){
                map[s[l]]--;
                if(map[s[l]]==0){
                    map.erase(s[l]);
                }
                l++;
            }
            r++;
        }
    }   
    return maxi;
    }
};