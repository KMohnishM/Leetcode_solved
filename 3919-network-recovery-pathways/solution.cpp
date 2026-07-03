class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {

        int n = online.size();

        vector<vector<pair<int,int>>> graph(n);

        int mx = 0;

        for(auto &e : edges){
            graph[e[0]].push_back({e[1], e[2]});
            mx = max(mx, e[2]);
        }

        auto check = [&](int limit)->bool{

            vector<int> indegree(n,0);

            for(auto &e : edges){

                if(e[2] < limit)
                    continue;

                int u = e[0];
                int v = e[1];

                if(u != 0 && u != n-1 && !online[u])
                    continue;

                if(v != 0 && v != n-1 && !online[v])
                    continue;

                indegree[v]++;
            }

            queue<int> q;

            for(int i=0;i<n;i++)
                if(indegree[i]==0)
                    q.push(i);

            const long long INF = 4e18;

            vector<long long> dist(n, INF);
            dist[0] = 0;

            while(!q.empty()){

                int u = q.front();
                q.pop();

                for(auto &[v,w] : graph[u]){

                    if(w < limit)
                        continue;

                    if(u != 0 && u != n-1 && !online[u])
                        continue;

                    if(v != 0 && v != n-1 && !online[v])
                        continue;

                    if(dist[u] != INF)
                        dist[v] = min(dist[v], dist[u] + (long long)w);

                    indegree[v]--;

                    if(indegree[v]==0)
                        q.push(v);
                }
            }

            return dist[n-1] <= k;
        };

        int lo = 0;
        int hi = mx;
        int ans = -1;

        while(lo <= hi){

            int mid = lo + (hi-lo)/2;

            if(check(mid)){
                ans = mid;
                lo = mid + 1;
            }
            else
                hi = mid - 1;
        }

        return ans;
    }
};
