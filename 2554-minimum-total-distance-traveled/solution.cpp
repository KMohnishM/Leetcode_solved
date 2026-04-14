class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        
        vector<int> slots;
        for (auto &f : factory) {
            int pos = f[0], limit = f[1];
            while (limit--) slots.push_back(pos);
        }

        int n = robot.size(), m = slots.size();

       
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 1e18));

       
        for (int j = 0; j <= m; j++) dp[0][j] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = dp[i][j-1];
                dp[i][j] = min(dp[i][j],
                    dp[i-1][j-1] + abs(robot[i-1] - slots[j-1]));
            }
        }

        return dp[n][m];
    }
};
