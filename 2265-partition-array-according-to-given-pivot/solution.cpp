class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {

        vector<int> ans;
        int pivots = 0;

        for(int x : nums) {
            if(x < pivot) ans.push_back(x);
            else if(x == pivot) pivots++;
        }

        while(pivots--)
            ans.push_back(pivot);

        for(int x : nums) {
            if(x > pivot)
                ans.push_back(x);
        }

        return ans;
    }
};
