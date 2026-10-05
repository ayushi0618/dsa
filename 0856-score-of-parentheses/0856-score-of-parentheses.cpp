class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0); // Base score for the current level
        
        for (char c : s) {
            if (c == '(') {
                st.push(0);
            } else {
                int v = st.top();
                st.pop();
                int val = (v == 0 ? 1 : 2 * v);
                st.top() += val;
            }
        }
        return st.top();
    }
};