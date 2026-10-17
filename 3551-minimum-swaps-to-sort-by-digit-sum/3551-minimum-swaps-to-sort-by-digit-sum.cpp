class Solution {
private:
    int getDigitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        
        // Store {number, original_index}
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = {nums[i], i};
        }
        
        // Sort based on digit sum, then by value
        sort(arr.begin(), arr.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            int sumA = 0, tempA = a.first;
            while (tempA > 0) { sumA += tempA % 10; tempA /= 10; }
            
            int sumB = 0, tempB = b.first;
            while (tempB > 0) { sumB += tempB % 10; tempB /= 10; }
            
            if (sumA != sumB) return sumA < sumB;
            return a.first < b.first;
        });
        
        // Find the number of cycles to determine minimum swaps
        vector<bool> visited(n, false);
        int cycles = 0;
        
        for (int i = 0; i < n; ++i) {
            // If already visited or already in the correct position
            if (visited[i] || arr[i].second == i) {
                continue;
            }
            
            // Traverse the cycle
            int j = i;
            int cycleSize = 0;
            while (!visited[j]) {
                visited[j] = true;
                j = arr[j].second;
                cycleSize++;
            }
            
            if (cycleSize > 1) {
                cycles += (cycleSize - 1);
            }
        }
        
        return cycles;
    }
};