class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int global=0;
        int local=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                local+=1;
            }
            else{
                local=0;
            }
            if(local>=global){
                global=local;
            }
        }
        return global;
    }
};
