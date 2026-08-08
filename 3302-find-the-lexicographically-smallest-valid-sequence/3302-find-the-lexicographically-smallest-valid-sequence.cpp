class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int  n = word1.size(); 
        int  m = word2.size();
        vector<int>rightsidematchlen(n,0);
        int rightmatched = 0;
        int i = n-1;
        int j = m-1;

        while(i>=0){
            if(j>=0 && word1[i]==word2[j]){
                rightmatched++;
                j--;
            }
            rightsidematchlen[i] = rightmatched;
            i--;
        } 

        vector<int>seq;
        bool canchangeval = true;
        i = 0, j =0;
        while(i<n && j<m){
            if(word1[i]==word2[j]){
                seq.push_back(i);
                j++;
            }else if(canchangeval == true && i+1<n && rightsidematchlen[i+1]>=m-j-1){
                seq.push_back(i);
                j++;
                canchangeval = false;
            }
            i++;
        }
        return j==m ? seq:vector<int>();
    }
};