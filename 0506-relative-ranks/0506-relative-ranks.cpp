class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<string> s(n);
        priority_queue<pair<int , int>>pq;
        for(int i = 0 ; i < score.size(); i++){
            pq.push({score[i],i});
        }
        int count = 1 ; 
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            int idx= top.second;
            if(count == 1) s[idx]="Gold Medal";

                // agar maine yahan if, if condtions hi dall di to issue ye ayega ki pehle
                /*
                if(count == 1) → TRUE  → s[idx] = "Gold Medal"
                if(count == 2) → FALSE
                if(count == 3) → FALSE
                else → TRUE  (kyunki last if false)
                */
                 
            // if(count == 2) s[idx] = "Silver Medal"; 
            // if(count == 3) s[idx] = "Bronze Medal"; 

            else if(count == 2) s[idx]= "Silver Medal";
            else if(count == 3) s[idx]= "Bronze Medal";

            else{
                s[idx]=to_string(count);
            }
            count++;
        }
    return s;
    }
};