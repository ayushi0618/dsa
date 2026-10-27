class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid(m, string(n, '#'));
        
        // Create the single valid path along the top row
        for (int j = 0; j < n; ++j) {
            grid[0][j] = '.';
        }
        
        // Create the single valid path down the right column
        for (int i = 0; i < m; ++i) {
            grid[i][n - 1] = '.';
        }
        
        return grid;
    }
};