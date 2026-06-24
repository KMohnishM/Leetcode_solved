class Solution {
public:
    static const long long MOD = 1000000007LL;

    using Matrix = vector<vector<long long>>;

    Matrix multiply(const Matrix& A, const Matrix& B) {
        int n = A.size();
        Matrix C(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (A[i][k] == 0) continue;

                long long aik = A[i][k];

                for (int j = 0; j < n; j++) {
                    if (B[k][j] == 0) continue;

                    C[i][j] =
                        (C[i][j] + aik * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }

    Matrix power(Matrix base, long long exp) {
        int n = base.size();

        Matrix res(n, vector<long long>(n, 0));
        for (int i = 0; i < n; i++)
            res[i][i] = 1;

        while (exp) {
            if (exp & 1)
                res = multiply(res, base);

            base = multiply(base, base);
            exp >>= 1;
        }

        return res;
    }

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        int S = 2 * m;

        auto UP = [&](int v) {
            return v - 1;
        };

        auto DOWN = [&](int v) {
            return m + (v - 1);
        };

        
        vector<long long> init(S, 0);

        for (int v = 1; v <= m; v++) {
            init[UP(v)] = v - 1;
            init[DOWN(v)] = m - v;
        }

        if (n == 2) {
            long long ans = 0;
            for (auto x : init)
                ans = (ans + x) % MOD;
            return (int)ans;
        }

        Matrix T(S, vector<long long>(S, 0));

        for (int v = 1; v <= m; v++) {

        
            for (int u = 1; u < v; u++) {
                T[UP(v)][DOWN(u)] = 1;
            }

        
            for (int u = v + 1; u <= m; u++) {
                T[DOWN(v)][UP(u)] = 1;
            }
        }

        Matrix P = power(T, n - 2);

        vector<long long> finalState(S, 0);

        for (int i = 0; i < S; i++) {
            for (int j = 0; j < S; j++) {
                finalState[i] =
                    (finalState[i] + P[i][j] * init[j]) % MOD;
            }
        }

        long long ans = 0;
        for (auto x : finalState)
            ans = (ans + x) % MOD;

        return (int)ans;
    }
};
