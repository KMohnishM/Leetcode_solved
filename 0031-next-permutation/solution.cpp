class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        
        
        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        

        if (i >= 0) {
            int j = n - 1;
            while (j >= 0 && nums[j] <= nums[i]) {
                j--;
            }
            
            swap(nums[i], nums[j]);
        }
        
       
        int left = i + 1;
        int right = n - 1;
        while (left < right) {
            swap(nums[left], nums[right]);
            left++;
            right--;
        }
    }
};
