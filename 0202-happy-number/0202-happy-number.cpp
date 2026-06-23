class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int>s;
        while(n!=1){
            if(s.count(n)) return false;
            s.insert(n);
            int happy = 0;
            while(n>0){
                int rem = n%10;
                happy+=rem*rem;
                n/=10;
            }
            n=happy;
        }
        return true;
    }
};