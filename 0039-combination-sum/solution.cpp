class Solution {
public:
    void permute(vector<int>c,int target,int sum,vector<vector<int>> &result,vector<int>&present,int index){
        
        if(sum==target){
            result.push_back(present);
            return;
        }
        if(sum>target){
            return;
        }
        for(int i=index;i<c.size();i++){
            sum+=c[i];
            present.push_back(c[i]);
            permute(c,target,sum,result,present,i);
            present.pop_back();
            sum-=c[i];
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int>present;
        permute(candidates,target,0,result,present,0);
        return result;
    }
};
