class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans=0;
        int finalans=0;
        for(int num:gain){
            ans+=num;
            finalans=max(ans,finalans);
        }
        return finalans;
    }
};
