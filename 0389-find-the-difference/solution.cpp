class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(),t.end());
        char r;
        
        for(int i=0;i<s.length();i++){
            if(s[i]!=t[i]){
               r=t[i];
               break; 
            }
        }
        return r;
    }
};
