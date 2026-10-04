class Solution {
public:
    bool checkValidString(string s) {
        int cmin = 0, cmax = 0;
        
        for (char c : s) {
            if (c == '(') {
                cmin++;
                cmax++;
            } else if (c == ')') {
                cmin = max(0, cmin - 1);
                cmax--;
            } else { // c == '*'
                cmin = max(0, cmin - 1); // treat '*' as ')'
                cmax++;                  // treat '*' as '('
            }
            
            if (cmax < 0) return false;
        }
        
        return cmin == 0;
    }
};