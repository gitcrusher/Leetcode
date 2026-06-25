class Solution {
public:
    string reverseVowels(string s) {
        int l = 0; 
        int r = s.size()-1;
        while(l<=r){
            bool leftvowels =  s[l] == 'a' || s[l] == 'e' || s[l] == 'i' || s[l] == 'o' || s[l] == 'u'||s[l] == 'A' || s[l] == 'E' || s[l] == 'I' || s[l] == 'O' || s[l] == 'U';

            bool rightvowels =  s[r] == 'a' || s[r] == 'e' || s[r] == 'i' || s[r] == 'o' || s[r] == 'u'||s[r] == 'A' || s[r] == 'E' || s[r] == 'I' || s[r] == 'O' || s[r] == 'U';

            if(leftvowels&&rightvowels) swap(s[l++],s[r--]);
            else if(leftvowels) r--;
            else if(rightvowels) l++;
            else{
                l++;
                r--;
            }

        }
        return s;
    }
};