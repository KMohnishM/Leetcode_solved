class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        int ans = INT_MAX;

        int n = landStartTime.size();
        int m = waterStartTime.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                
                int landFinish = landStartTime[i] + landDuration[i];
                int waterBegin = max(waterStartTime[j], landFinish);

                ans = min(ans, waterBegin + waterDuration[j]);

                
                int waterFinish = waterStartTime[j] + waterDuration[j];
                int landBegin = max(landStartTime[i], waterFinish);

                ans = min(ans, landBegin + landDuration[i]);
            }
        }

        return ans;
    }
};
