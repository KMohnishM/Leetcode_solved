class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> freq;

        for (int x : nums)
            freq[x]++;

        int ans = 1;

        
        if (freq.count(1)) {
            int cnt = freq[1];
            ans = max(ans, (cnt % 2) ? cnt : cnt - 1);
        }

        for (auto &[start, cnt] : freq) {
            if (start == 1) continue;

            long long cur = start;
            int len = 0;

            while (true) {
                if (!freq.count(cur))
                    break;

                if (freq[cur] == 1) {
                    len++;
                    break;
                }

                long long nxt = cur * cur;
                if (!freq.count(nxt)) {
                    len++;
                    break;
                }

                len += 2;
                cur = nxt;
            }

            ans = max(ans, len);
        }

        return ans;
    }
};
