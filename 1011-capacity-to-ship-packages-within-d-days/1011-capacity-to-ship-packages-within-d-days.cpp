class Solution {
public:
    bool isValid(vector<int>& weights, int n , int days, int mid){
        int curr = 0; 
        int countdays = 1;
        for(int i = 0 ; i < n ; i++){
            if(curr+weights[i]<=mid) curr+=weights[i];
            else {
                countdays++;
                curr = weights[i];
            }
        }
        return countdays<=days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        if(days>n)return -1;

        int a = weights[0];
        for(int i  = 0 ; i < n; i++){
            a = max(a,weights[i]);
        }
        int sum = 0;
        for(int i = 0 ; i < n ; i++){
            sum+=weights[i];
        }

        int low = a ; 
        int high = sum;
        int result = 0 ; 
        while(low <= high){
            int mid = low +(high-low)/2;
            if(isValid(weights, n , days,mid)){
                result = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return result;
    }
};