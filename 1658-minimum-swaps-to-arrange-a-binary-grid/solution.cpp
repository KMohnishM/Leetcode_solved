class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> trailingZero(n, 0);
        
        
        for(int i = 0; i < n; i++) {
            int count = 0;
            for(int j = n - 1; j >= 0; j--) {
                if(grid[i][j] == 0)
                    count++;
                else
                    break;
            }
            trailingZero[i] = count;
        }
        
        int swaps = 0;
        
       
        for(int i = 0; i < n; i++) {
            int required = n - 1 - i;
            int pos = i;
            
            
            while(pos < n && trailingZero[pos] < required)
                pos++;
            
            if(pos == n)
                return -1;  
            
            
            while(pos > i) {
                swap(trailingZero[pos], trailingZero[pos - 1]);
                pos--;
                swaps++;
            }
        }
        
        return swaps;
    }
};
