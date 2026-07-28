class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        ans=0
        # nums.append(0)
        if len(nums)==1:
            return 0
        for i in range(0,len(nums)):
            if(i==0):
                if(nums[i]>nums[i+1]):
                    ans=i
            elif i==len(nums)-1:
                if(nums[i]>nums[i-1]):
                    ans=i
            else: 
                if nums[i]>nums[i-1] and nums[i]>nums[i+1]:
                    ans=i
        return ans        
        
