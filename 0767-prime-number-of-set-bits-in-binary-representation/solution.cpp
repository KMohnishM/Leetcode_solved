class Solution {
public:
    bool isprime(int n){
        if(n==1)return false;
        for(int i=2;i*i<=n;i++){
            if(n%i==0)return false;
        }
    return true;
    }

    int setbitscount(int n){
       int temp=n;
        vector<int>arr;
        while(temp>0){
            arr.push_back(temp%2);
            temp=temp/2;
        }
        int count=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==1){count++;}
        }
        return count;
    }
    int countPrimeSetBits(int left, int right) {
        int count=0;
        for(int i=left;i<=right;i++){
            if(isprime(setbitscount(i))){
            //   cout<<i<<" "<<setbitscount(i);
              count++;
            }
        }
    return count;
    }

};
