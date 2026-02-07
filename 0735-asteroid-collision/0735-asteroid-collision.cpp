class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
       stack<int> st;
       for(int i = 0; i<asteroids.size();i++){
            int val=asteroids[i];
            while(!st.empty()&& st.top()>0 && val<0){
                if(st.top()<-val){
                    st.pop();
                    continue;
                }else if(st.top()==-val){
                    st.pop();
                    val =0;
                    break;
                }else{
                    val=0;
                    break;
                }
            }
        if(val !=0){
            st.push(val);
        }
       }
       vector<int>ans(st.size());
       for(int i = ans.size()-1;i>=0;i--){
        ans[i]=st.top();
        st.pop();
       }
       return ans;
    }
};