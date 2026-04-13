class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int dist=1000000;
        for(int i=start;i<nums.size();i++){
            if(nums[i]==target){
                if(abs(start-i)<dist){
                    dist=abs(start-i);
                }
            }
        }
        for(int i=start;i>=0;i--){
            if(nums[i]==target){
                if(abs(start-i)<dist){
                    dist=abs(start-i);
                }
            }
        }
        
    return dist;
    }
};
