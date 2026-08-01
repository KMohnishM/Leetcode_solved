class Solution:
    def deleteAndEarn(self, nums: List[int]) -> int:
        points=[0]*(max(nums)+1)

        for i in nums:
            points[i]+=i
        
                
        dp=[-1]*(len(points))
        dp[0]=points[0]
        if(len(points)==1):
            return dp[0]
        dp[1]=max(points[0],points[1])
        for i in range(2,len(points)):
            dp[i]=max(points[i]+dp[i-2],dp[i-1])
        return dp[len(points)-1]
