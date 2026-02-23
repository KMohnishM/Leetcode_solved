class Solution {
public:
    void permute(int n,int o,int c,vector<string> &result,string present){
        if(o==n&&c==n){
            result.push_back(present); 
             return ;
        }
        if(o<n){
            // cout<<o;
            string temp=present;
             temp+="(";
             permute(n,o+1,c,result,temp);
            }
        if(c<o){
            present+=")";
            permute(n,o,c+1,result,present);
        }    

    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        permute(n,0,0,result,"");
        return result;
    }
};
