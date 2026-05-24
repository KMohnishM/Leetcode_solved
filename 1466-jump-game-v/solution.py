class Solution:
    def maxJumps(self, arr: List[int], d: int) -> int:
        n = len(arr)
        memo = {}
        
        def dp(i):
            
            if i in memo:
                return memo[i]
            
            max_jumps = 1
            
            
            for x in range(1, d + 1):
                j = i + x
                
                if j >= n or arr[j] >= arr[i]:
                    break
                max_jumps = max(max_jumps, 1 + dp(j))
                
            
            for x in range(1, d + 1):
                j = i - x
            
                if j < 0 or arr[j] >= arr[i]:
                    break
                max_jumps = max(max_jumps, 1 + dp(j))
                
            memo[i] = max_jumps
            return max_jumps
            
        
        return max(dp(i) for i in range(n))
