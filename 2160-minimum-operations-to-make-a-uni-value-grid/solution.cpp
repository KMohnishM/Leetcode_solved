class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;
        
       
        for (auto &row : grid) {
            for (auto &val : row) {
                nums.push_back(val);
            }
        }
        
       
        int rem = nums[0] % x;
        for (int val : nums) {
            if (val % x != rem) return -1;
        }
        
       
        sort(nums.begin(), nums.end());
        
       
        int median = nums[nums.size() / 2];
        
       
        int ops = 0;
        for (int val : nums) {
            ops += abs(val - median) / x;
        }
        
        return ops;
    }
};
