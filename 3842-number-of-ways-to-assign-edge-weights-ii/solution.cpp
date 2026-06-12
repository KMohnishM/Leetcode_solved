class Solution {
public:
    static constexpr long long MOD = 1000000007LL;

    vector<int> depth;
    vector<vector<int>> up;
    int LOG;

    void dfs(int u, int p, const vector<vector<int>>& adj) {
        up[0][u] = p;

        for (int v : adj[u]) {
            if (v == p) continue;
            depth[v] = depth[u] + 1;
            dfs(v, u, adj);
        }
    }

    int lca(int a, int b) {
        if (depth[a] < depth[b]) swap(a, b);

        int diff = depth[a] - depth[b];

        for (int j = 0; j < LOG; j++) {
            if (diff & (1 << j))
                a = up[j][a];
        }

        if (a == b) return a;

        for (int j = LOG - 1; j >= 0; j--) {
            if (up[j][a] != up[j][b]) {
                a = up[j][a];
                b = up[j][b];
            }
        }

        return up[0][a];
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges,
                                  vector<vector<int>>& queries) {

        int n = edges.size() + 1;

        vector<vector<int>> adj(n + 1);

        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        depth.assign(n + 1, 0);
        up.assign(LOG, vector<int>(n + 1));

        dfs(1, 1, adj);

        for (int j = 1; j < LOG; j++) {
            for (int i = 1; i <= n; i++) {
                up[j][i] = up[j - 1][up[j - 1][i]];
            }
        }

        vector<long long> pow2(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            pow2[i] = (pow2[i - 1] * 2) % MOD;
        }

        vector<int> ans;

        for (auto &q : queries) {
            int u = q[0];
            int v = q[1];

            int w = lca(u, v);

            int dist = depth[u] + depth[v] - 2 * depth[w];

            if (dist == 0)
                ans.push_back(0);
            else
                ans.push_back((int)pow2[dist - 1]);
        }

        return ans;
    }
};
