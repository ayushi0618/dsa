class Solution {
private:
    bool isValid(const string& str) {
        int count = 0;
        for (char c : str) {
            if (c == '(') count++;
            else if (c == ')') count--;
            if (count < 0) return false;
        }
        return count == 0;
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
        if (s.empty()) return {""};

        unordered_set<string> visited;
        queue<string> q;

        q.push(s);
        visited.insert(s);
        bool found = false;

        while (!q.empty()) {
            int size = q.size();
            unordered_set<string> currentLevel;

            for (int i = 0; i < size; ++i) {
                string curr = q.front();
                q.pop();

                if (isValid(curr)) {
                    result.push_back(curr);
                    found = true;
                }

                if (found) continue;

                // Generate all possible states by removing one parenthesis
                for (int j = 0; j < curr.length(); ++j) {
                    if (curr[j] != '(' && curr[j] != ')') continue;

                    string next = curr.substr(0, j) + curr.substr(j + 1);
                    if (visited.find(next) == visited.end()) {
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }
            if (found) break;
        }

        return result;
    }
};