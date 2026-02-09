class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        int n = temperatures.size();
        vector<int> v(n, 0);
        stack<int> st;
        st.push(n-1);   // indices store karega

        for (int i = n - 2; i >= 0; i--) {

            while (!st.empty() && temperatures[st.top()] <= temperatures[i]) {
                st.pop();
            }

            if (st.empty()) {
                v[i] = 0;
            } else {
                v[i] = st.top() - i;
            }

            st.push(i);
        }

        return v;
    }
};
    