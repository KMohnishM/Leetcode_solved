class Solution {
public:
    char processStr(string s, long long k) {
        const long long LIM = 1000000000000000LL;

        int n = s.size();
        vector<long long> len(n + 1, 0);

        for (int i = 0; i < n; i++) {
            char ch = s[i];

            if ('a' <= ch && ch <= 'z') {
                len[i + 1] = min(LIM + 1, len[i] + 1);
            }
            else if (ch == '*') {
                len[i + 1] = max(0LL, len[i] - 1);
            }
            else if (ch == '#') {
                len[i + 1] = min(LIM + 1, len[i] * 2);
            }
            else { // %
                len[i + 1] = len[i];
            }
        }

        if (k >= len[n]) return '.';

        long long idx = k;

        for (int i = n - 1; i >= 0; i--) {
            char ch = s[i];

            if ('a' <= ch && ch <= 'z') {
                if (idx == len[i]) return ch;
            }
            else if (ch == '#') {
                if (len[i] > 0)
                    idx %= len[i];
            }
            else if (ch == '%') {
                idx = len[i] - 1 - idx;
            }
            
        }

        return '.';
    }
};
