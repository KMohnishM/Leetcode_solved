class Solution {
public:
    void permute(vector<int>c,int target,int sum,vector<vector<int>> &result,vector<int>&present,int index){
        
        if(sum==target){
            result.push_back(present);
            return;
        }
        
        for(int i=index;i<c.size();i++){
            if (i > index && c[i] == c[i - 1]) continue;
            sum+=c[i];
            if(sum>target){
            sum-=c[i];
            return;
        }
            present.push_back(c[i]);
            permute(c,target,sum,result,present,i+1);
            present.pop_back();
            sum-=c[i];
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int>present;
        sort(candidates.begin(),candidates.end());
        permute(candidates,target,0,result,present,0);
        return result;
    }
};
