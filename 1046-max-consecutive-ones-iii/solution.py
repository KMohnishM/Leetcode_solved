class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        cnt=0
        ans=0
        l=0
        for i,num in enumerate(nums):
            if(num==0):
                cnt+=1
            while(cnt>k):
                if(nums[l]==0):
                    cnt-=1
                l+=1
            ans=max(ans,i-l+1)
        return ans                
        
