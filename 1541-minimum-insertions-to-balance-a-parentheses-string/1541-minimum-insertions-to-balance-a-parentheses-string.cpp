class Solution {
public:
    int minInsertions(string s) {
        stack<char> st;
        int insertions = 0;
        int n = s.length();

        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                st.push('(');
            } else {
                // If we see ')', check if there is a second consecutive ')'
                if (i + 1 < n && s[i + 1] == ')') {
                    i++; // Skip the next ')' since we consume them in pairs
                } else {
                    // Only one ')' found, we need to insert another ')'
                    insertions++;
                }

                // Now match with an opening parenthesis from the stack
                if (!st.empty()) {
                    st.pop();
                } else {
                    // No matching '(', so we need to insert an opening '('
                    insertions++;
                }
            }
        }

        // Each remaining '(' in the stack needs two ')'
        insertions += st.size() * 2;

        return insertions;
    }
};