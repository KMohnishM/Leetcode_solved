class Solution {
public:
    
    long long heightReduced(long long t, long long T){
        
        long long left = 0, right = 1e5;
        long long ans = 0;
        
        while(left <= right){
            long long mid = (left + right) / 2;
            
            long long time = t * (mid * (mid + 1) / 2);
            
            if(time <= T){
                ans = mid;
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        
        return ans;
    }
    
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        
        long long left = 0;
        long long right = 1e18;
        long long ans = right;
        
        while(left <= right){
            
            long long mid = (left + right) / 2;
            
            long long total = 0;
            
            for(long long t : workerTimes){
                total += heightReduced(t, mid);
                
                if(total >= mountainHeight)
                    break;
            }
            
            if(total >= mountainHeight){
                ans = mid;
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        
        return ans;
    }
};
