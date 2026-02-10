class Solution {
public:
    string simplifyPath(string path) {
        string token;
        stringstream ss(path);
        stack<string> st;

        while (getline(ss, token, '/')) {
            if (token == "" || token == ".") {
                continue;
            } 
            else if (token == "..") {
                if (!st.empty()) st.pop();
            } 
            else {
                st.push(token);
            }
        }

        // Build the result path
        string result = "";
        while (!st.empty()) {
            result = "/" + st.top() + result;
            st.pop();
        }

        return result.empty() ? "/" : result;
    }
};
