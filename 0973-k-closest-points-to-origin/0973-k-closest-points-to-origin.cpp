class Solution {
public:

/*
Approach: K Closest Points to Origin (Heap)

1.   Har point ka origin se distance nikaalne ke liye
    Euclidean distance ke bajay distance² = x² + y² use kiya
    (kyunki √ monotonic hota hai, comparison ke liye sqrt ki zarurat nahi)

2.    Ek min-heap (priority_queue) banaya jisme:
        key = distance²
        value = point ka index

3.    Sabhi points ko heap me push kiya
    → heap automatically points ko distance ke increasing order me arrange karta hai

4.    Heap se top k elements nikale
    → ye k points origin ke sabse closest hote hain

5.    Nikaale gaye indices ka use karke
    original points array se answer build kiya

6.    Answer ko kisi bhi order me return kiya
    (problem statement ke according order important nahi hai)

*/

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