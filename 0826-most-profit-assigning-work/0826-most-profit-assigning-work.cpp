class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int tp = 0;
        int n = worker.size();
        int m = difficulty.size();
        int maxi = 0;
        for(int i = 0 ; i < n;i++){
            int maxi = 0;
            for(int j = 0 ; j < m;j++){
                if(difficulty[j]<=worker[i]){
                    maxi = max(maxi,profit[j]);
                }
            }
            tp+=maxi;
        }
        return tp;
    }
};