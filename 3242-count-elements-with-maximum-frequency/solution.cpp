#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

class Solution {
public:
    int maxFrequencyElements(std::vector<int>& nums) {
        
        std::map<int, int> frequencies;
        for (int num : nums) {
            frequencies[num]++;
        }
        
        
        int maxFreq = 0;
        for (const auto& pair : frequencies) {
            if (pair.second > maxFreq) {
                maxFreq = pair.second;
            }
        }
        
        
        int totalFrequency = 0;
        for (const auto& pair : frequencies) {
            if (pair.second == maxFreq) {
                totalFrequency += maxFreq;
            }
        }
        
        return totalFrequency;
    }
};
