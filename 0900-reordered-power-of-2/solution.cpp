class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string s = to_string(n);
        sort(s.begin(), s.end());

        static unordered_set<string> power2digits;
        if (power2digits.empty()) {
            for (int i = 1; i <= 1e9; i <<= 1) {
                string t = to_string(i);
                sort(t.begin(), t.end());
                power2digits.insert(t);
            }
        }

        return power2digits.count(s);
    }
};

