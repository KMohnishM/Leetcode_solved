class Solution {
public:
    long long earliestFinishTime(vector<int>& landStartTime,
                                 vector<int>& landDuration,
                                 vector<int>& waterStartTime,
                                 vector<int>& waterDuration) {

        int n = landStartTime.size();
        int m = waterStartTime.size();

        vector<pair<int,int>> land(n), water(m);

        for (int i = 0; i < n; i++)
            land[i] = {landStartTime[i], landDuration[i]};

        for (int i = 0; i < m; i++)
            water[i] = {waterStartTime[i], waterDuration[i]};

        sort(land.begin(), land.end());
        sort(water.begin(), water.end());

        vector<int> landStarts(n), waterStarts(m);

        for (int i = 0; i < n; i++)
            landStarts[i] = land[i].first;

        for (int i = 0; i < m; i++)
            waterStarts[i] = water[i].first;

      
        vector<long long> landPrefDur(n), waterPrefDur(m);

        landPrefDur[0] = land[0].second;
        for (int i = 1; i < n; i++)
            landPrefDur[i] = min(landPrefDur[i - 1],
                                 (long long)land[i].second);

        waterPrefDur[0] = water[0].second;
        for (int i = 1; i < m; i++)
            waterPrefDur[i] = min(waterPrefDur[i - 1],
                                  (long long)water[i].second);

       
        vector<long long> landSuf(n), waterSuf(m);

        landSuf[n - 1] =
            (long long)land[n - 1].first + land[n - 1].second;

        for (int i = n - 2; i >= 0; i--) {
            landSuf[i] = min(
                landSuf[i + 1],
                (long long)land[i].first + land[i].second
            );
        }

        waterSuf[m - 1] =
            (long long)water[m - 1].first + water[m - 1].second;

        for (int i = m - 2; i >= 0; i--) {
            waterSuf[i] = min(
                waterSuf[i + 1],
                (long long)water[i].first + water[i].second
            );
        }

        long long ans = LLONG_MAX;

       
        for (int i = 0; i < n; i++) {
            long long finishLand =
                (long long)landStartTime[i] + landDuration[i];

            int pos = upper_bound(
                waterStarts.begin(),
                waterStarts.end(),
                finishLand
            ) - waterStarts.begin();

        
            if (pos > 0) {
                ans = min(
                    ans,
                    finishLand + waterPrefDur[pos - 1]
                );
            }

           
            if (pos < m) {
                ans = min(
                    ans,
                    waterSuf[pos]
                );
            }
        }

        
        for (int i = 0; i < m; i++) {
            long long finishWater =
                (long long)waterStartTime[i] + waterDuration[i];

            int pos = upper_bound(
                landStarts.begin(),
                landStarts.end(),
                finishWater
            ) - landStarts.begin();

           
            if (pos > 0) {
                ans = min(
                    ans,
                    finishWater + landPrefDur[pos - 1]
                );
            }

           
            if (pos < n) {
                ans = min(
                    ans,
                    landSuf[pos]
                );
            }
        }

        return ans;
    }
};
