class Solution:
    def missingInteger(self, nums: List[int]) -> int:
        sum=nums[0]
        n=len(nums)
        if(n==1):
            return nums[0]+1
        i=1
        while i<n and nums[i]==nums[i-1]+1 :
            sum+=nums[i]
            i+=1
        ans=sum
        while sum in nums:
            sum+=1
             
        return sum  
        
