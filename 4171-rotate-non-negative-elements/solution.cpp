class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int> arr;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] >= 0){
                arr.push_back(nums[i]);
            }
        }
        int l = arr.size();
        if(l == 0) return nums;
        k = k % l;
        
        reverse(arr.begin(), arr.begin() + k);
        reverse(arr.begin() + k, arr.end());
        reverse(arr.begin(), arr.end());
        int a = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] >= 0){
                nums[i] = arr[a++];
            }
        }
        
        return nums;
    }
};
