class Solution {
public:
    void sortColors(vector<int>& nums) {
        unordered_map<int,int> freq = {{0,0}, {1,0}, {2,0}};
        
        
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        
        
        int index = 0;
        
        for(int color=0;color<=2;color++){
            while(freq[color] > 0){
                nums[index++] = color;
                freq[color]--;
            }
        }
    }
};
