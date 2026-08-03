class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l = 0 , r = 0;
        int maxi = 0;
        unordered_map<int , int> mp;
        if(fruits.size()<=1) return fruits.size();
        while(r<fruits.size()){
            mp[fruits[r]]++;
            while(mp.size()>2){
                mp[fruits[l]]--;
                if(mp[fruits[l]]==0)mp.erase(fruits[l]);
                l++;
            }
            maxi = max(maxi,r-l+1);
            r++;
        }
        return maxi;
    }
};