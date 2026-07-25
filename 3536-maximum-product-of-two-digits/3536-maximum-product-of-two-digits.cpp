class Solution {
public:
    int maxProduct(int n) {
        
        int maxi = -1 ; 
        int ans = -1;
        while(n>0){
            int digit = n%10;
            if(digit>maxi){
                ans = maxi;
                maxi = digit;
            }
            else if(digit>ans){
                ans = digit;
            }
            n/=10;
        }
        return maxi*ans;
        
    }
};