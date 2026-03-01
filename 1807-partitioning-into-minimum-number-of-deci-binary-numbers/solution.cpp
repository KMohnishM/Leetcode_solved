class Solution {
public:
    int minPartitions(string n) {
        int max=0;
        for(int i=0;i<n.length();i++){
           if(max<n[i]-'0'){
            max=n[i]-'0';
           }
        }
        return max;
    }
};
