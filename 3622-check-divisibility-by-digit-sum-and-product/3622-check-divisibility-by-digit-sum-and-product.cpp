class Solution {
public:
    bool checkDivisibility(int n) {
        int original = n;
        int digitSum = 0;
        int digitProduct = 1;
        
        while (n > 0) {
            int digit = n % 10;
            digitSum += digit;
            digitProduct *= digit;
            n /= 10;
        }
        
        int total = digitSum + digitProduct;
        return original % total == 0;
    }
};