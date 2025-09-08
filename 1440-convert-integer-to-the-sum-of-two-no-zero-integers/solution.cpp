class Solution {
public:
    bool nz(int n){
        while(n>0){
            int temp=n%10;
            n/=10;
            if(temp==0){
                return false;
            }
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        vector<int> res;
        int j=0;
        for(int i=1;i<n;i++){
            if(nz(i)&&nz(n-i)){
                res.push_back(n-i);
                res.push_back(i);
                j=1;
            }
            if(j==1){
                break;
            }
        }
        
        return res;
    }
};
