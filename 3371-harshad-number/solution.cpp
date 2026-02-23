class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int tmp=x;
        int sum=0;
        while(tmp>0){
          sum+=tmp%10;
          tmp=tmp/10;
        }
        if(x%sum==0) return sum;
        return -1;
    }
};
