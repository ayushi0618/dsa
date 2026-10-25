#include <vector>

class Solution {
private:
    void dfs(int r, int c, std::vector<std::vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        // Check bounds and if the current cell is water (1)
        if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == 1) {
            return;
        }
        
        // Mark the land as visited by turning it into water (1)
        grid[r][c] = 1;
        
        // Traverse all 4 directions
        dfs(r + 1, c, grid);
        dfs(r - 1, c, grid);
        dfs(r, c + 1, grid);
        dfs(r, c - 1, grid);
    }

public:
    int closedIsland(std::vector<std::vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        // Step 1: Eliminate all 0s connected to the boundaries
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if ((i == 0 || i == rows - 1 || j == 0 || j == cols - 1) && grid[i][j] == 0) {
                    dfs(i, j, grid);
                }
            }
        }
        
        // Step 2: Count the remaining closed islands in the interior
        int closedIslandsCount = 0;
        for (int i = 1; i < rows - 1; ++i) {
            for (int j = 1; j < cols - 1; ++j) {
                if (grid[i][j] == 0) {
                    closedIslandsCount++;
                    dfs(i, j, grid);
                }
            }
        }
        
        return closedIslandsCount;
    }
};