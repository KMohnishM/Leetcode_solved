class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> map;
        for(int i=0;i<arr.size();i++){
            map[arr[i]]+=1;
        }
        int count=-1;
        for(auto x : map){
            if(x.first==x.second){
                if(x.first>count){
                    count=x.first;
                }
                
            
            }
        }
    return count;
    }
};
