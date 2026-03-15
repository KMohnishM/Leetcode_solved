class Fancy {
public:
    const long MOD = 1e9 + 7;

    vector<long> seq;
    long a, b;

    long modpow(long x, long n) {
        long res = 1;
        while (n) {
            if (n & 1) res = (res * x) % MOD;
            x = (x * x) % MOD;
            n >>= 1;
        }
        return res;
    }

    Fancy() {
        a = 1;
        b = 0;
    }

    void append(int val) {
        long inv = modpow(a, MOD - 2);
        long stored = ((val - b) % MOD + MOD) % MOD;
        stored = (stored * inv) % MOD;
        seq.push_back(stored);
    }

    void addAll(int inc) {
        b = (b + inc) % MOD;
    }

    void multAll(int m) {
        a = (a * m) % MOD;
        b = (b * m) % MOD;
    }

    int getIndex(int idx) {
        if (idx >= seq.size()) return -1;
        return (a * seq[idx] + b) % MOD;
    }
};
