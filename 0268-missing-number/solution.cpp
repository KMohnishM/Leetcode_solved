class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_map<int, int> map;
        // Populate map with frequencies
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }
        // Check numbers from 0 to n
        for (int i = 0; i <= nums.size(); i++) {
            if (map.find(i) == map.end()) {
                return i; // Missing number found
            }
        }
        return -1; // Should never reach here for valid input
    }
};
