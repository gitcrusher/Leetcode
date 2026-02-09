class Solution {
public:
    string decodeString(string s) {
        stack<string>st;
        for (int i = 0 ; i < s.size(); i++){
            if(s[i]!=']'){
                st.push(string(1,s[i]));
            }else{
                string curr= "";
                while(!st.empty() && st.top() != "["){
                    curr = st.top()+curr;
                    st.pop();
                }

                st.pop();

                string num = "";
                while(!st.empty() && isdigit(st.top()[0])){
                    num =  st.top()+num;
                    st.pop();
                }

                int k = stoi(num);

                string expanded ="";
                for(int j = 0; j < k; j++){
                    expanded += curr;
                }
                st.push(expanded);
            }
        }
        string ans = "";
        while(!st.empty()){
            ans = st.top()+ans;
            st.pop();
        }
        return ans;
    }
};