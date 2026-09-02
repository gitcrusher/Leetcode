class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        unordered_map<string, vector<string>>mp;

        for(string s: strs){
            string a = s;
            sort(begin(a),end(a));
            mp[a].push_back(s);
        }
        for(auto i: mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};