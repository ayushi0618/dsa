class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int islandCount = 0;

        auto dfs = [&](auto& self, int r, int c, long long& currentSum) -> void {
            currentSum += grid[r][c];
            grid[r][c] = 0; // Mark as visited

            int dr[] = {-1, 1, 0, 0};
            int dc[] = {0, 0, -1, 1};

            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] > 0) {
                    self(self, nr, nc, currentSum);
                }
            }
        };

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0) {
                    long long currentSum = 0;
                    dfs(dfs, i, j, currentSum);
                    if (currentSum % k == 0) {
                        islandCount++;
                    }
                }
            }
        }

        return islandCount;
    }
};