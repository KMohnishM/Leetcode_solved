class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int c=0;
        int present;
        for(int i=0;i<nums.size();i++){
            if(c==0){
                c=1;
                present=nums[i];
            }
            else if(present==nums[i]){c++;}
            else{
                c--;
            }
        }
        // int k=0;
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]==present){
        //         k++;
        //     }
        // }
        // if(k)
        return present;
    }
};
