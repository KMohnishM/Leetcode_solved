class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int>mp={{'b',0},{'a',0},{'l',0},{'o',0},{'n',0}};
        for(char t:text){
           mp[t]++;
        }
        int ans=0;
        ans=min(mp['b'],min(mp['a'],mp['n']));
        ans=min(ans,mp['l']/2);
        ans=min(ans,mp['o']/2);
        return ans;
    }
};
