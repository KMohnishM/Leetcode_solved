class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<int> height(n, 0);
        int maxArea = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1)
                    height[j]++;
                else
                    height[j] = 0;
            }
            vector<int> sorted = height;
            sort(sorted.begin(), sorted.end(), greater<int>());
            for (int j = 0; j < n; j++) {
                maxArea = max(maxArea, sorted[j] * (j + 1));
            }
        }
        
        return maxArea;
    }
};
