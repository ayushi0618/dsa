class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.length();
        int sign = 1;
        int result = 0;
        
        // 1. Ignore leading whitespace
        while (i < n && s[i] == ' ') {
            i++;
        }
        
        // 2. Determine the sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        
        // 3. Convert characters to integer
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';
            
            // 4. Handle rounding / overflow before it happens
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > 7)) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            
            result = result * 10 + digit;
            i++;
        }
        
        return result * sign;
    }
};