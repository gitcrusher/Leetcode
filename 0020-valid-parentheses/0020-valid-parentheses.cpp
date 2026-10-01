class Solution {
public:
    bool isValid(string s) {
        map<char , char> mp = {
            {')','(' },
            {'}','{' },
            {']','[' }
        };
        stack<char> st;
        for(int i = 0 ; i < s.size(); i++){
            if(s[i]=='('||s[i]=='{' || s[i]=='['){
                st.push(s[i]);
                continue;
            }
            if(st.empty())return false;
            else if(mp[s[i]]==st.top()){
                st.pop();
            }
            else{
                return false;
            }
        }
        return st.empty()?true:false;
    }
};