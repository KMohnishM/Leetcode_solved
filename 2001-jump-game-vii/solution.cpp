class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        vector<int> q;
        q.push_back(0);

        int farthest = 0;

        for (int i = 0; i < q.size(); i++) {
            int idx = q[i];

            int start = max(idx + minJump, farthest + 1);
            int end = min(idx + maxJump, n - 1);

            for (int j = start; j <= end; j++) {
                if (s[j] == '0') {
                    if (j == n - 1)
                        return true;

                    q.push_back(j);
                }
            }

            farthest = end;
        }

        return n == 1;
    }
};
