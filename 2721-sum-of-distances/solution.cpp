class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        
        
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        
        vector<long long> ans(n, 0);
        
        
        for (auto &it : mp) {
            vector<int> &pos = it.second;
            int m = pos.size();
            
            vector<long long> prefix(m, 0);
            prefix[0] = pos[0];
            
            for (int i = 1; i < m; i++) {
                prefix[i] = prefix[i-1] + pos[i];
            }
            
            long long total = prefix[m-1];
            
            for (int i = 0; i < m; i++) {
                long long left = (long long)i * pos[i] - (i > 0 ? prefix[i-1] : 0);
                long long right = (total - prefix[i]) - (long long)(m-i-1) * pos[i];
                
                ans[pos[i]] = left + right;
            }
        }
        
        return ans;
    }
};
