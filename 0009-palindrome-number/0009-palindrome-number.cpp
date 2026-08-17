class Solution {
public:
    bool isPalindrome(int x) {
        // Edge cases: 
        // 1. Negative numbers are never palindromes.
        // 2. Any number that ends with 0 cannot be a palindrome unless the number is 0 itself.
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int reversedHalf = 0;
        
        // Reverse the second half of the number
        while (x > reversedHalf) {
            reversedHalf = reversedHalf * 10 + x % 10;
            x /= 10;
        }

        // For even length numbers, x == reversedHalf.
        // For odd length numbers, we can get rid of the middle digit using reversedHalf / 10.
        // (e.g., for 12321, at the end x = 12 and reversedHalf = 123).
        return x == reversedHalf || x == reversedHalf / 10;
    }
};