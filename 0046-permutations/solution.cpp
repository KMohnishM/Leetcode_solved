class Solution {
public:
    bool found(int n,vector<int>a){
      for(int i=0;i<a.size();i++){
        if(n==a[i])return true;
      }
      return false;
    }
    void ans(vector<int> nums,vector<vector<int>>&result,int index,vector<int>&present){
         if(present.size()==nums.size()){
            result.push_back(present);
            return;
         }
         for(int i=0;i<nums.size();i++){
            if(found(nums[i],present)) continue;
            present.push_back(nums[i]);
            ans(nums,result,i+1,present);
            present.pop_back();
         }
    }
    vector<vector<int>> permute(vector<int>& nums) {
            vector<vector<int>>result;
            vector<int>present;
            ans(nums,result,0,present);
            return result;   
    }
};
