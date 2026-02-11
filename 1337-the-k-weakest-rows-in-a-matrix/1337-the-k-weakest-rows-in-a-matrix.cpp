class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int n = mat.size();
        
        for(int i =0 ; i < n ; i ++){
            int count =0;
            for(int j = 0 ; j<mat[i].size();j++){
                if(mat[i][j]==1){
                    count++;
                }
            }
            pq.push({count ,i});
        }
        vector<int>a;
        while(k--){
            auto top = pq.top();
            pq.pop();
            int index = top.second;
            a.push_back(index);
        }
        return a;
    }
};