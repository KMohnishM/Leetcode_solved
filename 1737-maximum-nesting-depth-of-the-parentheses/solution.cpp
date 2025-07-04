class Solution {
public:
    int maxDepth(string s) {
        int lmax=0;
        int gmax=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                lmax++;
            }
            if(gmax<lmax){
                gmax=lmax;
            }
            if(s[i]==')'){
                lmax--;
            }
        }
     return gmax;
    }
};
