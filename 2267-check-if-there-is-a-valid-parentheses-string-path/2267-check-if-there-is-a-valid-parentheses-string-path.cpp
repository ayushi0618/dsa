class Solution {
private:
    int m, n;
    int memo[100][100][201]; // memoization table for (row, col, open_count)

    bool dfs(int r, int c, int count, const vector<vector<char>>& grid) {
        // If we hit a closing bracket that outnumbers our opening brackets, invalid path
        if (grid[r][c] == '(') {
            count++;
        } else {
            count--;
        }
        
        if (count < 0) return false;

        // Base case: reached bottom-right cell
        if (r == m - 1 && c == n - 1) {
            return count == 0;
        }

        if (memo[r][c][count] != -1) {
            return memo[r][c][count];
        }

        bool res = false;
        // Move Down
        if (r + 1 < m) {
            res = res || dfs(r + 1, c, count, grid);
        }
        // Move Right
        if (!res && c + 1 < n) {
            res = res || dfs(r, c + 1, count, grid);
        }

        return memo[r][c][count] = res;
    }

public:
    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        // Length of any path must be even for valid parentheses
        if ((m + n - 1) % 2 != 0) return false;

        memset(memo, -1, sizeof(memo));
        return dfs(0, 0, 0, grid);
    }
};