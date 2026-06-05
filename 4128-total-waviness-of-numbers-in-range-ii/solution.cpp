class Solution {
public:
    struct Node {
        long long cnt;
        long long wav;
    };

    string s;

    Node dp[20][2][2][20][11][11];
    bool vis[20][2][2][20][11][11];

    Node dfs(int pos,
             int tight,
             int started,
             int len,
             int last2,
             int last1) {

        if (pos == (int)s.size()) {
            return {1, 0};
        }

        if (vis[pos][tight][started][len][last2][last1])
            return dp[pos][tight][started][len][last2][last1];

        vis[pos][tight][started][len][last2][last1] = true;

        Node ans = {0, 0};

        int lim = tight ? s[pos] - '0' : 9;

        for (int d = 0; d <= lim; d++) {
            int ntight = tight && (d == lim);

            if (!started && d == 0) {
                Node child =
                    dfs(pos + 1, ntight, 0, 0, 10, 10);

                ans.cnt += child.cnt;
                ans.wav += child.wav;
                continue;
            }

            if (!started) {
                Node child =
                    dfs(pos + 1, ntight, 1, 1, 10, d);

                ans.cnt += child.cnt;
                ans.wav += child.wav;
            } else {
                long long add = 0;

                if (len >= 2) {
                    if ((last1 > last2 && last1 > d) ||
                        (last1 < last2 && last1 < d))
                        add = 1;
                }

                Node child =
                    dfs(pos + 1,
                        ntight,
                        1,
                        len + 1,
                        last1,
                        d);

                ans.cnt += child.cnt;
                ans.wav += child.wav + add * child.cnt;
            }
        }

        return dp[pos][tight][started][len][last2][last1] = ans;
    }

    long long solve(long long n) {
        if (n < 0) return 0;

        s = to_string(n);
        memset(vis, 0, sizeof(vis));

        return dfs(0, 1, 0, 0, 10, 10).wav;
    }

    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};
