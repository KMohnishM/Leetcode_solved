class Solution {
public:
    int lengthOfLongestSubstring(string_view s) {
        const int n = static_cast<int>(s.size());
        int best = 0;

        for (int i = 0; i < n; ++i) {
            unordered_set<char> seen;
            // Early cut‑off: if the remaining chars can’t beat current best
            if (n - i <= best) break;

            for (int j = i; j < n; ++j) {
                char c = s[j];
                if (seen.count(c)) break;      // duplicate found, stop growing
                seen.insert(c);
                best = max(best, j - i + 1);   // update answer
            }
        }
        return best;
    }
};

