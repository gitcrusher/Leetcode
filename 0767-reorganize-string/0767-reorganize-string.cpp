class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char ,int>freq;
        for(char c: s){
            freq[c]++;
            if(freq[c]>(s.size()+1)/2) return "";
        }

        priority_queue<pair<int ,char>>pq;
        for(auto &i: freq ){
            pq.push({i.second,i.first});
        }

        string a = "";
        
        while(pq.size() >=2){
            auto first = pq.top(); pq.pop(); 
            auto second = pq.top(); pq.pop();
            a.push_back(first.second);
            a.push_back(second.second);
            first.first--;
            second.first--;
            if(first.first>0)pq.push(first);
            if(second.first>0)pq.push(second);
        }

        if(!pq.empty()){
            a.push_back(pq.top().second);
        }
        return a;
    }
};