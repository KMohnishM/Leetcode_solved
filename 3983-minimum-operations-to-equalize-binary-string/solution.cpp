#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(string s, int k) {
        int n = s.size();
        
        
        int z = 0;
        for (char c : s)
            if (c == '0') z++;
        
        
        if (z == 0) return 0;
        
        
        if (k == 1) return z;
        
        
        vector<int> dist(n + 1, -1);
        queue<int> q;
        
        dist[z] = 0;
        q.push(z);
        
        set<int> evenStates, oddStates;
        for (int i = 0; i <= n; i++) {
            if (i == z) continue;  
            if (i % 2 == 0) evenStates.insert(i);
            else oddStates.insert(i);
        }
        
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            
            
            int low_i = max(0, k - (n - cur));
            int high_i = min(k, cur);
            
            
            int L = cur + k - 2 * high_i;
            int R = cur + k - 2 * low_i;
            
            
            int targetParity = (cur + k) % 2;
            
            set<int> &candidateSet = 
                (targetParity == 0 ? evenStates : oddStates);
            
            
            auto it = candidateSet.lower_bound(L);
            
            vector<int> toRemove;
            
            while (it != candidateSet.end() && *it <= R) {
                int nextZ = *it;
                dist[nextZ] = dist[cur] + 1;
                q.push(nextZ);
                toRemove.push_back(nextZ);
                ++it;
            }
            
            for (int val : toRemove)
                candidateSet.erase(val);
        }
        
        return dist[0];
    }
};
