class Solution {
public:
    int res(int a){
        int ans=0;
        while(a>0){
           ans+=a%10;
           a=a/10;
        }
        return ans;
    }
    int differenceOfSum(vector<int>& nums) {
        int es=0;
        int ds=0;
        for(int i=0;i<nums.size();i++){
            es+=nums[i];
            ds+=res(nums[i]);
        }
        return abs(es-ds);
    }
};
