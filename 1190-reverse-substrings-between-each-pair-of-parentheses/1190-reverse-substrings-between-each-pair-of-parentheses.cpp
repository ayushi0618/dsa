class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        
        for (char c : s) {
            if (c == ')') {
                string temp = "";
                // Pop characters until we find the matching '('
                while (!st.empty() && st.top() != '(') {
                    temp += st.top();
                    st.pop();
                }
                // Pop the '(' itself
                if (!st.empty()) {
                    st.pop();
                }
                // Push the reversed characters back onto the stack
                for (char ch : temp) {
                    st.push(ch);
                }
            } else {
                st.push(c);
            }
        }
        
        // Extract the result from the stack
        string result = "";
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        
        // Since stack outputs in reverse order, reverse it to get the correct string
        reverse(result.begin(), result.end());
        return result;
    }
};