#include <string>
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
    bool isIsomorphic(const std::string& s, const std::string& t) {
        if (s.size() != t.size()) return false;

        std::unordered_map<char, char> mp;        // s‑char → t‑char
        std::unordered_set<char> usedInT;         // targets already taken

        for (size_t i = 0; i < s.size(); ++i) {
            char a = s[i];
            char b = t[i];

            /* ---------- 1. self‑mapping case ---------- */
            if (a == b) {
                auto it = mp.find(a);

                if (it == mp.end()) {             // first time we meet ‘a’
                    if (usedInT.count(b))         // some other letter uses ‘b’
                        return false;
                    mp[a] = b;                    // store a → a
                    usedInT.insert(b);
                } else if (it->second != b) {     // ‘a’ mapped to something else
                    return false;
                }
                continue;                         // go to next character pair
            }

            /* ---------- 2. ordinary case (a ≠ b) ---------- */
            auto it = mp.find(a);

            if (it == mp.end()) {                 // first time we meet ‘a’
                if (usedInT.count(b))             // ‘b’ already taken
                    return false;
                mp[a] = b;
                usedInT.insert(b);
            } else if (it->second != b) {         // conflicting mapping
                return false;
            }
        }
        return true;
    }
};

