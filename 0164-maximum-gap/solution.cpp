class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()<2){
            return 0;
        }
        if(nums.size()==2){
            return abs(nums[1]-nums[0]);
        }
        sort(nums.begin(),nums.end());
        int temp=-11;
        for(int i=0;i<nums.size()-1;i++){
           if(abs(nums[i]-nums[i+1])>temp){
            temp=abs(nums[i]-nums[i+1]);
           }
        }
        return temp;
    }
};
