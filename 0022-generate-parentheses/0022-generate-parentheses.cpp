class Solution {
private:
    void backtrack(int open, int n, int close, string current, vector<string>& result) {
        // Base case: if the current string length is 2 * n, we have a valid combination
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }
        
        // If we can still add an open parenthesis, do so
        if (open < n) {
            backtrack(open + 1, n, close, current + "(", result);
        }
        
        // If we can add a close parenthesis without violating validity, do so
        if (close < open) {
            backtrack(open, n, close + 1, current + ")", result);
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(0, n, 0, "", result);
        return result;
    }
};