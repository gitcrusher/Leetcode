class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<
        pair<int,int> , 
        vector<pair<int,int>>, 
        greater<pair<int,int>>
        >pq;
        int n =points.size();

        for(int i = 0; i < n; i++){
            int b = points[i][0];
            int c= points[i][1];
            int dist = b*b+c*c;
            pq.push({dist,i});
        }

        vector<vector<int>>ans;

        while(k--){
            auto top = pq.top();
            pq.pop();
            ans.push_back(points[top.second]);
        }
        return ans;
    }
};