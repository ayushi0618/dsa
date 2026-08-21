class Solution {
private:
    const vector<string> phoneMap = {
        "",     // 0
        "",     // 1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz"  // 9
    };

    void backtrack(int index, const string& digits, string& current, vector<string>& result) {
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }

        int digit = digits[index] - '0';
        string letters = phoneMap[digit];

        for (char letter : letters) {
            current.push_back(letter);
            backtrack(index + 1, digits, current, result);
            current.pop_back(); // backtrack
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) {
            return result;
        }
        string current = "";
        backtrack(0, digits, current, result);
        return result;
    }
};