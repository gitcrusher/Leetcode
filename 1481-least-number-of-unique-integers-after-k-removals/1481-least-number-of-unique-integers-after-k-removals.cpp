class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int>freq;
        for(int c: arr){
            freq[c]++;
        }

        priority_queue<pair<int, int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
        >pq;

        for(auto c:freq){
            pq.push({c.second,c.first});
        }

        while(k--){
            auto top = pq.top();
            pq.pop();
            
            // for(int i = 0 ;i < arr.size();i++){
            //     if(arr[i]==top.second){
            //         arr.erase(arr.begin()+i);
            //     }
            // }
            top.first--;
            if(top.first>0)pq.push(top);    
        }
    return pq.size();    
    }
};