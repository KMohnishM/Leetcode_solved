class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        l=0
        ans=1000000
        n=len(nums)
        curr=0
        for i,num in enumerate(nums):
            curr+=num
            while(curr>=target):
                ans=min(ans,i-l+1)
                curr-=nums[l]
                l+=1
        return 0 if ans==1000000 else ans

