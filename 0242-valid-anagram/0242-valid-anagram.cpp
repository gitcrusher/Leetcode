class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())return false; 
        unordered_map<char,int>fors;
        unordered_map<char,int>fort;
        for(char c:s)fors[c]++;
        for(char i:t)fort[i]++;
        return fors==fort;
    }
};