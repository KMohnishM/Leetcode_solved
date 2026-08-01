class Solution:
    def rob(self, nums: List[int]) -> int:
      m=len(nums)  
      if m == 1:
        return nums[0]
      def rob1(arr):  
        n=len(arr)
        dp=[-1]*(n+1)
        dp[0]=arr[0]
        if n==1:
            return dp[0]
        dp[1]=max(arr[1],arr[0])
        for i in range(2,n):
            dp[i]=max(dp[i-1],dp[i-2]+arr[i])
        return dp[n-1]   
      return max(rob1(nums[:-1]),rob1(nums[1:]))    
        
