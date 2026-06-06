class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        int lsum=0,rsum=0;
        for(int i=0;i<n;i++){
            rsum+=nums[i];
        }
        for(int i=0;i<n;i++){
            rsum-=nums[i];
            ans.push_back(abs(rsum-lsum));
            lsum+=nums[i];
        }
        return ans;
    }
};
