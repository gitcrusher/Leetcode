class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1;
        int element = nums[0];
        int n = nums.size();
        for(int i=0; i < n-1; i++){
            if (element==nums[i+1]) count++;
            else if (count==0) element = nums[i];
            else{
                count--;
            }
        }
        return element;
    }
};


// int cnt =0 ; int can = 0 ;
// for(int n:nums){
//     if(cnt==0){
//         can =n;
//     }if(n==can){
//             cnt++;
//         }else{
//         cnt--;
//         }
//         return can;

// }
