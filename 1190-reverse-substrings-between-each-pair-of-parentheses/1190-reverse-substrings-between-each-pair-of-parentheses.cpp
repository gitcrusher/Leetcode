class Solution {
public:
    string reverseParentheses(string s) {
        stack<char>st;
        int open = 0;
        for(int i = 0 ; i < s.size();i++){
            if(s[i]=='('){
                st.push('(');
                open++;
            }
            else if(s[i]==')'){
                vector<char>rev;
                while(st.top()!='('){
                    char ele = st.top();
                    rev.push_back(ele);
                    st.pop();
                }
                st.pop() ;//removes (
                reverse(begin(rev),end(rev));
                for(int j = rev.size() - 1; j >= 0; j--) {
                    st.push(rev[j]);
                }
                open--;
            }else{
                st.push(s[i]);
            }
            
        }
        string a = "";  
        while(!st.empty()){
            a+=st.top();
            st.pop();
        }
        reverse(begin(a),end(a));
        return a;
    }
    
};