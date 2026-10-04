class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        // Traverse from right to left
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits; // FIX: Return the entire vector, not digits[i]
            }
            digits[i] = 0; // If it was 9, it becomes 0 and carries over
        }
        
        // If the loop finishes, all digits were 9 (e.g., 999 -> 1000)
        vector<int> newDigits(n + 1, 0);
        newDigits[0] = 1;
        return newDigits;
    }
};