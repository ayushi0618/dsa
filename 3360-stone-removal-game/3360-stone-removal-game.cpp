class Solution {
public:
    bool canAliceWin(int n) {
        int removeCount = 10;
        bool aliceTurn = true;

        while (n >= removeCount && removeCount > 0) {
            n -= removeCount;
            removeCount--;
            aliceTurn = !aliceTurn;
        }

        // If aliceTurn is true now, Alice has no valid move left, so she loses.
        // If aliceTurn is false now, Bob has no valid move left, so Alice wins.
        return !aliceTurn;
    }
};