class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {

        const int MOD = 1e9+7;

        vector<vector<vector<int>>> dp(
            zero+1, vector<vector<int>>(one+1, vector<int>(2,0))
        );

        for(int i=1;i<=min(zero,limit);i++)
            dp[i][0][0] = 1;

        for(int i=1;i<=min(one,limit);i++)
            dp[0][i][1] = 1;

        for(int z=1; z<=zero; z++){
            for(int o=1; o<=one; o++){

                dp[z][o][0] =
                    (dp[z-1][o][0] + dp[z-1][o][1]) % MOD;

                if(z-limit-1 >= 0)
                    dp[z][o][0] =
                        (dp[z][o][0] - dp[z-limit-1][o][1] + MOD) % MOD;

                dp[z][o][1] =
                    (dp[z][o-1][0] + dp[z][o-1][1]) % MOD;

                if(o-limit-1 >= 0)
                    dp[z][o][1] =
                        (dp[z][o][1] - dp[z][o-limit-1][0] + MOD) % MOD;
            }
        }

        return (dp[zero][one][0] + dp[zero][one][1]) % MOD;
    }
};
