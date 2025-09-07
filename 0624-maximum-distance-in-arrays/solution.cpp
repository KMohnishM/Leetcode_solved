class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int res = 0;
        int gmin = arrays[0][0];
        int gmax = arrays[0].back();

        for (int i = 1; i < arrays.size(); i++) {
            
            res = max(res, abs(arrays[i].back() - gmin));
            res = max(res, abs(gmax - arrays[i][0]));

            
            gmin = min(gmin, arrays[i][0]);
            gmax = max(gmax, arrays[i].back());
        }

        return res;
    }
};

