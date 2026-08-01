class Solution:
    def climbStairs(self, n: int, costs: List[int]) -> int:
        # print(costs[0])
        # return 0
        
        dp=[-1]*(n+1)
        dp[0]=0
        
        dp[1]=costs[0]+1
        if n==1:
            return dp[1]
        dp[2]=min(dp[1]+costs[1]+1,dp[0]+costs[1]+4)
        for i in range(3,n+1):
            dp[i]=costs[i-1]+min(dp[i-3]+9,dp[i-2]+4,dp[i-1]+1)


        return dp[n]                            
        
