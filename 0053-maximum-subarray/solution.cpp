#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int maxCrossingSum(vector<int>& nums, int left, int mid, int right) {
        int leftSum = INT_MIN, rightSum = INT_MIN;
        int sum = 0;

        // Find the max sum in the left half (including mid)
        for (int i = mid; i >= left; i--) {
            sum += nums[i];
            leftSum = max(leftSum, sum);
        }

        sum = 0;
        // Find the max sum in the right half (excluding mid)
        for (int i = mid + 1; i <= right; i++) {
            sum += nums[i];
            rightSum = max(rightSum, sum);
        }

        // The max subarray crossing the mid
        return leftSum + rightSum;
    }

    int maxSubArrayHelper(vector<int>& nums, int left, int right) {
        if (left == right) return nums[left]; // Base case: single element

        int mid = left + (right - left) / 2;

        // Recursively find max subarray sum in left, right, and crossing mid
        int leftMax = maxSubArrayHelper(nums, left, mid);
        int rightMax = maxSubArrayHelper(nums, mid + 1, right);
        int crossMax = maxCrossingSum(nums, left, mid, right);

        return max({leftMax, rightMax, crossMax});
    }

    int maxSubArray(vector<int>& nums) {
        return maxSubArrayHelper(nums, 0, nums.size() - 1);
    }
};



