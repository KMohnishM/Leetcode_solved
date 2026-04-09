class Solution {
public:
    static const int MOD = 1e9 + 7;

    long long modExp(long long base, long long exp) {
        long long res = 1;
        while (exp) {
            if (exp & 1) res = res * base % MOD;
            base = base * base % MOD;
            exp >>= 1;
        }
        return res;
    }

    long long modInv(long long x) {
        return modExp(x, MOD - 2);
    }

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int B = sqrt(n) + 1;

        vector<long long> mul(n, 1);

        
        vector<vector<vector<tuple<int,int,int>>>> small(B, vector<vector<tuple<int,int,int>>>(B));

        for (auto &q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];

            if (k >= B) {
                
                for (int i = l; i <= r; i += k) {
                    mul[i] = mul[i] * v % MOD;
                }
            } else {
                small[k][l % k].push_back({l, r, v});
            }
        }

       
        for (int k = 1; k < B; k++) {
            for (int rem = 0; rem < k; rem++) {

                int maxLen = (n - rem + k - 1) / k;
                vector<long long> diff(maxLen + 1, 1);

                for (auto &[l, r, v] : small[k][rem]) {

                    
                   int start = l + ((rem - l % k + k) % k);
                    if (start > r) continue;

                    int posL = (start - rem) / k;
                    int posR = (r - rem) / k;

                    diff[posL] = diff[posL] * v % MOD;
                    if (posR + 1 < maxLen)
                        diff[posR + 1] = diff[posR + 1] * modInv(v) % MOD;
                }

                
                long long cur = 1;
                for (int idx = 0, i = rem; i < n; i += k, idx++) {
                    cur = cur * diff[idx] % MOD;
                    mul[i] = mul[i] * cur % MOD;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            long long val = nums[i] * mul[i] % MOD;
            ans ^= (int)val;
        }

        return ans;
    }
};
