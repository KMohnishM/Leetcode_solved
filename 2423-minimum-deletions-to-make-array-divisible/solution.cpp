class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        
        priority_queue<int, vector<int>, greater<int>> p;
        
        for(int i = 0; i < nums.size(); i++){
            p.push(nums[i]);
        }

        int ans;
        int res = 0;
        unordered_set<int> s;

        while(!p.empty()){
            
            ans = p.top();
            p.pop();

            // If already processed
            if(s.find(ans) != s.end()){
                res++;
                continue;
            }

            int c = 0;

            for(int i = 0; i < numsDivide.size(); i++){
                if(numsDivide[i] % ans == 0){
                    c++;
                }
                else{
                    break;
                }
            }

            if(c == numsDivide.size()){
                return res;
            }

            s.insert(ans);
            res++;
        }

        return -1;
    }
};
