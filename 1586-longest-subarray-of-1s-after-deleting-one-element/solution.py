class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        cnt=0
        ans=0
        l=0
        for i,num in enumerate(nums):
            if(num==0):
                cnt+=1
            while(cnt>1):
                if(nums[l]==0):
                    cnt-=1
                l+=1
            ans=max(ans,i-l)
        return ans                
