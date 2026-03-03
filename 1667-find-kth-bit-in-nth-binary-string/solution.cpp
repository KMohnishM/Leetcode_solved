class Solution {
public:
    string find(int a){
        if(a==1){
            return "0";
        }
        string tmp=find(a-1);
        int i=tmp.length()-1;
        string tmp1="";
        while(i>=0){
            if(tmp[i]=='0')tmp1+="1";
            else tmp1+="0";
            i--;
        }
        return tmp+"1"+tmp1;
    }
    char findKthBit(int n, int k) {
        string a=find(n);
        cout<<a;
        return a[k-1];
    }
};
