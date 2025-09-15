class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int,int>c;
        for(int i=0;i<nums.size();i++){
            if(c.count(nums[i])){
                return nums[i];
            }
            c[nums[i]]=1;
        }
    return -1;
    }
};
