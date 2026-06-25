class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>mapstot;
        unordered_map<char,char>mapttos;

        for(int i = 0 ; i <s.size(); i ++){
            // for s->t
            if(mapstot.count(s[i])){
                if(mapstot[s[i]]!=t[i])return false;
            }else{
                mapstot[s[i]]=t[i];
            }

            if(mapttos.count(t[i])){
                if(mapttos[t[i]]!=s[i])return false;
            }else{
                mapttos[t[i]]=s[i];
            }
        }
        return true;
    }
};