class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum=0;
        int count=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        int lsum=0;
        int rsum=sum;
        for(int i=0;i<nums.size()-1;i++){
            lsum+=nums[i];
            rsum-=nums[i];
            if(abs(lsum-rsum)%2==0){
                count+=1;
            }
        }
    return count;
    }
};
