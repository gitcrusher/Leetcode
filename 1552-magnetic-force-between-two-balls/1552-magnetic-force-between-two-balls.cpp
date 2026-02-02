bool canWePlace(vector<int>& arr, int force, int x){
    int Count = 1;
    int lastPos = arr[0];
    
    for(int i=0; i<arr.size(); i++){
        if(arr[i] - lastPos >= force){
            Count++;
            lastPos = arr[i];
        }
    }
    if(Count >= x) return true;
    else return false;
}

class Solution {
  public:
    int maxDistance(vector<int> &arr, int x) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        
        int low = 0;
        int high = arr[n-1] - arr[0];
        int ans = 0;
        
        while(low<=high){
            int mid = low+(high-low)/2;
            if(canWePlace(arr,mid,x) == true){
                ans = mid;
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return ans;
    }
};