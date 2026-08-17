class Solution {
public:
    string convert(string s, int numRows) {
        // Edge case: If there's only 1 row or the string is shorter than the rows, 
        // the zigzag pattern is identical to the original string.
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }
        
        // Create a vector of strings for each row. 
        // We only need as many rows as the string length if the string is very short.
        vector<string> rows(min(numRows, int(s.length())));
        int curRow = 0;
        bool goingDown = false;
        
        // Traverse the string and place characters in the correct row
        for (char c : s) {
            rows[curRow] += c;
            
            // Change direction when we hit the top or bottom row bounds
            if (curRow == 0 || curRow == numRows - 1) {
                goingDown = !goingDown;
            }
            
            // Move up or down the rows
            curRow += goingDown ? 1 : -1;
        }
        
        // Concatenate all rows into the final result
        string result = "";
        for (const string& row : rows) {
            result += row;
        }
        
        return result;
    }
};