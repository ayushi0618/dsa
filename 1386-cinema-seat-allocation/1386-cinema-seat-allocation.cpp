#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        // Map to store the bitmask of obstructed blocks for each row
        unordered_map<int, char> row_masks;
        
        for (const auto& seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];
            
            // Set bits based on which blocks the reserved seat falls into
            if (col >= 2 && col <= 5) {
                row_masks[row] |= 1; // Obstructs Left (seats 2-5)
            }
            if (col >= 4 && col <= 7) {
                row_masks[row] |= 2; // Obstructs Middle (seats 4-7)
            }
            if (col >= 6 && col <= 9) {
                row_masks[row] |= 4; // Obstructs Right (seats 6-9)
            }
        }
        
        // Rows with no reserved seats can always fit 2 groups
        int max_groups = (n - row_masks.size()) * 2;
        
        // Evaluate rows that have at least one reserved seat
        for (const auto& [row, mask] : row_masks) {
            // If neither Left nor Right are obstructed (mask & 5 == 0)
            if ((mask & 1) == 0 && (mask & 4) == 0) {
                max_groups += 2;
            } 
            // Otherwise, if AT LEAST ONE block is still free
            else if ((mask & 1) == 0 || (mask & 2) == 0 || (mask & 4) == 0) {
                max_groups += 1;
            }
        }
        
        return max_groups;
    }
};