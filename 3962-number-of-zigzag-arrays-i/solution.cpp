class Solution {
public:
    static constexpr long long MOD = 1e9 + 7;

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        vector<long long> up(m + 1), down(m + 1);
        vector<long long> newUp(m + 1), newDown(m + 1);

        for (int v = 1; v <= m; v++) {
            up[v] = v - 1;
            down[v] = m - v;
        }

        for (int len = 3; len <= n; len++) {

            long long pref = 0;
            for (int v = 1; v <= m; v++) {
                newUp[v] = pref;
                pref = (pref + down[v]) % MOD;
            }

            long long totalUp = 0;
            for (int v = 1; v <= m; v++)
                totalUp = (totalUp + up[v]) % MOD;

            long long suffix = totalUp;
            for (int v = 1; v <= m; v++) {
                suffix = (suffix - up[v] + MOD) % MOD;
                newDown[v] = suffix;
            }

            up.swap(newUp);
            down.swap(newDown);
        }

        long long ans = 0;
        for (int v = 1; v <= m; v++) {
            ans = (ans + up[v] + down[v]) % MOD;
        }

        return (int)ans;
    }
};
