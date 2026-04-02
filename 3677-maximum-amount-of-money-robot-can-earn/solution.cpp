class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size(), n = coins[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(3, INT_MIN)));
        for (int k = 0; k <= 2; k++) {
            if (coins[0][0] >= 0)
                dp[0][0][k] = coins[0][0];
            else {
                dp[0][0][k] = coins[0][0];
                if (k > 0)
                    dp[0][0][k] = max(dp[0][0][k], 0);
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;

                for (int k = 0; k <= 2; k++) {
                    int best = INT_MIN;
                    if (i > 0)
                        best = max(best, dp[i-1][j][k]);
                    if (j > 0)
                        best = max(best, dp[i][j-1][k]);

                    if (best == INT_MIN) continue;
                    dp[i][j][k] = max(dp[i][j][k], best + coins[i][j]);

                   
                    if (coins[i][j] < 0 && k > 0) {
                        int bestPrev = INT_MIN;

                        if (i > 0)
                            bestPrev = max(bestPrev, dp[i-1][j][k-1]);
                        if (j > 0)
                            bestPrev = max(bestPrev, dp[i][j-1][k-1]);

                        if (bestPrev != INT_MIN)
                            dp[i][j][k] = max(dp[i][j][k], bestPrev);
                    }
                }
            }
        }

        return max({dp[m-1][n-1][0], dp[m-1][n-1][1], dp[m-1][n-1][2]});
    }
};
