class Solution {
public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        vector<long long> pos;
        long long L = side;

       
        for (auto &p : points) {
            long long x = p[0], y = p[1];
            if (y == 0) pos.push_back(x);
            else if (x == L) pos.push_back(L + y);
            else if (y == L) pos.push_back(3 * L - x);
            else pos.push_back(4 * L - y);
        }

        sort(pos.begin(), pos.end());
        int n = pos.size();
        long long perimeter = 4 * L;

        
        vector<long long> extended = pos;
        for (auto x : pos) extended.push_back(x + perimeter);

        
        auto can = [&](long long d) {
            for (int start = 0; start < n; start++) {
                int count = 1;
                long long curr = extended[start];

                for (int taken = 1; taken < k; taken++) {
                   
                    auto it = lower_bound(
                        extended.begin(),
                        extended.begin() + start + n,
                        curr + d
                    );

                    if (it == extended.begin() + start + n)
                        break;

                    curr = *it;
                    count++;
                }

                if (count >= k) {
                    long long first = extended[start];
                    long long last = curr;

                    long long dist = last - first;
                    dist = min(dist, perimeter - dist);

                    if (dist >= d) return true;
                }
            }
            return false;
        };

       
        long long low = 0, high = 2 * L, ans = 0;

        while (low <= high) {
            long long mid = (low + high) / 2;
            if (can(mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};
