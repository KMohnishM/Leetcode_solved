class Solution {
public:
    int minOperations(string s) {
        int count=0,ans=0;
        string tmp=s;
        for(int i=1;i<s.length();i++){
           if(s[i]==s[i-1]){
               count++;
               if(s[i]=='0')s[i]='1';
               else s[i]='0';
           }
        }
        s=tmp;
        if(s[0]=='0'){
            s[0]='1';
        }
        else s[0]='0';
        ans=count;
        count=1;
        for(int i=1;i<s.length();i++){
           if(s[i]==s[i-1]){
               count++;
               if(s[i]=='0')s[i]='1';
               else s[i]='0';
           }
        }
        ans=min(ans,count);
        return ans;
    }
};
