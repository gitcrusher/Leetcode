class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string , int> freq;
        for(string &w :words){
            freq[w]++;
        }
        
         auto comp = [](const pair<int,string>& a,
                       const pair<int,string>& b) {
            if (a.first == b.first)
                return a.second > b.second;  
            return a.first < b.first;        
        };

         priority_queue<
            pair<int,string>,
            vector<pair<int,string>>,
            decltype(comp)
        > pq(comp);

        for(auto &c: freq){
            pq.push({c.second, c.first});
        }
        vector<string> v;
        while(k--){
            auto top = pq.top();
            pq.pop();
            v.push_back(top.second);
        }
    return v;
    }
};