class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        int mx = 50000;

        vector<int> tree(4 * (mx + 1), 0);

        auto update = [&](auto&& self, int node, int l, int r,
                          int idx, int val) -> void {
            if (l == r) {
                tree[node] = val;
                return;
            }

            int mid = (l + r) >> 1;

            if (idx <= mid)
                self(self, node * 2, l, mid, idx, val);
            else
                self(self, node * 2 + 1, mid + 1, r, idx, val);

            tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
        };

        auto query = [&](auto&& self, int node, int l, int r,
                         int ql, int qr) -> int {
            if (ql > r || qr < l)
                return 0;

            if (ql <= l && r <= qr)
                return tree[node];

            int mid = (l + r) >> 1;

            return max(
                self(self, node * 2, l, mid, ql, qr),
                self(self, node * 2 + 1, mid + 1, r, ql, qr)
            );
        };

        set<int> obstacles = {0, mx};

        for (auto &q : queries) {
            if (q[0] == 1)
                obstacles.insert(q[1]);
        }

        auto it = obstacles.begin();
        int prv = *it;
        ++it;

        while (it != obstacles.end()) {
            update(update, 1, 0, mx, *it, *it - prv);
            prv = *it;
            ++it;
        }

        vector<bool> ans;

        for (int i = (int)queries.size() - 1; i >= 0; --i) {
            auto &q = queries[i];

            if (q[0] == 2) {
                int x = q[1];
                int sz = q[2];

                int best = query(query, 1, 0, mx, 0, x);

                auto it = obstacles.upper_bound(x);

                int right = *it;
                int left = *prev(it);

                best = max(best, x - left);

                ans.push_back(best >= sz);
            }
            else {
                int p = q[1];

                auto it = obstacles.find(p);

                int left = *prev(it);
                int right = *next(it);

                obstacles.erase(it);

                update(update, 1, 0, mx, right, right - left);
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
