class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int ans = 0;

        for (int dr = -(n - 1); dr <= n - 1; dr++) {
            for (int dc = -(n - 1); dc <= n - 1; dc++) {

                int count = 0;

                for (int r = 0; r < n; r++) {
                    for (int c = 0; c < n; c++) {

                        if (img1[r][c] == 1) {
                            int nr = r + dr;
                            int nc = c + dc;

                            if (nr >= 0 && nr < n &&
                                nc >= 0 && nc < n &&
                                img2[nr][nc] == 1) {
                                count++;
                            }
                        }
                    }
                }

                ans = max(ans, count);
            }
        }

        return ans;
    }
};