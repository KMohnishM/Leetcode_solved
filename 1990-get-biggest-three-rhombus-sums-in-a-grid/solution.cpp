class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        set<int> sums;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                sums.insert(grid[i][j]); 

                for(int k=1;;k++){
                    if(i-k<0 || i+k>=m || j-k<0 || j+k>=n)
                        break;

                    int sum = 0;

                    int r=i-k, c=j;
                    
                    for(int t=0;t<k;t++)
                        sum += grid[r+t][c+t];

                    for(int t=0;t<k;t++)
                        sum += grid[r+k+t][c+k-t];

                    for(int t=0;t<k;t++)
                        sum += grid[r+2*k-t][c-t];

                    for(int t=0;t<k;t++)
                        sum += grid[r+k-t][c-k+t];

                    sums.insert(sum);
                }
            }
        }

        vector<int> res;
        for(auto it = sums.rbegin(); it!=sums.rend() && res.size()<3; ++it)
            res.push_back(*it);

        return res;
    }
};
