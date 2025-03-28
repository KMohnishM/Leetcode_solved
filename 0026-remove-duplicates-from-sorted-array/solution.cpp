class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=1;
        int count=0;
        while(i<n&&j<n){
            if(nums[i]==nums[j]){
                
                j++;
            }
            else{
                nums[++i]=nums[j];
                count++;
            }
        }
        return count+1;
    }
};
