class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>freq;
        for(char c : s){
            freq[c]++;
        }

        priority_queue<pair<int , char>> pq;

        for(auto c: freq){
            pq.push({c.second, c.first});
        }
        string result;
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            result.append(top.first,top.second);

        }
        return result;
    }
};