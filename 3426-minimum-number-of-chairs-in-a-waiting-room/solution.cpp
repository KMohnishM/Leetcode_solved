class Solution {
public:
    int minimumChairs(string s) {
        int count=0;
        int ans=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='E'){
                count++;
            }
            else{
                count--;
            }
            ans=max(ans,count);
        }
    return ans;}
};
