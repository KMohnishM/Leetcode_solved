class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size();
        int m = s.size();

        sort(g.begin(), g.end());  // sort greed
        sort(s.begin(), s.end());  // sort sizes

        int i = 0; // index for children (greed)
        int j = 0; // index for cookies

        int count = 0;

        while (i < n && j < m) {
            if (g[i] <= s[j]) {
                // Cookie satisfies child's greed
                count++;
                i++;
                j++;
            } else {
                // Cookie too small, try next bigger cookie
                j++;
            }
        }

        return count;
    }
};

