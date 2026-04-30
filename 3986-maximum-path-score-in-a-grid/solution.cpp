class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        dp[0][0] = 0;

        for (int i = 0; i < m; i++) {
            vector<vector<int>> new_dp(n, vector<int>(k + 1, -1));

            for (int j = 0; j < n; j++) {
                int cell_cost = (grid[i][j] == 0 ? 0 : 1);

                for (int c = 0; c <= k; c++) {

                    
                    if (dp[j][c] != -1) {
                        int nc = c + cell_cost;
                        if (nc <= k) {
                            new_dp[j][nc] = max(new_dp[j][nc], dp[j][c] + grid[i][j]);
                        }
                    }
                    if (j > 0 && new_dp[j-1][c] != -1) {
                        int nc = c + cell_cost;
                        if (nc <= k) {
                            new_dp[j][nc] = max(new_dp[j][nc], new_dp[j-1][c] + grid[i][j]);
                        }
                    }
                }
            }

            dp = new_dp;
        }

        int ans = *max_element(dp[n - 1].begin(), dp[n - 1].end());
        return ans == -1 ? -1 : ans;
    }
};
