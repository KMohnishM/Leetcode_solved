class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int>dp1(n,1);
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp1[j]+=dp1[j-1];
            }
        } 
    return dp1[n-1];
    }
};
