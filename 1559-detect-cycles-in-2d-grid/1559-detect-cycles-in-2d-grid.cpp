class Solution {
private:
    bool dfs(int r, int c, int prevR, int prevC, char target, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
        visited[r][c] = true;
        
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        
        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            
            // Check boundaries
            if (nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size()) {
                if (grid[nr][nc] == target) {
                    if (visited[nr][nc]) {
                        // If it's visited and NOT the parent we just came from, we found a cycle!
                        if (nr != prevR || nc != prevC) {
                            return true;
                        }
                    } else {
                        if (dfs(nr, nc, r, c, target, grid, visited)) {
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }

public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!visited[i][j]) {
                    if (dfs(i, j, -1, -1, grid[i][j], grid, visited)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};