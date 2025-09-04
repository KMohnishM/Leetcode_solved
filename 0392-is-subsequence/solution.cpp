class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i1=s.length();
        int i2=t.length();
        while(i1>0&&i2>0){
           if(s[i1-1]==t[i2-1]){
            i1--;
           }
           i2--;
        }
        if(i1==0){
            return true;
        }
        return false;
    }
};
