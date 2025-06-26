class Solution {
public:
    int hammingWeight(int n) {
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
};
