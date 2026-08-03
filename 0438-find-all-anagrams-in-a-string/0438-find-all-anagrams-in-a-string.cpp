class Solution {
public:
    bool allzero(unordered_map<char, int>& mp){
        for(auto& it: mp){
            if(it.second != 0)return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> mp;
        for(char& c: p)mp[c]++;
        int l = 0, r=0, sum =0;
        vector<int>matched;
        while(r<s.size()){
            //check for the char if its present into map decrease frequency;
            if(mp.find(s[r])!=mp.end())mp[s[r]]--;
            // but we have to check wether on reaching of window upto p.size() wether all the element of map are zeros or not. we also have to shrink the size of window now we would move l.
            if(r-l+1==p.size()){
                //if the size matches then check wether all the element are zeroes or not if all zeroes increase sum value
                if(allzero(mp)) matched.push_back(l);
                // now also have to retain back the map frequency to normal for the element which are not gonna be use or get zero such as "c" in the case of cbaebabacd on its r++ and r = 4
                if(mp.find(s[l])!=mp.end()) mp[s[l]]++;
                // for shrinking
                l++;
            }
            //if char not present in map then not present then r++;
            r++;
        }
        return matched;
    }
};