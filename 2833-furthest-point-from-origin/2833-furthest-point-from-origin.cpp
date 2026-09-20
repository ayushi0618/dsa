class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int leftCount = 0;
        int rightCount = 0;
        int underscoreCount = 0;
        
        for (char c : moves) {
            if (c == 'L') {
                leftCount++;
            } else if (c == 'R') {
                rightCount++;
            } else {
                underscoreCount++;
            }
        }
        
        // Maximize the distance by pushing all underscores in the direction 
        // that already has more momentum
        return abs(rightCount - leftCount) + underscoreCount;
    }
};